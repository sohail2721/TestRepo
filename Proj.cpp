//------------OOP PROJECT------------//
//Name:Muhammad Sohail Shahbaz
//Roll # 21I1356
#include <iostream>
#include <fstream>
#include<string.h>
#include<cstring>
using namespace std;
#include "Proj.h"
bool isValidCNIC(string CNIC){  //Function to check validity of 13 digit NIC
    for(int i=0;i < 13; i++)
        if(CNIC[i] < '0' or CNIC[i] > '9')
            return false; 
            
        return true;
}
bool isValid(string password)   //Function to check validity of password
{   // For checking if password length
    // is between 8 and 15
    if (!((password.length() >= 8) &&
          (password.length() <= 15)))
        return false;
 
    // To check space
    if (password.find(" ") !=
        std::string::npos)
        return false;
 
    if (true)
    {
        int count = 0;
 
        // Check digits from 0 to 9
        for(int i = 0; i <= 9; i++)
        
        {
             
            // To convert int to string
            string str1 = to_string(i);
 
            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }
 
    // For special characters
    if (!((password.find("@") != std::string::npos) ||
          (password.find("#") != std::string::npos) ||
          (password.find("!") != std::string::npos) ||
          (password.find("~") != std::string::npos) ||
          (password.find("$") != std::string::npos) ||
          (password.find("%") != std::string::npos) ||
          (password.find("^") != std::string::npos) ||
          (password.find("&") != std::string::npos) ||
          (password.find("*") != std::string::npos) ||
          (password.find("(") != std::string::npos) ||
          (password.find(")") != std::string::npos) ||
          (password.find("-") != std::string::npos) ||
          (password.find("+") != std::string::npos) ||
          (password.find("/") != std::string::npos) ||
          (password.find(":") != std::string::npos) ||
          (password.find(".") != std::string::npos) ||
          (password.find(",") != std::string::npos) ||
          (password.find("<") != std::string::npos) ||
          (password.find(">") != std::string::npos) ||
          (password.find("?") != std::string::npos) ||
          (password.find("|") != std::string::npos)))
        return false;
     
    if (true)
    {
        int count = 0;
 
        // Checking capital letters
        for(int i = 65; i <= 90; i++)
        {
             
            // Type casting
            char c = (char)i;
            string str1(1, c);
             
            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }
 
    if (true)
    {
        int count = 0;
 
        // Checking small letters
        for(int i = 97; i <= 122; i++)
        {
             
            // Type casting
            char c = (char)i;
            string str1(1, c);
 
            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }
 
    // If all conditions fails
    return true;
}
bool isChar(char c){ return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));} 
bool isDigit(const char c){ return (c >= '0' && c <= '9');}
bool is_valid(string email){ //Function to check validity of email
    // is an alphabet or not
   
    if (!isChar(email[0])) return 0;
    int At = -1, Dot = -1;
  
    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;i < email.length(); i++) {
        if (email[i] == '@')  At = i;
        else if (email[i] == '.') Dot = i;
    }
  
    // If At or Dot is not present
    if (At == -1 || Dot == -1) return 0;
   
    // If Dot is present before At
    if (At > Dot) return 0;
  
    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
     
}
void insertData(const string fileName, doctor obj) {    //Write data in doctor.bin file
	ofstream myBFile(fileName.c_str(), ios::binary | ios::app);
	myBFile.write((char*)&obj, sizeof(obj));
	myBFile.close();
}
void readData(const string fileName){   //Read data from doctor file
    doctor temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
        temp.display();
	}
}
void readDataSearch(const string fileName,int spec){    //Function to search data with specialization
    doctor temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
        if(temp.spec==spec) {
            cout << "Following Doctors available: " << endl;
            temp.display();
        }
	}
}
void readDataSearchH(const string fileName,string city){ //Function to search data with specialization
    doctor temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
        cout << "Following Doctors available: " << endl;
        if(temp.city==city) temp.display();
	}
}
void readDataP(const string fileName){  //Read data from patient
    patient temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
        temp.Display();
	}
}
void insertData(const string fileName, patient obj) {   //Write data in patient file
	ofstream myBFile(fileName.c_str(), ios::binary | ios::app);
	myBFile.write((char*)&obj, sizeof(obj));
	myBFile.close();
}
void readCNIC(const string fileName,string NIC,int s,int e){    //Function to change availability hours
    doctor temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
        temp.display();
		if(NIC==temp.CNIC) {
           temp.Stime=s;
           temp.Etime=e;
           cout << "The availabilty hours have been changed!" << endl;
           return;
        }
	}
    cout << "Wrong Credientials!" << endl;
}
void deleteDoc(const string fileName,string NIC){   //Function to delete doctor from database
    doctor temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
		if(NIC==temp.CNIC) {
           temp.Null(NIC);
           cout << "The doctor has been deleted!" << endl;
           return;
        }
	}
    cout << "Wrong Credientials!" << endl;
}
void DeleteP(const string fileName,string NIC){     //Function to delete patient from database
    patient temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
		if(NIC==temp.CNIC) {
           temp.Null(NIC);
           cout << "The patient has been deleted!" << endl;
           return;
        }
	}
    cout << "Wrong Credientials!" << endl;
}
bool readCredientials(string fileName,string NIC,string pass) { //Confirming credientials of Doctor  
	doctor temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
		if(NIC==temp.CNIC && pass==temp.password) {
            cout << "Login successful!" << endl;
            cout << "Welcome Mr/Ms " << temp.name  << "! Select options from menu to perform operations:" << endl;
            return 1;
        }
	}
     cout << "No records found against given credientials!" << endl;
     return 0;
}
bool PreadCredientials(string fileName,string NIC,string pass) {//Confirming credientials of Patients
	patient temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
       // temp.Display();
		if(NIC==temp.CNIC && pass==temp.password) {
            cout << "Login successful!" << endl;
            cout << "Welcome Mr/Ms " << temp.name  << "! Select options from menu to perform operations:" << endl;
            return 1;
        }
	}
     cout << "No records found against given credientials!" << endl;
     return 0;
}
void WriteAppointment(const string fileName,Appointments obj){  //Writing appointments in file
    ofstream myBFile(fileName.c_str(), ios::binary | ios::app);
	myBFile.write((char*)&obj, sizeof(obj));
	myBFile.close();
}
doctor ReturnDoctor(const string fileName,string CNIC){ //Returning obj of doctor by confirming NIC
    doctor temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp)))  if(temp.CNIC==CNIC)  return temp;
    cout << "Doctor not found!" << endl;
    return temp;
}
patient ReturnPatient(const string fileName,string CNIC){ //Returning obj of patient by confirming NIC
    patient temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) if(temp.CNIC==CNIC) return temp;
    return temp;
}
int ReturnPrice(const string fileName,string CNIC){//returning price of appointment
    Appointments temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) if(temp.A.CNIC==CNIC) return temp.price;
    return 0;
}
void Admin::Login(){ //Admin
    string U,P;
    string check="admin";
    cout << "Enter Username: " << endl;
    cin >> U;
    cout << "Enter Password: " << endl;
    cin >> P;
    if(check!="admin" && check != "admin") Login();
    else cout << "Login Successful!" << endl;
}
bool CheckRepeatD(const string fileName,string CNIC){   //Function to check if doctor is already present in database
    doctor temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) 
    if(CNIC==temp.CNIC) {
        cout << "This CNIC already exists!" << endl;
        return 0;
    }
    return 1;
}
bool CheckRepeatP(const string fileName,string CNIC){   //Function to check if patient is already present in database
    patient temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) 
    if(CNIC==temp.CNIC) {
        cout << "This CNIC already exists!" << endl;
        return 0;
    }
    return 1;
}
bool CheckRepeatApp(const string fileName,string PCNIC,string DCNIC){
    Appointments temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) 
    if(PCNIC==temp.A.CNIC  && DCNIC==temp.B.CNIC && temp.status!=3 && temp.status!=0) {
        cout << "Appointment with this doctor already exists!" << endl;
        cout << "Failed to book appointment!" << endl;
        return 0;
    }
    return 1;
}
void Admin::RegDoc(){        //Doctor Registration
    cout << "Enter Name: " << endl;
    cin >> D[NoOFDoc].name;
    do{
    cout << "Enter CNIC: " << endl;
    cin >> D[NoOFDoc].CNIC;
    bool check = CheckRepeatD("Doctor.bin", D[NoOFDoc].CNIC);
    if(check==0) return;
    }while(!isValidCNIC( D[NoOFDoc].CNIC));
    do{
    cout << "Enter Email: " << endl;
    cin >> D[NoOFDoc].email ;
    }while(!is_valid(D[NoOFDoc].email));
    do{ 
    cout << "Enter password: " << endl;
    cin >> D[NoOFDoc].password;
    }while(!isValid(D[NoOFDoc].password));
   

    cout << "Registration succesful! Enter the following details: " << endl;
    cout << "Enter years of experience: " << endl;
    cin >> D[NoOFDoc].exp;
    cout << "Enter Specialization: " << endl << "1.Cardiologist" << endl << "2.Dermatologist" << endl << "3.Oncologist" << endl;
    cin >> D[NoOFDoc].spec ;
    cout << "Enter Hospital Name : " << endl;
    cin >> D[NoOFDoc].Hosp_Name; 
    cout << "Enter City: " << endl;
    cin >> D[NoOFDoc].city;
    cout << "Enter availability hours(Start): " << endl;
    cin >> D[NoOFDoc].Stime;
    cout << "Enter closing time:" << endl;
    cin >> D[NoOFDoc].Etime;
    cout << "Enter hourly rate: " << endl;
    cin >> D[NoOFDoc].rate; 
    D[NoOFDoc].totalminOcc=0;
    D[NoOFDoc].totalmin=(abs(D[NoOFDoc].Etime - D[NoOFDoc].Stime))*60;
    D[NoOFDoc].amount=0;
    insertData("Doctor.bin",D[NoOFDoc]);
    NoOFDoc++;

}
void Admin::RegPatient(){   //Admin Registration
    cout << "Enter Name: " << endl;
    cin >> P[NoOfPat].name;
    do{
    cout << "Enter CNIC: " << endl;
    cin >> P[NoOfPat].CNIC;
    bool check = CheckRepeatP("Patient.bin", D[NoOFDoc].CNIC);
    if(check==0) return;
    }while(P[NoOfPat].CNIC[12]=='\0');
    do{
    cout << "Enter Email: " << endl;
    cin >> P[NoOfPat].email ;
    }while(!is_valid(P[NoOfPat].email));
    do{ 
    cout << "Enter password: " << endl;
    cin >> P[NoOfPat].password;
    }while(!isValid(P[NoOfPat].password));
    P[NoOfPat].amount=3500;
    insertData("Patient.bin",P[NoOfPat]);
    NoOfPat++;
}
string Admin::DocLog(){     //Doctor Login
    string NIC;
    string pass;
    cout << "Enter CNIC: " << endl;
    cin >> NIC;
    cout << "Enter password: " << endl;
    cin >>pass;
    if(readCredientials("Doctor.bin",NIC,pass)!=1) DocLog();  
    return NIC;
}
string Admin::PatLog(){     //Patient Login
    string NIC;
    string pass;
    cout << "Enter CNIC: " << endl;
    cin >> NIC;
    cout << "Enter password: " << endl;
    cin >>pass;
    if(PreadCredientials("Patient.bin",NIC,pass)!=1) PatLog(); 
    return NIC;   
}
void Admin::ManageDoc(){    //Edit availability hours of doc
    string Nic;
    int s,e;
    cout << "Following are the doctors working: " << endl;
    readData("Doctor.bin");
    cout << "Enter CNIC number of the doctor to set availability hours: " << endl;
    cin >> Nic;
    cout << "Enter starting hours:" << endl;
    cin >>  s;
    cout << "Enter Ending hours: " << endl;
    cin >> e;
    readCNIC("Doctor.bin",Nic,s,e);

}
void Admin::DeleteDoc(){    //Delete doc from database
    string Nic;
    cout << "Following are the doctors working: " << endl;
    readData("Doctor.bin");
    cout << "Enter CNIC number of the doctor to delete from database: " << endl;
    cin >> Nic;
    deleteDoc("Doctor.bin",Nic);
}
void Admin::DeletePat(){    //Detele Patient from data base
    string Nic;
    cout << "Following are the Patients enrolled: " << endl;
    readDataP("Patient.bin");
    cout << "Enter CNIC number of the patient to delete from database: " << endl;
    cin >> Nic;
    DeleteP("Patient.bin",Nic);
}
void Admin:: EditDoc(const string fileName,string NIC){ //Edit doctor file
    int input,r,s,e;
    doctor temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	while(myFile.read((char*)&temp, sizeof(doctor))) { 
		if(NIC==temp.CNIC) {
           temp.display();
           cout << "1.Edit hourly rate" << endl << "2.Edit available timings" << endl ;
           cin >> input;
           switch (input)
           {
           case 1:
            {
                cout << "Enter new hourly rate: " << endl;
                cin >>r;
                temp.rate=r;
                int current = myFile.tellg();
			    int one_obj = sizeof(doctor);
			    myFile.seekg(current - one_obj);
			    myFile.write((char*)&temp, sizeof(temp));
			    myFile.close();
            }
               break;
           case 2:
           {
            cout << "Enter new start time: " << endl;
            cin >> s;
            cout << "Enter end time: " << endl;
            cin >> e;
            temp.Stime=s;
            temp.Etime=e;
            int current = myFile.tellg();
			int one_obj = sizeof(doctor);
			myFile.seekg(current - one_obj);
			myFile.write((char*)&temp, sizeof(temp));
			myFile.close(); 
           }
           break;

           default:
               break;
           } 
        }
	}

}
void EditApp(const string fileName,string nic,int inp){ //Edit appointments file
    Appointments temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	while(myFile.read((char*)&temp, sizeof(Appointments))) { 
		if(nic==temp.A.CNIC) {
                temp.status=inp;
                int current = myFile.tellg();
			    int one_obj = sizeof(Appointments);
			    myFile.seekg(current - one_obj);
			    myFile.write((char*)&temp, sizeof(temp));
			    myFile.close();
                cout << "Task Successful!" << endl;
                return;
        }
    }
    cout << "CNIC not found!" << endl;
}
void EditAppPatient(const string fileName,string nic,int inp){  //Edit Appointment
    Appointments temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	while(myFile.read((char*)&temp, sizeof(Appointments))) { 
		if(nic==temp.B.CNIC) { 
            temp.status=inp;
                int current = myFile.tellg();
			    int one_obj = sizeof(Appointments);
			    myFile.seekg(current - one_obj);
			    myFile.write((char*)&temp, sizeof(temp));
			    myFile.close();
                cout << "Booking Status changed!" << endl;
                return;
        }
    }
    cout << "CNIC not found!" << endl;
}
void Appointments::Display(const string fileName,string CNIC){  //Display Appointment
    cout << "Following patients are appointed to you: " << endl;
    Appointments temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) 
        if(CNIC==temp.B.CNIC)  cout << "Name: " << temp.A.name << "\tCNIC: " << temp.A.CNIC << "\tStatus: " << temp. status << endl ;
}
void Admin::SearchDoc(){    //Search doc function
    int inp,inp1;
    string input;
    cout << "1.Search by specialization" << endl << "2.Search by hospital" << endl;
    cin >> inp;
    switch (inp)
    {
    case 1:
        cout << "1.Oncologist" << endl << "2.Dermatologist" << endl << "3.Cardiologist" << endl;
        cin >> inp1;
        if(inp1==1) readDataSearch("Doctor.bin",3);
        else if (inp1==2) readDataSearch("Doctor.bin",2);
        else if (inp1==3) readDataSearch("Doctor.bin",1);
        break;
    case 2:
    cout << "Enter name of city: " << endl;
    cin >> input;
    readDataSearchH("Doctor.bin",input);
        break;
    default:
        cout << "Invalid option!" << endl;
        break;
    }
}
void setPatientAmount(const string fileName,string PNIC,Appointments obj){  //Update patient amount
    patient temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	
	while(myFile.read((char*)&temp, sizeof(patient))) {
		if (PNIC==temp.CNIC) {
			temp.amount = obj.A.amount;
			int current = myFile.tellg();
			int one_student_obj = sizeof(patient);
			myFile.seekg(current - one_student_obj);
			myFile.write((char*)&temp, sizeof(temp));
			myFile.close();
		}
	}
}
void Admin::BookApp(string PNIC){   //Function to book appointment with doctor
    Appointments obj;
    string NIC;
    int min,typeOf;
    readData("Doctor.bin");
    cout << endl;
    cout << endl << endl << "Enter CNIC number of doctor to book an appointment: " << endl;
    cin >> NIC;
    bool check = CheckRepeatApp("Appointments.bin",PNIC,NIC);
    if(check==0) return;
    obj.B=ReturnDoctor("Doctor.bin",NIC);
    if(obj.B.CNIC !=NIC) return;
    obj.A=ReturnPatient("Patient.bin",PNIC);
    cout << "Account balance: " << obj.A.amount << endl;
    cout << "Enter duration of appointment in minutes:" << endl;
    cin >> min;
    cout << "1.In person appointment" << endl << "2.Video appointment" << endl;
    cin >> typeOf;
    int price=obj.A.amount;
    obj.min = min;
    obj.status=0;
    if (min>obj.B.totalmin - obj.B.totalminOcc )
        cout << "Doctor doesn't have enough time! They have " <<   obj.B.totalmin -  obj.B.totalminOcc << " minutes for appointment!" << endl;
    else{
        if(typeOf==2){
            obj.A.amount -= ((((min*1.0)/60)*obj.B.rate))*0.7;
            obj.B.amount += ((((min*1.0)/60)*obj.B.rate))*0.7;
            obj.price=((((min*1.0)/60)*obj.B.rate))*0.7;
        }
        else if(typeOf==1){
            obj.A.amount-= (((min*1.0)/60)*obj.B.rate);
            obj.B.amount += (((min*1.0)/60)*obj.B.rate);
            obj.price=((((min*1.0)/60)*obj.B.rate));
        }
        if(obj.price>price) {
            cout << obj.price << " " << obj.A.amount << " " << obj.B.amount << endl;
            cout << "Insufficient Balance! Please recharge your account!" << endl;
            return;
        }
        obj.B.totalminOcc+=min;
        WriteAppointment("Appointments.bin", obj);
        setPatientAmount("Patient.bin",PNIC,obj);
        cout << "Your appointment is booked, you'll be charged soon!" << endl << "Current status: Pending" << endl;
    }
}
void Admin::ManageApp(const string fileName,string CNIC){ //Manage appointments
    cout << "Following patients are appointed to you: " << endl;
    bool check = false;
    Appointments temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) 
         if(temp.B.CNIC==CNIC && temp.status!=3) {
         cout << "Name: " << temp.A.name << "\tCNIC: " << temp.A.CNIC << "\tStatus: " << temp.status << endl ;
         }
    if(check == false){
    string nic;
    int inp;
    cout << "Enter the CNIC number of patient to change appointment status: " << endl;
    cin >> nic;    
    cout << "1.Approve" << endl << "2.Reject" << endl;
    cin >> inp;
    EditApp("Appointments.bin", nic, inp);
    }
    else cout << "No patients in record currently!" << endl;
}
void PatientCApp(const string fileName,string CNIC){  //Functions to display appointments with doctor
    cout << "You have appointments with the following doctors :" << endl;
    Appointments temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
        if(CNIC==temp.B.CNIC && temp.status!=3){
            cout << "Appointment not completed! Cannot Rate." << endl;
            return;
        }
        if(CNIC==temp.A.CNIC && temp.status!=0 && temp.status!=2 && temp.status!=3) 
         cout << "Name: " << temp.B.name << "\tCNIC: " << temp.B.CNIC  << endl ;
        else if(CNIC == temp.A.CNIC && temp.status ==3)
            cout << "Name: " << temp.B.name << "\tCNIC: " << temp.B.CNIC << "(COMPLETED)" << endl ;
    }
}
void Admin::LeaveJob(string CNIC){  //Function to leave job
    deleteDoc("Doctor.bin",CNIC);
    cout << "Job left successfully!" << endl;
}
void returnAmount(const string fileName,string PNIC,string DNIC, float D,float P){  //Return amount after cancellation
    Appointments temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	while(myFile.read((char*)&temp, sizeof(Appointments))) { 
		if(DNIC==temp.B.CNIC && PNIC == temp.A.CNIC) { 
                temp.A.amount+=P;
                temp.B.amount-=D;
                int current = myFile.tellg();
			    int one_obj = sizeof(Appointments);
			    myFile.seekg(current - one_obj);
			    myFile.write((char*)&temp, sizeof(temp));
			    myFile.close();
                return;
        } 
    }
    cout << "CNIC not found!" << endl;
}
void Admin::cancelApp(string CNIC){ //Cancel Appointment
    Appointments obj;
    string nic;
    int days;
    PatientCApp("Appointments.bin",CNIC);
    cout << "Enter CNIC of the doctor to cancel Appointment with them: " << endl;
    cin >> nic;
    EditAppPatient("Appointments.bin", nic, 2);
    //Deleting appointment
    const string fileName = "Appointments.bin";
    Appointments temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	ofstream myFileTemp("temp.bin", ios::app | ios::binary);
	while(myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.B.CNIC!= nic) {
			myFileTemp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFileTemp.close();
	remove(fileName.c_str());
	rename("temp.bin", fileName.c_str());

    obj.B=ReturnDoctor("Doctor.bin",nic);
    obj.A=ReturnPatient("Patient.bin",CNIC);
    obj.price = ReturnPrice("Appointments.bin",CNIC);
    cout << "Enter number of days passed after fixing the apppointment: " << endl;
    cin >> days;
    if(days==0) {
        obj.B.amount -= obj.price;
        obj.A.amount += obj.price;
    }
    else if(days==1) {
        obj.B.amount -= ((obj.price)*0.6);
        obj.A.amount += ((obj.price)*0.6);
    }
    else if(days==2){
        obj.B.amount -= ((obj.price)*0.3);
        obj.A.amount += ((obj.price)*0.3);
    }
    cout << "The amount of money after due deduction(if any) has been returned!" << endl;
    returnAmount("Appointments.bin",CNIC,nic,obj.B.amount,obj.A.amount);

}
void Admin::takeApp(string CNIC){   //Attend appointment
    int inp;
    string NIC;
    PatientCApp("Appointments.bin",CNIC);
    cout << "Enter CNIC number of the doctor to start Appointment: " << endl;
    cin >> NIC;
    EditAppPatient("Appointments.bin",NIC,3);
    cout << "Your appointment time has been started!" << endl << "Press any key when appointment is finished: " << endl;
    cin >> inp;
    cout << "Do leave feedback on the appointment from the feedback module!" << endl;
    cout << "Have a nice day!" << endl;
    return;
}
void PatientUpdate(const string fileName,string CNIC,int inp){  //Appointment amount update
    patient temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	while(myFile.read((char*)&temp, sizeof(patient))) { 
		if(CNIC==temp.CNIC) {
                temp.amount=inp;
                int current = myFile.tellg();
			    int one_obj = sizeof(patient);
			    myFile.seekg(current - one_obj);
			    myFile.write((char*)&temp, sizeof(temp));
			    myFile.close();
                return;
        }
    }
    cout << "CNIC not found!" << endl;
}
int ReadPatientAmount(const string fileName,string CNIC){   //Getting money in patient account
    patient temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	while(myFile.read((char*)&temp, sizeof(patient))) { 
		if(CNIC==temp.CNIC) {
            return temp.amount;
        }
    }
    cout << "CNIC not found!" << endl;
}
void patient::RechargeAccount(string CNIC){     //Recharge patient account
    amount = ReadPatientAmount("Patient.bin",CNIC);
    Payment P;
    int money,inp;
    cout << "Current balance: " << amount << endl;
    cout << "Enter amount of money to recharge :" << endl;
    cin >> money;
    cout << "Select Payment option: " << endl << "1.JazzCash" << endl << "2.EasyPaisa" << endl << "3.Bank Transfer" << endl;
    cin >> inp;
    amount +=money;
    PatientUpdate("Patient.bin",CNIC,amount);
    if(inp==1 or inp ==2) P.JazzCash();
    else if (inp == 3) P.BankTransfer();
    else {
        cout << "Invalid Option!" << endl;
        RechargeAccount(CNIC);
    }
}
void Payment::JazzCash(){   //Jazzcash Transfer
    long long PhNo;
    int PIN;
    cout << "Enter Mobile Number: " << endl;
    cin >> PhNo;
    cout << "Enter MPIN:" << endl;
    cin >> PIN;
    cout << "Account Recharged Successfully!" << endl;
}
void Payment::BankTransfer(){ //Bank Transfer
    long long ACCNo;
    int PIN;
    cout << "Enter Account Number: " << endl;
    cin >> ACCNo;
    cout << "Enter PIN:" << endl;
    cin >> PIN;
    cout << "Account Recharged Successfully!" << endl;
}
FeedBack FeedBack::WriteFeedBack(string CNIC){  //Function to write feedback
    NIC=CNIC;
    do{
    cout << "Enter rating out of 5:" << endl;
    cin >> rating;
    }while(rating<0 or rating > 5);
    cout << "Write a review: " << endl;
    cin >> review;
    totalRatings++;
    return *this;
}
void setDoctorRatings(const string fileName,FeedBack hello,string CNIC){    //set doctor ratings after feedback
    doctor temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	while(myFile.read((char*)&temp, sizeof(doctor))) { 
		if(CNIC==temp.CNIC) {
                temp.rating = (hello.rating + temp.rating) / (++hello.totalRatings); 
                int current = myFile.tellg();
			    int one_obj = sizeof(doctor);
			    myFile.seekg(current - one_obj);
			    myFile.write((char*)&temp, sizeof(temp));
			    myFile.close();
                return;
        }
    }
    cout << "CNIC not found!check" << endl;
}
void patient::AddFeedback(string CNIC){ //Add feedback to file
    const string fileName = "Feedbacks.bin";
    FeedBack F;
    string DCNIC;
    PatientCApp("Appointments.bin",CNIC);
    cout << "Enter CNIC of the apppointment completed doctor!" << endl;
    cin >> DCNIC;
    PatientCApp("Appointments.bin",DCNIC);
    F.WriteFeedBack(DCNIC);
    ofstream myBFile(fileName.c_str(), ios::binary | ios::app);
	myBFile.write((char*)&F, sizeof(FeedBack));
	myBFile.close();
    setDoctorRatings("Doctor.bin",F,DCNIC);
}
void Admin::SeeFeedbacks(string CNIC){  //Function for doctor to see their feedbacks
    const string fileName= "Feedbacks.bin";
    cout << "Following are the ratings and reviews of your profile: " << endl;
    FeedBack temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
        if(temp.NIC==CNIC)
            temp.display();
	}
    cout << "Enter reply to reply to all the reviews: " << endl;
    cin >> temp.review;
    temp.WriteFeedBack(CNIC);
}
void patient::Null(string C){   //Delete patient from data base
    const string fileName = "Patient.bin";
    patient temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	ofstream myFileTemp("temp.bin", ios::app | ios::binary);
	while(myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.CNIC != C) 
			myFileTemp.write((char*)&temp, sizeof(temp));
	}
	myFile.close();
	myFileTemp.close();
	remove(fileName.c_str());
	rename("temp.bin", fileName.c_str());
}
void doctor::Null(string C){    //Delete doctor from database
    const string fileName= "Doctor.bin";
    doctor temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	ofstream myFileTemp("temp.bin", ios::app | ios::binary);
	while(myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.CNIC != C) {
			myFileTemp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFileTemp.close();
	remove(fileName.c_str());
	rename("temp.bin", fileName.c_str());
}
void patient::resetPassword(string CNIC){   //Reset Patient password
    const string fileName="Patient.bin";
    string pass;
    cout << "Enter new password: " << endl;
    cin >> pass;
    patient temp;
	fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);
	while(myFile.read((char*)&temp, sizeof(patient))) { 
		if(CNIC==temp.CNIC) {
                temp.password=pass;
                int current = myFile.tellg();
			    int one_obj = sizeof(patient);
			    myFile.seekg(current - one_obj);
			    myFile.write((char*)&temp, sizeof(temp));
			    myFile.close();
                cout << "Password changed successfully!" << endl;
                return;
        }
    }
    cout << "CNIC not found!" << endl;
}
void Admin::SeeReplies(string CNIC){    //See replies for patient
    const string fileName= "Feedbacks.bin";
    PatientCApp("Appointments.bin",CNIC);
    string nic;
    cout << "Enter CNIC of the doctor to see there reply(IF ANY): " << endl;
    cin >> nic;
    FeedBack temp;
	ifstream myFile(fileName.c_str());
	while(myFile.read((char*)&temp, sizeof(temp))) {
        if(temp.NIC==nic) cout << "They Replied: "<< temp.reply;
	}
}


void Menu(){
    oladoc MS;
    int input,rpt;
    do{ 
        cout << "Welcome to OLADOC!" << endl << "Find the best Doctors near you!" << endl 
        << endl << "Select options from the following: " << endl << "1.Admin Login" << endl 
        << "2.Doctor Login" << endl << "3.Patient Login" << endl << "4.Register Doctor" << endl << "5.Register Patient" << endl; 
        cin >> input;
        switch(input){
           case 1:{MS.A.Login();
                cout << "1.Register New Doctor" << endl << "2.Register New Patient" << endl << "3.Manage Availability times" << endl << "4.Delete Doctors" <<endl << "5.Discharge Patients" << endl;
                cin >> input;
                switch (input)
                {case 1:
                    MS.A.RegDoc();
                    break;
                case 2:
                    MS.A.RegPatient();
                    break;
                case 3:
                    MS.A.ManageDoc();
                    break;
                case 4:
                    MS.A.DeleteDoc();
                    break;
                case 5:
                    MS.A.DeletePat();
                    break;
                default:
                cout << "Invalid option selected!" << endl;
                    break;
                }
            break;
           }
       case 2:
            {   string NIC=MS.A.DocLog();
                cout << "1.Edit Info" << endl << "2.See Appointments" << endl << "3.Manage Appointments" << endl << "4.Leave Job" << endl << "5.See feedbacks" << endl;
                cin >> input;
                switch (input)
                {case 1:
                    MS.A.EditDoc("Doctor.bin",NIC);
                    break;
                case 2:
                    MS.A.App.Display("Appointments.bin",NIC);
                   break;
                case 3:
                    MS.A.ManageApp("Appointments.bin",NIC); 
                    break;
                case 4:
                    MS.A.LeaveJob(NIC);
                    break;
                case 5:
                    MS.A.SeeFeedbacks(NIC);
                    break;
                default:
                    cout << "Invalid option selected!" << endl;
                    break;
                }
            }
            break;
            case 3:
            {   string Nic=MS.A.PatLog();
                cout << "1.Search Doctors"<< endl << "2.Book Appointment" << endl << "3.Cancel Appointment" << endl << "4.Recharge account"<< endl << "5.Take Appointment"<< endl << "6.Leave feedback on finished appointments" << endl << "7.Reset Password"<< endl << "8.See replies" << endl;
                cin >> input;
                switch(input){
                    case 1:
                        MS.A.SearchDoc();
                    break;
                    case 2:
                        MS.A.BookApp(Nic);
                        break;
                    case 3:
                        MS.A.cancelApp(Nic);
                        break;
                    case 4:
                        MS.A.P->RechargeAccount(Nic);
                        break;
                    case 5:
                        MS.A.takeApp(Nic);
                        break;
                    case 6:
                        MS.A.P->AddFeedback(Nic);
                        break;
                    case 7:
                        MS.A.P->resetPassword(Nic);
                        break;    
                    case 8:
                        MS.A.SeeReplies(Nic);
                        break;
                    default:
                    cout << "Invalid option selected!" << endl;
                    break;
                }
                break;
            }
            case 4:
                MS.A.RegDoc();
            break;
            case 5:
                MS.A.RegPatient();
            break;
         default:{
                cout << "Wrong option!" << endl;
                Menu();
         }
            break;
        }
        cout << "Press 1 to continue or press any key to exit!" << endl; cin >> rpt;
    }while(rpt==1);
    }

void TESTFUNC(){
    // To see if changes are committed
}
int main(){
    system("clear");
    Menu();
}