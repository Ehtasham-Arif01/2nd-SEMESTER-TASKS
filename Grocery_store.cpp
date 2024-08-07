#include<iostream>
using namespace std;

class store{
    private:
    int id;
    string name;
    float price;
    int quantity;

    public:
    store()
    {
        //Default construvcetr//
    }

    store(int item_id,string item_name,float item_price, int item_quantity){

        this->id=item_id;
        this->name=item_name;
        this->price=item_price;
        this->quantity=item_quantity;

    }

//Destructer...

    ~store()
    {
        //CONSTRUCTER IS DESTROYED.....
    }


//Setters.

void setid(int item_id)
{
    this->id=item_id;
}

void setname(string item_name)
{
    this->name=item_name;
}

void setprice(float item_price)
{
    this->price=item_price;
}

void setquantity(int item_quantity)
{
    this->quantity=item_quantity;
}

//Getters

int getid()
{
    return id;
}

string getname()
{
    return name;
}

float getprice()
{
    return price;
}

int getquantity()
{
    return quantity;
}

};

//display function.
void display(store array[],int no_of_items)
{
    for(int i=0;i<no_of_items;i++)
    {
        cout<<"\n\t\tITME NO : | "<<i+1<<" | \n\n";
        cout<<"THE ITEM'S ID IS  : "<<array[i].getid()<<endl;
        cout<<"THE ITEM'S NAME IS  : "<<array[i].getname()<<endl;
        cout<<"THE ITEM'S PRICE IS   : "<<array[i].getprice()<<endl;
        cout<<"THE ITEM'S QUANTITY IS  : "<<array[i].getquantity()<<endl<<endl;
    }

}

//update function
void update(store array[],int no_of_items)
{
    int id_search,option,new_price,new_quantity;
    int count=0;
    cout<<"ENTER THE ID YOU WANT TO UPDATE : ";
    cin>>id_search;
for(int i=0;i<no_of_items;i++)
{
if(id_search==array[i].getid())
{
        cout<<"THE ITEM'S ID IS  : "<<array[i].getid()<<endl;
        cout<<"THE ITEM'S NAME IS  : "<<array[i].getname()<<endl;
        cout<<"THE ITEM'S PRICE IS   : "<<array[i].getprice()<<endl;
        cout<<"THE ITEM'S QUANTITY IS  : "<<array[i].getquantity()<<endl<<endl;
        count=1;
        cout<<endl<<"WHAT DO WANT TO UPDATE :"<<endl;
        cout<<"1) PRICE "<<endl;
        cout<<"2) QUANTITY "<<endl<<endl;
        cin>>option;
    if(option==1)
         {
            cout<<"ENTER THE NEW PRICE OF THE ITEM :";
            cin>>new_price;
            array[i].setprice(new_price);
            cout<<"\n\n\t\tPRICE UPDATED SUCCESSFULLY! \n\n";
         }
    if(option==2)
        {
             cout<<"ENTER THE NEW QUANTITY OF THE ITEM :";
             cin>>new_quantity;
             array[i].setquantity(new_quantity);
             cout<<"\n\n\t\tQUANTITY UPDATED SUCCESSFULLY! \n\n";
        }
             break;
}
}
if(count!=1){
    cout<<"\n\t\tERROR! \n ENTERED ID NOT FOUND \n\n ";
}


}

//search function.
void search(store array[],int no_of_items)
{
    int id_search;
    int count=0;
    cout<<"ENTER THE ID YOU WANT TO SEARCH : ";
    cin>>id_search;
for(int i=0;i<no_of_items;i++)
{
if(id_search==array[i].getid())
{
        cout<<"THE ITEM'S ID IS  : "<<array[i].getid()<<endl;
        cout<<"THE ITEM'S NAME IS  : "<<array[i].getname()<<endl;
        cout<<"THE ITEM'S PRICE IS   : "<<array[i].getprice()<<endl;
        cout<<"THE ITEM'S QUANTITY IS  : "<<array[i].getquantity()<<endl<<endl;
        count=1;
        break;
}
}
if(count!=1){
    cout<<"\nERROR! \n ENTERED ID NOT FOUND \n\n ";
}

}
int main()
{
    int no_of_items;
    int item_quantity;
    string item_name;
    float item_price;
    int item_id;

    cout<<"ENTER THE NUMBER OF ITMES : ";
    cin>>no_of_items;

    store array[no_of_items];

    for(int i=0;i<no_of_items;i++)
    {
        cout<<"\n\n\t\tITME NO : | "<<i+1<<" | \n\n";
        cout<<"ENTER THE ITEM'S ID    : ";
        cin>>item_id;
        array[i].setid(item_id);

        cout<<"ENTER THE ITEM'S NAME  : ";
        cin>>item_name;
        array[i].setname(item_name);

        cout<<"ENTER THE ITEM'S PRICE :  ";
        cin>>item_price;
        array[i].setprice(item_price);

        cout<<"ENTER THE ITEM'S QUANTITY : ";
        cin>>item_quantity;
        array[i].setquantity(item_quantity);
    }

    int choice;
    
do{
    
    cout<<"\nSELECT THE OPERATION YOU WANT TO PERFORM\n\n";
    cout<<"\t1) DISPLAY ITMES "<<endl;
    cout<<"\t2) UPDATE ITMES DETAILS "<<endl;
    cout<<"\t3) SEARCH FOR ITMES BY ID "<<endl;
    cout<<"\t4) EXIT THE PROGRAM "<<endl<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            display(array,no_of_items);
            break;
        }
        case 2:
        {
            update(array,no_of_items);
            break;
        }
        case 3:
        {
            search(array,no_of_items);
            break;
        }
        default:
        {
            if(choice!=4)
            {
                cout<<"\n\tERROR!\n INPUT VALID CHOICE \n\n";
            }
            break;
        }
    }
}while(choice!=4);
   
cout<<"\n\n\t\tCONSTRUCTER IS DESTROYED\n\n";
   return 0;
}