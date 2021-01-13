#ifndef DEVICES_H
#define DEVICES_H

#include <typeinfo>
#include "mixins.hpp"
#include "pin.h"
#include "utilities.h"
class GPIOBase
{
    public:
        GPIOBase();
        virtual ~GPIOBase();
        void close();
        void _check_open();

    protected:
        bool closed();

  
};
class Device:ValuesMixin, GPIOBase
{

    public:
        Device();
        Device(Factory *pin_factory );
        static Factory* _default_pin_factory();
        //Property <int> value;
        bool is_active();
       
    protected:
        Factory*  pin_factory ; // instance of a Factory sub-class

};
class GPIODevice:Device
{
    public:
        GPIODevice(int pin);
        bool _state_to_value(int  state);
    private:
        Pin _pin;
        bool _active_state;
        bool _inactive_state;

};

#endif