#include<iostream>
using namespace std;

class papulation_rate{
private:
    int birth_rate;
    int death_rate;
    int papulation;

public:
    //default constructor.
    papulation_rate() {
        birth_rate = 0;
        death_rate = 0;
        papulation = 0;
    }

    //parameterized constructor.
    papulation_rate(int a, int b, int c) {
        papulation = a;
        birth_rate = b;
        death_rate = c;
    }

    //getter methods
    int get_papulation() {
        return papulation;
    }

    int get_birth() {
        return birth_rate;
    }

    int get_death() {
        return death_rate;
    }

    //setter methods
    void setpapulation(int a) {
        papulation = a;
    }

    void setbirth_rate(int b) {
        birth_rate = b;
    }

    void setdeath_rate(int c) {
        death_rate = c;
    }

    //calculating birth rate
    float cal_birth_rate() {
        float b_rate = (float)birth_rate / papulation;
        return b_rate;
    }

    //calculating death rate
    float cal_death_rate() {
        float d_rate = (float)death_rate / papulation;
        return d_rate;
    }
};

int main() {
    int birth_rate, death_rate, papulation;

    cout << "ENTER POPULATION RATE:";
    cin >> papulation;
    if (papulation < 1) {
        cout << "ERROR! POPULATION SHOULD BE > 1 " << endl;
        cout << "ENTER POPULATION RATE AGAIN:";
        cin >> papulation;
    }

    cout << "ENTER THE NUMBER OF BIRTHS :";
    cin >> birth_rate;
    if (birth_rate < 0) {
        cout << "ERROR! BIRTH RATE BE >= 0 " << endl;
        cout << "ENTER THE NUMBER OF BIRTHS :";
        cin >> birth_rate;
    }

    cout << "ENTER THE NUMBER OF DEATHS :";
    cin >> death_rate;
    if (death_rate < 0) {
        cout << "ERROR! DEATH RATE BE >= 0 " << endl;
        cout << "ENTER THE NUMBER OF DEATHS :";
        cin >> death_rate;
    }

    papulation_rate r1;
    r1.setpapulation(papulation);
    r1.setbirth_rate(birth_rate);
    r1.setdeath_rate(death_rate);

    cout << endl << "THE BIRTH RATE IS : " << r1.cal_birth_rate() << endl;
    cout << "THE DEATH RATE IS : " << r1.cal_death_rate() << endl << endl;

    return 0;
}
