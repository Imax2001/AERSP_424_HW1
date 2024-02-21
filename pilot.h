#pragma once
#include <iostream>
#include<string>
#include<memory>
#include"plane.h"
using namespace std;

class pilot {
	string name;
public:
	pilot(string);
	~pilot();
	string get_name();
	Plane* myPlane;
	unique_ptr<Plane> myPlaneModern;
};