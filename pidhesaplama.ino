//void pidhesaplama(){
//  //Roll hesaplamalari
//  double roll_mem = 0;
//  double roll_ki = 0 ;
//  double roll_kp = 0;
//  double roll_kd = 0;
//  double roll_error = 0;
//  double roll_output = 0,
//  roll_error = -roll;
//  roll_output = roll_kp * roll_error + roll_error*roll_ik + roll_kd * ( roll_error - roll_mem ); 
//  roll_mem = roll_error;
//
//
//  //Pitch Hesaplamalari
//  double pitch_mem = 0;
//  double pitch_ki = 0 ;
//  double pitch_kp = 0;
//  double pitch_kd = 0;
//  double pitch_error = 0;
//  double pitch_output = 0,
//  pitch_error = -pitch;
//  pitch_output = pitch_kp * pitch_error + pitch_error*pitch_ik + pitch_kd * ( pitch_error - pitch_mem ); 
//  pitch_mem = pitch_error;
//  
//  //Yaw Hesaplamalari
//  double yaw_mem = 0;
//  double yaw_ki = 0 ;
//  double yaw_kp = 0;
//  double yaw_kd = 0;
//  double yaw_error = 0;
//  double yaw_output = 0,
//  yaw_error = -yaw;
//  yaw_output = yaw_kp * yaw_error + yaw_error*yaw_ik + yaw_kd * ( yaw_error - yaw_mem ); 
//  yaw_mem = yaw_error;
//  
//  
//
//  //Altitude hesaplamalari
//  double Altitude_mem = 0;
//  double Altitude_ki = 0 ;
//  double Altitude_kp = 0;
//  double Altitude_kd = 0;
//  double Altitude_error = 0;
//  double Altitude_output = 0,
//  Altitude_error = -Altitude;
//  Altitude_output = Altitude_kp * Altitude_error + Altitude_error*Altitude_ik + Altitude_kd * ( Altitude_error - Altitude_mem ); 
//  Altitude_mem = Altitude_error;
//
//  double motor1,motor2,motor3,motor4;
//
//  motor1 = Altitude_output + roll_output + pitch_output + yaw_output;
//  motor2 = Altitude_output + roll_output + pitch_output + yaw_output;
//  motor3 = Altitude_output + roll_output + pitch_output + yaw_output;
//  motor4 = Altitude_output + roll_output + pitch_output + yaw_output;
//
//  motor1 = map(motor1, 0, 1023, 0, 180);
//  motor2 = map(motor2, 0, 1023, 0, 180);
//  motor3 = map(motor3, 0, 1023, 0, 180);
//  motor4 = map(motor4, 0, 1023, 0, 180);
//
//  ESC1.write(motor1);
//  ESC2.write(motor2);
//  ESC3.write(motor3);
//  ESC4.write(motor4);
//
//
//
//  
//}
