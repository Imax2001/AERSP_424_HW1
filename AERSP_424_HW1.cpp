#include <iostream>
#include <vector>
using namespace std;

void Q1() 
{
	// define relevant variables
	// w -> weight; m -> moment arm
	double e_w, e_m, occ_m, rear_occ_m, fuel, fuel_w, fuel_m, baggage_w, baggage_m;
	int occ_num, rear_occ_num;
	vector<double> occ_w, rear_occ_w;

	// Collect necessary info from user
	cout << "Please enter the airplane empty weight in pounds:   ";
	cin >> e_w;
	cout << endl;

	cout << "Please enter the moment of the plane's empty weight in pound-inches:   ";
	cin >> e_m;
	cout << endl;

	cout << "Please enter the number of front seat passengers:   ";
	cin >> occ_num;
	cout << endl;

	double pass_w;
	double front_tot = 0;
	for (int i = 1; i <= occ_num; i++)
	{
		cout << "Please enter the weight of passenger " << i << " in pounds:   ";
		cin >> pass_w;
		cout << endl;
		occ_w.push_back(pass_w);
		front_tot += pass_w;
	}

	cout << "Please enter the front seat moment arm in inches:   ";
	cin >> occ_m;
	cout << endl;
	
	cout << "Please enter the number of rear passengers:   ";
	cin >> rear_occ_num;
	cout << endl;

	double rear_tot = 0;
	for (int i = 1; i <= rear_occ_num; i++)
	{
		cout << "Please enter the weight of passenger " << i << " in pounds:   ";
		cin >> pass_w;
		cout << endl;
		rear_occ_w.push_back(pass_w);
		rear_tot += pass_w;
	}
	

	cout << "Please enter the rear seat moment arm in inches:   ";
	cin >> rear_occ_m;
	cout << endl;
	
	cout << "Please enter the number of gallons of useable fuel:  ";
	cin >> fuel;
	cout << endl;

	cout << "Please enter the weight of fuel in pounds:   ";
	cin >> fuel_w;
	cout << endl;

	cout << "Please enter the fuel moment arm in inches:   ";
	cin >> fuel_m;
	cout << endl;

	cout << "Please enter the baggage weight in pounds:   ";
	cin >> baggage_w;
	cout << endl;

	cout << "Please enter the baggage moment arm in inches:   ";
	cin >> baggage_m;
	cout << endl;


	// Check gross weight and C.G. limits
	double gross_weight = e_w + front_tot + rear_tot + fuel_w + baggage_w;
	if (gross_weight > 2950)
		cout << "You have exceeded the maximum weight for this airplane!" << endl;
	else
		cout << "You are within the design limits for gross weight." << endl;


}

int main() {
	Q1();

	return 0;
}