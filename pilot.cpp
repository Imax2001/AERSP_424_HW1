#include "pilot.h"
#include<iostream>
using namespace std;


pilot::pilot(string name) {
	this->name = name;
	cout << "Pilot's name: " << this->name << "    Memory address: " << this << endl;
	cout << this->name << " is ready to board the plane!" << endl;
}

pilot::~pilot() {
	cout << this->name << " is out of the plane." << endl;
}

string pilot::get_name() { return this->name; }

void enter_plane(Plane*) {

}

void enter_plane(unique_ptr<Plane>) {

}



