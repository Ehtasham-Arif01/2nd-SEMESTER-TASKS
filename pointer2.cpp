#include<iostream>
using namespace std;
int main()
{
    int arr[5][5];
    int (*ptr)[5];
    ptr=arr;


    int a=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
             *(*(ptr+i)+j)=a;
            a++;
        }
            
        
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<(*(*ptr+i)+j)<<"  ";
            
           
        }
        cout<<endl;
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
           
            cout<<(*(ptr+i)+j)<<"  ";
           
        }
        cout<<endl;
    }

    return 0;
}