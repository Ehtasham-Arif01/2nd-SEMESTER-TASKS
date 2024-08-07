#include<iostream>
using namespace std;

struct Moviedata {
    string title;
    string director;
    int year_released;
};

Moviedata create_movie_data();
void display_movie_data(Moviedata);

int main() {
    Moviedata variable1, variable2;
    variable1 = create_movie_data();
    display_movie_data(variable1);
    return 0;
}

Moviedata create_movie_data() {
    Moviedata m;
    cout << "ENTER THE TITLE OF MOVIE: ";
    getline(cin, m.title);
    cout << "ENTER THE DIRECTOR NAME: ";
    getline(cin, m.director);
    cout << "ENTER THE YEAR RELEASED: ";
    cin >> m.year_released;
    return m;
}

void display_movie_data(Moviedata m) {
    cout << "\n\nTITLE OF THE MOVIE IS: " << m.title << endl;
    cout << "THE NAME OF DIRECTOR IS: " << m.director << endl;
    cout << "THE YEAR RELEASED IS: " << m.year_released << endl;
}