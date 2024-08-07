#include<iostream>
#include<string>
using namespace std;

class engine{
    public:
    string type;
    engine(string t):type(t){
        cout<<"ENGINE CONSTRIUCETR\n";
    }
    ~engine()
    {
        cout<<"ENGINE DESTRUCTER\n";
    }
    void show()
    {
        cout<<"STRATING "<<type<<" engine"<<endl;
    }
};
class car{
    public:
    string model;
    engine e;
    car(string m,string t):model(m),e(t){
        cout<<"\nCAR CONSTRUCTER\n";
    }
    ~car()
    {
        cout<<"\nCAR DSTRUCTER\n";
    }
    void show()
    {
        e.show();
        cout<<"car of moedl "<<model;
    }
};

int main()
{
    car c("AUDI","V8");
    c.show();
    return 0;
}