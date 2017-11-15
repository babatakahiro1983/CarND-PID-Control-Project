#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	Kp = 0.2
	Ki = 3.0;
	Kd = 0.004;
	i_error = 0;
	is_initialized = false;

}

void PID::UpdateError(double cte) {

	if (is_initialized == false) {

		prev_cte = cte;
		is_initialized = true;
	}

	p_error = cte;
	i_error += cte;
	d_error = cte - prev_cte;

	prev_cte = cte;

}

double PID::TotalError() {

	double total_error;
	Kp = 0.01; //0.2
	Ki = 3.0;
	Kd = 0.004;

	total_error = - Kp * p_error - Kd * d_error - Ki * i_error;

	return total_error;
}

