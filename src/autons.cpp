#include "main.h"


const int DRIVE_SPEED = 110;     
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



pros::Motor right_intake(14);
pros::Motor left_intake(20);
pros::ADIDigitalOut horizontal_wings('G', false);
pros::Motor kicker(9);

pros::Motor left1(-12);
pros::Motor left2(-18);
pros::Motor left3(-19);

pros::Motor right1(13);
pros::Motor right2(17);
pros::Motor right3(1);



// Intake
void runIntake() {
    right_intake.move_velocity(-600);
    left_intake.move_velocity(600);
}

void stopIntake() {
    right_intake.move_velocity(0);
    left_intake.move_velocity(0);
}

void runOuttake() {
  right_intake.move_velocity(600);
  left_intake.move_velocity(-600);
}



// Wings
void wingsDown() {
  wings.set_value(true);
}

void wingsUp() {
  wings.set_value(false);
}



// Horizontal Wings
void horiz_wingsDown() {
  horizontal_wings.set_value(true);
}

void horiz_wingsUp() {
  horizontal_wings.set_value(false);
}



// Kicker
void runKicker() {
  // Max Speed
  kicker.move_velocity(600);
}

void stopKicker() {
  kicker.move_velocity(0);
}



// Braking
void chassisBrake(pros::motor_brake_mode_e_t M) {
  left1.set_brake_mode(M);
  left2.set_brake_mode(M);
  left3.set_brake_mode(M);

  right1.set_brake_mode(M);
  right2.set_brake_mode(M);
  right3.set_brake_mode(M);
}



//AUTONS:







void auton_close_wp(){
  runIntake();
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 20, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(27.35, 90, true);
  pros::delay(30);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  horiz_wingsDown();
  pros::delay(30);
  chassis.set_drive_pid(20, 127, true);// Pushes triball over barrier
  chassis.wait_drive();
  chassis.set_drive_pid(-27, 100, true);
  horiz_wingsUp();
  chassis.wait_drive();
  chassis.set_turn_pid(-180, TURN_SPEED);// TURN AT MID
  chassis.wait_drive();
  chassis.set_drive_pid(45.75, 110, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, -230, SWING_SPEED);
  runOuttake();
  pros::delay(50);
  chassis.wait_drive();
  pros::delay(50);// DROPS TRIBALL FROM MID
  chassis.set_drive_pid(-35, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-190, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 127, true);// SCORE BLUE TRIBALL
  blocker.move_velocity(127);
  chassis.wait_drive();
  chassis.set_drive_pid(18, 110, true);
  chassis.wait_drive();
  wingsDown();
  pros::delay(30);
  chassis.set_swing_pid(ez::RIGHT_SWING, -280, SWING_SPEED);// DESCORE
  chassis.wait_drive();
  wingsUp();
  runOuttake();
  chassis.set_turn_pid(-268, TURN_SPEED);
  pros::delay(200);
  wingsDown();
  chassis.wait_drive();
  chassis.set_drive_pid(37, 127, true);
  wingsUp();
  chassis.wait_drive();

  // OLD WP CODE:
  /*runIntake();
  wingsDown();
  pros::delay(30);
  chassis.wait_drive();
  chassis.set_drive_pid(2, 120, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, -71, SWING_SPEED);
  chassis.wait_drive();
  wingsUp();
  chassis.set_drive_pid(45, 90, true);
  chassis.wait_drive();
  pros::delay(100);
  chassis.wait_drive();
  chassis.set_drive_pid(-46, 90, true);
  chassis.wait_drive();
  chassis.set_turn_pid(15, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(10, 120, true);
  runOuttake();
  pros::delay(100);
  chassis.wait_drive();
  chassis.set_drive_pid(-11, 120, true);
  chassis.wait_drive();//BRINGS BACK THE BALL FROM MID
  chassis.set_turn_pid(-51, TURN_SPEED);
  runIntake();
  chassis.wait_drive();
  chassis.set_drive_pid(57.75, 110, true);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_drive_pid(-64, 90, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, 8, SWING_SPEED);
  runOuttake();
  chassis.wait_drive();
  chassis.set_drive_pid(37.5, 120, true);
  stopIntake();*/
}



void auton_far_qual(){ 
  runIntake();
  chassis.set_drive_pid(4, 120, true);
  pros::delay(100);
  chassis.wait_drive();
  chassis.set_drive_pid(-37.5, 100, true);
  chassis.wait_drive();
  chassis.set_turn_pid(140, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(16, 120, true);
  chassis.wait_drive();
  wingsDown();
  chassis.wait_drive();
  chassis.set_drive_pid(6, 120, true);
  chassis.wait_drive();
  runOuttake();
  chassis.set_swing_pid(ez::RIGHT_SWING, 110, 110);// Descore
  pros::delay(500);
  wingsUp();
  chassis.wait_drive();
  chassis.set_drive_pid(-2.5, 120, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-80, 110);// Turn to score
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 120, true);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127, true);
  stopIntake();
  chassis.wait_drive();
  chassis.set_turn_pid(22.5, 110);
  chassis.wait_drive();
  runIntake();
  chassis.set_drive_pid(53, 120, true);
  chassis.wait_drive();
  pros::delay(75);// Intakes first triball from mid
  runOuttake();
  chassis.set_turn_pid(140, 100);// Turn to drop triball at mid
  chassis.wait_drive();
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();
  runIntake();
  chassis.wait_drive();
  chassis.set_turn_pid(49, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(21, 120, true);
  chassis.wait_drive();
  chassis.set_turn_pid(180, 110);// Turn to face goal
  chassis.wait_drive();
  horiz_wingsDown();
  runOuttake();
  chassis.set_drive_pid(34, 120, true);// Scores
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 127, true);
  horiz_wingsUp();
  wingsUp();
}


void auton_far_elim(){
  runIntake();
  pros::delay(10);
  wingsUp();
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-47, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(39, 90, true);
  chassis.wait_drive();
  pros::delay(30);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  wingsDown();
  chassis.wait_drive();
  chassis.set_drive_pid(-33, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_drive_pid(10, DRIVE_SPEED, true);
  wingsUp();
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  runOuttake();
  chassis.wait_drive();
  chassis.set_drive_pid(14.75, 115, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-30, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(147, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(51, 90, true);//good^
  chassis.wait_drive();
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(18, DRIVE_SPEED, true);
  chassis.wait_drive();
  wingsDown();
  chassis.wait_drive();
  chassis.set_turn_pid(5, TURN_SPEED);
  chassis.wait_drive();
  chassis.wait_drive();
  chassis.set_drive_pid(19, DRIVE_SPEED, true);
  chassis.wait_drive();
  wingsUp();
  chassis.wait_drive();
  stopIntake();
  chassis.set_drive_pid(-14, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_turn_pid(175, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(5, DRIVE_SPEED , true);
}



void auton_close_elim(){
  runIntake();
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 20, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(27.35, 90, true);
  pros::delay(30);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  horiz_wingsDown();
  pros::delay(30);
  chassis.set_drive_pid(20, 127, true);// Pushes triball over barrier
  chassis.wait_drive();
  chassis.set_drive_pid(-27, 100, true);
  horiz_wingsUp();
  chassis.wait_drive();
  chassis.set_turn_pid(-180, TURN_SPEED);// TURN AT MID
  chassis.wait_drive();
  chassis.set_drive_pid(45.75, 110, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, -230, SWING_SPEED);
  runOuttake();
  pros::delay(50);
  chassis.wait_drive();
  pros::delay(50);// DROPS TRIBALL FROM MID
  chassis.set_drive_pid(-35, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-190, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 127, true);// SCORE BLUE TRIBALL
  blocker.move_velocity(127);
  chassis.wait_drive();
  chassis.set_drive_pid(18, 110, true);
  chassis.wait_drive();
  wingsDown();
  pros::delay(30);
  chassis.set_swing_pid(ez::RIGHT_SWING, -280, SWING_SPEED);// DESCORE
  chassis.wait_drive();
  wingsUp();
  runOuttake();
  chassis.set_turn_pid(-255, TURN_SPEED);
  pros::delay(200);
  wingsDown();
  chassis.wait_drive();
  chassis.set_drive_pid(40, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-41, 127, true);
  chassis.wait_drive();
  stopIntake();
}



void skills_auton(){


  // This auton was pseudo coded on 2/16

  // Going to position
  chassis.set_turn_pid(45, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(0, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 110, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 127, true);


  // Match Loading & Brakes
  wingsDown();
  chassisBrake(MOTOR_BRAKE_BRAKE);
  runKicker();
  pros::delay(30000); // Match loading time (ms)
  stopKicker();
  chassisBrake(MOTOR_BRAKE_COAST);
  chassis.wait_drive();


  // Pushing triballs using horz_wings
  wingsUp();
  runOuttake();
  chassis.set_drive_pid(20, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, 180, 127);
  pros::delay(200);
  horiz_wingsDown();
  chassis.set_drive_pid(60, 127, true);
  pros::delay(300);
  horiz_wingsUp();
  chassis.set_turn_pid(-90, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 180, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, 90, 127);


  // Going to other side
  chassis.set_drive_pid(30, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 45, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 0, 127);
  chassis.wait_drive();

  // First Side Push
  horiz_wingsDown();
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-12, 127, true);
  pros::delay(300);
  horiz_wingsUp();
  chassis.wait_drive();
  chassis.set_turn_pid(-80, 127);
  chassis.wait_drive();

  // Going to First Mid Push
  chassis.set_drive_pid(30, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(0, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(30, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, 127);
  pros::delay(200);

  //First Mid Push
  wingsDown();
  chassis.set_drive_pid(-25, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, -60, 127);
  pros::delay(100);
  wingsUp();
  chassis.wait_drive();

  // Going to Second Mid Push
  chassis.set_drive_pid(25, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-20, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(7, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, 127);
  chassis.wait_drive();

  // Second Mid Push
  wingsDown();
  chassis.set_drive_pid(-25, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, -45, 127);
  pros::delay(200);
  wingsUp();

  // Going to Last Push
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 45, 127);
  horiz_wingsDown();
  chassis.wait_drive();
  chassis.set_drive_pid(12, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, 180, 127);
  chassis.wait_drive();

  // Last Push
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 127, true);
  horiz_wingsUp();
  wingsUp();
  stopIntake();

  
  // This auton was coded ~2/14. Old route, new route above^
  /*Skills auton without pushing triballs into bowling alley (pseudo code)
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(75, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();
  
  // Match Loading & Brakes
  wingsDown();
  chassisBrake(MOTOR_BRAKE_BRAKE);
  runKicker();
  pros::delay(30000);
  stopKicker();
  chassisBrake(MOTOR_BRAKE_COAST);
  chassis.wait_drive();


  // Scoring triballs
  wingsUp();
  runOuttake();
  chassis.set_swing_pid(ez::LEFT_SWING, 135, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(90, 127);
  chassis.wait_drive();
  wingsDown();
  chassis.set_drive_pid(40, 127, true);
  chassis.wait_drive();
  wingsUp();
  horiz_wingsDown(); // Went to other side

  chassis.set_swing_pid(ez::RIGHT_SWING, 45, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 0, 127);
  chassis.wait_drive();

  // First Side Push
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-12, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, 127);
  chassis.wait_drive();

  // Going to First Mid Push
  chassis.set_drive_pid(30, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, 127);
  pros::delay(200);

  //First Mid Push
  wingsDown();
  chassis.set_drive_pid(-25, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(25, 127, true);
  pros::delay(100);
  wingsUp();
  chassis.wait_drive();

  // Going to Second Mid Push
  chassis.set_turn_pid(0, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, 127);
  chassis.wait_drive();

  // Second Mid Push
  wingsDown();
  chassis.set_drive_pid(-25, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, -45, 127);
  wingsUp();

  // Going to Last Push
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 45, 127);
  horiz_wingsDown();
  chassis.wait_drive();
  chassis.set_drive_pid(12, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, 180, 127);
  chassis.wait_drive();

  // Last Push
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 127, true);
  horiz_wingsUp();
  wingsUp();
  stopIntake();*/
}










//heyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy











// Constants

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  //default: chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, .75, 0.0, 6, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, .75, 0.0, 6, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}


void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}


// Interference example
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}