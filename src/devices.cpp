#include <typeinfo>
#include "mixins.hpp"
#include "pin.hpp"

class GPIOBase
{
    public:
        GPIOBase();
        ~GPIOBase();
        void close();
        void _check_open();

    protected:
        bool closed();

  
};

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
           throw("%s is closed or uninitialized",typeid(this).name());
}


class Device:ValuesMixin, GPIOBase
{

    public:
        Device();
   
    protected:
        Factory pin_factory ; // instance of a Factory sub-class

};

Device::Device()
{
   // this->pin_factory  = factory;

}
 