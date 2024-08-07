#include<iostream>
using namespace std;

//forward declaration of class.
class Distance;

class class23{
    public:
void Add_five(Distance d);

};


class Distance{
    private:
    //we can declare it in private or public part as we want .
    friend void class23::Add_five(Distance);
    int meter;
    public:
    Distance(int m):meter(m){}

    

};
void class23::Add_five(Distance d)
{
    d.meter+=5;
    cout<<"\nMETER IS : "<<d.meter<<"\n\n"<<endl;
}

int main()
{
    Distance d(12);
    class23 c;
    c.Add_five(d);
    return 0;
}