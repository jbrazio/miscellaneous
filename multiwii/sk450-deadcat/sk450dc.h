/*
 *
 *   Author : João Brázio <joao@brazio.org>
 *  Version : 20140815
 *  License : GPLv3
 *
 *    Frame : Hobbyking SK450 Dead Cat
 *
 * =======
 *
 * Description
 * Motor mix file for the Hobbyking SK450 Dead Cat quadcopter frame.
 * Based on the work of Hayden Thring at http://goo.gl/ojv7Eb
 *
 */

motor[0] = PIDMIX( -1   , +1.08, -1    ); // REAR_R
motor[1] = PIDMIX( -1.31, -0.56, +1.31 ); // FRONT_R
motor[2] = PIDMIX( +1   , +1.08, +1    ); // REAR_L
motor[3] = PIDMIX( +1.31, -0.56, -1.31 ); // FRONT_L
