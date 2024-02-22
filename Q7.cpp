#include "Q7.h"
#include<iostream>
#include "pilot.h"
#include "plane.h"
using namespace std;

void Q7() {
	cout << "================= Question 7 =================" << endl;
	
	//create the plane
	Plane ourPlane("SCE", "PHL");
	//create the pilots and "put them in the plane"
	pilot mainPilot("Jane");
	mainPilot.myPlane = &ourPlane;
	pilot coPilot("John");
	coPilot.myPlane = 0;
	cout << mainPilot.get_name() << " is in control of " << mainPilot.myPlane << endl;
	cout << coPilot.get_name() << " is in control of " << coPilot.myPlane << endl;

	ourPlane.set_vel(450); //mph
	double dt = 0.003; //~=10 seconds in hours
	for (int i = 0; i < 1000; i++) {
		ourPlane.operate(dt);
		cout << "Time: " << dt * i * 60 * 60 << " seconds    Position: " << ourPlane.get_pos() << " miles" << endl;
		if (ourPlane.get_at_SCE() == 1) {
			Plane* temp = mainPilot.myPlane;
			mainPilot.myPlane = coPilot.myPlane;
			coPilot.myPlane = temp;
			cout << mainPilot.get_name() << " is in control of " << mainPilot.myPlane << endl;
			cout << coPilot.get_name() << " is in control of " << coPilot.myPlane << endl;
		}
	}
	mainPilot.myPlane = 0; delete mainPilot.myPlane;
	coPilot.myPlane = 0;  delete coPilot.myPlane;

	cout << "================= End Question 7 =================" << endl << endl;
}