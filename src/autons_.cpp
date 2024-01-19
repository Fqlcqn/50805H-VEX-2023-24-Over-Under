  #include "main.h"


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;





void auton_close_wp(){
  chassis.wait_drive();
  wings.set_value(true);
  pros::delay(30);
  chassis.wait_drive();
  chassis.set_drive_pid(2, 120, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, -71, SWING_SPEED);
  chassis.wait_drive();
  wings.set_value(false);
  chassis.set_drive_pid(45, 90, true);
  chassis.wait_drive();
  intake.set_value(true);
  pros::delay(100);
  chassis.wait_drive();
  chassis.set_drive_pid(-46, 90, true);
  chassis.wait_drive();
  chassis.set_turn_pid(15, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(10, 120, true);
  intake.set_value(false);
  pros::delay(50);
  chassis.wait_drive();
  chassis.set_drive_pid(-11, 120, true);
  chassis.wait_drive();//BRINGS BACK THE BALL FROM MID
  chassis.set_turn_pid(-51, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(57.75, 110, true);
  chassis.wait_drive();
  intake.set_value(true);
  pros::delay(100);
  chassis.set_drive_pid(-64, 90, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, 8, SWING_SPEED);
  chassis.wait_drive();
  intake.set_value(false);
  chassis.set_drive_pid(37.5, 120, true);
}

void auton_far_wp(){
  intake.set_value(true);
  pros::delay(60);
  chassis.set_drive_pid(-34.5, 120, true);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.set_swing_pid(ez::LEFT_SWING, -45, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(-11, 120, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, -80, 110);
  chassis.wait_drive();
  wings.set_value(false);
  chassis.set_drive_pid(-15, 120, true);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 120, true);
  chassis.wait_drive();
  chassis.set_turn_pid(117, 110);
  chassis.wait_drive();
  intake.set_value(false);
  chassis.set_drive_pid(23, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-22, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(30, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(48, 120, true);
  chassis.wait_drive();
  intake.set_value(true);
  pros::delay(25);//INTAKES FIRST BALL FROM MID
  chassis.set_turn_pid(140, 100);
  chassis.wait_drive();
  intake.set_value(false);
  chassis.set_drive_pid(20, 120, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-8, 120, true);
  chassis.wait_drive();
  chassis.set_turn_pid(48.5, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(18, 120, true);
  chassis.wait_drive();
  intake.set_value(true);
  chassis.set_turn_pid(0, 110);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.wait_drive();
  chassis.set_drive_pid(-35, 120, true);
  chassis.wait_drive();
  wings.set_value(false);
  chassis.set_drive_pid(20, 120, true);
  chassis.wait_drive();
  chassis.set_turn_pid(180, 110);
  chassis.wait_drive();
  intake.set_value(false);
  chassis.set_drive_pid(23, 120, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 120, true);
  chassis.wait_drive();
}


void auton_far_elim(){
  wings.set_value(false);
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-47, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(39, 90, true);
  chassis.wait_drive();
  intake.set_value(true);
  pros::delay(30);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.wait_drive();
  chassis.set_drive_pid(-33, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_drive_pid(10, DRIVE_SPEED, true);
  wings.set_value(false);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  intake.set_value(false);
  chassis.wait_drive();
  chassis.set_drive_pid(15, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-30, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_turn_pid(149, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(51, 90, true);//good^
  chassis.wait_drive();
  intake.set_value(true);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(18, DRIVE_SPEED, true);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.wait_drive();
  chassis.set_turn_pid(5, TURN_SPEED);
  chassis.wait_drive();
  intake.set_value(false);
  chassis.wait_drive();
  chassis.set_drive_pid(19, DRIVE_SPEED, true);
  chassis.wait_drive();
  wings.set_value(false);
  chassis.wait_drive();
  chassis.set_drive_pid(-14, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_turn_pid(21, TURN_SPEED);
  chassis.wait_drive();
  intake.set_value(true);
  chassis.set_drive_pid(12, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, DRIVE_SPEED , true);
}


void auton_close_elim(){
  wings.set_value(false);
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 20, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(27.35, 90, true);
  pros::delay(30);
  chassis.wait_drive();
  intake.set_value(true);
  pros::delay(100);
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  wings.set_value(true);
  pros::delay(30);
  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();
  wings.set_value(false);
  chassis.set_drive_pid(22.5, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-180, TURN_SPEED);//TURN AT MID
  chassis.wait_drive();
  chassis.set_drive_pid(44.5, 110, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, -230, SWING_SPEED);
  pros::delay(50);
  chassis.wait_drive();
  intake.set_value(false);
  pros::delay(50);//DROPS TRIBALL FROM MID
  chassis.set_drive_pid(-35, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-190, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 127, true);//SCORE BLUE TRIBALL
  chassis.wait_drive();
  chassis.set_drive_pid(18, 110, true);
  chassis.wait_drive();
  wings.set_value(true);
  pros::delay(30);
  chassis.set_swing_pid(ez::RIGHT_SWING, -280, SWING_SPEED);//DESCORE
  chassis.wait_drive();
  wings.set_value(false);
  pros::delay(30);
  chassis.set_turn_pid(-260, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(39, 127, true);
}


void skills_auton(){
  pros::Motor slapper();

  wings.set_value(true);
  intake.set_value(true);

  // Move the flywheel (blocker) at a specific velocity
  blocker.move_velocity(-600);
  chassis.wait_drive();

  // Wait for 20 seconds
  pros::delay(25000);
  chassis.wait_drive();

  // Stop the lift and flywheel
  blocker.move_velocity(0);
  chassis.wait_drive();

  // Scoring triballs
  wings.set_value(false);
  intake.set_value(false);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-13, 127, true);
  chassis.wait_drive();//Scores alliance triballs
  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-38, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(170, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-45, 127, true);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.set_drive_pid(-18, 127, true);//Went to other side, ready to score
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 220, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-22, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 270, SWING_SPEED);
  pros::delay(20);
  wings.set_value(false);
  chassis.wait_drive();
  chassis.set_drive_pid(-20, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(245, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-20, 127, true);
  chassis.wait_drive();
}










//heyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy










///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

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


void first_auton() {
  /*intake.set_value(false);
  intake_on = false;
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();
  wings.set_value(true);
  wings_on = true;
  chassis.set_swing_pid(ez::LEFT_SWING, -30, SWING_SPEED);*/
}


void drive_example(){
  //DONT USE THIS CODE, CLOSE ELIM IS INSIDE DRIVE_EXAMPLE
  wings.set_value(false);
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.set_turn_pid(47, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(39, 90, true);
  chassis.wait_drive();
  intake.set_value(true);
  pros::delay(30);
  chassis.set_swing_pid(ez::LEFT_SWING, -90, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-20, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(20, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 180, SWING_SPEED);
  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 110, SWING_SPEED);
  chassis.wait_drive();
  intake.set_value(false);
  pros::delay(25);
  chassis.set_drive_pid(-20, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING, 155, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(8, 127, true);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.set_swing_pid(ez::RIGHT_SWING, -90, SWING_SPEED);
  chassis.wait_drive();
  wings.set_value(false);
  chassis.set_drive_pid(35, 127, true);
}


void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
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



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
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



// . . .
// Make your own autonomous functions here!
// . . .