#include "Doctor.h"
#include "Patient.h"
struct Appointments{
    patient A;
    doctor B;
    int min;
    int status;
    int price;
    void WriteData(const string fileName);
    void Display(const string fileName,string NIC) ;
};