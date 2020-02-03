
///Header file
#include <iostream>///basic I/O
#include <fstream> ///for file manipulation

using namespace std;

///data structure to store sick and doctor
struct doctor{
	
	int code;
	string name;
	string family;
	string phone;
	string special;

};

struct sick{
	
	int sickCode;
	int doctorCode;
	string name;
	string family;
	string phone;

};
///

///sick functions prototypes
void removeSick();
void removeSickbydocid(int);
void editSick();
void insertSick();
void sortSick(struct sick[], int);
void listSick();
void listSickAsending();
///end sick

///doctor functions prototypes
void editDoctor();
void searchDoctor();
void insertDoctor();
void removeDoctor();
void sortDoctor(struct doctor[], int);
void listDoctor();
///end doctor

///File I/O functions prototypes
void syncDoctor();
void syncSick();
///

///Helper functions prototypes
void printSick();
void printDoctor();
void resetDatabase();
///

///Credential check function prototype
int credential();
///

///UI
void menu();
void enter();
void sickMenu();
void doctorMenu();
void cls();
///

int main(){
	
	menu();
	
	return 0;
}

void syncDoctor(){	
	///rename file
    if (rename("docback.txt", "doctor.txt")) {
        perror("Error renaming");
    }		
}

void syncSick(){

    if (rename("sickback.txt", "sick.txt")) {
        perror("Error renaming");
    }
}

void removeSick(){
	
	cout << "Remove Sick " << endl;

	ofstream outfile;
	outfile.open("sickback.txt", ios::trunc);

	ifstream file("sick.txt");
    int rmsick=0;
     
    cout<<"Enter sick ID to remove: ";
    cin>>rmsick;    
      
    struct sick sick[100];  
		
    int i=0;
    
    while (file >> sick[i].sickCode)
	{
		file >> sick[i].doctorCode;		
		file >> sick[i].name;
		file >> sick[i].family;
		file >> sick[i].phone;
		
		if (sick[i].sickCode != rmsick){
			outfile<<sick[i].sickCode<<" "<<sick[i].doctorCode<<" "<<sick[i].name<<
			" "<<sick[i].family<<" "<<sick[i].phone<<endl;			
		}
		
		i++;
	}

	syncSick();
	
}

void removeSickbydocid(int id){
	
	ofstream outfile;
	outfile.open("sickback.txt", ios::trunc);

	ifstream file("sick.txt");
     
    int rmsick=id; 
       
    struct sick sick[100];  		

    int i=0;
    
    while (file >> sick[i].sickCode)
	{
		file >> sick[i].doctorCode;
		file >> sick[i].name;
		file >> sick[i].family;
		file >> sick[i].phone;
		
		if (sick[i].doctorCode != rmsick){
			outfile<<sick[i].sickCode<<" "<<sick[i].doctorCode<<" "<<sick[i].name<<
			" "<<sick[i].family<<" "<<sick[i].phone<<endl;	
		}
		
		i++;
	}

	syncSick();
	
}

void editSick(){
	
	cout << "Edit Sick " << endl;

	ofstream outfile;
	outfile.open("sickback.txt", ios::trunc); // trunc to remove file contents

	ifstream file("sick.txt");

    int edsick=0;    
    cout<<"Enter sick ID to edit: ";
    cin>>edsick;
       
    struct sick sick[100];  
		
    int i=0;
    
    while (file >> sick[i].sickCode)
	{
		
		file >> sick[i].doctorCode;
		file >> sick[i].name;
		file >> sick[i].family;
		file >> sick[i].phone;
		
		if (sick[i].sickCode==edsick){

			///sick[i].sickCode=id;/// id not change
				
			cout<<"Enter doctorCode: ";
			cin >>sick[i].doctorCode;
			
			cout<<"Enter name: ";
			cin>>sick[i].name;
			
			cout<<"Enter family: ";
			cin >>sick[i].family;
			
			cout<<"Enter phone: ";
			cin>>sick[i].phone;

		}
		
		outfile<<sick[i].sickCode<<" "<<sick[i].doctorCode<<" "<<sick[i].name<<
		" "<<sick[i].family<<" "<<sick[i].phone<<endl;		
		
		i++;
	}

	syncSick();
	
}

void insertSick(){ 
	
	cout << "Insert Sick " << endl;
	
	ofstream outfile;
	outfile.open("sick.txt", ios::app); 
	
	struct sick sk1;
	
	cout<<"Enter code: ";
	cin >>sk1.sickCode;
	
	cout<<"Enter doctorCode: ";
	cin >>sk1.doctorCode;
	
	cout<<"Enter name: ";
	cin>>sk1.name;
	
	cout<<"Enter family: ";
	cin >>sk1.family;
	
	cout<<"Enter phone: ";
	cin>>sk1.phone;
	
	cout<<"You Enter: "<<sk1.sickCode<<" "<<sk1.doctorCode<<"  "<<sk1.name<<" "<<sk1.family 
		<<" " <<sk1.phone  <<"  " <<"\n";

	outfile << sk1.sickCode<<" "<<sk1.doctorCode<<" "<<sk1.name<<" "<<sk1.family<<" "<<
	sk1.phone<<endl;
	
}

void sortSick(struct sick dk[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
		{
			if(dk[j].sickCode>dk[j+1].sickCode)
			{
					struct sick temp=dk[j];
					dk[j]=dk[j+1];
					dk[j+1]=temp;
			}

		}
}

void listSickAsending(){

	cout << "List Sick asending ..." << endl;

	ifstream file("sick.txt");
    	
    struct sick sick[100];  
	int i=0;

    while (file >> sick[i].sickCode)
	{
		file >> sick[i].doctorCode;
		
		file >> sick[i].name;
		file >> sick[i].family;
		
		file >> sick[i].phone;
				
		i++;
	}
	
	sortSick(sick, i);
	
	cls();
	
	///print sorted
	for (int j=0;j<i;j++){
			cout<<sick[j].sickCode<<" "<<sick[j].doctorCode<<" "<<sick[j].name<<
			" "<<sick[j].family<<" "<<sick[j].phone<<endl;			
	}
	
}

void listSick(){
	
	cout << "List Sick " << endl;

	ifstream file("sick.txt");

    int edsick=0;    
    cout<<"Enter doctor ID to list sicks: ";
    cin>>edsick;
    	
    struct sick sick[100];  
    struct sick tmpsk[100];   

	int i=0;
    int j=0;
    
    while (file >> sick[i].sickCode)
	{
		file >> sick[i].doctorCode;
		
		file >> sick[i].name;
		file >> sick[i].family;
		
		file >> sick[i].phone;
		
		if (sick[i].doctorCode==edsick){
			
			tmpsk[j]=sick[i];
			j++;
		}
		
		i++;
	}
	
	sortSick(tmpsk, j);
	
	cls();
	
	///print sorted
	for (int i=0;i<j;i++){
			cout<<tmpsk[i].sickCode<<" "<<tmpsk[i].doctorCode<<" "<<tmpsk[i].name<<
			" "<<tmpsk[i].family<<" "<<tmpsk[i].phone<<endl;			
	}

}

void editDoctor(){
	
	cout << "Edit Doctor " << endl;

	ofstream outfile;
	outfile.open("docback.txt", ios::trunc); 
	
	ifstream file("doctor.txt");
    
    int number=0;   
    cout<<"Enter doctor ID to edit: ";
    cin>>number;      
    
    struct doctor doctor[100];  
    
    int i=0;
    
    while (file >> doctor[i].code)
	{
		file >> doctor[i].name;
		file >> doctor[i].family;
		file >> doctor[i].phone;
		file >> doctor[i].special;
		
		if (doctor[i].code==number){	
			
			//doctor[i].code=id;
			cout<<"Enter name: ";
			cin>>doctor[i].name;
			
			cout<<"Enter family: ";
			cin >>doctor[i].family;
			
			cout<<"Enter phone: ";
			cin>>doctor[i].phone;
			
			cout<<"Enter special: ";
			cin>>doctor[i].special;
		}

		outfile << doctor[i].code<<" "<<doctor[i].name<<" "<<doctor[i].family 
			<<" " <<doctor[i].phone  <<"  "<<doctor[i].special<<endl;
	
		i++;
	}
	
	syncDoctor();
	
}

void searchDoctor(){
	
	cout << "Search Doctor " << endl;

	ifstream file("doctor.txt");
    
    int number=0;
    cout<<"Enter doctor ID to show: ";
    cin>>number;        
    
    struct doctor doctor[100];  
    
    int i=0;
    
    while (file >> doctor[i].code)
	{
		file >> doctor[i].name;
		file >> doctor[i].family;
		file >> doctor[i].phone;
		file >> doctor[i].special;
		
		if (doctor[i].code==number){
			
			cout<<doctor[i].code<<" "<<doctor[i].name<<" "<<doctor[i].family<<
			" "<<doctor[i].phone<<doctor[i].special<<endl;			
			return;
		}
		
		i++;
	}
	
	cout<<"Doctor with id: "<<number<<"   Not found ...\n";

}

void insertDoctor(){ 

	cout << "Insert Doctor " << endl;

	ofstream outfile;
	outfile.open("doctor.txt", ios::app);
	
	struct doctor dk1;
	
	cout<<"Enter code: ";
	cin >>dk1.code;
	
	cout<<"Enter name: ";
	cin>>dk1.name;
	
	cout<<"Enter family: ";
	cin >>dk1.family;
	
	cout<<"Enter phone: ";
	cin>>dk1.phone;
	
	cout<<"Enter special: ";
	cin>>dk1.special;

	cout<<"You Enter: "<<dk1.code<<" "<<dk1.name<<" "<<dk1.family 
		<<" " <<dk1.phone  <<"  "<<dk1.special<<"\n";

	outfile << dk1.code<<" "<<dk1.name<<" "<<dk1.family 
		<<" " <<dk1.phone  <<"  "<<dk1.special<<endl;	
	
}

void removeDoctor(){
	
	cout << "Remove Doctor " << endl;

	ofstream outfile;
	outfile.open("docback.txt", ios::trunc);
	
	ifstream file("doctor.txt");
    
    int rmdoc=0; 
    cout<<"Enter doctor ID to remove: ";
    cin>>rmdoc;
       
    struct doctor doctor[100];  
    
    int i=0;
    
    while (file >> doctor[i].code)
	{
		file >> doctor[i].name;
		file >> doctor[i].family;
		file >> doctor[i].phone;
		file >> doctor[i].special;
			
		if (doctor[i].code==rmdoc){
			
			removeSickbydocid(rmdoc);
			
		}else {///write to temp file, this implement remove function
			
			outfile<<doctor[i].code<<" "<<doctor[i].name<<" "<<doctor[i].family<<
			" "<<doctor[i].phone<<" "<<doctor[i].special<<endl;	
		}
		
		i++;
	}

	syncDoctor();

}

///sort doctors by name, array call by reference
void sortDoctor(struct doctor dk[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
		{
			if(dk[j].family>dk[j+1].family)
			{
					struct doctor temp=dk[j];
					dk[j]=dk[j+1];
					dk[j+1]=temp;
			}

		}
}

void listDoctor(){
	
	cls();
	cout << "List Doctor " << endl;

	ifstream file("doctor.txt");
		
    struct doctor doctor[100];  

	int i=0;

    while (file >> doctor[i].code)
	{
		file >> doctor[i].name;
		file >> doctor[i].family;
		file >> doctor[i].phone;
		file >> doctor[i].special;
		i++;
	}
	
	///i number of doctors
   	sortDoctor(doctor, i);
	
	///print sorted doctors
    for (int j=0;j<i;j++){
		cout<<doctor[j].code<<" "<<doctor[j].name<<" "<<doctor[j].family<<
		" "<<doctor[j].phone<<" "<<doctor[j].special<<endl;		
	}

}

void printDoctor(){

	cls();
	
	cout<<"print doctor database ...\n";
	cout<<"code\t"<<"name\t\t"<<"family\t\t"<<"phone\t\t"<<"special\n";

	ifstream file("doctor.txt");
    
    struct doctor doctor[100];  
    
    int i=0;
    
    while (file >> doctor[i].code)
	{
		file >> doctor[i].name;
		file >> doctor[i].family;
		file >> doctor[i].phone;
		file >> doctor[i].special;			

		cout<<doctor[i].code<<"\t"<<doctor[i].name<<"\t\t"<<doctor[i].family<<
		"\t\t"<<doctor[i].phone<<"\t\t"<<doctor[i].special<<endl;		

		i++;
	}
	
}

void printSick(){

	cls();
	
	cout<<"print sick database ...\n";
	cout<<"Code\t"<<"docCode\t"<<"name\t\t"<<"family\t\t"<<"phone\n";

	ifstream file("sick.txt");
    
    struct sick sick[100];  
    
    int i=0;
    
    while (file >> sick[i].sickCode)
	{
		file >> sick[i].doctorCode;
		file >> sick[i].name;
		file >> sick[i].family;
		file >> sick[i].phone;

		cout<<sick[i].sickCode<<"\t"<<sick[i].doctorCode<<"\t"<<sick[i].name<<
		"\t\t"<<sick[i].family<<"\t\t"<<sick[i].phone<<endl;	

		i++;
	}

}

void sickMenu(){
	
	int choice=0;		
		
	while (1)
	{	
		
		cls();

		cout << "Modireat Bimaran" << endl;
		cout << "1. Insert new sick" << endl;
		cout << "2. Remove the sick" << endl;
		cout << "3. Edit sick" << endl;
		cout << "4. Show sicks information" << endl;
		cout << "5. Print sick database" << endl;
		cout << "6. Exit" << endl;
		
		cin >> choice;
		
		switch(choice){
			
			case 1: insertSick(); printSick(); enter(); break;
			case 2: printSick(); removeSick(); printSick(); enter(); break;
			case 3: printSick(); editSick(); printSick(); enter(); break;
			
			case 4: printSick(); listSickAsending(); enter(); break;
			
			case 5: printSick(); enter();break;
			case 6: return;///exit
			default: cout<<"Enter 1<number<6 \n"; break;		
		};	

	}		

}

void doctorMenu(){
	
	int choice=0;		
		
	while (1)
	{	
		
		cls();

		cout << "Modireat Pezeshkan:" << endl;
		cout << "1. Insert new doctor" << endl;
		cout << "2. Remove the doctor" << endl;
		cout << "3. Edit doctor information" << endl;
		cout << "4. Search for a doctor" << endl;
		cout << "5. List doctor"<< endl;
		
		cout << "6. Show doctor's sicks" << endl;
		
		cout << "7. Show doctor database" << endl;
		cout << "8. Exit"<< endl;
			
		cin >> choice;
		
		switch(choice){
			
			case 1: insertDoctor(); printDoctor(); enter(); break;
			case 2: printDoctor(); removeDoctor(); printDoctor(); enter(); break;
			case 3: printDoctor(); editDoctor(); printDoctor(); enter(); break;	
			case 4: printDoctor(); searchDoctor(); enter(); break;
			case 5: printDoctor(); listDoctor(); enter(); break;
			
			case 6: printDoctor(); listSick(); enter(); break;
			
			case 7: printDoctor(); enter(); break;
			case 8: return;///exit
			default: cout<<"Enter 1<number<8 \n"; enter(); 		
		};	

	}	
			
}

void menu(void){
	
	//~ int c=0;
	//~ do{
		//~ cls();
		//~ c = credential();
	//~ }while (c);
		
	while (1){
		
		cls();
		
		cout << "Please select 1 or 2:\n";
		cout << "1. Modireat Bimaran" << endl;
		cout << "2. Modireat Pezeshgan" << endl;
		
		cout << "3. Reset Database" << endl;
		cout << "4. Exit" << endl;

		int number;
		cin >> number;
		
		cls();

		switch (number){
		case 1:	sickMenu(); break;
		case 2:	doctorMenu(); break;
		
		case 3:	resetDatabase(); enter(); break;
		case 4:	return;	///exit
		default: cout<<"Enter 1<number<4 \n"; enter();	
		};
			
	}

}

int credential(){
	
	ifstream infile("password.txt", ios::in);

	string rusr;
	string rpass;

	if (!infile) {
		cout << "could not open file!" << endl;
		return 0;
	}

	infile >> rusr;
	infile >> rpass;

	infile.close();

	string usr;
	string pass;
	
	cout << "username:";
	cin >> usr;
	
	cout << "password:";
	cin >> pass;
	
	if (usr == rusr && pass == rpass) {
		cout<<"OK ...\n";
		return 0;
	}
	else {
		cout<<"No user or password incorrect ...\n";
		return 1;
	}

}

void resetDatabase(){

	cout<<"Reset file database ...\n";
	
	ifstream    inFilesk("./db/sick.txt");
    ofstream    outFilesk("./sick.txt");

    outFilesk << inFilesk.rdbuf();
    
	ifstream    inFiledk("./db/doctor.txt");
    ofstream    outFiledk("./doctor.txt");

    outFiledk << inFiledk.rdbuf();
}

void enter(){
	cout<<"press Enter to continue ... ";
	///remain \n in buffer and not work
	cin.get();//getchar();
	cin.ignore();
}

///cls, clear: clear screen
void cls(){
	//linux
	system("clear");
	//windows
	//system("cls");		
}
