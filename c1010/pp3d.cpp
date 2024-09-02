#include<iostream>
using namespace std;
int main()
{
 char floor; 
 do
 {
  cout<<"Pick a flooring option"<<endl<<"H hardwood"<<endl<<"L laminate"<<endl<<
  "E engineered hardwood"<<endl<<"Q quit"<<endl<<"Choice: ";
 cin>>floor; 
switch(floor)
 {
  case'H': case'h':
   cout<<"You ordered hardwood"<<endl;
   break;
  case'L': case'l':
   cout<<"You ordered laminate"<<endl;
   break;
  case'E': case'e':
   cout<<"You ordered egineered hardwood"<<endl;
   break;
  case'Q': case'q':
   break;
  default:
   cout<<"Invalid choice: "<<floor<<endl;
  }
}while (floor != 'Q'&& floor !='q');
 
return(0);
}
