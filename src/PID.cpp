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

	Kp = 0.005;
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
	Kp = 0.001;
	Ki = 3.0;
	Kd = 0.004;

	total_error = - Kp * p_error - Kd * d_error - Ki * i_error;

	return total_error;
}

double PID::ErrorEvaluation(double cte, int num, double error_sum) {

	double error_eval;
		
	error_sum += error_sum + cte * cte;
	num += 1;

	if (num > 0) {
		error_eval = error_sum / num;
	}

	return error_eval;

}


void PID::Twiddle(double cte, double Kp, double Ki, double Kd) {

	double tol = 0.2;
	vector<double>p = {0, 0, 0};
	vector<double>dp = {1, 1, 1};
	//robot = make_robot();
	//x_trajectory, y_trajectory, best_err = run(robot, p);

	//best_err = cte;
	
	//int it = 0;
		
	//while (accumulate(dp.begin(), dp.end(), 0) > tol) {
	//	cout << "Iteration: " << it << "best error: " << best_err << endl;

	//	for (int i = 0; i < 3; i++) {
	//		p[i] += dp[i];
			//robot = make_robot();
			//x_trajectory, y_trajectory, err = run(robot, p);
			
	//		if (err < best_err) {
	//			best_err = err;
	//			dp[i] *= 1.1;
	//		}
	//		else {
	//			p[i] -= 2 * dp[i];
				//robot = make_robot();
				//x_trajectory, y_trajectory, err = run(robot, p);
				
	//			if (err < best_err) {
	//				best_err = err;
	//				dp[i] *= 1.1;
	//			}
	//			else {
	//				p[i] += dp[i];
	//				dp[i] *= 0.9;
	//			}
	//		}
	//	}
	//	it += 1;
	//}

//	Kp = p[0];
//	Ki = p[1];
//	Kd = p[1];
//
//	return p, best_err;
}
