#include<iostream>
using namespace std;
int main()
{
    int arr[5];
    int (*ptr)[5];
    ptr=&arr;
    int a=0;
    for(int i=0;i<5;i++)
    {
            *(*ptr+i)=a;
            a++;
        
    }

    for(int i=0;i<5;i++)
    {
            cout<<*(*ptr+i)<<endl;
            cout<<(*ptr+i)<<endl;
            cout<<endl;
        
    }

    return 0;
}