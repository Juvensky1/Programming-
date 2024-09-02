/*
*File.pp1a.cpp
*Author: Wilson Flynn and Juvensky Hyppolite - Jean
*This program gets 2 integers from the user, adds them and displays the sum 
*/
#include <iostream>
int main()
{
  int number1; //first and second intergers to add 
  int number2;
 int sum;	//sum of double number1 and double number2
 int difference; //difference of double number1 and double number2
 int product; //product of double number1 and double number2
 int  quotient;  //quotient of double number1 and double number2

 //Get numbers from user
 std::cout<<"Enter first number:";
 std::cin>>number1;
 std::cout<<"Enter second number:";
 std::cin>>number2;
 //add numbers and print the sum
 sum = number1 + number2;
 difference =  number1 -  number2;
 product =  number1 *  number2;
 quotient =  number1 /  number2; 
 std::cout<< "Sum:"<<sum<<std::endl;
 std::cout<< "difference:"<<difference<<std::endl;
 std::cout<< "Product:"<<product<<std::endl;
 std::cout<< "Quotient:"<<quotient<<std::endl;
 return(0);
}
