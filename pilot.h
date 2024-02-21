#pragma once
#include <iostream>
#include<string>
#include"plane.h"
using namespace std;

class pilot {
	string name;
public:
	Plane* myPlane;
	pilot(string);
	~pilot();
	string get_name();
};