#include <typeinfo>
#include <initializer_list>
#include "mixins.hpp"
#include "pin.h"
#include "utilities.h"
#include "devices.hpp"


GPIOBase::~GPIOBase()
{
    this->close();
    
}
void GPIOBase::close() {}
bool GPIOBase::closed(){
    //raise NotImplementedError
    throw("NotImplementedError");
}   

void GPIOBase:: _check_open(){
    if (this->closed())
           throw(format_str("%s is closed or uninitialized",typeid(this).name()));
}




Device::Device(Factory* pin_factory )
{
   if (pin_factory ==NULL)  
    this->pin_factory  = pin_factory;

    else
        //暂时不实现
        this->pin_factory= _default_pin_factory();
}
 
Factory*  Device::_default_pin_factory(){
   // return nullptr;
  
   return NULL;
}

bool Device::is_active(){
    return bool(this->value);
}



GPIODevice::GPIODevice(int pin){

    if (pin >=1 && pin <=31)   {
        //{pin} 为可变参数函数调用模式
          this->pin_factory->reserve_pins(typeid(this).name(),{pin});
        }

}

bool GPIODevice:: _state_to_value(int  state){
        return (state == this->_active_state);
}
