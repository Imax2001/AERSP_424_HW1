#include "Q8.h"
#include<iostream>
#include "pilot.h"
#include "plane.h"
#include<memory>
using namespace std;

void Q8() {
	cout << "================= Question 8 =================" << endl;

	//create the plane
	Plane ourPlane("SCE", "PHL");
	//create the pilots and "put them in the plane"
	pilot mainPilot("Jane");
	mainPilot.myPlaneModern.reset(&ourPlane);
	pilot coPilot("John");
	coPilot.myPlaneModern.reset(nullptr);
	cout << mainPilot.get_name() << " is in control of " << mainPilot.myPlaneModern << endl;
	cout << coPilot.get_name() << " is in control of " << coPilot.myPlaneModern << endl;
	
	ourPlane.set_vel(450); //mph
	double dt = 0.003; //~=10 seconds in hours
	for (int i = 0; i < 1000; i++) {
		ourPlane.operate(dt);
		cout << "Time: " << dt * i * 60 * 60 << " seconds    Position: " << ourPlane.get_pos() << " miles" << endl;
		if (ourPlane.get_at_SCE() == 1) {
			mainPilot.myPlaneModern.swap(coPilot.myPlaneModern);
			cout << mainPilot.get_name() << " is in control of " << mainPilot.myPlaneModern << endl;
			cout << coPilot.get_name() << " is in control of " << coPilot.myPlaneModern << endl;
		}
	}
	coPilot.myPlaneModern.release();
	mainPilot.myPlaneModern.release();


	cout << "================= End Question 8 =================" << endl << endl;
	
}
