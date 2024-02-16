
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