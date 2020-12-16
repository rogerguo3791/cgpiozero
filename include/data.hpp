#ifndef DATA_H
#define DATA_H

#include <map>
#include <string>

using namespace std;


#define V1_8       "1V8"
#define V3_3       "3V3"
#define V5         "5V"
#define GND        "GND"
#define NC         "NC" // not connected
#define GPIO0      "GPIO0"
#define GPIO1      "GPIO1"
#define GPIO2      "GPIO2"
#define GPIO3      "GPIO3 "
#define GPIO4      "GPIO4 "
#define GPIO5      "GPIO5 "
#define GPIO6      "GPIO6 "
#define GPIO7      "GPIO7 "
#define GPIO8      "GPIO8 "
#define GPIO9      "GPIO9 "
#define GPIO10     "GPIO10 "
#define GPIO11     "GPIO11 "
#define GPIO12     "GPIO12 "
#define GPIO13     "GPIO13 "
#define GPIO14     "GPIO14 "
#define GPIO15     "GPIO15 "
#define GPIO16     "GPIO16 "
#define GPIO17     "GPIO17 "
#define GPIO18     "GPIO18 "
#define GPIO19     "GPIO19 "
#define GPIO20     "GPIO20 "
#define GPIO21     "GPIO21 "
#define GPIO22     "GPIO22 "
#define GPIO23     "GPIO23 "
#define GPIO24     "GPIO24 "
#define GPIO25     "GPIO25 "
#define GPIO26     "GPIO26 "
#define GPIO27     "GPIO27 "
#define GPIO28     "GPIO28 "
#define GPIO29     "GPIO29 "
#define GPIO30     "GPIO30 "
#define GPIO31     "GPIO31 "
#define GPIO32     "GPIO32 "
#define GPIO33     "GPIO33 "
#define GPIO34     "GPIO34 "
#define GPIO35     "GPIO35 "
#define GPIO36     "GPIO36 "
#define GPIO37     "GPIO37 "
#define GPIO38     "GPIO38 "
#define GPIO39     "GPIO39 "
#define GPIO40     "GPIO40 "
#define GPIO41     "GPIO41 "
#define GPIO42     "GPIO42 "
#define GPIO43     "GPIO43 "
#define GPIO44     "GPIO44 "
#define GPIO45     "GPIO45 "

typedef map<int, pair<string , bool>> revision_t;
      //REV1_P1[1]=make_pair(V3_3, false);REV1_P1[2]=make_pair(V5, false);
typedef map<string,revision_t> header_t;
struct piBoardInfo_t
{
   string  revision;
   string  model;
   string  pcb_revision;
   string  released;
   string  soc;
   string  manufacturer;
   int     memory;
   string  storage;
   int     usb;
   int     ethernet;
   bool    wifi;
   bool    bluetooth;
   int     csi;
   int     dsi;
   header_t headers;
    
};

piBoardInfo_t from_revision(uint32_t revision);
#endif