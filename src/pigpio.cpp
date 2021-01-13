#include <stdlib.h>
#include <iostream>
#include "pin.h"
#include <pigpiod_if2.h>
#include "utilities.h"
#include "pigpio.hpp"

using namespace std;
typedef map<int, string > func_t;
typedef map<string, int > name_t;

name_t GPIO_FUNCTIONS {
    {"input", PI_INPUT},
    {"output",PI_OUTPUT},
    {"alt0"  ,PI_ALT0},
    {"alt1"  ,PI_ALT1},
    {"alt2"  ,PI_ALT2},
    {"alt3"  ,PI_ALT3},
    {"alt4"  ,PI_ALT4},
    {"alt5"  ,PI_ALT5}
};

name_t GPIO_PULL_UPS  {
    {"up"      ,PI_PUD_UP},
    {"down"    ,PI_PUD_DOWN},
    {"floating",PI_PUD_OFF}
};

name_t GPIO_EDGES = {
    {"both"   ,EITHER_EDGE},
    {"rising" ,RISING_EDGE},
    {"falling",FALLING_EDGE}
};

func_t GPIO_FUNCTION_NAMES {
    {PI_INPUT, "input"},
    {PI_OUTPUT,"output"},
    {PI_ALT0,  "alt0"},
    {PI_ALT1,  "alt1"},
    {PI_ALT2,  "alt2"},
    {PI_ALT3,  "alt3"},
    {PI_ALT4,  "alt4"},
    {PI_ALT5,  "alt5"}
};

func_t GPIO_PULL_UP_NAMES{
    {PI_PUD_UP,    "up"},
    {PI_PUD_DOWN , "down"},
    {PI_PUD_OFF  , "floating"}
};

func_t GPIO_EDGES_NAMES = {
    {EITHER_EDGE,"both"  } ,
    {RISING_EDGE,"rising" },
    {FALLING_EDGE,"falling"}
};


PiGPIOFactory::PiGPIOFactory( char * host,  char* port ){
    //PiFactory();
    if (host ==NULL)
        host = getenv("PIGPIO_ADDR");
    if (port ==NULL)
        port = getenv("PIGPIO_PORT");
    //this->pin_class=new PiGPIOPin;
    /*self.spi_classes = {
            ('hardware', 'exclusive'): PiGPIOHardwareSPI,
            ('hardware', 'shared'):    PiGPIOHardwareSPIShared,
            ('software', 'exclusive'): PiGPIOSoftwareSPI,
            ('software', 'shared'):    PiGPIOSoftwareSPIShared,
            }
            */
    _connection = pigpio_start(host, port); /* Connect to Pi. */
    if (_connection <0 )
        throw(format_str("failed to connect to %s:%s",host,port));
       // cout<<"failed to connect to PI"<<endl;
    this->_host = host;
    this->_port = port;
    this->pins.clear();

    //this->pin_class = new PiGPIOPin;
    //this->_spis =[];
}

void PiGPIOFactory::close(){

    Pin* pin;
    for (map<int ,Pin*>::iterator it = this->pins.begin(); it != this->pins.end(); ++it) 
    {  
        pin = it->second;
        pin->close();
        delete pin; //释放pin
    }
    

    if (this->_connection >=0)
        pigpio_stop(this->_connection);
    this->_connection=-1;
    this->pins.clear();    

}

int PiGPIOFactory::connection(){
    return this->_connection;
}

char* PiGPIOFactory::host(){
    return this->_host;
}
char * PiGPIOFactory::port(){
    return this->_port;
}

uint32_t PiGPIOFactory::ticks(){
    return get_current_tick(_connection);
}
uint32_t PiGPIOFactory::ticks_diff(uint32_t later,uint32_t earlier){
    return ((later - earlier) % 0x100000000) / 1000000;
}

Pin* PiGPIOFactory::pin(int n){
    Pin* pin;
  
    pin = this->pins[n];
    if (pin ==NULL){
        pin = new PiGPIOPin(this,n);
        this->pins[n]=pin;
    } 
    return pin;
}

piBoardInfo_t PiGPIOFactory::get_pi_info(){
    uint32_t hardware_revision =get_hardware_revision(this->_connection);
    return(from_revision(hardware_revision));
}

PiGPIOPin::PiGPIOPin(PiGPIOFactory* factory, unsigned number){
    this->_pull ="up";
    this->_pwm  = false;
    this->_callback = -1;
    this->_bounce = 0;
    this->_edges =GPIO_EDGES_NAMES[ EITHER_EDGE];
    this->_factory =factory;
    this->_number  =number;
    //self._when_changed_lock = RLock();
    this->_when_changed =NULL;
    this->pi =this->_factory->connection();   
    try {
        set_mode(this->pi,number,PI_INPUT);
    }
    catch (exception& e)  {
        throw(format_str("ValueError %s",e));
    }
    set_pull_up_down(this->pi,number,PI_PUD_UP);
    set_glitch_filter(this->pi,number,0);
    

}

unsigned PiGPIOPin::number(){
    return this->_number;
}

Factory* PiGPIOPin::factory(){
    return this->_factory;
}

void PiGPIOPin::close(){
     /// PiGPIOFactory* f=(PiGPIOFactory*)this->_factory;
    if (this->pi>=0){
        this->_set_frequency(0);
        this->_set_when_changed(NULL);
        this->_function= "input";
        this->_pull = "floating";
    }

}

string PiGPIOPin::_get_function() const  {

    return  GPIO_FUNCTION_NAMES[get_mode(this->pi,this->_number)];
}

void PiGPIOPin::_set_function(const string& value){

    if (value != "input")
            this->_pull = "floating";
        try{
            set_mode(this->pi,this->_number, GPIO_FUNCTIONS[value]);
            }
        catch (...){   
            throw(format_str("invalid function %s for pin %d",value, this->_number));
        }

}

int  PiGPIOPin::_get_state() const{
    
    if (this->_pwm)
        return (
            get_PWM_dutycycle(this->pi,this->_number) /
            get_PWM_range(this->pi,this->_number)
            );
    else
        return gpio_read(this->pi,this->_number);
}

void PiGPIOPin::_set_state(const int& value){
    int v;
        if (this->_pwm)
            try{
                v = int(value * get_PWM_range(this->pi,this->_number));
                if (v != get_PWM_dutycycle(this->pi,this->_number))
                    set_PWM_dutycycle(this->pi,this->_number, value);
            }
            catch (...){
                throw(format_str("invalid state %s for pin %d", value, this->_number));
            }
        else if (this->_get_function() == "input")
            throw(format_str("cannot set state of pin %d",this->_number));
        else 
            // write forces pin to OUTPUT, hence the check above
            gpio_write(this->pi,this->_number, bool(value));
}

string PiGPIOPin::_get_pull()const {
        return this->_pull;
}

void PiGPIOPin::_set_pull(const string& value){
 
        if (this->_function != "input")
            throw(format_str("cannot set pull on non-input pin %d", this->_number));
        //if value != 'up' and self.factory.pi_info.pulled_up(repr(self)):
        //    raise PinFixedPull('%r has a physical pull-up resistor' % self)
        try{
            set_pull_up_down(this->pi,this->_number, GPIO_PULL_UPS[value]);
            this->_pull = value;
            }
        catch (...){
              throw(format_str("invalid pull %s for pin %d",value, this->_number));
        }
}

unsigned PiGPIOPin::_get_frequency() const {
        if (this->_pwm)
            return get_PWM_frequency(this->pi,this->_number);
        return 0;
}

void PiGPIOPin::_set_frequency(const unsigned& value){
        if (!this->_pwm  &&  value !=0  ) {
            if (this->_get_function() != "output")
                throw(format_str("cannot start PWM on pin %d", this->_number));
            gpio_write(this->pi,this->_number, 0);
            set_PWM_frequency(this->pi,this->_number, value);
            set_PWM_range(this->pi,this->_number, 10000);
            set_PWM_dutycycle(this->pi,this->_number, 0);
            this->_pwm = true;
        }
        else if (this->_pwm && value !=0)
            if (value != get_PWM_frequency(this->pi,this->_number)){
                set_PWM_frequency(this->pi,this->_number, value);
                set_PWM_range(this->pi,this->_number, 10000);
                }
        else if (this->_pwm && value ==0){
            gpio_write(this->pi,this->_number, 0);
            this->_pwm = false;
        }
        
}

unsigned PiGPIOPin::_get_bounce()const {
        return this->_bounce / 1000000;
 }
void PiGPIOPin::_set_bounce(const unsigned& value){
    unsigned v=value;
        if (v <0)
            v = 0;
        this->_bounce =v;
        set_glitch_filter(this->pi,this->_number, int(v * 1000000));
}
string PiGPIOPin::_get_edges() const{

        return this->_edges;
}

void PiGPIOPin::_set_edges(const string& value){
        CBFunc_t f = this->_when_changed;

        this->_when_changed = NULL;
        try {
           this->_edges = value;
        }
        catch(...)
        {

        }
        this->_when_changed = f;
}
//TODO ： 此处需要进一步需要根据情况进一步修改，
void PiGPIOPin::_call_when_changed(unsigned gpio, int level, u_int32_t ticks){
        CBFunc_t method = this->_when_changed;
        if (method ==NULL)
            this->_when_changed = NULL;
        else
            method(this->pi,gpio,level,ticks);

}

void PiGPIOPin::_call_when_changed_ex(int pi, unsigned gpio, unsigned level, u_int32_t ticks,void * user){

     PiGPIOPin * mySelf =(PiGPIOPin *) user;
     mySelf->_call_when_changed(gpio,level,ticks);

 }
//TODO ： 此处需要进一步需要根据情况进一步修改，
//        考虑回调函数的通用性，不必使用 CBFunc_t类型
void PiGPIOPin::_set_when_changed(const CBFunc_t&  value){
     //with self._when_changed_lock:

            if (value == NULL){
                if (this->_when_changed !=NULL)
                    this->_disable_event_detect();
                this->_when_changed = NULL;
            }
            else {
                this->_when_changed = value;
                enabled =(this->_when_changed !=NULL) ? true :false;
               }
}

CBFunc_t  PiGPIOPin::_get_when_changed() const {
    return this->_when_changed;
}
void PiGPIOPin::_enable_event_detect(){
   int edgs = GPIO_EDGES[this->_edges];
   this->_callback = callback_ex(this->pi,this->_number, edgs, _call_when_changed_ex,this);
   
}

void PiGPIOPin::_disable_event_detect(){
    if (this->_callback >=0){
        callback_cancel(this->_callback);
        this->_callback =-1;
    }


}


