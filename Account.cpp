#include<iostream>
using namespace std;

class Bank_Acccount{
    protected:
    int acc_no;
    double balance;

    public:
    Bank_Acccount(int acc_input=0, double balance_input=0.0): acc_no(acc_input), balance(balance_input){

    }

    //set 
    void set_acc(int acc_input){
        this->acc_no=acc_input;
    }

    void set_balance(double balance_input){
        this->balance=balance_input;
    }

    //get

    int acc_no(){
        return acc_no;
    }

    double balance(){
        return balance;
    }

    void deposit()
    {
        int deposit;
        cout<<"ENTER THE DEPOSIT AMOUNT :";
        cin>>deposit;
        balance=balance + deposit;
        cout<<"\nAMOUNT DEPOSITED SUCCESSFULLY! \n\n";

    }

    void withdraw()
    {
        int withdraw;
        cout<<"ENTER THE AMOUNT TO WITHDRAW : ";
        cin>>withdraw;
        if(balance>withdraw)
        {
            balance=balance-withdraw;
            cout<<"\nAMOUNT WITHDRAW SUCCESSFULLY! \n\n";
        }
        else{
            cout<<"\nPLEASE ENTER VALID AMOUNT !\n\n";
        }
        
    }

    void display_acc()
    {
        cout<<"ACCOUNT NUMBER IS : "<<acc_no<<endl;
        cout<<"BALANCE IS : "<<balance<<endl;
    }

};

class saving_acc: public Bank_Acccount{
    protected:
    float intrest;
    public:

    saving_acc(int acc_no_input, double balance_input) : Bank_Acccount(acc_no_input,balance_input){

    }

    void set_intrest()
    {
        cout<<"ENTER THE INTREST RATE : ";
        cin>>intrest;
        intrest=(balance/10);
        balance=balance*intrest;
    }

    void post_intrest()
    {
        cout<<"intrest rate is :"<<intrest<<endl;
    }

};

int main()
{
Bank_Acccount a1;
saving_acc a2;
int acc;
double balance;

int choice;
do{
    cout<<"1) SET ACCOUNT NO :";
    cout<<"2) SET BALANCE : ";
    cout<<"3) DEPOSIT MONEY :";
    cout<<"4) WITHDRAW MONEy :";
    cout<<"5) SET INTREST RATE :";
    cout<<"6) PRINT INTREST RATE :";
    cin>>choice;

    switch(choice){
    case 1:
    {
        cout<<"ENTER THE ACCOUNT NO : ";
        cin>>acc;
        a1.set_acc(acc);
    }
    case 2:
    {
        cout<<"ENTER THE BALANCE AMOUNT :";
        cin>>balance;
        a1.set_balance(balance);
    }
    case 3:
    {
        a1.deposit();
    }
    case 4:
    {
        a1.withdraw();
    }
    case 5:
    {
        a2.set_intrest();
    }
    case 6:
    {
        a2.post_intrest();
    }
    case 7:
    {
        cout<<"\nEXITING ....\n\n";
    }

    default:
    {
        cout<<"INVALID CHOICE !\nPLEASE ENTER VALID CHOICE \n\n";
    }
    }

}while(choice!=7);



    return 0;
}