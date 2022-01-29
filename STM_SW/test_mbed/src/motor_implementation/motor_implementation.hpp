#ifndef motor_implementation_h
#define motor_implementation_h


class Motor_Implementation
{
  public:
    // virtual void motor_control(float velocity) = 0;
    virtual void start_motor_control(void) = 0;
    virtual void quit_motor_control(void) = 0;
    Motor_Implementation() {};
    virtual ~Motor_Implementation() {};

  protected:
};


#endif



