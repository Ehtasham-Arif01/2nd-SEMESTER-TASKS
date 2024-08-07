// NAME : EHTASHAM ARIF
// ROLL NO : 23P-0567
// SECTION : BCS-2A

//Header files
#include<iostream>
using namespace std;

////////////////////Class named Ocean_Navigation.//////////////////
class Ocean_Navigation {
private:
//data members 
    int *degrees;
    float *minutes;
    char *direction;

public:
    //////////////////// Constructor.//////////////////
    Ocean_Navigation(){
        // Allocating the data members dynamically.
        degrees = new int;
        minutes = new float;
        direction = new char;

//As asked that firstly the values should be initiized and,
//printed by the constructer therefore.
//fixing some values to print first.
//then After printing taking data from user.
        *degrees=78;
        *minutes=34.6;
        *direction='W';
    }

    //////////////////// Destructor.//////////////////
    ~Ocean_Navigation() {
        // Deallocating the dynamically allocated data members.
        delete degrees;
        delete minutes;
        delete direction;
    }


////////////////////parameterized constructer//////////////////
Ocean_Navigation(int degree_input, float minute_input, char direction_input)
{
    *degrees = degree_input;
    *minutes = minute_input;
    *direction = direction_input;

}

////////////////////Copy Constructer...//////////////////
Ocean_Navigation(const Ocean_Navigation &obj)
{
    //Allocating memory Dynamically.
        degrees = new int;
        minutes = new float;
        direction = new char;

//////////copying the contents of the objets into another./////////

            *degrees = *(obj.degrees);
            *minutes = *(obj.minutes);
            *direction = *(obj.direction);

}

/////////////////Function to set the data entered by the user./////////
    void set_degree(int degree_input) {
        *degrees = degree_input;
    }

    void set_minute(float minute_input) {
        *minutes = minute_input;
    }

    void set_direction(char direction_input) {
        *direction = direction_input;
    }

//////////////////Function to display the data.//////////////////
    void display_data() {

        //value is specified in get data function
        if(*direction=='E' || *direction=='W')
        {
            cout<<"\n\n|**---------------------------------------**|\n";
            cout<<"\n\t==>  LONGITUDE  : "<<*degrees<<"\xF8"<<*minutes<<"' "<<*direction<<endl<<endl;
            cout<<"|**---------------------------------------**|\n\n";
        }
        else
        {
            cout<<"\n\n|**---------------------------------------**|\n";
            cout<<"\n\t==>  LAATITUDE  : "<<*degrees<<"\xF8"<<*minutes<<"' "<<*direction<<endl<<endl;
            cout<<"|**---------------------------------------**|\n\n";
        }

    }
};//end of class

////////Function to dynamically allocate the object and set its values./////////

//we can write/link this function in class 
//but as Asked so created a seprate function.
void Allocate_Objects(Ocean_Navigation *&obj1, Ocean_Navigation *&obj2,int degree_input, float minute_input, char direction_input) {
    //Allocating the memmory dynamically
    obj1 = new Ocean_Navigation;

    // initilizing the values by the constructer...
    obj1->set_degree(degree_input);
    obj1->set_minute(minute_input);
    obj1->set_direction(direction_input);

    //creating object to copy data.
    //passing the object 1 for deep copy.
    obj2 = new Ocean_Navigation(*obj1);

    // Displaying the data.
    obj1->display_data();


}


////////////////////function to get data from the user.//////////////////

//we can write/link this function in class 
//but as asked so created a seprate function.
void Get_Data(int &degree, float &minute, char &direction)
{

 // Variable to track the error message display.
    int i;

    ////////  Inputting degree value.  ////////
    //Restriction applied to get most precise input
     i = 0;
    do {
       
        if (i > 0) {
            cout << "\n***ERROR_____________!\nDEGREE VALUE SHOULD BE BETWEEN (0 TO 180)\n\n";
        }
        cout << "\n==> ENTER THE DEGREES (in integer i.e : 45, etc): ";
        cin >> degree;
        ++i;
    } while (degree < 0 || degree > 180);

    ////////  Inputting minute value. ///////
    //Restriction applied to get most precise input
     i = 0;
    do {
       
        if (i > 0) {
            cout << "\n***ERROR_____________!\nMINUTES VALUE SHOULD BE BETWEEN 0 TO 60 \n\n";
        }
        cout << "\n==> ENTER THE MINUTES (in float i.e : 31.4, etc): ";
        cin >> minute;
        ++i;
    } while (minute < 0.0 || minute > 60.0);

    ///////////  Inputting the direction.  ////////////
    //Restriction applied to get most precise input
     i = 0;
    do {
       
        if (i > 0) {
            cout << "\n***ERROR_____________!\nPLEASE ENTER E, W, N, S: \n\n";
        }
        cout << "\n==> ENTER THE DIRECTION (in char i.e : E, W, N, S): ";
        cin >> direction;
        ++i;
    } while (direction != 'E' && direction != 'W' && direction != 'N' && direction != 'S');

//Specifying the East and west by the Degree and Direction
//if degree>90 then direction must be EAST or WEST

    if((degree>90.0) && (direction!='E' && direction!='W'))
    {
    do{
        cout<<"\n***ERROR_____________!\nAS DEGREE > 90.0 SO DIRECTION MUST BE  'E' or 'W'\n\n";
        cout << "\n==> ENTER THE DIRECTION (in char i.e : E, W, N, S, etc): ";
        cin >> direction;
        
    }while ((degree>90.0) && (direction!='E' && direction!='W'));
    }

}

////////////////////Main Function//////////////////.
int main() {

cout<<"\n\n****___________________ WELCOME! ___________________****\n\n";
 
//making an object to call constructer 
//as aksed to print values of the constructer first
Ocean_Navigation obj;
cout<<"\n\t**____CONSTRUCTER INITILZED VALUES____**\n";
//calling display function to display,
//values initilized by the constructer.
obj.display_data();

 //Declaring the objects that will be declared dynamically 
 //in a seprate function
 Ocean_Navigation *Object1=nullptr;
 Ocean_Navigation *Object2=nullptr;


//local avriables to get user input data.
cout<<"\n**_______ NOW INPUTTING VALUES FROM USER______**\n\n";
    int degree;
    float minute;
    char direction;

    int choice;

//using loop to repete the process
do{
    //calling function to get the data from the user.
    
    Get_Data(degree,minute,direction);

//passing the objects to function to alloacte them dynamically.

//then initilizing values by the constructer....
    Allocate_Objects(Object1,Object2,degree,minute,direction);

//this loop will ask for the user to choice the optio 1 or 2.
//i is used to track the invalid choice.
    int i=0;
    do{
        
        if(i>0)
        {
            cout<<"\n***ERROR_____________!\n PLEASE SELECT 1 or 2 OPTION\n\n";
        }
    cout<<"\n\n\t____**DO YOU WANT TO ENTER ANY OTHER DATA**____\n\n";
    cout<<"\n\t ==> 1)  YES SURE...\n";
    cout<<"\n\t ==> 2)  NO QUIT...\n\n";
    cin>>choice;
    if(choice==2)
    {
        cout<<"\n\n****__________EXITING PROGRAM....\n";
    }
    ++i;
    }while(choice!=1 && choice!=2);


 }while(choice!=2);


    // Deleting the Dynamically Allocated objects.
    delete Object1;
    delete Object2;

cout<<"\n\n****___________________ PROGRAM ENDED! ___________________****\n\n";
    return 0;
}
