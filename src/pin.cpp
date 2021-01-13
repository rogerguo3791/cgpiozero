#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <map>
#include <cstring>
#include "utilities.h"
#include <pigpiod_if2.h>
#include <iostream>
#include "pin.h"
#include "Property.h"
using namespace std;
/*
    class Pin
    {
        private:
            const char* function ; //引脚功能
            unsigned    state;     //引脚状态
            unsigned    pull;      //上拉双胎
            unsigned    bounce;    //边界出发范围 
            const char* edges;     //边沿检测 
        
        public:
            Pin();
            virtual ~Pin(){};
            void close();
            int output_with_state(unsigned state);
            int input_with_pull(unsigned pull);
            char * get_function();
            void set_function(char* value);
            unsigned get_state();
            void set_state(unsigned value);
            char*  get_pull();
            void set_pull(char*  value);
            unsigned get_frequency();
            void set_frequency(unsigned value);
            unsigned get_bounce();
            void set_bounce(unsigned value);
            char*  get_edges();
            void set_edges(char*  value);
            eventFunc_t  get_when_changed();
            void set_when_changed(eventFunc_t value);
    };
    */

Pin::Pin()
{
    /*
    private:
            const char* function ; //引脚功能
            unsigned    state;     //引脚状态
            unsigned    pull;      //上拉双胎
            unsigned    bounce;    //边界出发范围 
            const char* edges;     //边沿检测 
            */
       function = Property<string>::of(this, &Pin::_get_function, &Pin::_set_function);
       state    = Property<int>::of(this, &Pin::_get_state,    &Pin::_set_state);
       pull     = Property<string>::of(this, &Pin::_get_pull, &Pin::_set_pull);
       frequency= Property<unsigned>::of(this, &Pin::_get_frequency, &Pin::_set_frequency);
       bounce   = Property<unsigned>::of(this, &Pin::_get_bounce, &Pin::_set_bounce);
       edges    = Property<string>::of(this, &Pin::_get_edges, &Pin::_set_edges);
       when_changed= Property<CBFunc_t>::of(this, &Pin::_get_when_changed, 
                                                 &Pin::_set_when_changed);


}

void Pin::close()
    { /*
        Cleans up the resources allocated to the pin. After this method is
        called, this :class:`Pin` instance may no longer be used to query or
        control the pin's state.
        */
       //return 0;
   }

int Pin::output_with_state(int state){
        
        this->function = "output";
        this->state = state;
        return 0;
    }
int Pin::input_with_pull(string value){
        this->function = "input";
        this->pull = value;
        return 0;
    }

string  Pin::_get_function() const{
       // return "input";
       return this->_function;
    }

void Pin::_set_function(const string& value){
        
       // if( value != "input") 
       //    throw (format_str("Cannot set the function of pin to %s",value) );
       this->_function = value;
    }

int Pin::_get_state() const {
        return this->_state ;
    }

void Pin::_set_state(const int& value){
        this->_state = value;
    }

string Pin::_get_pull()const {
        return "floating";
    }
void Pin::_set_pull(const string&  value){
        throw (format_str("Cannot change pull-up on pin %s" ,value));
    }
unsigned Pin::_get_frequency() const {
        return -1;
    }
 
void Pin::_set_frequency(const unsigned& value){
        if (value != 0)
            throw ("PWM is not supported on pin ");
    }
unsigned Pin::_get_bounce()const {
        return 0;
    }
void Pin::_set_bounce(const unsigned& value){
        if (value != 0)
            throw("Edge detection is not supported on pin");

    /*
        doc="""\
        The amount of bounce detection (elimination) currently in use by edge
        detection, measured in seconds. If bounce detection is not currently in
        use, this is :data:`None`.

        For example, if :attr:`edges` is currently "rising", :attr:`bounce` is
        currently 5/1000 (5ms), then the waveform below will only fire
        :attr:`when_changed` on two occasions despite there being three rising
        edges:

        .. code-block:: text

            TIME 0...1...2...3...4...5...6...7...8...9...10..11..12 ms

            bounce elimination   |===================| |==============

            HIGH - - - - >       ,--. ,--------------. ,--.
                                 |  | |              | |  |
                                 |  | |              | |  |
            LOW  ----------------'  `-'              `-'  `-----------
                                 :                     :
                                 :                     :
                           when_changed          when_changed
                               fires                 fires

        If the pin does not support edge detection, attempts to set this
        property will raise :exc:`PinEdgeDetectUnsupported`. If the pin
        supports edge detection, the class must implement bounce detection,
        even if only in software.
        """)
    */
    }
string Pin::_get_edges() const {
        return "none";
    }
void Pin::_set_edges(const string& value){
        throw("Edge detection is not supported on pin " );
    }
    /*
    edges = property
               doc="""\
        The edge that will trigger execution of the function or bound method
        assigned to :attr:`when_changed`. This can be one of the strings
        "both" (the default), "rising", "falling", or "none":

        .. code-block:: text

            HIGH - - - - >           ,--------------.
                                     |              |
                                     |              |
            LOW  --------------------'              `--------------
                                     :              :
                                     :              :
            Fires when_changed     "both"         "both"
            when edges is ...     "rising"       "falling"

        If the pin does not support edge detection, attempts to set this
        property will raise :exc:`PinEdgeDetectUnsupported`.
        """)
    */
    
CBFunc_t  Pin::_get_when_changed() const {
        return nullptr;
    }

void Pin::_set_when_changed(const CBFunc_t & value){
        throw ("Edge detection is not supported on pin \n");
    }
    /*
        A function or bound method to be called when the pin's state changes
        (more specifically when the edge specified by :attr:`edges` is detected
        on the pin). The function or bound method must accept two parameters:
        the first will report the ticks (from :meth:`Factory.ticks`) when
        the pin's state changed, and the second will report the pin's current
        state.

        .. warning::

            Depending on hardware support, the state is *not guaranteed to be
            accurate*. For instance, many GPIO implementations will provide
            an interrupt indicating when a pin's state changed but not what it
            changed to. In this case the pin driver simply reads the pin's
            current state to supply this parameter, but the pin's state may
            have changed *since* the interrupt. Exercise appropriate caution
            when relying upon this parameter.

        If the pin does not support edge detection, attempts to set this
        property will raise :exc:`PinEdgeDetectUnsupported`.

        */



Factory::Factory(){
        /*
       private:
                map<int,string> reservations;
                uint32_t _ticks;
               
        这是pin工厂的抽象基类，用于为devices生成pins和SPI接口
        派生类必须重载下列方法：
        methods:

        * :meth:`ticks`
        * :meth:`ticks_diff`

        根据需要，派生类可以实现如下方法:

        * :meth:`close`
        * :meth:`reserve_pins`
        * :meth:`release_pins`
        * :meth:`release_all`
        * :meth:`pin`
        * :meth:`spi`
        * :meth:`_get_pi_info`
        """
    */

    this->reservations.clear();
    //this->res_lock =Lock();
}


void Factory::reserve_pins(const char * requester, initializer_list<int> pins){
    
         //map<int ,string> ::iterator iter;  //迭代器
    
        for (auto pin :pins ) {               //遍历可变参数
                map<int ,string> ::iterator iter = this->reservations.find(pin);  //引脚是否已经预留
                if(iter != reservations.end())        //如果已经被占用
                    throw ("pin is already in use by iter->second");
                else
                   this->reservations[pin] = requester;
        }
}

void Factory::show_reserved_pins(){
    
    for (map<int ,string>::iterator it = this->reservations.begin(); it != this->reservations.end(); ++it) 
        cout<<it->first<<":"<<it->second<<endl;
}

void Factory::release_pins(const char *  reserver, initializer_list<int> pins){
        /*"""
        Releases the reservation of *reserver* against *pins*.  This is
        typically called during :meth:`~gpiozero.Device.close` to clean up
        reservations taken during construction. Releasing a reservation that is
        not currently held will be silently ignored (to permit clean-up after
        failed / partial construction).
        """*/
        //with self._res_lock:
        //map<int ,string> ::iterator iter;  //迭代器
        for (auto pin :pins ) {
            map<int ,string> ::iterator iter = this->reservations.find(pin);  //引脚是否已经预留
            if(iter != this->reservations.end())
            {
                //delete iter->second
                this->reservations.erase(iter);
            }
        }

}
 void  Factory::release_all(const char * reserver){
     for(map<int ,string > ::iterator iter=this->reservations.begin();iter!=this->reservations.end();iter++)  
           {
              // printf("%d -> %s\n",iter->first,iter->second.c_str());
               // delete iter->second) ; //将来考虑要删除对象实例
           }     
 }

void Factory::close()
    {
        /*
        Closes the pin factory. This is expected to clean up all resources
        manipulated by the factory. It it typically called at script
        termination.
        */    
    }
        
Pin* Factory::pin(int spec){
        /*
        Creates an instance of a :class:`Pin` descendent representing the
        specified pin.

    *    .. warning::

            Descendents must ensure that pin instances representing the same
            hardware are identical; i.e. two separate invocations of
            :meth:`pin` for the same pin specification must return the same
            object.
        */
        throw("Individual pins are not supported by this pin factory");
        return NULL;
}

void  Factory::spi(char  **spi_args){
    /*
        Returns an instance of an :class:`SPI` interface, for the specified SPI
        *port* and *device*, or for the specified pins (*clock_pin*,
        *mosi_pin*, *miso_pin*, and *select_pin*).  Only one of the schemes can
        be used; attempting to mix *port* and *device* with pin numbers will
        raise :exc:`SPIBadArgs`.
        """*/
        throw("SPI not supported by this pin factory");
}
        
uint32_t  Factory::ticks(){
    /*       """
        Return the current ticks, according to the factory. The reference point
        is undefined and thus the result of this method is only meaningful when
        compared to another value returned by this method.

        The format of the time is also arbitrary, as is whether the time wraps
        after a certain duration. Ticks should only be compared using the
        :meth:`ticks_diff` method.
        """
        */
        throw("NotImplementedError");
}
 uint32_t  Factory::ticks_diff(uint32_t later, uint32_t earlier){
        /*
        Return the time in seconds between two :meth:`ticks` results. The
        arguments are specified in the same order as they would be in the
        formula *later* - *earlier* but the result is guaranteed to be in
        seconds, and to be positive even if the ticks "wrapped" between calls
        to :meth:`ticks`.
        */
       throw("NotImplementedError");
 }



 piBoardInfo_t   Factory::get_pi_info(){
        /*
        doc="""\
        Returns a :class:`PiBoardInfo` instance representing the Pi that
        instances generated by this factory will be attached to.

        If the pins represented by this class are not *directly* attached to a
        Pi (e.g. the pin is attached to a board attached to the Pi, or the pins
        are not on a Pi at all), this may return :data:`None`.
        """)
        */
        piBoardInfo_t piBoardInfo;
        
        return piBoardInfo;
    }


/*
class SPI
{
   /*
    SPI的抽象接口实现
    派生类必须重载下列方法:

    * :meth:`transfer`
    * :meth:`_get_clock_mode`

    派生类可以选择重载下列方法:

    * :meth:`read`
    * :meth:`write`
    * :meth:`_set_clock_mode`
    * :meth:`_get_lsb_first`
    * :meth:`_set_lsb_first`
    * :meth:`_get_select_high`
    * :meth:`_set_select_high`
    * :meth:`_get_bits_per_word`
    * :meth:`_set_bits_per_word`
    * 

};
*/
    
/*
    def read(self, n):
        """
        Read *n* words of data from the SPI interface, returning them as a
        sequence of unsigned ints, each no larger than the configured
        :attr:`bits_per_word` of the interface.

        This method is typically used with read-only devices that feature
        half-duplex communication. See :meth:`transfer` for full duplex
        communication.
        """
        return self.transfer([0] * n)

    def write(self, data):
        """
        Write *data* to the SPI interface. *data* must be a sequence of
        unsigned integer words each of which will fit within the configured
        :attr:`bits_per_word` of the interface. The method returns the number
        of words written to the interface (which may be less than or equal to
        the length of *data*).

        This method is typically used with write-only devices that feature
        half-duplex communication. See :meth:`transfer` for full duplex
        communication.
        """
        return len(self.transfer(data))

    def transfer(self, data):
        """
        Write *data* to the SPI interface. *data* must be a sequence of
        unsigned integer words each of which will fit within the configured
        :attr:`bits_per_word` of the interface. The method returns the sequence
        of words read from the interface while writing occurred (full duplex
        communication).

        The length of the sequence returned dictates the number of words of
        *data* written to the interface. Each word in the returned sequence
        will be an unsigned integer no larger than the configured
        :attr:`bits_per_word` of the interface.
        """
        raise NotImplementedError

    @property
    def clock_polarity(self):
        """
        The polarity of the SPI clock pin. If this is :data:`False` (the
        default), the clock pin will idle low, and pulse high. Setting this to
        :data:`True` will cause the clock pin to idle high, and pulse low. On
        many data sheets this is documented as the CPOL value.

        The following diagram illustrates the waveform when
        :attr:`clock_polarity` is :data:`False` (the default), equivalent to
        CPOL 0:

        .. code-block:: text

                   on      on      on      on      on      on      on
                  ,---.   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.
            CLK   |   |   |   |   |   |   |   |   |   |   |   |   |   |
                  |   |   |   |   |   |   |   |   |   |   |   |   |   |
            ------'   `---'   `---'   `---'   `---'   `---'   `---'   `------
            idle       off     off     off     off     off     off       idle

        The following diagram illustrates the waveform when
        :attr:`clock_polarity` is :data:`True`, equivalent to CPOL 1:

        .. code-block:: text

            idle       off     off     off     off     off     off       idle
            ------.   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.   ,------
                  |   |   |   |   |   |   |   |   |   |   |   |   |   |
            CLK   |   |   |   |   |   |   |   |   |   |   |   |   |   |
                  `---'   `---'   `---'   `---'   `---'   `---'   `---'
                   on      on      on      on      on      on      on
        """
        return bool(self.clock_mode & 2)

    @clock_polarity.setter
    def clock_polarity(self, value):
        self.clock_mode = self.clock_mode & (~2) | (bool(value) << 1)

    @property
    def clock_phase(self):
        """
        The phase of the SPI clock pin. If this is :data:`False` (the default),
        data will be read from the MISO pin when the clock pin activates.
        Setting this to :data:`True` will cause data to be read from the MISO
        pin when the clock pin deactivates. On many data sheets this is
        documented as the CPHA value. Whether the clock edge is rising or
        falling when the clock is considered activated is controlled by the
        :attr:`clock_polarity` attribute (corresponding to CPOL).

        The following diagram indicates when data is read when
        :attr:`clock_polarity` is :data:`False`, and :attr:`clock_phase` is
        :data:`False` (the default), equivalent to CPHA 0:

        .. code-block:: text

                ,---.   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.
            CLK |   |   |   |   |   |   |   |   |   |   |   |   |   |
                |   |   |   |   |   |   |   |   |   |   |   |   |   |
            ----'   `---'   `---'   `---'   `---'   `---'   `---'   `-------
                :       :       :       :       :       :       :
            MISO---.   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.
              /     \\ /     \\ /     \\ /     \\ /     \\ /     \\ /     \\
            -{  Bit  X  Bit  X  Bit  X  Bit  X  Bit  X  Bit  X  Bit  }------
              \\     / \\     / \\     / \\     / \\     / \\     / \\     /
               `---'   `---'   `---'   `---'   `---'   `---'   `---'

        The following diagram indicates when data is read when
        :attr:`clock_polarity` is :data:`False`, but :attr:`clock_phase` is
        :data:`True`, equivalent to CPHA 1:

        .. code-block:: text

                ,---.   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.
            CLK |   |   |   |   |   |   |   |   |   |   |   |   |   |
                |   |   |   |   |   |   |   |   |   |   |   |   |   |
            ----'   `---'   `---'   `---'   `---'   `---'   `---'   `-------
                    :       :       :       :       :       :       :
            MISO   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.
                  /     \\ /     \\ /     \\ /     \\ /     \\ /     \\ /     \\
            -----{  Bit  X  Bit  X  Bit  X  Bit  X  Bit  X  Bit  X  Bit  }--
                  \\     / \\     / \\     / \\     / \\     / \\     / \\     /
                   `---'   `---'   `---'   `---'   `---'   `---'   `---'
        """
        return bool(self.clock_mode & 1)

    @clock_phase.setter
    def clock_phase(self, value):
        self.clock_mode = self.clock_mode & (~1) | bool(value)

    def _get_clock_mode(self):
        raise NotImplementedError

    def _set_clock_mode(self, value):
        raise SPIFixedClockMode("clock_mode cannot be changed on %r" % self)

    clock_mode = property(
        lambda self: self._get_clock_mode(),
        lambda self, value: self._set_clock_mode(value),
        doc="""\
        Presents a value representing the :attr:`clock_polarity` and
        :attr:`clock_phase` attributes combined according to the following
        table:

        +------+-----------------+--------------+
        | mode | polarity (CPOL) | phase (CPHA) |
        +======+=================+==============+
        | 0    | False           | False        |
        +------+-----------------+--------------+
        | 1    | False           | True         |
        +------+-----------------+--------------+
        | 2    | True            | False        |
        +------+-----------------+--------------+
        | 3    | True            | True         |
        +------+-----------------+--------------+

        Adjusting this value adjusts both the :attr:`clock_polarity` and
        :attr:`clock_phase` attributes simultaneously.
        """)

    def _get_lsb_first(self):
        return False

    def _set_lsb_first(self, value):
        raise SPIFixedBitOrder("lsb_first cannot be changed on %r" % self)

    lsb_first = property(
        lambda self: self._get_lsb_first(),
        lambda self, value: self._set_lsb_first(value),
        doc="""\
        Controls whether words are read and written LSB in (Least Significant
        Bit first) order. The default is :data:`False` indicating that words
        are read and written in MSB (Most Significant Bit first) order.
        Effectively, this controls the `Bit endianness`_ of the connection.

        The following diagram shows the a word containing the number 5 (binary
        0101) transmitted on MISO with :attr:`bits_per_word` set to 4, and
        :attr:`clock_mode` set to 0, when :attr:`lsb_first` is :data:`False`
        (the default):

        .. code-block:: text

                ,---.   ,---.   ,---.   ,---.
            CLK |   |   |   |   |   |   |   |
                |   |   |   |   |   |   |   |
            ----'   `---'   `---'   `---'   `-----
                :     ,-------. :     ,-------.
            MISO:     | :     | :     | :     |
                :     | :     | :     | :     |
            ----------' :     `-------' :     `----
                :       :       :       :
               MSB                     LSB

        And now with :attr:`lsb_first` set to :data:`True` (and all other
        parameters the same):

        .. code-block:: text

                ,---.   ,---.   ,---.   ,---.
            CLK |   |   |   |   |   |   |   |
                |   |   |   |   |   |   |   |
            ----'   `---'   `---'   `---'   `-----
              ,-------. :     ,-------. :
            MISO:     | :     | :     | :
              | :     | :     | :     | :
            --' :     `-------' :     `-----------
                :       :       :       :
               LSB                     MSB

        .. _Bit endianness: https://en.wikipedia.org/wiki/Endianness#Bit_endianness
        """)

    def _get_select_high(self):
        return False

    def _set_select_high(self, value):
        raise SPIFixedSelect("select_high cannot be changed on %r" % self)

    select_high = property(
        lambda self: self._get_select_high(),
        lambda self, value: self._set_select_high(value),
        doc="""\
        If :data:`False` (the default), the chip select line is considered
        active when it is pulled low. When set to :data:`True`, the chip select
        line is considered active when it is driven high.

        The following diagram shows the waveform of the chip select line, and
        the clock when :attr:`clock_polarity` is :data:`False`, and
        :attr:`select_high` is :data:`False` (the default):

        .. code-block:: text

            ---.                                                     ,------
            __ |                                                     |
            CS |      chip is selected, and will react to clock      |  idle
               `-----------------------------------------------------'

                ,---.   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.
            CLK |   |   |   |   |   |   |   |   |   |   |   |   |   |
                |   |   |   |   |   |   |   |   |   |   |   |   |   |
            ----'   `---'   `---'   `---'   `---'   `---'   `---'   `-------

        And when :attr:`select_high` is :data:`True`:

        .. code-block:: text

               ,-----------------------------------------------------.
            CS |      chip is selected, and will react to clock      |  idle
               |                                                     |
            ---'                                                     `------

                ,---.   ,---.   ,---.   ,---.   ,---.   ,---.   ,---.
            CLK |   |   |   |   |   |   |   |   |   |   |   |   |   |
                |   |   |   |   |   |   |   |   |   |   |   |   |   |
            ----'   `---'   `---'   `---'   `---'   `---'   `---'   `-------
        """)

    def _get_bits_per_word(self):
        return 8

    def _set_bits_per_word(self, value):
        raise SPIFixedWordSize("bits_per_word cannot be changed on %r" % self)

    bits_per_word = property(
        lambda self: self._get_bits_per_word(),
        lambda self, value: self._set_bits_per_word(value),
        doc="""\
        Controls the number of bits that make up a word, and thus where the
        word boundaries appear in the data stream, and the maximum value of a
        word. Defaults to 8 meaning that words are effectively bytes.

        Several implementations do not support non-byte-sized words.
        """)
*/