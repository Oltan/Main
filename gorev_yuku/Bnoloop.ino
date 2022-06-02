static void Bnoloop(){
  
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

  roll= euler.x();
  pitch=euler.y();
  yaw=euler.z();
  
  }
