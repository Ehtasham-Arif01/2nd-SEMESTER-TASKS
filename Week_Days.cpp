// NAME : EHTASHAM ARIF

//Header files
#include<iostream>
//using <cstring> to work with strings
#include<cstring>
using namespace std;


/// using class named DayType..
class DayType {
private:
//data member
    string *week_day;

public:
    // Default constructor
    DayType() {

        //Allocating memory dynamically
        week_day = new string;
    }

    // Destructor
    ~DayType() {
        
        //Deallocating memory.
        delete week_day;
    }

    // performing Deep Copy
    DayType(const DayType &obj) {
        // Allocate memory for the new string
        week_day = new string;

        // Copying the contents of the string
        *week_day = *obj.week_day;
    }

    /////////Function to set the day//////////////

    void set_day(string day_input) {

        //setting the day passesd.
        *week_day=day_input;
    }

    /////////////Function to print the day////////////
    void print_day() {
        cout<<"\n\n|**-------------------------------------------------**|\n";
        cout << endl << "\tPRINTING .. : THE DAY IS : " << *week_day << endl << endl;
        cout<<"|**-------------------------------------------------**|\n\n";
    }


    //////////Function to get the day/////////////////
    string get_day() {
        return *week_day;
    }


    /////////Function to return previous day//////////
    string get_previous_day(string day_update) {
        int index = 0;
        //using the array of string
        string days[] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
        
        //searching for the desired day.
        for (int i = 0; i < 7; i++) {
            if (day_update == days[i]) {

                //finding the index of the prevoius day of week.
                index = (((i - 1) + 7) % 7);
                break;
            }
        }
        
        //returning the prevoius day.
        return days[index];
    }

    ///////////Function to return the next day//////////////
    string get_next_day(string day_update) {
        int index = 0;
        //using the array of string
        string days[] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
        
        //searching for the desired day.
        for (int i = 0; i < 7; i++) {
            if (day_update == days[i]) {

                //finding the index of the next day of week.
                index = (((i + 1) + 7) % 7);
                break;
            }
        }

    //Returning the next day.
        return days[index];
    }

    ///////////Function to add days and return the days//////////////////////
    string add_days(int days_added, string day_update) {
        int index = 0;
        //using the array of string
        string days[] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
        
          //searching for the desired day.
        for (int i = 0; i < 7; i++) {
            if (day_update == days[i]) {
                index = i;
                break;
            }
        }
       //finding the index after adding the days.
        index = ((index + days_added) % 7);
        
        //returning the day after adding.
        return days[index];
    }
};

//////////////////////Main function////////////////////////////
int main() {

    cout<<"\n////////////////////////*** WELCOME ***////////////////////////\n";

    //dynamicaaly allocated objects
    DayType *day = new DayType();
    //object to copy the days.
    //passing the origional object for deep copy.
    DayType *day2 = new DayType(*day);

    string new_day;
    int choice;
    //using to track the invalid inputs
    int j=0;
    int counter=0;

    do {
        cout<<"\n\t////////////*** MENU ***//////////////\n\n";
        cout << "1) SET THE DAY " << endl;
        cout << "2) PRINT THE CURRENT DAY " << endl;
        cout << "3) RETURN THE DAY " << endl;
        cout << "4) RETURN THE PREVIOUS DAY " << endl;
        cout << "5) RETURN THE NEXT DAY " << endl;
        cout << "6) RETURN DAY BY ADDING DAYS INTO CURRENT DAYS " << endl;
        cout << "7) EXIT THE PROGRAM " << endl;
        cout << "\n\nENTER THE OPERATION YOU WANT TO PERFORM :" << endl;
        cout <<"\nPLEASE CHOOSE THE OPTION ( 1 to 7 ) : ";
        cin  >> choice;
        
    //Error message for the user if he choice..
    //any other option before setting the day.
 
            if(choice==1)
        {
            j=-1;
        }

    if(j!=-1)
    {
 if(choice!=1 && choice!=7)
    {
        int i=0;
        do{
            if(i>=0)
            {
                cout<<"\n***WARNING!_________\n\nPLEASE SET THE DAY FIRST\n\n";
            }
        cout <<"\nPLEASE CHOOSE THE OPTION ( 1 to 7 ) : ";
        cin  >> choice;
        if(choice==1)
        {
            j=-1;
        }
        ++i;
        }while(choice!=1 && choice!=7);
        //until the user set the day or choose to exit.
    }

    }
   
    //using switch case to match choice with cases.
        switch(choice) {
            case 1: {

        //using loop to repeat the input till valid input
        //updating the counter value and displayig messsage,,,
        //incase of valid inputs.
        do{

            //getting day from the user.
            cout << "PLEASE ENTER THE DAY : "<<endl;
            cout<<"\nLIKE MON OR mon OR Mon FOR MONDAY ...etc : ";
            cin >> new_day;

    
        //setting the day properly by use if else structure.
        if(new_day=="sun" || new_day=="SUN" || new_day=="Sun")
        {
            new_day="SUNDAY";
            counter=1;
            cout<<"\n\t==> **--DAY SETTED SUCCESSFULLY!--**\n\n";
        }
        else if(new_day=="mon" || new_day=="MON" || new_day=="Mon")
        {
            new_day="MONDAY";
            counter=1;
            cout<<"\n\t==> **--DAY SETTED SUCCESSFULLY!--**\n\n";
        }
        else if(new_day=="tue" || new_day=="tue" || new_day=="Tue")
        {
            new_day="tuesDAY";
            counter=1;
            cout<<"\n\t==> **--DAY SETTED SUCCESSFULLY!--**\n\n";
        }
        else if(new_day=="wed" || new_day=="WED" || new_day=="Wed")
        {
            new_day="WEDNESDAY";
            counter=1;
            cout<<"\n\t==> **--DAY SETTED SUCCESSFULLY!--**\n\n";
        }
        else if(new_day=="thu" || new_day=="THU" || new_day=="Thu")
        {
            new_day="THURSDAY";
            counter=1;
            cout<<"\n\t==> **--DAY SETTED SUCCESSFULLY!--**\n\n";
        }
        else if(new_day=="fri" || new_day=="FRI" || new_day=="Fri")
        {
            new_day="FRIDAY";
            counter=1;
            cout<<"\n\t==> **--DAY SETTED SUCCESSFULLY!--**\n\n";
        }
        else if(new_day=="sat" || new_day=="SAT" || new_day=="Sat")
        {
            new_day="SATURDAY";
            counter=1;
            cout<<"\n\t==> **--DAY SETTED SUCCESSFULLY!--**\n\n";
        }

        //incase of invalid inputs ....
        else{
            cout<<"\n**ERROR!_______\n**______INVALID DAY ENTERED____**\n\nENTER ONLY FIRST THREE DIGITS OF DAY\n\n";
        }

        }while(counter==0);
 
                //setting the day entered.
                day->set_day(new_day);
                break;
            }
            case 2: {
                //calling print_day function to print the day.
                day->print_day();
                break;
            }
            case 3: {
                //retyurning the day...
                //means setting the current enterned day.
                day->set_day(new_day);
                
                cout<<"\n\n|**-------------------------------------------------**|\n";
                cout << "\n\t  DAY RETURNED SUCCESSFULLY!\n\n";
                cout<<"|**-------------------------------------------------**|\n\n";
                break;
            }
            case 4: {
                //returning the prevoius day.
                //passing the day that is updated means in curent.
                //i am updating the day with each calling for the current day.
                //so when you again call then the updated day will be used.
                new_day=(*day).get_previous_day(new_day);
                
                //updating the current day by the prevoius day
                day->set_day(new_day);
                cout<<"\n\n|**-------------------------------------------------**|\n";
                cout << "\n\tPREVIOUS DAY RETURNED SUCCESSFULLY! \n\n\t WHICH IS ===> Day: " <<new_day<< endl<<endl;
                cout<<"|**-------------------------------------------------**|\n\n";
                break;
            }
            case 5: {
                //returning the next day.
                //passing the day that is updated means in curent.
                //i am updating the day with each calling for the current day.
                //so when you again call then the updated day will be used.
                new_day=(*day).get_next_day(new_day);
                
                //updating the current day by th enext week day.
                day->set_day(new_day);
                cout<<"\n\n|**-------------------------------------------------**|\n";
                cout << "\n\tNEXT DAY RETURNED SUCCESSFULLY! \n\n\t WHICH IS ===> Day: " <<new_day<< endl<<endl;
                cout<<"|**-------------------------------------------------**|\n\n";
                break;
            }
            case 6: {
                //adding the days to the current day.
                //passing the day that is updated means in curent.
                //i am updating the day with each calling for the current day.
                //so when you again call then the updated day will be used.
                int days_added;
                cout << "ENTER THE NO OF DAYS YOU WANT TO ADD IN CURRENT DAY :";
                cin >> days_added;

                //returning the days after adding into current day.
                new_day=(*day).add_days(days_added,new_day);
                
                //updating the current day after adding
                day->set_day(new_day);
                cout<<"\n\n|**-------------------------------------------------**|\n";
                cout << "\n \tDAYS ADDED SUCCESSFULLY! \n\n\t FINAL DAY IS ===> Day: " <<new_day<< endl<<endl;
                cout<<"|**-------------------------------------------------**|\n\n";
                break;
            }
            case 7: {
                //program ending 
                cout<<"\nEXITING PROGRAM....\n"<<endl;
                break;
            }
            default: {
                //incase of invalid input by the user choice.
                cout << "\n\tERROR!\nINVALID CHOICE \n";
                break;
            }
        }
    } while(choice != 7);

    // Deallocating the objects
    delete day;
    delete day2;

    cout<<"\n////////////////////////*** PROGRAM ENDED ***////////////////////////\n\n";
   
    return 0;
}
