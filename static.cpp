#include<iostream>
using namespace std;

class count{
    public:
    static int counter;
    count()
    {
        counter++;
    }

    int getcounter(){
        return counter;
    }

};

int count ::counter=0;
int main()
{
count c1,c2,c3;
cout<<"THE TOTAL COUNTERS ARE "<<c1.getcounter()<<endl;
cout<<"THE TOTAL COUNTERS ARE "<<c2.getcounter()<<endl;
cout<<"THE TOTAL COUNTERS ARE "<<c3.getcounter()<<endl;
cout<<"THE TOTAL COUNTERS ARE "<<c1.getcounter()<<endl;

//count value willbe same for all because of ststic varible

return 0;
}