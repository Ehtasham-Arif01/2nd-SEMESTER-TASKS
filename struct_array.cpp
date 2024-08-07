#include<iostream>
using namespace std;

struct student{
    int id_num;
    int test_score[3];
    int final_marks;
};
int main()
{
    student s1,s2;
    s1.id_num= 999;
    s1.test_score[0]=89;
    s1.test_score[1]=46;
    s1.test_score[2]=99;
    s1.final_marks=98;

    cout<<"THE STUDENT ID NUM IS : "<<s1.id_num<<endl;
    cout<<"THE MARKS OF STUDENT IN TEST NO 01 :"<<s1.test_score[0]<<endl;
    cout<<"THE MARKS OF STUDENT IN TEST NO 02 :"<<s1.test_score[1]<<endl;
    cout<<"THE MARKS OF STUDENT IN TEST NO 03 :"<<s1.test_score[2]<<endl;
    cout<<"THE FINAL EXAM MARKS OF THE STUDENT ARE : "<<s1.final_marks<<endl;

    return 0;
}