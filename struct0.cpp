#include<iostream>
using namespace std;
 struct student{
    int marks;
    int roll;
};
void print(student stu);
student change(student csstu);
int main()
{
student stu={40,45};
print(stu);
stu=change(stu);
cout<<endl<<endl;
print(stu);
return 0;
}
void print(student stu)
{
    cout<<stu.marks<<endl;
    cout<<stu.roll<<endl;
}
student change(student csstu){
    csstu.roll=78;
    return csstu;
}