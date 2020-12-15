
#include <stdio.h>
#include <cstring>
#include <list>
#include <map>
#include <initializer_list>
#include <iostream>
#include <exception>  
#include <pthread.h>
#include <mutex>
#include "pin.hpp"

class PiPin : public Pin
{
    public:
        PiPin(Factory factory, unsigned number);

    private:
       Factory _factory;
       //_when_changed_lock ;
       eventFunc_t _when_changed ;
       unsigned _number;

};

PiPin::PiPin(Factory factory, unsigned number)
{
    this->_factory =factory;
    this->_number  =number;
    //self._when_changed_lock = RLock();
    this->_when_changed =NULL;
   // try{
        //factory.get_pi_info().physical_pin(repr(self))
    //}
            



}

/*
    """
    Extends :class:`~gpiozero.Pin`. Abstract base class representing a
    multi-function GPIO pin attached to a Raspberry Pi. Descendents *must*
    override the following methods:

    * :meth:`_get_function`
    * :meth:`_set_function`
    * :meth:`_get_state`
    * :meth:`_call_when_changed`
    * :meth:`_enable_event_detect`
    * :meth:`_disable_event_detect`


    def __init__(self, factory, number):
        super(PiPin, self).__init__()
        self._factory = factory
        self._when_changed_lock = RLock()
        self._when_changed = None
        self._number = number
        try:
            factory.pi_info.physical_pin(repr(self))
        except PinNoPins:
            warnings.warn(
                PinNonPhysical(
                    'no physical pins exist for %s' % repr(self)))

    @property
    def number(self):
        return self._number

    def __repr__(self):
        return 'GPIO%d' % self._number

    @property
    def factory(self):
        return self._factory

    def _call_when_changed(self, ticks, state):
        """
        Called to fire the :attr:`when_changed` event handler; override this
        in descendents if additional (currently redundant) parameters need
        to be passed.
        """
        method = self._when_changed()
        if method is None:
            self.when_changed = None
        else:
            method(ticks, state)

    def _get_when_changed(self):
        return None if self._when_changed is None else self._when_changed()

    def _set_when_changed(self, value):
        with self._when_changed_lock:
            if value is None:
                if self._when_changed is not None:
                    self._disable_event_detect()
                self._when_changed = None
            else:
                enabled = self._when_changed is not None
                # Have to take care, if value is either a closure or a bound
                # method, not to keep a strong reference to the containing
                # object
                if isinstance(value, MethodType):
                    self._when_changed = WeakMethod(value)
                else:
                    self._when_changed = ref(value)
                if not enabled:
                    self._enable_event_detect()

    def _enable_event_detect(self):
        """
        Enables event detection. This is called to activate event detection on
        pin :attr:`number`, watching for the specified :attr:`edges`. In
        response, :meth:`_call_when_changed` should be executed.
        """
        raise NotImplementedError

    def _disable_event_detect(self):
        """
        Disables event detection. This is called to deactivate event detection
        on pin :attr:`number`.
        """
        raise NotImplementedError
*/

class PiFactory: public Factory
{
    public:
        PiFactory();
        void close();
        void reserve_pins(char *requester, initializer_list<int> pins);
        void  release_pins(char *reserver, initializer_list<int> pins);
        Pin pin(int n);
    private:
        char const *_info;
        map<int , Pin> pins;
        Pin pin_class;
};

PiFactory::PiFactory()
{
    this->_info =NULL;
    this->pins.clear();
    //this->pin_class = NULL;
    /*
         self.spi_classes = {
            ('hardware', 'exclusive'): None,
            ('hardware', 'shared'):    None,
            ('software', 'exclusive'): None,
            ('software', 'shared'):    None,
            }
     */
}
void PiFactory::close(){
         Pin pin;
       /*  
        for (map<int ,string>::iterator it = this->pins.begin(); it != this->pins.end(); ++it) 
        {  
           //it->second.close();
        }
        this->pins.clear();
        */
    }


void PiFactory::reserve_pins(char *requester, initializer_list<int> pins)
{
        Factory::reserve_pins(requester, pins);

}

void  PiFactory::release_pins(char *reserver, initializer_list<int> pins)
{
    Factory::release_pins(reserver, pins);   
}

Pin PiFactory::pin(int n){
     //n = self.pi_info.to_gpio(spec)
        Pin pin;
        try {
            pin = this->pins[n];
        }
        catch (exception& e)
        {
            //this->pin_class = new Pin();
            //pin =this->pin_class;
            //this->pins[n] = pin;
        }
           
        
        return pin ;
}
        
