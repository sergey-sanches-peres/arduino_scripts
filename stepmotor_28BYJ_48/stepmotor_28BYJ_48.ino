#include <CustomStepper.h>
/*
  CW - по часовой стрелке
  CCW - против часовой стрелки
*/
CustomStepper stepper(8, 9, 10, 11);

int action = 1;

void setup()
{
  stepper.setRPM(15);
  stepper.setSPR(4075.7728395);
}

void loop()
{
  if (stepper.isDone() and action == 1)
  {
    stepper.setDirection(CW);
    stepper.rotateDegrees(50);
    action = 2;
  }
  if (stepper.isDone() and action == 2)
  {
    stepper.setDirection(CCW);
    stepper.rotateDegrees(50);
    action = 3;
  }
  if (stepper.isDone() and action == 3)
  {
    stepper.setDirection(CW);
    stepper.rotateDegrees(50);
    action = 4;
  }
  if (stepper.isDone() and action == 4)
  {
    stepper.setDirection(CCW);
    stepper.rotateDegrees(50);
    action = 5;
  }
  if(stepper.isDone() and action == 5)
  {
    stepper.setDirection(STOP);
  }
  stepper.run();
}
