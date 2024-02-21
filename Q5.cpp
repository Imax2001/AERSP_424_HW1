#include<iostream>
#include "plane.h"
#include "Q5.h"
using namespace std;

void Q5() {
	Plane plane1("SCE", "PHL");
	plane1.set_vel(450); //mph
	double dt = 0.003; //~=10 seconds in hours
	for (int i = 0; i < 1000; i++) {
		plane1.operate(dt);
		cout << "Time: " << dt * i * 60 * 60 << " seconds    Position: " << plane1.get_pos() << " miles" << endl;
	}
}