#pragma once

double calc_gross(double e_w, double fuel_w, double baggage_w, double front_tot, double rear_tot);

double calc_cg(double e_w, double e_m, double occ_m, double rear_occ_m, double fuel_w,
	double fuel_m, double baggage_w, double baggage_m, double front_tot, double rear_tot);

void Q1();