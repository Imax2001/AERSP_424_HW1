#pragma once
#include<string>
#include"plane.h"
using namespace std;

class pilot {
	string name;
public:
	pilot();
	~pilot();
	string get_name();
	Plane* myPlane;
};