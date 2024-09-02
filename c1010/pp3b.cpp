#include<iostream>
using namespace std;
int main()
{
int x;
int i;
int n;
 cout<<" Enter n: ";
 cin>>n;
 for(i=0, x=1 ; i<= n; i++,x*=2)
  {
   cout<<i<<" "<<x<<endl;
  }
return(0);
}
