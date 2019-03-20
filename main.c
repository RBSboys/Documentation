#include <kipr/botball.h>
void turn_right();
void turn_left();
void till_blackline();
void detect_blackline();
void fire();
int main()
{
    shut_down_in(120);
    enable_servo(0);
    set_servo_position(0,1024);
    mav(0,1000);
    mav(1,1000);
    msleep(3200);          //get out of the starting box
    turn_right(); 
    mav(0,1000);
    mav(1,1000);
    msleep(2700);     //turn 90 degrees right
    till_blackline();
    turn_left();  
    mav(0,1000);
    mav(1,1000);
    msleep(2000);// turn 90 degrees left
    till_blackline();
    turn_right();           //turn 90 degrees right
    ao();
    msleep(100);
    
    {
    while (digital(0)==0);    // move straight untill the sesor hits
    mav(0,1000);
    mav(1,1000);
        msleep(1000);
    }  
    
     mav(0,-1000);
    mav(1,1000);
    msleep(300);       //adjust position to move the magnet
    
    enable_servo(0);
    set_servo_position(0,100); //move the magnet to the right
    
    mav(0,1000);
    mav(1,-1000);
    msleep(300);    //adjust position to move to the original position
    
    mav(0,-1000);
    mav(1,1000);
    msleep(300);       //adjust position to move the magnet
    
     enable_servo(0);
    set_servo_position(0,2300);  //move the magnet to the right
    
    set_servo_position(0,1024);   // return the claw to its original position
    
     mav(0,-1000);
    mav(1,1000);
    msleep(300);      //return to original position
    
     mav(0,1000);
    mav(1,1000);
    msleep(300);  //go back
    turn_right();
    
    till_blackline();
    turn_left();
    till_blackline();
    detect_blackline();
    set_servo_position(0,100);
    till_blackline();
    while (digital(0)==0)
{
if(analog(0)>=2000)
{
mav(0,1000);
mav(1,-1000);
msleep(100);
}
else
{
mav(0,-1000);
mav(1,1000);
msleep(100);
}
   set_servo_position(0,2000); 
   fire();
   fire();     
   fire();    
   fire();    
  
}
      
    
    
     
}
void turn_right()
{
 mav(0,1000);
    mav(1,-1000);
    msleep(1600); 
}
void turn_left()
{
   mav(0,-1000);
    mav(1,1000);
    msleep(1600);    
}
void till_blackline()
{
 {
    while (analog(1)<=3900);    // move straight untill the blackline
    mav(0,1000);
    mav(1,1000);
     msleep(500);
    }
}
void detect_blackline()
{
while (analog(2)>=2000)
{
if(analog(0)>=2000)
{
mav(0,1000);
mav(1,-1000);
msleep(100);
}
else
{
mav(0,-1000);
mav(1,1000);
msleep(100);
}
}
}
void fire()
{
mav(0,-1000);
mav(1,-1000);
msleep(250);
set_servo_position(0,100);
mav(0,1000);
mav(1,1000);
msleep(250);
set_servo_position(0,2000);

}