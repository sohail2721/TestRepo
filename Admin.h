
#include "Appointments.h"
#include "Doctor.h"
#include "Patient.h"
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
};