#include "pilot.h"
#include<iostream>
using namespace std;


pilot::pilot() {
	cout << "Pilot's name: " << this->name << "    Memory address: " << &this->name << endl;
	cout << this->name << " is ready to board the plane!" << endl;
}

pilot::~pilot() {
	cout << this->name << " is out of the plane." << endl;
}

string pilot::get_name() { return this->name; }



