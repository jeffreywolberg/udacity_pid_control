/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {
	for (int i = 0; i < 3; i++){
    	pid_errors[i] = 0;  
    }
    
  	delta_time = 1;
}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
    * Initialize PID coefficients (and errors, if needed)
    */
  
  pid_coeffs[0] = Kpi;
  pid_coeffs[1] = Kii;
  pid_coeffs[2] = Kdi;
  output_lim_max = output_lim_maxi;
  output_lim_min = output_lim_mini;
}


void PID::UpdateError(double cte) {
   /**
    * Update PID errors based on cte.
    */
  	if (delta_time > 0) {
		pid_errors[2] = (cte - pid_errors[0]) / delta_time;
    }
    else {
    	pid_errors[2] = 0;
    }
    pid_errors[1] += cte * delta_time;
    pid_errors[0] = cte;
}

double PID::TotalError() {
   /**
    * Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
    */
  
    double control = 0.0;
  	for (int i = 0; i < 3; i++){
    	control -= pid_coeffs[i] * pid_errors[i];
    }
  	control = max(output_lim_min, control);
    control = min(output_lim_max, control);
  
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
    * Update the delta time with new value
    */
	delta_time = new_delta_time;
  	return delta_time;
}