void pidhesaplama(){
  //Roll hesaplamalari
  double roll_mem = 0;
  double roll_ki = 0 ;
  double roll_kp = 0;
  double roll_kd = 0;
  double roll_error = 0;
  double roll_output = 0,
  roll_error = -roll;
  roll_output = roll_kp * roll_error + roll_error*roll_ik + roll_kd * ( roll_error - roll_mem ); 
  roll_mem = roll_error;


  //Pitch Hesaplamalari
  double pitch_mem = 0;
  double pitch_ki = 0 ;
  double pitch_kp = 0;
  double pitch_kd = 0;
  double pitch_error = 0;
  double pitch_output = 0,
  pitch_error = -pitch;
  pitch_output = pitch_kp * pitch_error + pitch_error*pitch_ik + pitch_kd * ( pitch_error - pitch_mem ); 
  pitch_mem = pitch_error;
  
  //Yaw Hesaplamalari
  double yaw_mem = 0;
  double yaw_ki = 0 ;
  double yaw_kp = 0;
  double yaw_kd = 0;
  double yaw_error = 0;
  double yaw_output = 0,
  yaw_error = -yaw;
  yaw_output = yaw_kp * yaw_error + yaw_error*yaw_ik + yaw_kd * ( yaw_error - yaw_mem ); 
  yaw_mem = yaw_error;
  

  



  
}
