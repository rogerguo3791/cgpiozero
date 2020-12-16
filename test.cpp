#include <stdio.h>
#include <cstring>
#include <list>
#include <map>
#include <string> 
#include <assert.h>
#include <initializer_list>
#include <pigpiod_if2.h>
#include <iostream>
#include "data.hpp"
#include "utilities.hpp"
#include <functional>
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

//template <typename Container, typename ValueType, int nPropType>
/*
class property
{
        public:
                property(){  
                 m_cObject = NULL;       
                       Set = NULL;
                       Get = NULL;
                }
 
        //-- This to set a pointer to the class that contain the
        //   property --
 
        void setContainer(Container* cObject){
                m_cObject = cObject;
        }
 
        //-- Set the set member function that will change the value --
        void setter(void (Container::*pSet)(ValueType value)){
                if((nPropType == WRITE_ONLY) || (nPropType == READ_WRITE))
                        Set = pSet;
                else
                        Set = NULL;
        }
 
                //-- Set the get member function that will retrieve the value --
        void getter(ValueType (Container::*pGet)()){
                if((nPropType == READ_ONLY) || (nPropType == READ_WRITE))
                        Get = pGet;
                else
                        Get = NULL;
        }
 
        //-- Overload the '=' sign to set the value using the set
        //   member --
 
        ValueType operator =(const ValueType& value){
                assert(m_cObject != NULL);
                assert(Set != NULL);
                (m_cObject->*Set)(value);
                return value;
        }
 
        //-- To make possible to cast the property class to the
        //   internal type --
 
        operator ValueType(){
                assert(m_cObject != NULL);
                assert(Get != NULL);
                return (m_cObject->*Get)();
        }
        private:
        Container* m_cObject;  //-- Pointer to the module that
                                //   contains the property --
        void (Container::*Set)(ValueType value);
                                //-- Pointer to set member function --
        ValueType (Container::*Get)();
                                //-- Pointer to get member function --
 };

 class PropTest{
         public:
 
        PropTest(){
                Count.setContainer(this);
                Count.setter(&PropTest::setCount); 
                Count.getter(&PropTest::getCount);
        }
   int getCount()  {
     return m_nCount;
   }
 
  void setCount(int nCount){
     m_nCount = nCount;
   }
   property<PropTest,int,READ_WRITE> Count;
        private:
             int m_nCount;
};


class propertyTest {
        private:
                int num;
                void set(int k) {
                        num = k;
                }
                int get() {
                        return num;
                }
        public:
                Property<int> Num;
                propertyTest():
                        Num(bind(&propertyTest::set, this, std::placeholders::_1), bind(&propertyTest::get, this)),num(0)
                {
                }
};
*/


class Test {
        public:
        Property<char *> s;    // int prop;
        Property<int> prop;
        void pt(){
                prop =12;
                
            cout<<s<<":"<<prop<<endl;    
        }
        
        };

int main(int argc, char* argv[]){
       // pi_info();
       //list_test();
       // dict_test();
       Test t;
        t.s="testd";
        t.prop = 1;
  
        cout <<t.s<<"   "<<t.prop<<endl;
        t.pt();
        //propertyTest t;
	//t.Num = 20;
	//cout << t.Num << endl;
	//t.Num = 100;
	//cout << t.Num << endl;
        // Basic usage, no override
        

    return 0;
}