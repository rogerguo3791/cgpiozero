#ifndef PIGPIO
#define PIGPIO

#include <string>
#include "pin.h"


class PiGPIOFactory: public Factory{
    public:
        PiGPIOFactory( char * host,  char* port );
        void close();
        int connection();
        char* host();
        char* port();
        uint32_t ticks();
        uint32_t ticks_diff(uint32_t later,uint32_t earlier);
        piBoardInfo_t get_pi_info();
        virtual Pin* pin(int n);

    private:
        char * _host;
        char * _port;
        int    _connection;
        map<int , Pin*> pins;
};

class PiGPIOPin: public Pin{
    public:
        PiGPIOPin(PiGPIOFactory* factory, unsigned number);
        void close();
        unsigned number();
        Factory* factory();
    //private:    
        void        _call_when_changed(unsigned gpio, int level, u_int32_t ticks);
        // Need a static callback to link with C. 
        static void _call_when_changed_ex(int pi, unsigned gpio, unsigned level, u_int32_t ticks, void * user);
        
        CBFunc_t    _get_when_changed() const;
        void        _set_when_changed(const CBFunc_t& value);
        void        _enable_event_detect();
        void        _disable_event_detect();

        string      _get_function() const;
        void        _set_function(const string& value);
        int         _get_state() const;
        void        _set_state(const int& value);
        string      _get_pull() const;
        void        _set_pull(const string& value);
        
        unsigned    _get_frequency() const;
        void        _set_frequency(const unsigned& value);
        unsigned    _get_bounce() const ; 
        void        _set_bounce(const unsigned& value); //设置边沿抖动滤波时间，单位为秒
        string      _get_edges() const;
        void        _set_edges(const string& value);

        bool        _pwm;

        int         _callback;

        PiGPIOFactory* _factory;
        //_when_changed_lock ;
  
        unsigned _number;
        bool enabled;
        int pi ;
     
        
};



#endif