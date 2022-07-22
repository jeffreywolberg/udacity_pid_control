# Project Writeup

The screenshots of the graphs show the steering, throttle, and brake errors per iteration. The ideal errors are 0, and most of the errors are located around it. The errors can be lessened with better parameter tuning of the PID controller.

The PID controller tells each command (break, steer, and throttle) how to reach the desired state given the current state in a smooth fashion. It minimizes the error in each iteration.

You can use twiddle to help tune the parameters to an optima. 

The pros of a model free controller is that it is more generalizable to other tasks, because it is not specific to the car. However, this generalizability must come at the cost of not being able to specifically tailor the controller to a car, which would make it better for self-driving