//------------OOP PROJECT------------//
//Name:Muhammad Sohail Shahbaz
//Roll # 21I1356
struct Payment{
    void JazzCash();
    void BankTransfer();
};

class FeedBack{
public:
    string NIC;
    float rating;
    string review,reply;
    int totalRatings;

    FeedBack(){rating=0;totalRatings=0;}
    FeedBack WriteFeedBack(string CNIC);
    void display(){cout << "Rating: " << rating << "\tReview: " << review << endl;}
};

class User{
public:
    string name ;
    char* email = new char[45];
    string password;
    string CNIC;
};

class patient: public User{
    public:
    float amount;
    int status;
    void Null(string CNIC);
    void Display(){cout << "NAME: " << name  << "\tCNIC: " << CNIC << endl;}
    void RechargeAccount(string Nic);
    void AddFeedback(string Nic);
    void Reg();
    void resetPassword(string NIC);
};

class doctor:public User{
public:
    int exp;
    int spec;
    string Hosp_Name;
    string city;
    float amount;
    bool access;
    int Stime,Etime;
    int rate;
    int Availability_Min;
    int totalmin,totalminOcc;
    float rating;
    FeedBack *F = new FeedBack[10];
    
    
    void Null(string CNIC);
    void display()  {cout << "NAME: " << name  << "\tCNIC: " << CNIC << "\tAvailabilty: " 
    << Stime << ":00-"<< Etime << ":00\tHourly rate: " << rate << "\tTotal ratings: " << rating << endl;} 
    void EditDoc(const string fileName,string NIC);
    
};



struct Appointments{
    patient A;
    doctor B;
    int min;
    int status;
    int price;
    void WriteData(const string fileName);
    void Display(const string fileName,string NIC) ;

};

class Admin{
    doctor *D = new doctor[20];
    int NoOFDoc;
    int NoOfPat;
public:
    patient *P = new patient[20];
    Appointments App;
    Admin() {NoOFDoc=0;NoOfPat=0;}
    void Login();
    
    void RegPatient();
    void RegDoc();
    string DocLog();
    string PatLog();
    void ManageDoc();
    void DeleteDoc();
    void DeletePat();
    void EditDoc(const string fileName,string NIC);
    void SearchDoc();
    void BookApp(string Nic);
    void ManageApp(const string fName,string NIC);
    void LeaveJob(string NIC);
    void cancelApp(string NIC);
    void takeApp(string NIC);
    void SeeFeedbacks(string NIC);
    void SeeReplies(string NIC);
    };

class oladoc : public Admin{
public:
    Admin A;
    User U;
};