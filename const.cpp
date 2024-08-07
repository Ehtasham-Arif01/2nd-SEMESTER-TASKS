#include<iostream>
using namespace std;

class point{
    private:
    int x;

    public:
    //constructer
    point(int x_input);
    const int getx();
    void setx(int x);
    void print() const;
};
//constructer
point :: point(int x_input)
{
x=x_input;
}
const int point ::getx()
{
return x;
}

void point::setx(int x_)
{
    x=x_;
}

void point :: print() const{
    cout<<"\t\t"<<x<<endl;
}

int main()
{
point a(1111111);
a.print();

return 0;
}