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

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * 
  */
  double prev_cte;
  bool is_initialized;


  int num;
  double error_sum;
  double error_eval;
  double best_error;
  std::vector<double>dp;
  std::vector<double>p;
  int tune_para_num;
  bool flg;

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

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * 
  */
  void Twiddle(double cte, double Kp, double Ki, double Kd);

  /*
  *
  */
   double ErrorEvaluation(double cte, int num, double error_sum);
};

#endif /* PID_H */
