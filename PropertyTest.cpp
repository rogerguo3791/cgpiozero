#include "Property.h"
#include "PropertyTest.h"
#include <string>
#include <iostream>
using namespace std;
class Test {
        public:
	// Auto generate getters and setters
	Property<int> SimpleIntProp;
	Property<string> SimpleStrProp;

	// Getters and setters will be set in the constructor
	Property<int> IntProp;
	Property<string> StrProp;

	// Read-only properties, getters will be set in the constructor
	Property<int> ReadOnlyIntProp;
	Property<string> ReadOnlyStrProp;

       // IntProp = Property<int>::of(this, &Test::v, &Test::setV);
        
	Test() :
		m_v(-1) {
		// Retranslate getter and setters calls to methods of this object
		IntProp = Property<int>::of(this, &Test::v, &Test::setV);
		StrProp = Property<string>::of(this, &Test::str, &Test::setStr);
                //IntProp.getter = v;
		// Set const getter from lambda
		//ReadOnlyIntProp = Property<int>::readOnlyOf([](const int& field) {
			//Q_UNUSED(field)
		//	return 42;
	//	});

		// Set const getter from value
		//ReadOnlyStrProp = Property<string>::readOnlyOf("Hello World!");

	
	}
        

        private:
	int v() const {
		cout << "getter"<<endl;
		return m_v;
	}
	void setV(const int& v) {
		cout<< "setter"<<endl;
		m_v = v;
	}

	string str() const {
		cout<< "getter str"<<endl;
		return m_str;
	}

	void setStr(const string& str) {
		cout<< "setter str"<<endl;
		m_str = str;
	}


	int m_v;
	string m_str;
};

void PropertyTest() {
  
       	
    Test t;
	t.SimpleIntProp = 10;
	t.IntProp = 20;
	t.SimpleStrProp = "Hello";
	t.StrProp = "World!";
//	t.ReadOnlyIntProp = 30; // cases exception
//	t.ReadOnlyStrProp = "Goodbye World!"; // cases exception
//	t.ReadOnlyStringsProp = {"Hello", "World!"}; // cases exception
//	t.ReadOnlyIntsProp = {1, 2, 3}; // cases exception

	int a = t.SimpleIntProp;
	int b = t.IntProp;
	string c = t.SimpleStrProp;
	string d = t.StrProp;
	int e = t.ReadOnlyIntProp;
	string f = t.ReadOnlyStrProp;


	cout<< a << b << c << d << e << f<<endl ;

};

/* thread test  */
struct thread_data{
   int  thread_id;
   char *message;
};