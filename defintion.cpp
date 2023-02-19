#include <iostream>
#include "project.h"
using namespace std;

// (fun12): disply the password condition when the user wants to entr his l her own pass
void passCond(){
	cout<<"your passowrd should contains the following condations: "<<endl;
	cout<<"1- password must be at least 6 charctaer. "<<endl;
	cout<<"2- consist of at least 1 letter (a-z). "<<endl;
	cout<<"3- consist of at least 1 numbers. "<<endl;
	cout<<"4- consist of at least 1 captil letter (A-Z). "<<endl;
	cout<<"5- consist of at lest one of the symbols ( @ , # , & , % , $ ) "<<endl;//we must check if ther is function do that
}

// closing statments when the guest want to exsit:
 void guest_closing (){
cout<<endl<<endl<<"*************** THANK YOU ***************"<<endl<<endl;
cout<<" We were blessed to surve you and make your life easier"<<endl;
cout<<" Do not not forget to drive safely. See you later (:"<<endl;
}

//// closing statments when the employee want to exsit:
void employee_closing () {
cout<<endl<<"********* Thank you For using our car rental employee system *********"<<endl;
	cout<<endl<<endl<<">>Please Open File (Employee Report.txt) to document your work (:"; 
    
}


