#include<iostream>
#include<cmath>
using namespace std;

void figureIt(double x, bool *divisible, char *sign, int *intPart);

int main()
{

  double x;
  bool divisible;
  char sign;
  int  intPart;

   do{
   cout<< " Enter x: ";
   cin>>x;
   figureIt(x, &divisible, &sign, &intPart);
   cout<<x<< ": ";
  (divisible)?cout<< "even, ": cout<< "not even, ";
   cout<<sign<<", "<<intPart<< endl;
   }
   while(x !=0);

 return(0);
}


 void figureIt(double x, bool *divisible, char *sign, int *intPart)
{
  double result;
  int y;
 result=fmod(x,2);
   if (result == 0){
   *divisible = true;
    }
    else{
    *divisible = false;
    }

          if ( x >= 0){
           *sign ='+';
          }
          else{
          *sign ='-';
          }


   y=fabs(x);

 if(fabs(x)-y < .5){
             *intPart=y;
             }
            else{
            *intPart=y+1;
             }
            if(x<0){
            *intPart=-*intPart;
             }
}

