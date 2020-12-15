#ifndef PIN_H
#define PIN_H

#include <map>
#include <cstring>
#include <pigpio.h>
using namespace std;

    /* 定义功能有效值 */  
    #define INPUT       0
    #define OUTPUT      1
    
    /*定义状态有效值 */
    #define FLOAT       2
    /*定义bounce有效值 */
    #define None        0
    /*定义edges  */
    #define none        0
    #define rising      1
    #define falling     2
    #define both        3
    
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
            unsigned  get_when_changed();
            void set_when_changed(eventFunc_t value);
    };

    class Factory
        {
            private:
                map<int,string> reservations;
                uint32_t _ticks;
               
            public:
                Factory();
                void reserve_pins(char *requester, initializer_list<int> pins);
                void release_pins( char *reserver, initializer_list<int> pins);
                void release_all(char *reserver);
                void close();
                Pin  pin(int spec);
                void spi(char **spi_args);
                uint32_t  ticks();
                uint32_t  ticks_diff(uint32_t later, uint32_t earlier);
                int  get_pi_info();
        };
#endif