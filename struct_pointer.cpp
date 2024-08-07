#include<iostream>
using namespace std;

struct point{

    int x;
    int y;

};

int main()
{
point p1,*p2;
p1.x=2;
p1.y=3;
p2=&p1;

cout<<"P2 REFER X  :"<<p2->x <<endl;
cout<<"P2 REFERS Y :"<<p2->y<<endl;

return 0;
}
