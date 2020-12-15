#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include "data.hpp"
#include  <stdarg.h>
using namespace std;

/**
 * 格式化字符串
 * 
 * \param pszFmt 格式描述
 * \param ... 不定参数
 * \return 格式化的结果字符串
 */
string format(const char *pszFmt, ...)
{
    std::string str;
    va_list args;
    va_start(args, pszFmt);
    {
        int nLength = vsnprintf(NULL,0,pszFmt, args);
        nLength += 1;  //上面返回的长度是包含\0，这里加上
        std::vector<char> chars(nLength);
        vsnprintf(chars.data(), nLength, pszFmt, args);
        str.assign(chars.data());
    }
    va_end(args);
    return str;
}

revision_t REV1_P1{
              // pin  func   pullup    pin   func    pullup
                {1,  {V3_3,   false}},{2,   {V5,     false}},
                {3,  {GPIO0,   true}},{4,   {V5,     false}},
                {5,  {GPIO1,   true}},{6,   {GND,    false}},
                {7,  {GPIO4,  false}},{8,   {GPIO14, false}},
                {9,  {GND,    false}},{10,  {GPIO15, false}},
                {11, {GPIO17, false}},{12,  {GPIO18, false}},
                {13, {GPIO21, false}},{14,  {GND,    false}},
                {15, {GPIO22, false}},{16,  {GPIO23, false}},
                {17, {V3_3,   false}},{18,  {GPIO24, false}},
                {19, {GPIO10, false}},{20,  {GND,    false}},
                {21, {GPIO9,  false}},{22,  {GPIO25, false}},
                {23, {GPIO11, false}},{24,  {GPIO8,  false}},
                {25, {GND,    false}},{26,  {GPIO7,  false}}        
        };
revision_t REV2_P1{
              // pin  func   pullup    pin   func    pullup
                {1,  {V3_3,   false}},{2,   {V5,     false}},
                {3,  {GPIO2,   true}},{4,   {V5,     false}},
                {5,  {GPIO3,   true}},{6,   {GND,    false}},
                {7,  {GPIO4,  false}},{8,   {GPIO14, false}},
                {9,  {GND,    false}},{10,  {GPIO15, false}},
                {11, {GPIO17, false}},{12,  {GPIO18, false}},
                {13, {GPIO27, false}},{14,  {GND,    false}},
                {15, {GPIO22, false}},{16,  {GPIO23, false}},
                {17, {V3_3,   false}},{18,  {GPIO24, false}},
                {19, {GPIO10, false}},{20,  {GND,    false}},
                {21, {GPIO9,  false}},{22,  {GPIO25, false}},
                {23, {GPIO11, false}},{24,  {GPIO8,  false}},
                {25, {GND,    false}},{26,  {GPIO7,  false}}        
        };
revision_t REV2_P5{
              // pin  func   pullup    pin   func    pullup
                {1,  {V5   ,  false}},{2,  {V3_3,  false}},
                {3,  {GPIO28,  true}},{4,  {GPIO29,false}},
                {5,  {GPIO30,  true}},{6,  {GPIO31,false}},
                {7,  {GND,    false}},{8,  {GND,   false}}     
        };
revision_t PLUS_J8{
              // pin  func   pullup    pin   func    pullup
                {1,  {V3_3,   false}},{2,   {V5,     false}},
                {3,  {GPIO2,   true}},{4,   {V5,     false}},
                {5,  {GPIO3,   true}},{6,   {GND,    false}},
                {7,  {GPIO4,  false}},{8,   {GPIO14, false}},
                {9,  {GND,    false}},{10,  {GPIO15, false}},
                {11, {GPIO17, false}},{12,  {GPIO18, false}},
                {13, {GPIO27, false}},{14,  {GND,    false}},
                {15, {GPIO22, false}},{16,  {GPIO23, false}},
                {17, {V3_3,   false}},{18,  {GPIO24, false}},
                {19, {GPIO10, false}},{20,  {GND,    false}},
                {21, {GPIO9,  false}},{22,  {GPIO25, false}},
                {23, {GPIO11, false}},{24,  {GPIO8,  false}},
                {25, {GND,    false}},{26,  {GPIO7,  false}},
                {27, {GPIO0,  false}},{28,  {GPIO1,  false}},
                {29, {GPIO5,  false}},{30,  {GND,    false}},
                {31, {GPIO6,  false}},{32,  {GPIO12, false}},
                {33, {GPIO13, false}},{34,  {GND,    false}},
                {35, {GPIO19, false}},{36,  {GPIO16, false}},
                {37, {GPIO26, false}},{38,  {GPIO20, false}},
                {39, {GND,    false}},{40,  {GPIO21, false}},

        };



piBoardInfo_t from_revision(uint32_t revision){
     
        piBoardInfo_t PiBoardInfo; 
        if (revision & 0x800000) {
           
           uint32_t revcode_memory       = (revision & 0x700000) >> 20;
           uint32_t revcode_manufacturer = (revision & 0xf0000)  >> 16;
           uint32_t revcode_processor    = (revision & 0xf000)   >> 12;
           uint32_t revcode_type         = (revision & 0xff0)    >> 4;
           uint32_t revcode_revision     = (revision & 0x0f);
           
           switch (revcode_type)
           {
                case 0:
                    PiBoardInfo.model ="A";
                    break;
                case 1:
                    PiBoardInfo.model ="B";
                    break;
                case 2:
                    PiBoardInfo.model ="A+";
                    break;
                case 3:
                    PiBoardInfo.model ="B+";
                    break;
                case 4:
                    PiBoardInfo.model ="2B";
                    break;
                case 6:
                    PiBoardInfo.model ="CM";
                    break;
                case 8:
                    PiBoardInfo.model ="3B";
                    break;
                case 9:
                    PiBoardInfo.model ="Zero";
                    break;
                case 10:
                    PiBoardInfo.model ="CM3";
                    break;
                case 12:
                    PiBoardInfo.model ="Zero M";
                    break;
                case 13:
                    PiBoardInfo.model ="3B+";
                    break;
                case 14:
                    PiBoardInfo.model ="3A+";
                    break;
                case 16:
                    PiBoardInfo.model ="CM3+";
                    break;
                case 17:
                    PiBoardInfo.model ="4B";
                    break;
                default:
                    PiBoardInfo.model ="???";
                    break;
           }
            if (PiBoardInfo.model.find("A") || PiBoardInfo.model.find("B"))
                switch (revcode_revision)
                {
                    case 0:
                        PiBoardInfo.pcb_revision ="1.0";
                        break;
                    case 1:
                        PiBoardInfo.pcb_revision ="1.0";
                        break;
                    case 2:
                        PiBoardInfo.pcb_revision ="2.0";
                        break;
                    default:
                        PiBoardInfo.pcb_revision ="Unknown";
                        break;
                }        
            else
                PiBoardInfo.pcb_revision ="1.%d" , revcode_revision;
            switch (revcode_processor)
            {
                case 0:
                    PiBoardInfo.soc ="BCM2835";
                    break;
                case 1:
                    PiBoardInfo.soc ="BCM2836";
                    break;
                case 2:
                    PiBoardInfo.soc ="BCM2837";
                    break;
                case 3:
                    PiBoardInfo.soc ="BCM2711";
                    break;
                default:
                    PiBoardInfo.soc ="Unknown";
                    break;
            }
            switch (revcode_manufacturer)
            {
                case 0:
                    PiBoardInfo.manufacturer="Sony";
                    break;
                case 1:
                    PiBoardInfo.manufacturer="Egoman";
                    break;
                case 2:
                    PiBoardInfo.manufacturer="Embest";
                    break;
                case 3:
                    PiBoardInfo.manufacturer="Sony Japan";
                    break;
                case 4:
                    PiBoardInfo.manufacturer="Embest";
                    break;
                case 5:
                    PiBoardInfo.manufacturer="Stadium";
                    break;
                default:
                    PiBoardInfo.manufacturer="Unknown";
                    break;
            }
            switch (revcode_memory)
            {
                case 0:
                    PiBoardInfo.memory = 256;
                    break;
                case 1:
                    PiBoardInfo.memory = 512;
                    break;
                case 2:
                    PiBoardInfo.memory = 1024;
                    break;
                case 3:
                    PiBoardInfo.memory = 2048;
                    break;
                case 4:
                    PiBoardInfo.memory = 4096;
                    break;
                case 5:
                    PiBoardInfo.memory = 8192;
                    break;
                default:
                    PiBoardInfo.memory = 0;
                    break;
            }
            switch (revcode_type)
            {
                case 0:
                    PiBoardInfo.released = "2013Q1";
                    break;
                case 1:
                    PiBoardInfo.released = "2012Q1";
                    break;
                case 2:
                    PiBoardInfo.released = "2014Q4";
                    break;
                case 3:
                    PiBoardInfo.released = "2014Q3";
                    break;
                case 4:
                    PiBoardInfo.released = "2015Q1";
                    break;
                case 6:
                    PiBoardInfo.released = "2014Q2";
                    break;
                case 8:
                    PiBoardInfo.released = "2015Q4";
                    break;
                case 10:
                    PiBoardInfo.released = "2017Q1";
                    break;
                case 12:
                    PiBoardInfo.released = "2017Q1";
                    break;
                case 13:
                    PiBoardInfo.released = "2018Q1";
                    break;
                case 14:
                    PiBoardInfo.released = "2018Q4";
                    break;
                case 16:
                    PiBoardInfo.released = "2019Q1";
                    break;
                case 17:
                    PiBoardInfo.released = "2020Q2";
                    break;
                default:
                    PiBoardInfo.released = "???";
                    break;
            }
            switch (revcode_type)
            {
                case 0:
                    PiBoardInfo.storage ="SD";
                    break;
                case 1:
                    PiBoardInfo.storage ="SD";
                    break;
                case 6:
                    PiBoardInfo.storage ="eMMC";
                    break;
                case 10:
                    PiBoardInfo.storage ="eMMC / off-board";
                    break;
                case 16:
                    PiBoardInfo.storage ="eMMC / off-board";
                    break;
                default:
                     PiBoardInfo.storage ="MicroSD";
                    break;
            }
            PiBoardInfo.usb =4;
            PiBoardInfo.ethernet =1;
            PiBoardInfo.wifi =true;
            PiBoardInfo.bluetooth = true;
            PiBoardInfo.csi =1;
            PiBoardInfo.dsi =1;
            
            PiBoardInfo.revision=format("%04x",revision);
            switch (revcode_type)
            {
                case 0:
                    PiBoardInfo.headers.insert(make_pair("P1", REV2_P1));
                    PiBoardInfo.headers.insert(make_pair("P5", REV2_P1));
                    break;
                case 1:
                    PiBoardInfo.headers.insert(make_pair("P1", REV2_P1));
                    PiBoardInfo.headers.insert(make_pair("P5", REV2_P5));
                    break;
                default:
                    PiBoardInfo.headers.insert(make_pair("J8", PLUS_J8));
                    break;
            }
        }
        else
        {
            throw("unknown old-style revision %d", revision);
        }
        
        return PiBoardInfo;
}



/*
    def physical_pins(self, function):
        """
        Return the physical pins supporting the specified *function* as tuples
        of ``(header, pin_number)`` where *header* is a string specifying the
        header containing the *pin_number*. Note that the return value is a
        :class:`set` which is not indexable. Use :func:`physical_pin` if you
        are expecting a single return value.

        :param str function:
            The pin function you wish to search for. Usually this is something
            like "GPIO9" for Broadcom GPIO pin 9, or "GND" for all the pins
            connecting to electrical ground.
        """
        return {
            (header, pin.number)
            for (header, info) in self.headers.items()
            for pin in info.pins.values()
            if pin.function == function
            }

    def physical_pin(self, function):
        """
        Return the physical pin supporting the specified *function*. If no pins
        support the desired *function*, this function raises :exc:`PinNoPins`.
        If multiple pins support the desired *function*, :exc:`PinMultiplePins`
        will be raised (use :func:`physical_pins` if you expect multiple pins
        in the result, such as for electrical ground).

        :param str function:
            The pin function you wish to search for. Usually this is something
            like "GPIO9" for Broadcom GPIO pin 9.
        """
        result = self.physical_pins(function)
        if len(result) > 1:
            raise PinMultiplePins('multiple pins can be used for %s' % function)
        elif result:
            return result.pop()
        else:
            raise PinNoPins('no pins can be used for %s' % function)

    def pulled_up(self, function):
        """
        Returns a bool indicating whether a physical pull-up is attached to
        the pin supporting the specified *function*. Either :exc:`PinNoPins`
        or :exc:`PinMultiplePins` may be raised if the function is not
        associated with a single pin.

        :param str function:
            The pin function you wish to determine pull-up for. Usually this is
            something like "GPIO9" for Broadcom GPIO pin 9.
        """
        try:
            header, number = self.physical_pin(function)
        except PinNoPins:
            return False
        else:
            return self.headers[header].pins[number].pull_up

    def to_gpio(self, spec):
        """
        Parses a pin *spec*, returning the equivalent Broadcom GPIO port number
        or raising a :exc:`ValueError` exception if the spec does not represent
        a GPIO port.

        The *spec* may be given in any of the following forms:

        * An integer, which will be accepted as a GPIO number
        * 'GPIOn' where n is the GPIO number
        * 'WPIn' where n is the `wiringPi`_ pin number
        * 'BCMn' where n is the GPIO number (alias of GPIOn)
        * 'BOARDn' where n is the physical pin number on the main header
        * 'h:n' where h is the header name and n is the physical pin number
          (for example J8:5 is physical pin 5 on header J8, which is the main
          header on modern Raspberry Pis)

        .. _wiringPi: http://wiringpi.com/pins/
        """
        if isinstance(spec, int):
            if not 0 <= spec < 54:
                raise PinInvalidPin('invalid GPIO port %d specified '
                                    '(range 0..53) ' % spec)
            return spec
        else:
            if isinstance(spec, bytes):
                spec = spec.decode('ascii')
            spec = spec.upper()
            if spec.isdigit():
                return self.to_gpio(int(spec))
            if spec.startswith('GPIO') and spec[4:].isdigit():
                return self.to_gpio(int(spec[4:]))
            elif spec.startswith('BCM') and spec[3:].isdigit():
                return self.to_gpio(int(spec[3:]))
            elif spec.startswith('WPI') and spec[3:].isdigit():
                main_head = 'P1' if 'P1' in self.headers else 'J8'
                try:
                    return self.to_gpio({
                        0:  '%s:11' % main_head,
                        1:  '%s:12' % main_head,
                        2:  '%s:13' % main_head,
                        3:  '%s:15' % main_head,
                        4:  '%s:16' % main_head,
                        5:  '%s:18' % main_head,
                        6:  '%s:22' % main_head,
                        7:  '%s:7'  % main_head,
                        8:  '%s:3'  % main_head,
                        9:  '%s:5'  % main_head,
                        10: '%s:24' % main_head,
                        11: '%s:26' % main_head,
                        12: '%s:19' % main_head,
                        13: '%s:21' % main_head,
                        14: '%s:23' % main_head,
                        15: '%s:8'  % main_head,
                        16: '%s:10' % main_head,
                        17: 'P5:3',
                        18: 'P5:4',
                        19: 'P5:5',
                        20: 'P5:6',
                        21: '%s:29' % main_head,
                        22: '%s:31' % main_head,
                        23: '%s:33' % main_head,
                        24: '%s:35' % main_head,
                        25: '%s:37' % main_head,
                        26: '%s:32' % main_head,
                        27: '%s:36' % main_head,
                        28: '%s:38' % main_head,
                        29: '%s:40' % main_head,
                        30: '%s:27' % main_head,
                        31: '%s:28' % main_head,
                        }[int(spec[3:])])
                except KeyError:
                    raise PinInvalidPin('%s is not a valid wiringPi pin' % spec)
            elif ':' in spec:
                header, pin = spec.split(':', 1)
                if pin.isdigit():
                    try:
                        header = self.headers[header]
                    except KeyError:
                        raise PinInvalidPin(
                            'there is no %s header on this Pi' % header)
                    try:
                        function = header.pins[int(pin)].function
                    except KeyError:
                        raise PinInvalidPin(
                            'no such pin %s on header %s' % (pin, header.name))
                    if function.startswith('GPIO') and function[4:].isdigit():
                        return self.to_gpio(int(function[4:]))
                    else:
                        raise PinInvalidPin('%s is not a GPIO pin' % spec)
            elif spec.startswith('BOARD') and spec[5:].isdigit():
                main_head = ({'P1', 'J8', 'SODIMM'} & set(self.headers)).pop()
                return self.to_gpio('%s:%s' % (main_head, spec[5:]))
            raise PinInvalidPin('%s is not a valid pin spec' % spec)

    def __repr__(self):
        return '{cls}({fields})'.format(
            cls=self.__class__.__name__,
            fields=', '.join(
                (
                    '{name}=...' if name in ('headers', 'board') else
                    '{name}={value!r}').format(name=name, value=value)
                for name, value in zip(self._fields, self)
                )
            )

    def __format__(self, format_spec):
        style, content = Style.from_style_content(format_spec)
        if content == 'full':
            return dedent("""\
                {self:{style} board}

                {self:{style} specs}

                {self:{style} headers}"""
                ).format(self=self, style=style)
        elif content == 'board':
            kw = self._asdict()
            kw.update({
                name: header
                for name, header in self.headers.items()
                })
            return self.board.format(style=style, **kw)
        elif content == 'specs':
            specs = self._asdict()
            if specs['memory'] < 1024:
                specs['memory_unit'] = "MB"
            else:
                specs['memory'] /= 1024
                specs['memory_unit'] = "GB"
            return dedent("""\
                {style:bold}Revision           {style:reset}: {revision}
                {style:bold}SoC                {style:reset}: {soc}
                {style:bold}RAM                {style:reset}: {memory}{memory_unit}
                {style:bold}Storage            {style:reset}: {storage}
                {style:bold}USB ports          {style:reset}: {usb} {style:yellow}(excluding power){style:reset}
                {style:bold}Ethernet ports     {style:reset}: {ethernet}
                {style:bold}Wi-fi              {style:reset}: {wifi}
                {style:bold}Bluetooth          {style:reset}: {bluetooth}
                {style:bold}Camera ports (CSI) {style:reset}: {csi}
                {style:bold}Display ports (DSI){style:reset}: {dsi}"""
                ).format(style=style, **specs)
        elif content == 'headers':
            return '\n\n'.join(
                dedent("""\
                {style:bold}{header.name}{style:reset}:
                {header:{style} full}"""
                ).format(header=header, style=style)
                for header in sorted(self.headers.values(), key=attrgetter('name'))
                )

    def pprint(self, color=None):
        """
        Pretty-print a representation of the board along with header diagrams.

        If *color* is :data:`None` (the default), the diagram will include ANSI
        color codes if stdout is a color-capable terminal. Otherwise *color*
        can be set to :data:`True` or :data:`False` to force color or monochrome
        output.
        """
        print('{0:{style} full}'.format(self, style=Style(color)))

*/