#include <iostream>
using namespace std;

int main() {
    int i, n = 1;
    double x = 1;
      
    cout.setf(ios::fixed);
    cout.precision(0);
    cout<<"Enter n: ";
    cin>>n;

    for (i = 1; i <= n; i++) {
        x *= i; //x = x * i
    }
    cout<<n<< "! is "<<x<< endl;

        return (0);
}
