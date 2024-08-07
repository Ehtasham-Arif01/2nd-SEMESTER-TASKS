#include<iostream>
using namespace std;
int main()
{

    int col;
    int row;
    cout<<"ENTER THE NO OF ROWS   :";
    cin>>row;
    
    cout<<"ENTER THE NO OF COLUMS :";
    cin>>col;

    int arr1[row][col];
    int arr2[row][col];
    int mul[row][col];

    //font input arr1...

cout<<"ENTER VALUES FOR MATRIX - 01 : ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr1[i][j];
        }
        
    }

      //font input arr2...

cout<<"ENTER VALUES FOR MATRIX - 02 : ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr2[i][j];
        }
       
    }

    // Using nested loops....
    if(col==row)
    {

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mul[i][j]=0;
                for(int k=0;k<row;k++)
                mul[i][j] = mul[i][j] + (arr1[i][k] * arr2[k][j]);

            }
        }

        //printing the mul array..
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<mul[i][j]<<" ";
        }
        cout<<endl;
    }

    }
    else
    {
        cout<<"\n\nERROR!  MATRIX MULTIPLICATION ONLY POSSIBLE WHEN COLUMS==ROWS "<<endl<<endl;
    }


    

    return 0;
}