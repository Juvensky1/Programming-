#include <iostream>
#include "binarySearchTree.h"
#include "position.h"
#include "node.h"
#include "activity.h"
#include "participant.h"
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	cout.precision(2);
	cout.setf(ios::fixed|ios::showpoint);
	char option;
	Participant temp;
	BinarySearchTree<Participant> b;
	ifstream file;
	file.open("tracking.bin", ios::in | ios::binary);
	
	if(!file.fail()) {
		while(temp.read(file)){
			temp.makeKey();
			b.insert(temp);
		}
		file.close();	
	}
	
	do{
		cout<< " 1 Remove participant" << endl;
		cout<< " 2 Add participant" << endl;
		cout<< " 3 Add activity" << endl;
		cout<< " 4 Calculate total miles walked" <<endl;
		cout<< " 5 Pre-order print" <<endl;
		cout<< " 6 Exit and save" <<endl;
		cout<< " Option> ";
		cin >> option;
		
		
		if (option == '1'){
			char firstName[30];
			char lastName[30];
			cout<< " Last name: ";
			cin>>lastName;
			cout<< " First name: ";
			cin>>firstName;
			Participant temp( firstName, lastName);
			Position<Participant> p = b.find(temp);
			if (!p.isInternal()){
				cout<< " Participant not found"<<endl;
			}
			else{
				temp = p.getItem();
				b.erase(p);
				cout<<"Participant "<<temp.getFirstName()<<" "<<temp.getLastName()<<", "<<temp.calcTotalMiles()<<" total miles walked removed"<<endl;
			}
		}
		else if (option == '2'){
			char firstName[30];
			char lastName[30];
			double height;
			cout<< " Last name: ";
			cin>>lastName;
			cout<< " First name: ";
			cin>>firstName;
			Participant temp( firstName, lastName);
			Position<Participant> p = b.find(temp);
			if (!p.isExternal()){
				cout<<temp.getFirstName()<<" "<<temp.getLastName()<<" is already a participant.";
			}
			else{
				cout<<" Height in inches: ";
				cin>>height;
				temp.setHeight(height);
				b.insert(temp);
				cout<<temp.getFirstName()<<" "<<temp.getLastName()<<" has been added"<<endl;
			}
		}
		else if(option == '3'){
			char firstName[30];
			char lastName[30];
			double height;
			int activity, minutes;
			Activity act;
			cout<< " Last name: ";
			cin>>lastName;
			cout<< " First name: ";
			cin>>firstName;
			Participant temp( firstName, lastName);
			Position<Participant> p = b.find(temp);
			if (!p.isInternal()){
				cout<<temp.getFirstName()<<" "<<temp.getLastName()<<" is not a participant."<<endl;
				
			}
			else{
			    temp = p.getItem();
			    b.erase(p);
			    
				cout<<" Activity: ";
				cin>>activity;
				act.setCode(activity);
				cout<<" Minutes: ";
				cin>>minutes;
				act.setMinutes(minutes);
				temp.setActivity(act);
				b.insert(temp);
				cout<<" Added "<<temp.getFirstName()<<" "<<temp.getLastName()<<", "<<ACTIVITY_NAMES[act.getCode()]<<", "<<act.getMinutes()<<" minutes "<<" = "<<act.calcMiles(temp.getHeight())<< " miles"<<endl;
			}
			
		}
		else if(option == '4'){
			Position<Participant> p = b.begin();
			double miles = 0;
			for(;p!= b.end() ;++p){ 
			   miles += p.getItem().calcTotalMiles();
			}
			cout<<"Total miles walked by *everyone* : "<<miles<<endl;
		}
		
		else if(option == '5'){
			b.traverseAndPrint(b.root(), PREORDER);
		}
		else if( option == '6'){
			ofstream fout;
			fout.open("tracking.bin", ios::out | ios::binary);
			b.preorderTraverseAndWrite(b.root(), fout);
			fout.close();
    	
		}
		else{
			cout<<"Invalid option."<<endl;
		}
		
    }while(option != '6');
    
	return 0;
}