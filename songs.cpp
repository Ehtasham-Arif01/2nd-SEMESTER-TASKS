//  ==> NAME : EHTASHAM ARIF
//  ==> ROLL NO : 23P-0567
//  ==> SECTION : BCS-2A

//Header Files
#include<iostream>
using namespace std;

//class named Favourite_songs
class Favourite_songs{
    private:
    //data members
    int size;
    string *song_name;

    public:
    //constructer.
    Favourite_songs(int size_input){
        size=size_input;
        //allocating the memory dynamically to the array
        song_name=new string[size_input];
    }

    //destructer.
    ~Favourite_songs()
    {
        //deallocating the array
        delete[] song_name;
    }

    //setter
    void set_name(int index, const string &name_input)
    {
        //setting the name of he song entered by the user
        song_name[index]=name_input;
    }

    //getter.
    string get_name(int index)
    {
        //retruning the value of the array
        return song_name[index];
    }

    //copy constructer to create the backup of the songs names.
    Favourite_songs(const Favourite_songs &obj)
    {
        //specifying the size of the array.
        size=obj.size;
        //allocating memory dynamically.
        song_name=new string[size];
        //copying the data
        for(int i=0;i<size;i++)
        {
            song_name[i]=obj.song_name[i];
        }

        cout<<"\n\tBACKUP DONE SUCCESSFULLY!\n";
    }


    ////////////function to print song_names stoed in array.//////////////
    void print_song_names() const{
        cout<<"\nSONGS NAMES ARE AS FOLLOWS : \n\n";
       for(int i=0;i<size;i++)
        {
            cout<<"INDEX - "<<i+1<<" : "<<song_name[i]<<endl;
        }
        cout<<endl;
    }

   /////////////function to add the names of new songs.///////////////////
    void add_songs() {

    //using a temporary pointer to store the data
        string *temp;
    //increasing the size of the array by 1.
        int new_size=size+1;
        temp=new string[new_size];
        string new_song;
    //taking the name of new song from the user
        cout<<"ENTER THE NAME OF NEW SONG : ";
        cin.ignore();//using ignore function to clear newline
        getline(cin,new_song);
    //copying the old data stored in array.
        for(int i=0;i<size;i++)
        {
            temp[i]=song_name[i];
        }
    //saving the new song also in the array.
        temp[size]=new_song;
    //deleting the data of the old array.

        delete[] song_name;
        song_name=NULL;

    //assingning the temporary pointer to the original.
        song_name=temp;
    //making temporary pointer null.
        temp=NULL;

    //updating the size of the array.
        size=new_size;

     cout<<endl<<"===>\tSONG NAME | "<<new_song<<" | ADDED SUCCFULLY IN THE ARRAY \n"<<endl;

    }


    //////////////////function to delete the name of song from the array./////////////////////
    void delete_songs(){
        string song;
    //taking the name of song from the user
        cout<<"ENTER THE NAME OF  SONG : ";
        cin.ignore();//using ignore function to clear the newline
        getline(cin, song);
    
        int count=0;
        int point=0;
    
    //searching the song entered
    for(int i=0;i<size;i++)
    {
        if(song_name[i]==song)
        {
            ++count;
            /*fixing the index (point) beacuse if two same names
            are stoed then it will lead to deletion of both
            by fixing it it will delete only first element*/
            point=i;
            break;
        }
    }
//if song found then..
    if(count!=0)
    {
        //creating a temporay pointer
        string *temp;
        //reducing the sie of the pointer by 1.
        int new_size=size-1;
        //allocating memory to array dynamically
        temp=new string[new_size];

        int j=0;
        ///copying the values of the array.
        for(int i=0;i<size;i++)
        {
            //to skip the matched name song
            if(i!=point)
            {
                temp[j]=song_name[i];
                j++;
            }
        }

    //clearing the old araary
        delete[] song_name;
        song_name=NULL;

    //assingning the temporary pointer to the original.
        song_name=temp;
    //making temporary pointer null.
        temp=NULL;

    //updating the size of the array.
        size=new_size;

     cout<<endl<<"===>\tSONG NAME | "<<song<<" | DELETED SUCCFULLY FROM THE ARRAY \n"<<endl;
    }
    //if song entered not found then..
    else{
        cout<<"\nERROR!\nSONG NOT FOUND\n\n";
    }

    }

};//end of the class 

/////////////////////"""MAIN FUNCTION"""""//////////////////////
int main()
{

cout<<"\n///////////////**** WELCOME ****///////////////"<<endl;
int array_size;
//getting array size from the user
cout<<"\nENTER THE NUMBER OF SONGS YOU WANT TO STORE :\n\t ===> ( ARRAY SIZE )  : ";
cin>>array_size;
//using ignore functio to clear the newline.
cin.ignore();

//making the array of object
Favourite_songs list(array_size);

//inputing the song names.
string name;
cout<<"\nPLEASE ENTER THE NAMES OF SONGS : \n\n";
for(int i=0;i<array_size;i++)
{
    cout<<"\tINDEX - "<<i+1<<" : ";
    getline(cin,name);
    //to store the name.
    list.set_name(i, name);
}
cout<<endl<<endl;
int choice;

//to Repeate the menu
do{
    cout<<"MENU : "<<endl;
    cout<<"1) PRINT THE ARRAY "<<endl;
    cout<<"2) ADD SONG IN THE ARRAY "<<endl;
    cout<<"3) DELETE A SONG FROM THE ARRAY "<<endl;
    cout<<"4) CREATE A BACKUP OF THE SONGS "<<endl;
    cout<<"5) EXIT THE PROGRAM "<<endl;
    cin>>choice;

//using switch statement.
    switch(choice)
    {
        case 1:
        {
            //calling function to print the names.
            list.print_song_names();
            break;
        }

        case 2:
        {
            //calling function to Add the song.
            list.add_songs();
            break;
        }

        case 3:
        {
            //calling function to delete the song.
            list.delete_songs();
            break;
        }

        case 4:
        {
            //creating the new object,,
            //using the original array to copy data values
            Favourite_songs backup(list);
            break;
        }

        case 5:
        {
            //Exiting the program.
            cout<<"\n\tPROGRAM EXITING....\n\n";
            break;
        }

        default:
        {
            cout<<"\nERROR! \nPLEAESE INPUT A VALID CHOICE \n\n";
            break;
        }
    }
}while(choice!=5);

//program Ended.
cout<<"\n///////////////**** PROGRAM ENDED ****///////////////\n"<<endl;
return 0;
}