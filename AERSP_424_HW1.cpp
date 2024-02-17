#include <iostream>
#include <vector>
using namespace std;

// Define a couple usefull functions for Q1
double calc_gross(double e_w, double fuel_w, double baggage_w, double front_tot, double rear_tot) {
	return e_w + front_tot + rear_tot + fuel_w + baggage_w;
}

double calc_cg(double e_w, double e_m, double occ_m, double rear_occ_m, double fuel_w,
	           double fuel_m, double baggage_w, double baggage_m, double front_tot, double rear_tot)
{
	double gross_weight = calc_gross(e_w, fuel_w, baggage_w, front_tot, rear_tot);
	double cg = (e_m + front_tot * occ_m + rear_tot * rear_occ_m + fuel_w * fuel_m + baggage_w * baggage_m) / gross_weight;
	return cg;
}

void Q1() 
{
	// define relevant variables
	// w -> weight; m -> moment arm
	double e_w, e_m, occ_m, rear_occ_m, fuel, fuel_w, fuel_w_pg, fuel_m, baggage_w, baggage_m;
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

	cout << "Please enter the weight of fuel in pounds per gallon:   ";
	cin >> fuel_w_pg;
	cout << endl;
	fuel_w = fuel_w_pg * fuel;

	cout << "Please enter the fuel moment arm in inches:   ";
	cin >> fuel_m;
	cout << endl;

	cout << "Please enter the baggage weight in pounds:   ";
	cin >> baggage_w;
	cout << endl;

	cout << "Please enter the baggage moment arm in inches:   ";
	cin >> baggage_m;
	cout << endl;


	// Check gross weight
	double gross_weight = calc_gross(e_w, fuel_w, baggage_w, front_tot, rear_tot);
	if (gross_weight > 2950) {
		cout << "You have exceeded the maximum weight for this airplane!" << endl;
		cout << "The maximum allowable weight is 2950 pounds and you have entered a total of " << gross_weight << " pounds." << endl;
	}
	else
		cout << "You are within the design limits for gross weight." << endl;

	// Check C.G. limits
	double cg = calc_cg(e_w, e_m, occ_m, rear_occ_m, fuel_w, fuel_m, baggage_w, baggage_m, front_tot, rear_tot);
	if (cg < 82.1 || cg > 84.7) {
		double fuel_diff = 0;
		cout << "The center of gravity is outside of the design limits." << endl;
		if (cg < 82.1) {
			while (cg < 82.1) {
				fuel_w -= 0.01;
				fuel_diff -= 0.01;
;				cg = calc_cg(e_w, e_m, occ_m, rear_occ_m, fuel_w, fuel_m, baggage_w, baggage_m, front_tot, rear_tot);
			}
			cout << "To meet requirements, drain " << -fuel_diff/fuel_w_pg << " gallons of fuel" << endl;
		}
		else {
			while (cg > 84.7) {
				fuel_w += 0.01;
				fuel_diff += 0.01;
				cg = calc_cg(e_w, e_m, occ_m, rear_occ_m, fuel_w, fuel_m, baggage_w, baggage_m, front_tot, rear_tot);
			}
			cout << "To meet requirements, add " << fuel_diff / fuel_w_pg << " gallons of fuel." << endl;
		}
		gross_weight = calc_gross(e_w, fuel_w, baggage_w, front_tot, rear_tot);
		cout << "The new gross weight is " << gross_weight << " lbs." << endl;
		cout << "The new center of gravity is " << cg << " inches." << endl;
	}

}

int main() {
	Q1();

	return 0;
}