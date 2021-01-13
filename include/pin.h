#ifndef PIN_H
#define PIN_H
#include <string> 
#include <map>
#include <pigpiod_if2.h>
#include "data.hpp"
#include "Property.h"

using namespace std;
  class Pin
    {
        private:
               
            virtual string      _get_function() const;
            virtual void        _set_function(const string& value);
            virtual int         _get_state() const;
            virtual void        _set_state(const int& value);
            virtual string      _get_pull() const;
            virtual void        _set_pull(const string& value);
            virtual unsigned    _get_frequency() const;
            virtual void        _set_frequency(const unsigned& value);
            virtual unsigned    _get_bounce() const;
            virtual void        _set_bounce(const unsigned& value);
            virtual string      _get_edges() const;
            virtual void        _set_edges(const string&  value);
            virtual CBFunc_t    _get_when_changed() const;
            virtual void        _set_when_changed(const CBFunc_t& value);

        protected:
            string      _function ; //引脚功能
            int         _state;     //引脚状态
            string      _pull;      //上拉双胎
            unsigned    _bounce;    //边界出发范围 
            string      _edges;     //边沿检测 
            CBFunc_t   _when_changed;


        public:
            Pin();
            virtual ~Pin(){};
            void close();
            int output_with_state(int state);
            int input_with_pull(string pull);
            Property<string> function;
            Property<int> state;
            Property<string> pull;
            Property<unsigned> frequency;
            Property<unsigned> bounce;
            Property<string> edges;
            Property<CBFunc_t> when_changed;

    };

    class Factory{
  
       private:
                map<int,string> reservations;
                uint32_t _ticks;
               
        //这是pin工厂的抽象基类，用于为devices生成pins和SPI接口
       // 派生类必须重载下列方法：
       // methods:
        public:
        Factory();
        uint32_t ticks();
        uint32_t ticks_diff(uint32_t later, uint32_t earlier);

        //根据需要，派生类可以实现如下方法:

        void close();
        void reserve_pins(const char * requester, initializer_list<int> pins);
        void release_pins(const char *  reserver, initializer_list<int> pins);
        void release_all(const char * reserver);
        void show_reserved_pins();

        Pin* pin(int spec);
        void  spi(char  **spi_args);
        piBoardInfo_t  get_pi_info();
    };
#endif