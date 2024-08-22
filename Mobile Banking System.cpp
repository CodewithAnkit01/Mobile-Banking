#include<iostream>
#include<conio.h> // using for getch function
#include<windows.h> // using Sleep function
using namespace std;
class banking{
	int completed;
	string id;
	struct customer{
		string ID,phone, name, fname, address, idcard;
		int cash;
	}customer[100]; // for access str member
	public:
		banking(){
			completed=0;
		}
	public:
		void options();
		void newaccount();
		void display();
		void update();
		void search();
		void transaction();
		void logout();
};



int main(){
	string Uname, Uname1;
	int pin,pin1;
	cout<<"\n\n\n\t\t\t\t\t\t Bank Management System \n\n\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t\t\t\t\t\tSign Up Here \n\n";
	cout<<" Enter Your Name: ";
	cin>>Uname;
	cout<<" Enter Your 4 Digit Pin: ";
	cin>>pin;
	cout<<" Your Account is Creating. Please Wait!! ";
	for(int i=0;i<2;i++){
		cout<<".";
		Sleep(1000); // using to give message to user after 3 seconds
	}
	cout<<endl;
	cout<<" Your Account is Creating Successfully";
	system("CLS"); // FOR NEW SCREEN
	previouslogin: 
	cout<<"\n\t\t\t\t\t\t\t Login Here \n";
    cout<<" Enter Your Name: ";
	cin>>Uname1;
	cout<<" Enter Your 4 Digit Pin: ";
	cin>>pin1;
	if(Uname1==Uname && pin1==pin){
		system("CLS");
		banking obj;
		obj.options();
	}
	else if (Uname1!=Uname){
	    cout<<" Incorrect Username !";
	    goto previouslogin;
     }
     else if (pin1!=pin){
	    cout<<" Incorrect Pin !";
	   goto previouslogin;
     }
	return 0;
	
}
void banking::options(){
	char select;
	while(1){
	cout<<"\n\n\n\t\t\t\t\t\t Bank Options \n\n\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";
	cout<<" Press 1 For Creating New Account. "<<endl;
	cout<<" Press 2 Display the Customer Information. "<<endl;
	cout<<" Press 3 For Updating Customer Information. "<<endl;
	cout<<" Press 4 For Searching the Specific Customer. "<<endl;
	cout<<" Press 5 For Transaction Operation Like Deposit and Withdraw. "<<endl;
	cout<<" Press 6 For Logout. "<<endl;
	select=getch(); // what options select by user
	switch(select){
		case'1':
			banking::newaccount();
			system("CLS");
			break;
			case'2':
			system("CLS");
			banking::display();
			break;
			case'3':
				system("CLS");
			banking::update();
			break;
			case'4':
				system("CLS");
			banking::search();
			break;
			case'5':
				system("CLS");
			banking::transaction();
			break;
			case'6':
				system("CLS");
			banking::logout();
			break;
				cout<<"Invalid Operation !";
				break;
       	}
    }
}

void banking::newaccount(){
	cout<<"\n\n\n\t\t\t\t\t\t For New Account \n\n\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n New Account Creating. "<<endl;
	cout<<"Enter the Record of " <<completed+1<<" Customer "<<endl;
	cout<<"Enter Your ID: ";
	cin>>customer[completed].ID;
	cout<<"Enter Your Name: ";
	cin>>customer[completed].name;
	cout<<"Enter Your Father Name: ";
	cin>>customer[completed].fname;
	cout<<"Enter Your Phone Number: ";
	cin>>customer[completed].phone;
	cout<<"Enter Your ID Card Number: ";
	cin>>customer[completed].idcard;
	cout<<"Enter Your Cash: ";
	cin>>customer[completed].cash;
	completed++;
}
void banking::display(){
	for(int i=0;i<completed;i++){
		cout<<"\n\n\n\t\t\t\t\t\t Customer Data \n\n\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";
	cout<<"Record of "<<" customer."<<endl;
	cout<<"Customer Unique ID:"<<customer[i].ID<<endl;
	cout<<"Customer Name:"<<customer[i].name<<endl;
	cout<<"Customer Father Name:"<<customer[i].fname<<endl;
	cout<<"Customer Phone Number:"<<customer[i].phone<<endl;
	cout<<"Customer ID Card Number:"<<customer[i].idcard<<endl;
	cout<<"Customer Amount:"<<customer[i].cash<<endl;
	i++;
	}
}
void banking::update(){
	cout<< "Enter the id of customer for updating the Information:";
	cin>>id;
	 bool found = false;
	for(int i=0;i<completed;i++){
		if(id==customer[i].ID){
			found = true;
	cout<<"\n\n\n\t\t\t\t\t\t For Update a Customer Data \n\n\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";		
	cout<<"Existing Record of "<<" Customer."<<endl<<endl;
	cout<<"Customer Unique ID:"<<customer[i].ID<<endl;
	cout<<"Customer Name:"<<customer[i].name<<endl;
	cout<<"Customer Father Name:"<<customer[i].fname<<endl;
	cout<<"Customer Phone Number:"<<customer[i].phone<<endl;
	cout<<"Customer ID Card Number:"<<customer[i].idcard<<endl;
	cout<<"Customer Amount:"<<customer[i].cash<<endl;
	
	cout<<"\n\n Updating the Customer Information. "<<endl;
	cout<<"Enter Your ID: ";
	cin>>customer[i].ID;
	cout<<"Enter Your Name: ";
	cin>>customer[i].name;
	cout<<"Enter Your Father Name: ";
	cin>>customer[i].fname;
	cout<<"Enter Your Phone Number: ";
	cin>>customer[i].phone;
	cout<<"Enter Your ID Card Number: ";
	cin>>customer[i].idcard;
	cout<<"Enter Your Cash: ";
	cin>>customer[i].cash;
	completed++;
			
		}
		if(!found){
		cout<<"Customer Record NOT FOUND!"<<endl;
	}
	}
}
void banking::search(){
	cout<< "Enter the id of customer for searching the Information:";
	cin>>id;
	 bool found = false;
	for(int i=0;i<completed;i++){
	if(id==customer[i].ID){
		found = true;
		cout<<"\n\n\n\t\t\t\t\t\t Customer Data \n\n\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";
		
	cout<<" Customer Record Found "<<endl<<endl;
	cout<<"Customer Unique ID:"<<customer[i].ID<<endl;
	cout<<"Customer Name:"<<customer[i].name<<endl;
	cout<<"Customer Father Name:"<<customer[i].fname<<endl;
	cout<<"Customer Phone Number:"<<customer[i].phone<<endl;
	cout<<"Customer ID Card Number:"<<customer[i].idcard<<endl;
	cout<<"Customer Amount:"<<customer[i].cash<<endl;
	 
	}

	
	if(!found){
		cout<<"Customer Record NOT FOUND!"<<endl;
	}
}
}
void banking::transaction(){
	char select;
	 bool found = false;
	int cash1;
	cout<< "Enter the id of customer for searching the Information:";
	cin>>id;
	for(int i=0;i<completed;i++){
	if(id==customer[i].ID){
		found = true;
		cout<<"\n\n\n\t\t\t\t\t\t For Transaction Amount \n\n\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";
	cout<<" Customer Record Found "<<endl<<endl;
	cout<<"Customer Name:"<<customer[i].name<<endl;
	cout<<"Customer Existing Amount:"<<customer[i].cash<<endl;
	cout<<"Press 1 for deposit amount : "<<endl;
	cout<<"Press 2 for withdraw amount : "<<endl;
	select=getch();
	switch(select){
		case'1':
	cout<< "Enter the Amount for deposit:";
	cin>>cash1;
	cout<<"Your Transaction is Processing Please Wait !"<<endl;
	Sleep(3000);
	customer[i].cash+=cash1;
	cout<<" Transaction DONE !"<<endl;
	cout<<"New Amount: "<<customer[i].cash<<endl;
	break;
	case'2':
		previouswithdraw:
	cout<< "Enter the Amount for Withdraw:";
	cin>>cash1;
	if(cash1>customer[i].cash){
		cout<<"Your Amount is greater than existing Amount !";
		goto previouswithdraw;
	}
	cout<<"Your Transaction is Processing Please Wait !";
	Sleep(3000);
	customer[i].cash-=cash1;
	cout<<" Transaction DONE !"<<endl;
	cout<<"Existing Amount: "<<customer[i].cash<<endl;
	break;
			
	}
	
	}
		
		if(!found){
		cout<<"Customer Record NOT FOUND!"<<endl;
	}
		
	}
}
void banking::logout(){
	exit(0);
}



   
	

