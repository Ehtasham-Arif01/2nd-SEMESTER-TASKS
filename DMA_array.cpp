#include<iostream>
using namespace std;

int main()
{

//inputing the size of the array from the user.
int size;
cout<<"\nENTER THE SIZE OF THE ARRAY : ";
cin>>size;

//declaring dynamic array.
int *array=new int[size];

//inilizing the array.
cout<<"\nENTER THE ELEMENTS TO STORE IN ARRAY : \n"<<endl;
for(int i=0;i<size;i++)
{
    cout<<"VALUE "<<i+1<<" : ";
    cin>>array[i];
}

//printing the elements of the array.
cout<<"\nELEMENTS OF THE ARRAY ARE FOLLOWING : \n"<<endl;
for(int i=0;i<size;i++)
{
    cout<<" | "<<array[i]<<" | ";
}
cout<<endl<<endl;

return 0;
}