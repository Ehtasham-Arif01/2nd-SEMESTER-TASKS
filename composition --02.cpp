#include<iostream>
using namespace std;

class classB;
class classA{
    private:
    friend int Add(classA a,classB b)
    int x;
    public:
    classA(int A):x(A){}
};
class classB{
    private:
    friend int  Add(classA a,classB b)
    int y;
    public:
    classB(int B):y(B){}
};

int  Add(classA a,classB b)
{
    return(a.x+b.y);
}
int main()
{
classA a(6);
classB b(5);

return 0;
}