#include "plane.h"
#include "destinations.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

Plane::Plane(string to, string from){
	this->origin = from;
	this->destination = to;
	this->vel = 0; this->pos = 0; this->at_SCE = 0;

	//pull from destination map to define 'distance' member
	if (to == "SCE") {
		this->distance = this->dest_map.get_dist(from);
	}
	else {
		this->distance = this->dest_map.get_dist(to);
	}
}

Plane::Plane() {}

Plane::~Plane() {
	cout << "Plane Destroyed." << endl;
}

void Plane::operate(double dt) {
	if (this->pos < this->distance) {
		this->pos += this->vel * dt;
		this->at_SCE = 0;
	}
	else {
		if (this->destination == "SCE") {
			this->at_SCE = 1;
		}
		string temp = this->destination;
		this->destination = this->origin;
		this->origin = temp;
		this->pos = 0;
	}
}
double Plane::get_pos() { return this->pos; }
double Plane::get_distance() { return this->distance; }
bool Plane::get_at_SCE() { return this->at_SCE; }
void Plane::set_vel(double vel) { this->vel = vel; }
double Plane::get_vel() { return this->vel; }