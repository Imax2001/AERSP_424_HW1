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
	mainPilot.myPlaneModern = make_unique<Plane>(&ourPlane);
	pilot coPilot("John");
	coPilot.myPlaneModern = make_unique<Plane>(0);
	cout << mainPilot.get_name() << " is in control of " << mainPilot.myPlane << endl;
	cout << coPilot.get_name() << " is in control of " << coPilot.myPlane << endl;

	ourPlane.set_vel(450); //mph
	double dt = 0.003; //~=10 seconds in hours
	for (int i = 0; i < 1000; i++) {
		ourPlane.operate(dt);
		cout << "Time: " << dt * i * 60 * 60 << " seconds    Position: " << ourPlane.get_pos() << " miles" << endl;
		if (ourPlane.get_at_SCE() == 1) {
			unique_ptr<Plane> temp = make_unique<Plane>(mainPilot.myPlaneModern.get());
			mainPilot.myPlaneModern = coPilot.myPlaneModern.get();
			coPilot.myPlaneModern = temp.get();
			cout << mainPilot.get_name() << " is in control of " << mainPilot.myPlane << endl;
			cout << coPilot.get_name() << " is in control of " << coPilot.myPlane << endl;
		}
	}
	mainPilot.myPlane = 0; delete mainPilot.myPlane;
	coPilot.myPlane = 0;  delete coPilot.myPlane;
}