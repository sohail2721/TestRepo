class FeedBack{
public:
    string NIC;
    float rating;
    string review;
    int totalRatings;

    FeedBack(){rating=0;totalRatings=0;}
    FeedBack WriteFeedBack(string CNIC);
    void display(){cout << "Rating: " << rating << "\tReview: " << review << endl;}
};