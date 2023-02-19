#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "project.h"
using namespace std;
  
// *************STUDENTS NAMES ************ 
// Norah ALanzi - 2220000572
// Nada ALrshisid - 2220000552
// Linah Alturki - 2220005219 


// Glopal Varibles:
int choose_insurance , choose_paymentMethod, days;
double price=0, *p=&price;
string car_code;

//The car info for the employee program
struct car{
    string name;
    int price;                                    
};

//The guest info for the guest program 
struct information{
    string name;
    string name2;
    string id;
    char gender;
    int age;
    string Nationality;
    char license;
    string phone;
}account;
// if the guest was from dammam, the pick up car location will be:
namespace Dammam {
	void location (){
		cout<<endl<<"You can pickup your car from our branch at King Fahd Suburb, Unnamed Road, Dammam "<<rand()<<endl;
	}
}
// if the guest was from Khobar, the pick up car location will be:
namespace Khobar{
	void location (){
		cout<<endl<<"You can pickup your car from our branch at Olaya, Al Khobar "<<rand()<<endl;
	}
}
// if the guest was from jubail, the pick up car location will be:
namespace jubail{
	void location (){
		cout<<endl<<"You can pickup your car from our branch at Fanateer, Al Jubail  "<<rand()<<endl;
		
	}
}

// (fun1): employee function
void employee();

void getinformation(information & account);// (fun2) function that asks the guests for their info

bool eligbile (int age,char license,string id, string phone );//(fun3):  function that asks the guests for their info


bool ValidPass(string &password);//(fun4): if the guest wanted to enter his / her own passowrd, this finction will ensure that the passowrd is valid

// (fun5): This function cheack if the user enter the reight username and passowrd before starting the car rental peosess
bool Entery_verification (string username,string Enterd_username,string pass, string Enterd_pass);

void AllCars ();//(fun6): function that disbly all cars mneu for the guest from a file

void BudgetCars();//(fun7): function that disbly cars list based on the budget chosen by the guest


void CatogriesCars();//(fun8): function that disbly cars list based on the category chosen by the guest

void AllCars(int disply_choise);//(fun9): function that call all the 3 previous cars functions inside of it when the user select how he/she want to see the cars list.

void total (string car_code);// (fun10): function calculate the price based on the guest choosen car code

void print_bill();// (fun11):function that disply the bill in fail for the guest



int main() {
	
	ofstream outFile;
	outFile.open("important.txt",ios::out);
	srand(time(0));
	
	// declaring variables 
	string passowrd = "G3@0rN",Enterd_pass,Enterd_username;
	int pass_choise, disply_choise, user, locat ;
	char confirm, run_agin;
    bool check;
    
   cout<<"Are you: \n1)employee  \n2)guest \n\nChoose (1 or 2): ";
   cin>>user;
   
   //loop to ensure that the program will not run until the user enter a valid menu choice
  while (true){
  	
    if (user ==1 || user == 2){
  		break;}
  		
	else {
	cout<<"You have enterd a wrong value !!"<<endl<<endl;
   	cout<<"Enter agin: \nAre you: \n1) guest  \n2)employee\nChoose (1 or 2): ";
   	cin>>user; }}
	  
	  
   //when the user enter 1, the car rental embloyee system will start:
   if (user== 1){
   	
   employee();}
   
   //otherwise, the guest car rental will start 
   else {
   	cout<<"\n-----------------------------------------------------------------------------------\n";
	cout<<"                       Welcome To Run car rental guest system                       \n";
	cout<<"-----------------------------------------------------------------------------------\n\n";
   	
   getinformation(account);// asking the guest for personal info.
   cout<<endl<<endl;
   
   // making sure that the guest is eligbile: (has a license and the age >=18 ), also the Id & phone number 10 didgit
   if (eligbile(account.age,account.license,account.id,account.phone)==true){
   
cout<<"\n\t\t*************** Hello "<<account.name<<" ***************"<<endl<<endl;

//creating a user name for the guest from the his / her information 
string usrename=account.name+"_"+account.Nationality[0]+account.id[5]+account.Nationality[1]+account.id[6];

    cout<<"Based on your information, here is your username ( "<<usrename <<" ) and for the passowrd:"<<endl;
	cout<<"We suggest this passowrd for you ( G3@0rN ) "<<endl<<endl;
	cout<<"*** If you want the suggested passowrd enter (1), otherwise enter (-1) *** "<<endl;
	// -1 mean that the user wants to creat his / her own pasword.
	cin>>pass_choise; 
	//
	if (pass_choise<0){
		passCond();
		cout<<endl<<"Pleas enter your password: ";
		cin>>passowrd;
		
	//if the guest chooses to enter his/her own passord, we must check that it's valid to enter 
	  check=ValidPass(passowrd);
	}
	
	//if the guest choose the suggested passord, a reminder message will appear in the screen
	else {
		cout<<"your password is { "<<passowrd<<" } please save it for later entrys "<<endl;	
	}
	
	// (chek) is the varible that holds the result of the ValidPass function 
	if (check==true || passowrd=="G3@0rN"){   
	 
    // to print the passowrd and the username for the guest in file to save it for later entrys.
    outFile<<" Hello "<<account.name<<endl;
    outFile<<" This your username and Passowrd to save it or later entrys:\n ";
    outFile<<"The Usrename: "<<usrename<<endl;
    outFile<<"The Password: "<<passowrd<<endl;
    
    //starting the car rental prosses
	do {
	system("CLS"); // to clear the output screen
	
	cout<<endl<<endl<<"\t\t\t****** Welcome to our online car rental program ******"<<endl<<endl;
	cout<<" For security reasons and to make the process of renting your car easier, please enter your own usrename and passowrs:"<<endl<<endl;
	cout<<" *You wiil find your password and username in (important.txt) File * "<<endl<<endl;
	cout<<"1) username: ";
	cin>>Enterd_username;
	cout<<endl<<"2) Password: ";
	cin>>Enterd_pass;
	
	//cheak if the guest enterd a correct username and passowrd to start the car rental prosses:
	if (Entery_verification(usrename,Enterd_username,passowrd,Enterd_pass)){
		
		
		cout<<endl<<endl<<"Successful entry (:"<<endl<<endl<<"welcome "<<account.name<<" How wold you like to rental your car?"<<endl<<endl;
		cout<<"1- Disply ALL available cars "<<endl<<"2- Disply cars based on their categories "<<endl<<"3- Disply cars based on my budget range ";
	
		cout<<endl<<"Please choose one of the following list number:" ;
		cin>>disply_choise;
		
		cout<<endl<<endl;
		AllCars(disply_choise); 
		cout<<"_________________________________________________________________________________"<<endl<<endl<<endl;
	    
		total(car_code); // calculating the price after select a car.
		
	    cout<<"For locating the pick up car location: \n"<<endl; 
	    cout<<"Where you live? \n1)Dammam \n2)Al Khobar\n3)Al Jubail \n";
    	cin>>locat;
    	
    	//loop to ensure tha the guest choose from the menu obtion only.
    	while (true){
    	if (locat ==1 || locat ==2 || locat ==3 ){	
	    break;}
    	else {
		cout<<"You have enterd a wrong value! Please enter your location agin "<<endl;
	    cout<<"Where you live? \n1)Dammam \n2)Al Khobar\n3)Al Jubail \n";
	    cin>>locat;
	    }}
	    
        cout<<endl<<"Do you want to confirm the car rental reguest? (y/n): "<<endl<<endl;
	    cin>>confirm;
	    //the guest must confirm the reguest to print the bill.
	    
	    if (confirm=='y' || confirm=='Y'){
	    	
	    	cout<<endl<<"Thank you for confirming your application. "<<endl;
	    	// display the pick up location:
	     if (locat == 1){
	      Dammam:: location();	
	      }
	      
	    else if(locat == 2){
        Khobar ::  location();	
        }
        
       	else {
		     jubail :: location ();
		     }
	    	
	    cout<<"\n\n ** You wiil find your bil in (Your Bill.txt) File ** ";
	    print_bill(); 
		}
	    
	}
	
	// after one car rental prosses, the program wil ask the guest for another car rntal prosses:
cout<<endl<<endl<<endl<<"Would you like to do another car renting prosses? (y/n): ";
cin>>run_agin;	
}
while (run_agin=='y' || run_agin=='Y' );

}
// when the guest choose to end the program, a closing statments will abear
guest_closing ();
}

// if the guest age <18 or the guest does not have a license, he will not be able to rent a car .
else {
	cout<<endl<<"sorry you are not eligible for car rental";
} }	

		return 0;
}





// employee function contain all the allowed operations for the employee
void employee(){
	
ofstream outofprocesses;

	const int SIZE = 100;
	car info [SIZE];
	int numberOfCars=0, edit, price,temp_price,Deleting=0 , Updating=0 , Adding=0;
    string name,name2,id,car,temp_name;
    bool id_len=false, found=false;
    
	cout<<"\n-----------------------------------------------------------------------------------\n";
	cout<<"                       Welcome To employee Run car rental system                       \n";
	cout<<"-----------------------------------------------------------------------------------\n\n";
	// start taking the employe info:
	
	cout<<"\nPlease enter your First name: ";
   	cin>>name;
   	cout<<"\nPlease enter your Last name: ";
   	cin>>name2;
   	cout<<"\nPleas enter your ID number:";
   	cin>>id;
   	
   	if (id.length()!=10) { // ensure the length of the employe id =10 digits
			while (id_len==false){
			cout<<endl<<"Your ID number must be 10 digit, Try agin."<<endl;
    		cout<<"Enter your ID :";
            cin>>id; 
			if (id.length()==10){
                id_len = true;
				}}}    
				 
   	cout<<"\n";
   	
   	//the employee operation list:
   	string menu="\nChoose operation:\n\t1-Add cars and its price\n\t2-Update car price \n\t3-Delete car\n\t4- print cars price (ascending /descending / enterd order)\n\t5-Exit\n" ;

cout<<menu;
cin>>edit;

while(edit!=5) 
{
switch (edit)
{
case 1: // adding 
if (numberOfCars<SIZE-1)
{
cout<<"Enter car name: ";
cin>>info[numberOfCars].name;
cout<<"Enter car rental price / day: ";
cin>>info[numberOfCars].price;
numberOfCars++;
Adding++;
}

else

cout<<endl<<"You have reached the Maximum limit, You need to delete items to add";

break;

case 2: // updating 
found=false;
cout<<"\nEnter car name to update: ";
cin>>car;
for (int i=0;i<numberOfCars;i++){
if (info[i].name==car)
{
cout<<"Enter new price: ";
cin>>price;
info[i].price=price;
cout<<"\nCar Updated: "<<"\ncar name:"<<info[i].name<<"\tnew price:"<<info[i].price<<endl;
Updating++;
found=true;
break;}}

if (found==false){
	cout<<endl<<"The car: "<<car<<" Was not found! you have to enter a name that already exisit"<<endl;
}


break;

case 3: // deleting
	if (numberOfCars>0)
{
cout<<"Please Enter the name of the car that you want to delet: ";
cin>>car;
for (int i=0;i<numberOfCars;i++){
if (info[i].name==car)
{
for (int j=i;j<numberOfCars-1;j++){
   info[j].name=info[j+1].name;
   info[j].price=info[j+1].price;
	}
numberOfCars--;
cout<<"\nCar is deleted. ";
Deleting ++;
break;
}}}
else {
	cout<<"you dont have any cars.\n\nYou have to enter cars informations to delet."<<endl;
}



break;
case 4:
	int print; //printing cars price in different order
	cout <<"Please choose:\n1)ascending order \n2)descending order \n3)Enterd order"<<endl;
	cin>>print;
	if(print==1){
		for(int i=0;i<numberOfCars-1;i++){ //price in ascending order
       for(int j=0;j<numberOfCars-1;j++){
           if (info[j].price>info[j+1].price){
           	temp_price=info[j].price;
            temp_name=info[j].name;
            info[j].price=info[j+1].price;
            info[j].name=info[j+1].name;
            info[j+1].price=temp_price;
            info[j+1].name=temp_name;
			}}}
      cout<<"price in ascending order: "<<endl;
    for(int i=0;i<numberOfCars;i++){
        cout<<info[i].name<<"  "<<info[i].price<<endl;
    } 
		
		
	}
	else if (print==2) { // price in descending order
		
		for(int i=0;i<numberOfCars-1;i++){
       for(int j=0;j<numberOfCars-1;j++){
           if (info[j].price<info[j+1].price){
           	temp_price=info[j].price;
            temp_name=info[j].name;
            info[j].price=info[j+1].price;
            info[j].name=info[j+1].name;
            info[j+1].price=temp_price;
            info[j+1].name=temp_name;
      }}}
      
      cout<<"price in descending order: "<<endl;
    for(int i=0;i<numberOfCars;i++){
        cout<<info[i].name<<"  "<<info[i].price<<endl;
    }}
    
    else {
    	cout<<"price in Enterd order: "<<endl; //Enterd order = without sorting 
    	for(int i=0;i<numberOfCars;i++){
        cout<<info[i].name<<"  "<<info[i].price<<endl;
	}}
break;

	
default:
cout<<"\nIncorrect menu option.";
}
cout<<menu;
cin>>edit;
}

if(edit==5){
	
       	employee_closing ();//closing statments 
		   
		   // printing the employee work report in fail :
		    
	       outofprocesses.open("Employee Report.txt", ios::out);
			if(outofprocesses.is_open()==true||outofprocesses.is_open())
			{
			outofprocesses<<"---------------------------------------------------\n";		
			outofprocesses<<"\t  Employee Name: "<<name<<" "<<name2<<endl<<endl;
			outofprocesses<<"\t  Employee ID :"<<id<<endl<<endl;
			outofprocesses<<"---------------------------------------------------\n";	
			outofprocesses<<"\t\t\n\tOperations performed by the employee: \n\n";	
		    outofprocesses<<"---------------------------------------------------\n";	
			outofprocesses<<"\tAdding items: ( "<<Adding<<" ) items "<<endl<<endl;
    		outofprocesses<<"\tDeleting items: ( "<<Deleting<<" ) items"<<endl<<endl;
	    	outofprocesses<<"\tUpdating items:  ( "<<Updating<<" ) items"<<endl<<endl;
			outofprocesses<<"---------------------------------------------------\n";	
            outofprocesses<<"The final form for the items (cars names and prices):\n";
            if (numberOfCars<=0){
            outofprocesses<<"   There is no registered cars "<<endl;
			}
			else{
               	for(int i=0;i<numberOfCars;i++){
                 outofprocesses<<info[i].name<<"  "<<info[i].price<<" SR "<<endl;
	        }
	        outofprocesses<<"---------------------------------------------------\n";	
			}}

		outofprocesses.close();	
}
}	



// guest info :
void getinformation(information & account) {
cout<<"Enter your First name: ";
cin>>account.name;
cout<<"Enter your Last name: ";
cin>>account.name2;
cout<<"Enter your age: ";
cin>>account.age;
cout<<"Enter your National ID: ";
cin>>account.id;
cout<<"The gender (F or M): ";
cin>>account.gender;
cout<<"Do you have license? (Y or N): ";
cin>>account.license;
cout<<"The Nationality: ";
cin>>account.Nationality;
cout<<"Enter phone number:";
cin>>account.phone;
}

// function ensure that the guset age >=18, and that he /she have a license , and that the Id and phone number = 10 digits

bool eligbile (int age,char license, string id,string phone){
	bool id_len = false, phone_len=false;
	if (age >=18 && ( license=='y' || license=='Y')){
		if ( (id.length()==10) && (phone.length()==10) ){
		return true;}
		
		else if (id.length()!=10) {
				while (id_len==false){
				cout<<endl<<"Your ID number must be 10 digit, Try agin."<<endl;
    			cout<<"Enter your National ID :";
                cin>>id; 
                account.id=id;
				if (id.length()==10){
                id_len = true;
				}}}     
				
		  if (phone.length()!=10){
			while ( phone_len==false ){
				cout<<endl<<"Your Phone number must be 10 digit, Try agin."<<endl;
    			cout<<"Enter Your phone number :";
                cin>>phone;
                account.phone=phone;
                if (phone.length()==10){
                	phone_len = true;
                	return true;
				}}}
				
			else {
					return true;}
	}
	else {
		return false;}	
}


bool ValidPass(string &password){
	bool length=false, letter=false, digit=false, symbol=false, result=false, captil=false;
	if (password.length()>=6){
		length=true;
		for (int i=0;i<password.length();i++){
			if (isalpha(password[i])){
				letter=true;
			}
			if (isdigit(password[i])){
				digit=true;	
		    }
		    if (isupper(password[i])){
			captil=true;
			}
		     
		    if (password[i]=='@' || password[i]=='#' || password[i]=='&' || password[i]=='%' || password[i]=='$'){
				symbol=true;	
		    }
	}}
		if (length && letter &&  digit && symbol){

			cout<<endl<<"your password { "<<password<<" } is valid please save it for later entrys "<<endl;
			return true;	
		}
		else {
		cout<<endl<<"your password is not valid";
		cout<<endl<<"Please enter again: ";
   	    cin>>password;
   	    ValidPass (password);}//calling the function again to ensure the user enter a valid password

}



bool Entery_verification (string username,string Enterd_username,string pass, string Enterd_pass){
	bool trueusrname=false, truepass=false;
		if (username.compare(Enterd_username)==0){
			trueusrname=true;
		}
		else {
			cout<<"incorect username"<<endl;
		}
		if (pass.compare(Enterd_pass)==0){
			truepass=true;
		}
		else {
			cout<<"incorect password"<<endl;
		}	
		
		if (trueusrname && truepass){
			return true;
		}
		else {
		 return false;	
		}
}


void AllCars (){
	
 string printAllCars;
	ifstream input;
	input.open("AllCars.txt");
    for(int i=0 ;i<33;i++){
	getline(input,printAllCars);
	cout<<printAllCars<<endl;}
	input.close();
cout<<endl<<endl<<"Choose the leter and the number that is behind the car you want. For instanse (F1) *Capital letter only* : ";
cin>>car_code;
}

	

void BudgetCars(){
int choise;
cout<<"Please enter the number of the price range that you want:   "<<endl;
cout<<	"1)-[125 SR - 170 SR]  "<<"2)-[175 SR - 599 SR]  "<<"3)-[697 SR - 1975 SR]  "<<endl;
cin>>choise;
switch (choise){
	case 1:
	
	cout<<"\t\t\t _______________________________________________________\n";
cout<<"\t\t\t|                      125-170                          |\n";
cout<<"\t\t\t|_______________________________________________________|\n";
cout<<"\t\t\t|E5) Suzuki Dzire 2023       |   (125 SR/day)           |\n";                                   
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|E3) NISSAN SUNNy 2022       |   (127 SR/day)           |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|E1) HyUNDAIELANTRA 2020     |   (135 SR/day)           |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|E4) Toyota yaris 2022       |   (144.87 SR/day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|F1) NISSAN Kicks 2022       |    (170 SR/day)          |\n";
cout<<"\t\t\t|____________________________|__________________________|"<<endl;	
	cout<<endl<<endl<<"Choose the leter and the number that is behind the car you want. For instanse (E1) *Capital letter only* : ";
   cin>>car_code;
		
		break;
	case 2:	
	cout<<"\t\t\t _______________________________________________________\n";
cout<<"\t\t\t|                       175-599                         |\n";
cout<<"\t\t\t|_______________________________________________________|\n";
cout<<"\t\t\t|F2)Toyota Corolla Cross2022 |   (176.18 SR/day)        |\n";                                   
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|F3) HYUNDAI kona 2021       |   (216.31 SR/day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|F4) CHEVROLET suburban 2018 |   (407 SR/day)           |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|S5) Hyundai Elantra 2020    |   (429.74 SR/day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|L4) Lexus ES250 2020        |    (500 SR/day)          |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|S3) Ford Eco Sport 2022     |   (514.70 SR/day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|F5) BMW X2 2023             |    (599 SR/day)          |\n";
cout<<"\t\t\t|____________________________|__________________________|"<<endl;

cout<<endl<<endl<<"Choose the leter and the number that is behind the car you want. For instanse (F3) *Capital letter only* : ";
cin>>car_code;
	
		break;
	case  3:	
	cout<<"\t\t\t _______________________________________________________\n";
cout<<"\t\t\t|                       697-1975                        |\n";
cout<<"\t\t\t|_______________________________________________________|\n";
cout<<"\t\t\t|S1) AUDI A6 2022.           |   (697 SR/day)           |\n";                                   
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|S4) Toyota RAV4 2023        |   (852.70 SR/day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|L3)MiniCooper Convertible22 |   (1173   SR/day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|S2) Range Rover Velar 2020  |   (1333 SR/day)          |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|L1) BMW 2020                |    (1440 SR/day)         |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|L5) Genesis GV80 2023       |    (1444 SR/day)         |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|L2) Mercedes S450 2020      |    (1975 SR/day)         |\n";
cout<<"\t\t\t|____________________________|__________________________|"<<endl;
 cout<<endl<<endl<<"Choose the leter and the number that is behind the car you want. For instanse (L1) *Capital letter only* : ";
cin>>car_code;
	    break;
	    
	default:
		cout<<" you have to enter a number from 1 to 3 onlay";
	
}}


void CatogriesCars(){  
int choise;
cout<<"Please enter the number of the Catogrie that you want:   "<<endl;
cout<<	"1-Family  "<<"2-Econmic  "<<"3-Sport  "<<"4-Lexury"<<endl;
cin>>choise;
switch (choise){
	case 1:
cout<<"\t\t\t _______________________________________________________\n";
cout<<"\t\t\t|                         Family                        |\n";
cout<<"\t\t\t|_______________________________________________________|\n";
cout<<"\t\t\t|  F1)"<<" NISSAN Kicks-2022        |   (170 SR/day)        |\n";                                   
cout<<"\t\t\t|_______________________________|_______________________|\n";
cout<<"\t\t\t|  F2)"<<" Toyota Corolla Cross-2022|   (176.18 SR / day)   |\n";
cout<<"\t\t\t|_______________________________|_______________________|\n";
cout<<"\t\t\t|  F3)"<<" HYUNDAI kona-2021        |   (216.31 SR /day)    |\n";
cout<<"\t\t\t|_______________________________|_______________________|\n";
cout<<"\t\t\t|  F4)"<<" CHEVROLET suburban-2018  |   (407 SR /day)       |\n";
cout<<"\t\t\t|_______________________________|_______________________|\n";
cout<<"\t\t\t|  F5)"<<" BMW X2-2023              |   (599 SR /day)       |\n";
cout<<"\t\t\t|_______________________________|_______________________|";

cout<<"\n\n";

cout<<"Choose the leter and the number that is behind the car you want. For instanse (F1) *Capital letter only* :";
cin>>car_code;
		break;
		
	case 2:	
	
cout<<"\t\t\t _______________________________________________________\n";
cout<<"\t\t\t|                       Econmic                         |\n";
cout<<"\t\t\t|_______________________________________________________|\n";
cout<<"\t\t\t|  E1)"<<" HYUNDAI ELANTRA-2020   |   (135 SR/day)          |\n";                                   
cout<<"\t\t\t|_____________________________|_________________________|\n";
cout<<"\t\t\t|  E2)"<<" KIA CERATO-2021        |   (162.76 SR/day)       |\n";
cout<<"\t\t\t|_____________________________|_________________________|\n";
cout<<"\t\t\t|  E3)"<<" NISSAN SUNNY-2022      |   (127 SR/day)          |\n";
cout<<"\t\t\t|_____________________________|_________________________|\n";
cout<<"\t\t\t|  E4)"<<" Toyota yaris-2022      |   (144.87 SR/day)       |\n";
cout<<"\t\t\t|_____________________________|_________________________|\n";
cout<<"\t\t\t|  E5)"<<" Suzuki Dzire-2023      |   (125 SR/day)          |\n";
cout<<"\t\t\t|_____________________________|_________________________|";
	
cout<<"\n\n";
cout<<"Choose the leter and the number that is behind the car you want. For instanse (E1) *Capital letter only* : ";
cin>>car_code;
		break;
		
		
	case 3:	
cout<<"\t\t\t _______________________________________________________\n";
cout<<"\t\t\t|                           Sport                       |\n";
cout<<"\t\t\t|_______________________________________________________|\n";
cout<<"\t\t\t|  S1)"<<" AUDI A6-2022          |   (697 SR/day)           |\n";                                   
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|  S2)"<<" Range Rover Velar-2020|   (1333 SR/day)          |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|  S3)"<<" Ford Eco Sport-2022   |   (514.70 SR/day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|  S4)"<<" Toyota RAV4-2023      |   (852.70 SR/day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|  S5)"<<" Hyundai Elantra-2020  |  (429.74 SR/day)         |\n";
cout<<"\t\t\t|____________________________|__________________________|";

	cout<<"\n\n";
	cout<<"Choose the leter and the number that is behind the car you want. For instanse (S1) *Capital letter only* : ";
    cin>>car_code;
	    break;
	    
	case 4:	
cout<<"\t\t\t _______________________________________________________\n";
cout<<"\t\t\t|                        Lexury                         |\n";
cout<<"\t\t\t|_______________________________________________________|\n";
cout<<"\t\t\t|  L1)"<<" BMW-2020              |   (1440 SR/day)          |\n";                                   
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|  L2)"<<"  Mercedes S450-2020   |   (1975 SR/day)          |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|  L3)"<<" Mini_Convertible-2022 |   (1173 SR/2 day)        |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|  L4)"<<" Lexus ES250-2020      |   (500 SR/day)           |\n";
cout<<"\t\t\t|____________________________|__________________________|\n";
cout<<"\t\t\t|  L5)"<<" Genesis GV80-2023     |   (1444 SR/day)          |\n";
cout<<"\t\t\t|____________________________|__________________________|";	

cout<<"\n\n";
cout<<"Choose the leter and the number that is behind the car you want. For instanse (L1) *Capital letter only* : ";
cin>>car_code;
		break;
	
	default:
		cout<<" you have to enter a number from 1 to 4 onlay";
	
	
}}


void AllCars(int disply_choise){
	switch (disply_choise){
	case 1:
	
		AllCars ();
		break;
		
	case 2:	
	
	CatogriesCars();
		break;
		
	case 3:	
	
	BudgetCars();
	    break;
	    
	default:
		cout<<" you have to enter a number from 1 to 3 onlay";	
}}



void total (string car_code){
string cars_code[4][5]={{"F1","F2","F3","F4","F5"},{"E1","E2","E3","E4","E5"},
{"S1","S2","S3","S4","S5"},{"L1","L2","L3","L4","L5"}};
double cars_price[4][5]={{170,176.18,216.31,407,599},{135,162.76,127,144.87,125},
{697,1333,514.70,852.70,429.74},{1440,1975,1173,500,1444}};
for (int i=0;i<4;i++){
	for (int j=0;j<5;j++){
		if (cars_code[i][j]==car_code){
			*p = cars_price[i][j];
		    break;}}}

cout<<endl<<"How many days do you want to rent the car?";
cin>>days;

    *p*=days;
	cout<<endl<<endl;
	
	//This part it is for display the menu for the user to choose the type of insurance :
	cout<<"Pleas choose the type of insurance frome the list:"<<endl<<endl;
	cout<<"{ 1)- Third Party (650 SR).  2)- Comprehensive (750 SR).  3)- no insurance }:";
	cin>>choose_insurance;
switch(choose_insurance) {
	case 1:
		*p+=650;
	 break;
	 
	case 2:
		*p+=750;
	 break;
	 
	case 3:
		*p+=0;
	 break;
	  	
	default:
		cout<<"Pleas choose from the list!!\n";
}

//This part it is for display a menu about payment Methods for the user to choose from:
 	double discount;
	cout<<"\nHow would you like the payment Method:"<<endl<<endl;
	cout<<"{ 1)- cash   2)- mada card - You will get 5% discount.   3)- Prepaid - You will get 10% discount. }: ";
	cin>>choose_paymentMethod;
	switch(choose_paymentMethod) {
		case 1:
	    	//The price without discount: "
	    	// no change on the price value
	    	break;
	
		case 2:
			//The price with discount 5% : "
		discount=(*p*5)/(100);
		*p-=discount;
		break;
			
		case 3:
			//The price with discount 10% :"
		discount=(*p*10)/(100);
		*p-=discount;
		break;
		 			
	default:
		//if the user enter a wrong choose:
		cout<<"\nPlease choose the number of list!!";
}
   
}


// printing the guest bill in filae
void print_bill(){
	ofstream outFile2;
	outFile2.open("Your Bill.txt", ios::out);

    outFile2<<"\t\t********[Your Bill]*******\n";
    outFile2<<"\t\tClint name: ";
    outFile2<<account.name<<" "<<account.name2;
    outFile2<<endl;
    outFile2<<"\t\tClint National ID: ";
    outFile2<<account.id;
    outFile2<<endl;
    outFile2<<"\t\tgender:  ";
    if(account.gender=='F'|| account.gender=='f'){
	outFile2<<"Female";
    }
    else{
	outFile2<<"Male";
    }
   outFile2<<endl;
   outFile2<<"\t\tNationality:   ";
   outFile2<<account.Nationality;
   outFile2<<endl;
   outFile2<<"\t\tPhone number: ";
    outFile2<<account.phone;
    outFile2<<endl;
   outFile2<<"\t\t---------------------------------------------------------\n";
   outFile2<<"\t\tThe chosen insurance:  ";
   if(choose_insurance==1){
 	outFile2<<" THE THIRD PARTY "<<endl;
   }
   else if(choose_insurance==2){
	outFile2<<" COMPREHENSIVE"<<endl;
    }
   else{
	outFile2<<" NO INSURANCE "<<endl;
   }	
outFile2<<endl;
outFile2<<"\t\t---------------------------------------------------------\n";	
outFile2<<"\t\tPayment mothod :  ";
if(choose_paymentMethod ==1){
	outFile2<<" CASH"<<endl;
}
else if(choose_paymentMethod ==2){
	outFile2<<" MADA CARD - WITH 5% DISCOUNT"<<endl;
}
else if(choose_paymentMethod ==3){
	outFile2<<" Prepaid PREPAID - WITH 10% DISCOUNT ";
}
outFile2<<"\n";
outFile2<<"\t\t---------------------------------------------------------\n";
	
   outFile2<<"\t\tThe total price for ("<<days<<") days is:  ";	
   outFile2<<price<<" SR ";
  outFile2.close(); 

}
