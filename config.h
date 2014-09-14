
#ifndef __config_h__
#define __config_h__

// IR Sensor Pin Definition
#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3

// Motor Direction Control Pin Definition
#define M1_OUT1 2
#define M1_OUT2 3
#define M2_OUT1 4
#define M2_OUT2 5

// Motor Enable (Speed) Pin Definition
#define EN1_CTL  9   // For M1
#define EN2_CTL  10  // For M2

// Speed values (PWM)
#define SPEED_VAL1 140     // PWM Value ( 0 - 255) 255 is highest speed and 0 is stop
#define SPEED_VAL2 140     // PWM Value ( 0 - 255) 255 is highest speed and 0 is stop

// Average level
#define SAMPLING_RATE 100 // Sensor sampling rate (Average value)

// IR Threshold values
#define IR1_THRESHOLD 200 // Lesser for black more for white
#define IR2_THRESHOLD 260
// Lesser for black more for white

// Delay
#define loop_delay 500 


#endif
