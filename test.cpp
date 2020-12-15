#include <stdio.h>
#include <cstring>
#include <list>
#include <map>
#include <string> 
#include <initializer_list>
#include <pigpiod_if2.h>
#include <iostream>
#include "data.hpp"

using namespace std;



/*
        gcc -Wall -pthread -o RED test_RED.c RED.c -lpigpiod_if2
*/

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


int main(int argc, char* argv[]){
        pi_info();
       //list_test();
       // dict_test();

  
    return 0;
}