#pragma once
#include <string>
#include <array>
#include "destinations.h"
using namespace std;


class Plane {
	double pos, vel, distance;
	bool at_SCE;
	string origin;
	string destination;
	destinations dest_map;
public:
	Plane();
	Plane(string to, string from);
	~Plane();
	void operate(double dt);
	double get_pos();
	double get_distance();
	bool get_at_SCE();
	void set_vel(double vel);
	double get_vel();
};