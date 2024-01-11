# TwoArmClock


Project Layout:

Firmware Programming:
    Two Arm Clock uses two timers, interrupts, and IO to send PWM signals
  while keeping track of time change requests from user. One timer is 
  configured to keep track of seconds and the other to send a 50Hz signal
  with a varying duty cycle under 10% to three servos. Two interrupts are 
  configured to watch for user time change requests and to increment 
  time. The servos are attached to two, 5 inch, arms which will be responsible
  for drawing the current time. 

Algorithm Programming:
    The program will keep track of a coordinate system. Degrees of the arms needed
  to achieve the (x, y) request will be calculated using the following formulas:
  
            Degrees of Arm = 2 * asin((sqrt((x^2 + y^2)))/(2 * (length of arm)))
            Degrees of Base = 180 - (atan(y/x) + acos(sidei/ 2 * (length of arm)))

  The degrees calculated will be mapped to the range of the duty cycle and sent to
  the servos. Images in the folder "Planning" will explain the formula process and
  will show general flow charts of the program.


  More Details Pending...
