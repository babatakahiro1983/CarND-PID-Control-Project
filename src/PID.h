#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  double p_error_throttle;
  double i_error_throttle;
  double d_error_throttle;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;


  double Kp_throttle;
  double Ki_throttle;
  double Kd_throttle;

  /*
  * 
  */
  double prev_cte;
  bool is_initialized;

  double prev_speed_error;
  bool is_initialized_throttle;


  int num;
  double error_sum;
  double error_eval;
  double best_error;
  std::vector<double>dp;
  std::vector<double>p;
  int tune_para_num;
  bool flg;

  double target_speed;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  void Init_throttle(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  void UpdateError_throttle(double speed_error);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  *
  */
  void CalcTargetSpeed(double cte);

};

#endif /* PID_H */
