#include <iostream>
#include <numeric>
#include <vector>

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


void PID::Twiddle(double cte, double Kp, double Ki, double Kd) {

	//double tol = 0.2;
	//vector<double>p = {0, 0, 0};
	//vector<double>dp = {1, 1, 1};
	//robot = make_robot();
	//x_trajectory, y_trajectory, best_err = run(robot, p);

	//best_err = cte;
	
	//int it = 0;
		
	//while (accumulate(dp.begin(), dp.end(), 0) > tol) {
	//	cout << "Iteration: " << it << "best error: " << best_err << endl;

	//	for (int i = 0; i < 3; i++) {
	//		p[i] = p[i] + dp[i];
	//		robot = make_robot();
	//		x_trajectory, y_trajectory, err = run(robot, p);
			
	//		if (err < best_err) {
	//			best_err = err;
	//			dp[i] = dp[i] * 1.1;
	//		}
	//		else {
	//			p[i] = p[i] - 2 * dp[i];
	//			robot = make_robot();
	//			x_trajectory, y_trajectory, err = run(robot, p);
	//			
	//			if (err < best_err) {
	//				best_err = err;
	//				dp[i] = dp[i] * 1.1;
	//			}
	//			else {
	//				p[i] = p[i] + dp[i];
	//				dp[i] = dp[i] * 0.9;
	//			}
	//		}
	//	}
	//	it += 1;
	//}

	//Kp = p[0];
	//Ki = p[1];
	//Kd = p[1];

	//return p, best_err;
}


void PID::CalcTargetSpeed(double cte) {


	if (fabs(cte) < 10) {

		target_speed = 30;
	}
	else {
		target_speed = 10;
	}

}