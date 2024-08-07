#include<iostream>
using namespace std;

class DOB{
    private:
    int month;
    int date;
    int year;
    public:
    DOB(int m,int d,int y):date(d),month(m),year(y){}

};

class contact{
private:
    string name;
    int phone_no;
    string email;
    int no_of_contacts=5;
    DOB object;
    int array[5];
    public:
    contact(string n,int p,string e,int m,int d,int y):name(n),phone_no(p),email(e),object(m,d,y){}

    //getting values from the user.
    void getdata()
    {
        for(int i=0;i<5;i++)
        {
            cout<<"ENTER NAME : ";
            cin>>name;
            cout<<"ENTER PHONE NO : ";
            cin>>phone_no;
            cout<<"ENTER E-MAIL : ";
            cin>>email;
            cout<<"ENTER DATE OF BIRTH : ";
            cin>>;
        }
    }
};

class contact_book{
    private:
    contact c_obj;
    public:
    
};


int main()
{
 
    return 0;
}