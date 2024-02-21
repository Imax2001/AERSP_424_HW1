#pragma once
#include<map>
#include<string>
using namespace std;

class destinations {
	map <string, int> dests{ {"PHL", 160}, {"ORD", 640}, {"EWR",220} };
public:
	int get_dist(string airport) { return this->dests[airport]; }
	destinations() {};
	~destinations() {};
};