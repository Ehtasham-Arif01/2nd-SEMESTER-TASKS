#include<iostream>
using namespace std;

class Animal{
    private:
    string name;
    int age;

    public:
    Animal(string n,int a):name(n),age(a){

    }
//speak function 
    void speak()
    {
        cout<<"\n\nMY NAME IS : "<<name<<endl;
        cout<<"MY AGE iS  : "<<age<<endl;
    }

};

class bird:public Animal{

private:
float wing_length;
public:
//construcetr
bird(string n,int a, float l):Animal(n,a),wing_length(l){

}
void speak()
{
Animal::speak();
cout<<"I am a bird i can sing...\n"<<endl;
}

};

class reptile:public Animal{
    private:
    string habitat;
    public:
    reptile(string n,int a,string h):Animal(n,a),habitat(h){

    }
    //speak function
void speak()
{
    Animal::speak();
    cout<<"I am a reptile . I can Creep...\n\n"<<endl;
}

};

//main function()
int main()
{
    bird obj("PARROT",2,3.56);
    obj.speak();
    reptile obj1("FISH",4,"WATER");
    obj1.speak();

    return 0;

}