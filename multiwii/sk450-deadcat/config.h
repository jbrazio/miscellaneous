/*
 *
 *   Author : João Brázio <joao@brazio.org>
 *  Version : 20140815
 *  License : GPLv3
 *
 * Platform : Multiwii (http://www.multiwii.com/)
 *  Version : 2.3, r1691
 *
 *    Frame : Hobbyking SK450 Dead Cat
 *       FC : Hobbyking Multiwii PRO (Red)
 *
 * =======
 *
 * Description
 * Configuration file for the Hobbyking Multwii PRO flight controller red board on Multiwii 2.3 or r1691.
 *
 * Features
 * - Custom motor mix for the Dead Cat confguration
 * - PPMSum input at A8
 * - RSSI meter at A13
 * - Ammeter sensor at A14
 * - Volmeter sensor at A15
 * - NEO 6m GPS using UBLOX protocol
 * - Optimized for SimonK ESC and D2830-11 1000Kv motors
 *
 */
#ifndef CONFIG_H_
#define CONFIG_H_


// NO FLY MODES
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#define ESC_CALIB_CANNOT_FLY													// This firmware will allow multiple ESC calibration
//#define DYNBALANCE															// This firmware will allow dynamic calibration of the motors/props


// BASIC SETUP AND MODEL CHARACTERISTICS
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define QUADX																	// Build Multiwii for SK450
#define FFIMUv2																	// Hobbyking's Multiwii PRO board
#define PID_CONTROLLER					1										// Use 2 for the unsupported experimental algorithm from Alex Khoroshko
//#define THROTTLE_ANGLE_CORRECTION		40										// Automatically increase throttle based on the angle of the copter


// CUSTOM MIX FOR SK450 DEAD CAT
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define MY_PRIVATE_MIXING "sk450dc.h"


// PIN OVERRIDE
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define OVERRIDE_V_BATPIN				A15										// instead of A3
#define OVERRIDE_PSENSORPIN				A14										// instead of A2


// GYRO/ACC SETUP
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define GYROCALIBRATIONFAILSAFE													// Gyro calibration will be repeated if model is moved
#define INFLIGHT_ACC_CALIBRATION												// In flight accelerometer calibration


// LOW PASS FILTER (ITG3200, ITG3205)
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#define ITG3200_LPF_256HZ														// Default filter value for ITG3200 or ITG3205
#define ITG3200_LPF_188HZ


// SERIAL PORT SETUP
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define SERIAL0_COM_SPEED				115200									// Hardware serial port 0 baud rate
#define SERIAL1_COM_SPEED				115200									// Hardware serial port 1 baud rate
#define SERIAL2_COM_SPEED				115200									// Hardware serial port 2 baud rate
#define SERIAL3_COM_SPEED				115200									// Hardware serial port 3 baud rate


// ESC SETUP AND CALIBRATION
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define MINCOMMAND						1000									// ESC minimal PWM value for initialization
#define MINTHROTTLE						1209									// ESC idle PWM value (default: 1150)
#define MAXTHROTTLE						1950									// ESC full power PWM value (default: 1850)
#define ESC_CALIB_LOW					MINCOMMAND								// Minimum ESC power value
#define ESC_CALIB_HIGH					2000									// Maximum ESC power value


// ARMING OPTIONS
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define ONLYARMWHENFLAT															// Prevent the copter from arming when the copter is tilted
//#define ALLOW_ARM_DISARM_VIA_TX_YAW												// Allow disarming the FC with the yaw stick
//#define ALLOW_ARM_DISARM_VIA_TX_ROLL											// Allow disarming the FC with the roll stick

//#define SAFER_ARM_DISARM_VIA_TX													// Increase arming security by requiring a two stick combination.
//#define SAFER_ARM_DISARM_VIA_TX_TIMEOUT 5 										// Number of seconds to disarm if thr is kept at it's minimum.
//#define ONLY_ALLOW_ARM_WITH_GPS_3DFIX											// Only allow FC arming if we have more than 5 satellites in view.


// RSSI, BATTERY AND POWER METER
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define RX_RSSI
#define RX_RSSI_PIN						A13
#define RSSI_SMOOTH						16										// Averaging vector length for smoothing the RSSI readings, should be power of 2; set to 1 to disable.

#define VBAT																	// Activate battery monitoring using A3
#define VBATSCALE						37										// Battery value adjustment
#define VBATNOMINAL						126										// 12,6V full battery nominal voltage
#define VBATLEVEL_WARN1					107										// 10,7V
#define VBATLEVEL_WARN2					99										// 9.9V
#define VBATLEVEL_CRIT					93										// 9.3V is critical, continuous beep
#define NO_VBAT							16										// Avoid beeping without any battery
#define VBAT_SMOOTH						16										// Averaging vector length for smoothing the VBAT readings, should be power of 2; set to 1 to disable.

#define POWERMETER_HARD															// Activate power consumption meter
#define PSENSORNULL						0										// Adjust the 0A power consumption of the sensor
#define PINT2mA							75										// Calculate with 4.9 / [Sensor value per mV] * 1000
#define PSENSOR_SMOOTH					16										// Averaging vector length for smoothing the PSENSOR readings, should be power of 2; set to 1 to disable.


// GPS SETUP
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define UBLOX																	// U-Blox binary protocol
#define AP_MODE							40										// Create a dead span to allow position adjustment in GPS_HOLD_MODE
#define GPS_SERIAL						3										// Hardware serial port used for the GPS receiver
#define GPS_BAUD						38400										// Baud rate used for GPS, recommended value is 57600 with only 0.8% error margin
#define GPS_LED_INDICATOR														// Blink LED once for each fixed satellite, starting at one blink for 5 satellites
#define MAG_DECLINATION					-2.8666f								// Search on http://magnetic-declination.com/ and use the formula: (degree + minutes * (1/60))
#define GPS_LEAD_FILTER 														// Forward predictive filter to compensate for GPS lag
//#define GPS_FILTERING															// Filters GPS noise but increases lag.


// RC SETUP
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define PPM_ON_THROTTLE															// Use the throttle input instead of D2
#define SERIAL_SUM_PPM					PITCH,YAW,THROTTLE,ROLL,AUX1,AUX2,AUX3,AUX4,8,9,10,11	// AUX1: Gear, AUX2: Flap, AUX3: Knob
#define DEADBAND 						6										// Uses a deadband for yaw, roll and pitch around stick center
#define MIDRC							1500									// Radio neutral point adjustment


// FAILSAFE SETUP
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#define FAILSAFE																// Activate the fail safe
#define FAILSAFE_DETECT_TRESHOLD		985										// FIXME:
#define FAILSAFE_DELAY					10										// Time out before entering fail safe after TX signal is lost (1 step = 0.1sec)
#define FAILSAFE_OFF_DELAY				200										// Landing time before stopping the motors (1 step = 0.1sec)
#define FAILSAFE_THROTTLE				(MINTHROTTLE + 200)						// Throttle power required for safe landing, it should be relative to MINTHROTTLE


// ALTITUDE HOLD MODE SETUP
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define ALT_HOLD_THROTTLE_NEUTRAL_ZONE	50										// Dead band for throttle's stick during altitude hold, default value is 50
//#define ALT_HOLD_THROTTLE_MIDPOINT	1500									// PWM value (in ms) for altitude hold position, ignoring the initialThrottleHold value


// HEADFREE MODE SETUP
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#define HEADFREE																// HEADFREE: Absolute stick orientation, ignores yaw position
//#define ADVANCED_HEADFREE														// ADVANCED HEADFREE
//#define ADV_HEADFREE_RANGE			15										// ADVANCED HEADFREE Range in meters where advanced headfree mode should be active


// NAVIGATION
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define GPS_WP_RADIUS					200										// Waypoint error radius in cm
#define NAV_SLEW_RATE					30										// Smooth navigation skew angles by using a rate control system
#define NAV_TAIL_FIRST					false									// Model comes in with tail first
#define NAV_CONTROLS_HEADING			true									// Model faces forward when navigating to a waypoint
#define NAV_SET_TAKEOFF_HEADING			true									// Model will face the take off heading when in home position


// MISCELLANEOUS STUFF
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define OSD_SWITCH																// Enables a switch to interact with MinimOSD
#define USE_MSP_WP																// Enables the MSP_WP command, which is used to display Home and Poshold positions
#define NO_FLASH_CHECK															// Do no reset constants when change of flashed program is detected
//#define DONT_RESET_HOME_AT_ARM												// To set home position use the GYRO calibration process


// FIXES AND HACKS
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define YAW_DIRECTION					1										// HACK: Obsolete but still a dependency to compile the source

#endif /* CONFIG_H_ */
