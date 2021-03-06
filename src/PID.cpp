#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
	i_error = 0;
	is_initialized = false;

}

void PID::Init_throttle(double Kp, double Ki, double Kd) {

	PID::Kp_throttle = Kp;
	PID::Ki_throttle = Ki;
	PID::Kd_throttle = Kd;
	i_error_throttle = 0;
	is_initialized_throttle = false;

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

void PID::UpdateError_throttle(double speed_error) {

	if (is_initialized_throttle == false) {

		prev_speed_error = speed_error;
		is_initialized_throttle = true;
	}

	p_error_throttle = speed_error;
	i_error_throttle += speed_error;
	d_error_throttle = speed_error - prev_speed_error;

	prev_speed_error = speed_error;

}


double PID::TotalError() {

	double total_error;

	total_error = - Kp * p_error - Kd * d_error - Ki * i_error;

	return total_error;
}


void PID::CalcTargetSpeed(double cte) {


	if (std::fabs(cte) > 1) {

		target_speed = 10;
	}
	else if (std::fabs(cte) > 0.5){
		target_speed = 20;
	}else{
		target_speed = 30;
	}
}