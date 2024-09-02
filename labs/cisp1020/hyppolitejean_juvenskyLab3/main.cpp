#include <iostream>
#include <fstream>
#include <string>
#include "timestamp.h"
#include "sensor.h"
#include "racer.h"
#include <iomanip>
#include <vector>
#include <algorithm>
using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
int main(){
	
	char filename[15];
	Racer r = Racer();
	ifstream in;
	char c;
	cout<<"Welcome to Racers-R-Us."<<endl;
	cout<<"Enter race file: ";
	cin>>filename;
	in.open(filename);
	if( in.fail()){
		cout<<"file does not exist"<<endl;
		return 1;
	}
	else{
		in.get(c);
		if(in.eof()){
			cout<<filename<<" is empty"<<endl;
			return 1;
		}
		in.putback(c);
	}
	int sensors;
	vector <Racer> racer;
	double distance;
	Timestamp t;
	string fornow;
      getline(in, fornow);
      size_t found= fornow.find(':');
      t.setHour(stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);
      
       found = fornow.find(':');
       t.setMinute(stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);

      found = fornow.find(':');
      t.setSecond(stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);

      found = fornow.find(';');
      t.setMillisecond(stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);

      found = fornow.find(';');
      sensors=(stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);

      found = fornow.find(';');
      distance=(stod(fornow.substr(0, found)));
      fornow.erase(0, found+1); 
      cout<<setw(41)<<left<<"Name"
     <<setw(6)<<left<<"Number"
     <<setw(8)<<" "
     <<setw(12)<<left<<"Time"<<endl;
     cout<<setfill('-')<<setw(64)<< "-"<<setfill(' ')<<endl;
     

      while(!in.eof()){
        in>>r;
        racer.push_back(r);
      }
      sort(racer.begin(), racer.end());
    for(int i = 0; i<racer.size(); i++){
      cout<<racer[i]<<endl;
   }

    
    return 0;
}