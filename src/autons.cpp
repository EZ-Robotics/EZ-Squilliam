#include "main.h"

const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

///
// Constants
///

// Reset all constants to default (what's in setup.hpp is default)
void
reset_constants() {
  reset_slew_min_power();
  reset_slew_distance();
  reset_fw_drive_constants();
  reset_bw_drive_constants();
  reset_turn_constants();
  reset_turn_i_constants();
  reset_swing_constants();
}

// Functions to change constants
// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.
/*
void
one_mogo_constants() {
  set_slew_min_power(80, 80);
  set_slew_distance(7, 7);
  set_fw_drive_constants(0.45, 5);
  set_bw_drive_constants(0.375, 4);
  set_turn_constants(5, 0.003, 35);
  set_turn_i_constants(15, 30);
  set_swing_constants(12, 35);
}

void
two_mogo_constants() {
  set_slew_min_power(80, 80);
  set_slew_distance(7, 7);
  set_fw_drive_constants(0.45, 5);
  set_bw_drive_constants(0.375, 4);
  set_turn_constants(5, 0.003, 35);
  set_turn_i_constants(15, 30);
  set_swing_constants(12, 35);
}
*/



void double_steal() {

  // Drive towards center goal
  claw_up();
  set_drive_pid(drive, 45, 127);
  lift_down(true);
  // Slow down when close to center
  wait_until(35);
  set_max_speed(40);
  wait_drive();

  // Grab goal
  claw_down();

  // Drive back with goal
  set_drive_pid(drive, -36, 127, true);
  // Release goal during drive back
  wait_until(-14);
  set_max_speed(DRIVE_SPEED);
  claw_up();
  wait_drive();

  // Turn to face center goal
  set_drive_pid(turn, -35, TURN_SPEED);
  wait_drive();

  // Drive towards center goal
  set_drive_pid(drive, 49, 127);
  lift_down(true);
  wait_until(44);
  set_max_speed(40);
  wait_drive();

  // Grab goal
  claw_down();

  // Drive back with goal
  set_drive_pid(drive, -36, 70, true);
  // Release goal during drive back
  wait_until(-27);
  set_max_speed(DRIVE_SPEED);
  claw_up();
  wait_drive();

  // Turn to face alliance goal
  set_drive_pid(turn, -90, TURN_SPEED);
  mogo_mid(true);
  wait_drive();

  // Drive into goal
  set_drive_pid(drive, -19, 80, true);
  wait_drive();

  // Drive goal lift
  mogo_down(true);
  set_drive_pid(turn, -35, TURN_SPEED);
  wait_drive();

  // Drive into first neutral
  set_drive_pid(drive, 10, 80);
  wait_drive();

  // Grab goal
  claw_down();

  // Turn to corner
  set_drive_pid(turn, -210, TURN_SPEED);
  lift_lil_down(true);
  wait_drive();

  // Drive into corner
  set_drive_pid(drive, 10, DRIVE_SPEED);
  wait_drive();

  // Release goal
  claw_up();

  // Drive away
  set_drive_pid(drive, -5, DRIVE_SPEED);
  wait_drive();

  // Turn to face opponents side
  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

}



void test_double_steal() {

  // Drive towards center goal
  claw_up();
  set_drive_pid(drive, 45, 127);
  lift_down(true);
  // Slow down when close to center
  wait_until(35);
  set_max_speed(40);
  wait_drive();

  // Grab goal
  claw_down();

  // Drive back with goal
  set_drive_pid(drive, -36, 127, true);
  // Release goal during drive back
  wait_until(-14);
  set_max_speed(DRIVE_SPEED);
  claw_up();
  wait_drive();

  // Turn to face center goal
  set_drive_pid(turn, -35, TURN_SPEED);
  wait_drive();

  // Drive towards center goal
  set_drive_pid(drive, 51, 127);
  lift_down(true);
  wait_until(40);
  set_max_speed(40);
  wait_drive();

  // Grab goal
  claw_down();

  // Drive back with goal
  set_drive_pid(drive, -38, 127, true);
  // Release goal during drive back
  wait_until(-27);
  set_max_speed(60);
  lift_lil_down(true);
  // claw_up();
  wait_drive();
  pros::delay(250);

  // Turn to face alliance goal
  set_drive_pid(turn, -90, TURN_SPEED);
  mogo_mid(true);
  wait_drive();

  // Drive into goal
  set_drive_pid(drive, -19, 80, true);
  wait_drive();
  mogo_down(true);

  /////

  /*
  // Drive forward a little
  set_drive_pid(drive, 5, DRIVE_SPEED);
  wait_drive();
  */

  // Turn to corner
  set_drive_pid(l_swing, -180, TURN_SPEED);
  wait_drive();

  // Drive into corner
  set_drive_pid(drive, 17, DRIVE_SPEED, true);
  wait_drive();

  // Release goal
  pros::delay(100);
  lift_down(true);
  claw_up();
  pros::delay(500);

  // Drive away
  set_drive_pid(drive, -27, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(turn, -360, TURN_SPEED);
  wait_drive();

  /////

  /*
  // Drive goal lift
  mogo_down(true);
  set_drive_pid(turn, -35, TURN_SPEED);
  wait_drive();

  // Drive into first neutral
  set_drive_pid(drive, 10, 80);
  wait_drive();

  // Grab goal
  claw_down();

  // Turn to corner
  set_drive_pid(turn, -210, TURN_SPEED);
  lift_lil_down(true);
  wait_drive();

  // Drive into corner
  set_drive_pid(drive, 10, DRIVE_SPEED);
  wait_drive();

  // Release goal
  claw_up();

  // Drive away
  set_drive_pid(drive, -5, DRIVE_SPEED);
  wait_drive();
  */

}



void steal_one() {

  // Drive towards center goal
  claw_up();
  set_drive_pid(drive, 45, 127);
  lift_down(true);
  // Slow down when close to center
  wait_until(35);
  set_max_speed(40);
  wait_drive();

  // Grab goal
  claw_down();

  // Turn 180
  set_drive_pid(turn, -180, TURN_SPEED);
  wait_drive();

  // Drive back with goal
  set_drive_pid(drive, 27, 127, true);
  lift_lil_down(true);
  wait_until(20);
  set_max_speed(DRIVE_SPEED);
  mogo_mid(true);
  wait_drive();

  set_drive_pid(turn, -90, TURN_SPEED, true);
  wait_drive();

  set_drive_pid(drive, -14, DRIVE_SPEED, true);
  wait_drive();
  mogo_down(true);

  set_drive_pid(l_swing, -180, TURN_SPEED, true);
  wait_drive();

  // Drive into corner
  set_drive_pid(drive, 17, DRIVE_SPEED, true);
  wait_drive();

  // Release goal
  pros::delay(100);
  lift_down(true);
  claw_up();
  pros::delay(500);

  // Drive away
  set_drive_pid(drive, -27, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(turn, -360, TURN_SPEED);
  wait_drive();

}




void plat_down_center_hit() {

  set_drive_pid(turn, 12, TURN_SPEED);
  lift_down(true);
  wait_drive();

  set_drive_pid(drive, 56, 127);
  wait_until(42);
  claw_down();
  set_max_speed(DRIVE_SPEED);
  wait_drive();

  set_drive_pid(l_swing, 90, TURN_SPEED);
  wait_until(45);
  lift_lil_down(true);
  wait_drive();

  set_drive_pid(drive, 62, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(drive, -12, DRIVE_SPEED);
  lift_down(true);
  wait_drive();

  //set_drive_pid(l_swing, 45, TURN_SPEED);
  //wait_drive();

}





void plat_down_center() {

  set_drive_pid(turn, 12, TURN_SPEED);
  lift_down(true);
  wait_drive();

  set_drive_pid(drive, 58, 127);
  wait_until(42);
  claw_down();
  set_max_speed(DRIVE_SPEED);
  wait_drive();

  set_drive_pid(drive, -46, 127);
  wait_until(-24);
  set_max_speed(DRIVE_SPEED);
  claw_up();
  wait_drive();

  set_drive_pid(turn, -48, TURN_SPEED);
  wait_drive();

  mogo_mid(true);

  set_drive_pid(drive, -11, 80);
  wait_drive();

  mogo_down(true);

  set_drive_pid(drive, 28, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

  set_drive_pid(drive, 14, DRIVE_SPEED, true);
  wait_drive();


}




// All drive movements use the "set_drive_pid" function
// the first parameter is the type of motion (drive, turn, r_swing, l_swing)
// below are example codes using each type


///
// Drive Example
///
void
auto_1() {
  // The second parameter is target inches
  // The third parameter is max speed the robot will drive at
  // The fourth parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(drive, -12, DRIVE_SPEED);
  wait_drive();

  set_drive_pid(drive, -12, DRIVE_SPEED);
  wait_drive();
}



///
// Turn Example
///
void
auto_2() {
  // The second parameter is target degrees
  // The third parameter is max speed the robot will drive at


  set_drive_pid(turn, 90, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();
}



///
// Combining Turn + Drive
///
void
auto_3() {
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, -45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

  set_drive_pid(drive, -24, DRIVE_SPEED, true);
  wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void
auto_4() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 12 inches, the robot will travel the remaining distance at a max speed of 40
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_until(12);
  set_max_speed(40); // After driving 12 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  wait_drive();

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, -45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

  // When the robot gets to -12 inches, the robot will travel the remaining distance at a max speed of 40
  set_drive_pid(drive, -24, DRIVE_SPEED, true);
  wait_until(-12);
  set_max_speed(40); // After driving 12 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  wait_drive();
}



///
// Swing Example
///
void
auto_5() {
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive

  set_drive_pid(l_swing, 45, SWING_SPEED);
  wait_drive();

  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_until(12);

  set_drive_pid(r_swing, 0, SWING_SPEED);
  wait_drive();
}



///
// Auto that tests everything
///
void
test_auton() {
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(r_swing, -45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

  set_drive_pid(drive, -24, DRIVE_SPEED, true);
  wait_drive();
}


// Make your own autonomous functions here!

void
auto_6() {

}



void
auto_7() {

}



void
auto_8() {

}



void
auto_9() {

}



void
auto_10() {

}
