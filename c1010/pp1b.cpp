 /*
*File pp1b.cpp
*Authors Wilson flynn and Juvensky Hyppolite - Jean
* this program gets the force 
*/
#include <iostream> 
int main()
{
  double mass; // in kg
  double acceleration; // in m/s^2
  double force; // in Newtons 
 
 // get numbers from users 
  std::cout<<" Enter mass in kg:";
  std::cin>>mass;
  std::cout<<"Enter acceleration in m/s^2:";
  std::cin>>acceleration;
  // multiplies mass and acceleration and prints the force
  force = mass * acceleration;
  std::cout<<"Force:"<<force<< " Newtons" << std::endl;
  return(0);
}
