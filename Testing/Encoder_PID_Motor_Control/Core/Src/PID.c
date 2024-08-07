#include "PID.h"


void initializePID(PIDController *pid, double Kp, double Ki, double Kd, double delay, int max, int min){
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kd = Kd;

	pid->current_error = 0;
	pid->previous_error = 0;
	pid->sum_error = 0;

	pid->set_point = 0;
	pid->control = 0;

	pid->time_delay = delay;

	pid->max = max;
	pid->min = min;


}

int calcControl(PIDController *pid, double current_speed){


	pid->current_error = pid->set_point - current_speed;
	pid->sum_error += pid->current_error;

	pid->control = pid->Kp*pid->current_error + pid->Ki*pid->sum_error*pid->time_delay;
			//+ pid->Kd*(pid->current_error-pid->previous_error)/pid->time_delay;

	if(pid->control > pid->max)
		pid->control = pid->max;
	else if(pid->control < pid->min)
		pid->control = pid->min;

	pid->previous_error = pid->current_error;

	return pid->control;
}

void updateSetPoint(PIDController *pid, double input){
	pid->set_point = input;
	return;
}


