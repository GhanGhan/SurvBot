/*
 * PID.h
 *
 *  Created on: Apr 14, 2024
 *      Author: Ghani
 */

#ifndef INC_PID_H_
#define INC_PID_H_

typedef struct PIDController{
	//Gains
	double Kp; //Proportional gain
	double Ki; //Integral gain
	double Kd; //Derivative gain

	//Error information
	double current_error;
	double sum_error;
	double previous_error;

	//Input and Output Signals
	double  set_point;
	int control;

	double time_delay;
	int max, min;


} PIDController;

void initializePID(PIDController *pid, double Kp, double Ki, double Kd, double delay, int max, int min);

int calcControl(double input);




#endif /* INC_PID_H_ */
