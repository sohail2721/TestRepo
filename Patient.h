
class patient: public User{
    public:
    float amount;
    int status;
    void Null(string CNIC);
    void Display(){cout << "NAME: " << name  << "\tCNIC: " << CNIC << endl;}
    void RechargeAccount(string Nic);
    void AddFeedback(string Nic);
    void Reg();
};