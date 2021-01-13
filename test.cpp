#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <list>
#include <map>
#include <string> 
#include <assert.h>
#include <initializer_list>
#include <pigpiod_if2.h>
#include <iostream>
#include "data.hpp"

#include <functional>
#include <pthread.h>
#include "pigpio.hpp"
#include <signal.h>

#include "utilities.h"
#include "PropertyTest.h"
using namespace std;
//using property::Property;


/*
        gcc -Wall -pthread -o RED test_RED.c RED.c -lpigpiod_if2
*/
typedef void (*signalFunc_t) (int signum);

static void setSignalHandler(int signum, signalFunc_t sigHandler)
{
   struct sigaction New;

   memset(&New, 0, sizeof(New));
   New.sa_handler = sigHandler;

   sigaction(signum, &New, NULL);
}

void pi_info()
{
        unsigned led=24;
        int pi;
        uint32_t hardware_revision,gpio_version;
        unsigned if_version;
        char *optHost   = NULL;
        char *optPort   = NULL;
        piBoardInfo_t piBoardInfo; 
        typedef header_t::const_iterator headerIt;
        typedef revision_t::const_iterator  revisionIt;

        pi = pigpio_start(optHost, optPort); /* Connect to Pi. */
        if (pi >= 0)
        {
              hardware_revision =get_hardware_revision(pi);
              gpio_version =get_pigpio_version(pi);
              if_version = pigpiod_if_version();
              piBoardInfo =from_revision(hardware_revision);


              printf( "You are successfully connected to raspi.\n");  
              printf("Pi's hardware revision number is %d \n",hardware_revision);
              printf("gpio_version is %d \n",gpio_version);
              printf("if_version is %d \n",if_version);
              
              printf("model is %s\n",piBoardInfo.model.c_str());
              printf("revision is %s\n",piBoardInfo.revision.c_str());
              printf("memory is %i\n",piBoardInfo.memory);
              printf("soc is %s\n",piBoardInfo.soc.c_str());
              printf("released is %s\n",piBoardInfo.released.c_str());
              printf("manufacturer is %s\n",piBoardInfo.manufacturer.c_str());
              printf("usb is %d\n",piBoardInfo.usb);
              printf("wifi is %d\n",piBoardInfo.wifi);
              printf("bluetooth is %d\n",piBoardInfo.bluetooth);
              printf("csi is %d\n",piBoardInfo.csi);
              printf("dsi is %d\n",piBoardInfo.dsi);
              printf("storage is %s\n",piBoardInfo.storage.c_str());
              printf("storage is %d\n",piBoardInfo.ethernet);
      
              for (headerIt hit(piBoardInfo.headers.begin()); hit != piBoardInfo.headers.end(); ++hit)
                {
               // int i(it->first.first);
               // int j(it->first.second);
                  revision_t REV = hit->second;
                  std::cout <<hit->first <<"  "<< endl;
                  for (revisionIt it(REV.begin()); it != REV.end(); ++it)    
                    cout <<it->first <<"  "<<it->second.first<<" "<<it->second.second<< endl;
                }


              set_mode(pi,led,PI_OUTPUT);
              set_pull_up_down(pi,led,PI_PUD_UP);

                while (true)
                {
                        /* code */
                        gpio_write(pi,led,0);
                        time_sleep(0.5);
                        gpio_write(pi,led,1);  
                        time_sleep(0.5);  
                }
              pigpio_stop(pi);   
        }
        else
        {
                fprintf(stderr, "You are unable  connected to raspi.\n");  
        }
        
}

void list_test() {
            //创建空的 list 容器
    std::list<double> values;
    //向容器中添加元素
    values.push_back(3.1);
    values.push_back(2.2);
    values.push_back(2.9);
    cout << "values size：" << values.size() << endl;
    //对容器中的元素进行排序
    values.sort();
    //使用迭代器输出list容器中的元素
    for (std::list<double>::iterator it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << " ";
    }
    cout <<endl;     
}

void dict_test() {
        typedef map<int, pair<string , bool>> Dict;
        typedef Dict::const_iterator It;
        //REV1_P1[1]=make_pair(V3_3, false);REV1_P1[2]=make_pair(V5, false);
        Dict REV1_P1{
              // pin  func   pullup    pin   func    pullup
                {1,  {V3_3,   false}},{2,   {V5,     false}},
                {3,  {GPIO0,   true}},{4,   {V5,     false}},
                {5,  {GPIO1,   true}},{6,   {GND,    false}},
                {7,  {GPIO4,  false}},{8,   {GPIO14, false}},
                {9,  {GND,    false}},{8,   {GPIO15, false}},
                {11, {GPIO17, false}},{8,   {GPIO18, false}},
                {13, {GPIO21, false}},{8,   {GND,    false}},
                {15, {GPIO22, false}},{8,   {GPIO23, false}},
                {17, {V3_3,   false}},{8,   {GPIO24, false}},
                {19, {GPIO10, false}},{8,   {GND,    false}},
                {21, {GPIO9,  false}},{8,   {GPIO25, false}},
                {23, {GPIO11, false}},{8,   {GPIO8,  false}},
                {25, {GND,    false}},{8,   {GPIO7,  false}}        
        };
     
        for (It it(REV1_P1.begin()); it != REV1_P1.end(); ++it)
        {
               // int i(it->first.first);
               // int j(it->first.second);
                std::cout <<it->first <<"  "<<it->second.first<<" "<<it->second.second<< endl;
        }

}
map<int,string> reservations{{1,"dfd"},{2,"dfgg"}};


struct thread_data{
   int  thread_id;
   char *message;
};
 
 
void *PrintHello(void *threadarg)
{
   struct thread_data *my_data;
 
   my_data = (struct thread_data *) threadarg;
 
   cout << "Thread ID : " << my_data->thread_id ;
   cout << " Message : " << my_data->message << endl;

   pthread_exit(NULL);
}

void   threadtest()
{
     #define NUM_THREADS     5
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;
   int i;
 
   for( i=0; i < NUM_THREADS; i++ ){
      cout <<"main() : creating thread, " << i << endl;
      td[i].thread_id = i;
      td[i].message = (char*)"This is message";
      rc = pthread_create(&threads[i], NULL,
                          PrintHello, (void *)&td[i]);
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit;
      }
   }
   pthread_exit(NULL);   
}
 
void piclass_test(){
        PiGPIOFactory* fa = new PiGPIOFactory(NULL,NULL) ;
        PiGPIOPin* p;
        piBoardInfo_t piBoardInfo;
        cout<<fa->host()<<" : "<<fa->port()<<endl;
        cout<<"Current ticks:"<<fa->ticks()<<endl;
        piBoardInfo=fa->get_pi_info();
        cout<<"model is "<<piBoardInfo.model<<endl;
        cout<<"revision is "<<piBoardInfo.revision<<endl;
        cout<<"memory is "<<piBoardInfo.memory<<endl;
        cout<<"soc is "<<piBoardInfo.soc<<endl;
        cout<<"released is "<<piBoardInfo.released<<endl;
        cout<<"manufacturer "<<piBoardInfo.manufacturer<<endl;
        cout<<"usb is "<<piBoardInfo.usb<<endl;
        cout<<"wifi is "<<piBoardInfo.wifi<<endl;
        cout<<"bluetooth is "<<piBoardInfo.bluetooth<<endl;
        cout<<"csi is "<<piBoardInfo.csi<<endl;
        cout<<"dsi is "<<piBoardInfo.dsi<<endl;
        cout<<"storage is "<<piBoardInfo.storage<<endl;
        cout<<"ethernet is "<<piBoardInfo.ethernet<<endl;
/*  functional test */
       // functest();
       fa->reserve_pins( "test",{24,25,26});
       fa->show_reserved_pins();
       p=(PiGPIOPin*)fa->pin(24);
   
        cout<<"pi: "<<p->pi<<endl;
       cout<<"pin Number :"<<p->number()<<endl;
       

       cout<<"func:"<< (string)p->function  <<endl;

       cout<<"state: "<<p->state<<endl;

       p->function ="output";
       p->state =0 ;
       cout<<"pull:" <<(string)p->pull<<endl;
       cout<<"edges:" <<(string)p->edges<<endl;
        
       //fa->release_pins( "test",{24,25,26});
       // fa->show_reserved_pins();
        
       fa->close(); 
       
       delete fa;
}

class Func
    {
    public:
        int sum;
        Func()   {
            sum = 2;
        }
        void func2(int numa, int numb, int numc,std::string name) {
            std::cout << numa << " " << numb << " " << numc<<" " << name<< endl ;
        }
        void func4()  {
            std::cout << "func4" << endl;
        }
        void operator() (int a,int b)   {
            std::cout << "Operator:" << sum<<"  "<<a<<"  "<<b<<endl;
        }
        static void  func6(int numa, int numb, int numc)        {
            std::cout << numa << " " << numb << " " << numc << endl;
        }
        static void  func5()        {
            std::cout << "static func" << endl;
        }
    };


void func3()  {
         std::cout <<"func3"<< endl;
     }
void func1(int numa, int numb, int numc)     {
         std::cout << numa << " " << numb << " " << numc << endl;
     }

void callFunc(std::function<void(int a,int b)> call)  {
         call(1,2);
     }

void functest(){
        Func func;
        int sum = 10;
        int resultInt = 0;
        //全局或者静态函数
        std::cout << "全局或者静态函数" << endl;
        std::function<void()> testFunc = func3;
        testFunc();
        testFunc = Func::func5;
        testFunc();
        //类成员函数
        std::cout << "类成员函数" << endl;
        testFunc = std::bind(&Func::func2, func, 1, 2, 3, "name");
        testFunc();
        //Lambda表达式
        std::cout << "Lambda表达式" << endl;
        testFunc = [=, &resultInt](){std::cout << sum << endl; resultInt += 100; };
        testFunc();
        cout << "the reslutInt is " << resultInt << endl;
        //仿函数
        std::cout << "仿函数" << endl;
        std::function<void(int a, int b)> abFunc = func;
        abFunc(10, 20);
        std::cout << resultInt << std::endl;

       callFunc(std::bind(func1, std::placeholders::_1, std::placeholders::_2, 3));
       callFunc(std::bind(func1, std::placeholders::_2, std::placeholders::_1, 3));
       callFunc(std::bind(func1, std::placeholders::_2, 3, std::placeholders::_1));
       callFunc(std::bind(Func::func6, std::placeholders::_1, std::placeholders::_2, 3));
       callFunc(std::bind(&Func::func2, func, std::placeholders::_1, std::placeholders::_2, 3, "name"));
}
int main(int argc, char* argv[]){
        
      //pi_info();
       //list_test();
       // dict_test();
      
        
        //PropertyTest();
        //cout <<t.s<<"   "<<t.prop<<endl;
        //t.pt();
        //propertyTest t;
	//t.Num = 20;
	//cout << t.Num << endl;
	//t.Num = 100;
	//cout << t.Num << endl;
        // Basic usage, no override

        //threadtest();
        //piclass_test();
    //char* host = getenv("PIGPIO_ADDR");
    //char* port = getenv("PIGPIO_PORT");
    //cout <<host<<" : "<<port<<endl;
     piclass_test();

    return 0;
}