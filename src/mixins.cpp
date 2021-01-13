#include "mixins.hpp"

int ValuesMixin::values(){
    while (true)

            {
                try{
                    return this->value;//yield self.value
                }
                catch (...)
                { 
                    break;
                }
            }
}


