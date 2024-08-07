#include <iostream>
#include <string>

using namespace std;

class FoodItem {
private:
//Member variables
    string name;
    int calories;
    int gramsOfFat;
    int gramsOfCarbs;
    int gramsOfProtein;

public:
    // Constructors with different parmeters
    FoodItem(string n) : name(n) {
        calories = 0;
        gramsOfFat = 0;
        gramsOfCarbs = 0;
        gramsOfProtein = 0;
    }

    FoodItem(string n, int c) : name(n), calories(c) {
        gramsOfFat = 0;
        gramsOfCarbs = 0;
        gramsOfProtein = 0;
    }

    FoodItem(string n, int c, int f, int cb, int p) : name(n), calories(c), gramsOfFat(f), gramsOfCarbs(cb), gramsOfProtein(p) {}


    // Setter method for name
    void setName(string n) { name = n; }
    // Getter method for name
    string getName() { return name; }

    // Setter method for calories
    void setCalories(int c) {
        calories = c;
    }
    // Getter method for calories
    int getCalories() { return calories; }

    // Setter method for fat
    void setFat(int f) {
        gramsOfFat = f;
    }
    // Getter method for fat
    int getFat() { return gramsOfFat; }

    // Setter method for carbohydrates
    void setCarbs(int cb) {
        gramsOfCarbs = cb;
    }
    // Getter method for carbohydrates
    int getCarbs() { 
        return gramsOfCarbs; 
    }

    // Setter method for protein
    void setProtein(int p) {
        gramsOfProtein = p;
    }
    // Getter method for protein
    int getProtein() { 
        return gramsOfProtein; 
    }

    // Friend function to calculate calories
    friend int calculateCalories(int carbs, int proteins, int fat);
};

// Function to calculate calories
int calculateCalories(int carbs, int proteins, int fat = 0) {
    return (4 * carbs) + (4 * proteins) + (9 * fat);
}

int main() {
    string name;
    int protein, carbs, fat;

    while (1) {
        // Prompt user to enter food item name
        cout << "Enter food item name (or type 'exit' to quit): ";
        getline(cin, name);

        // Check if user wants to exit
        if (name == "exit") {
            break;
        }

        // Prompt user to enter protein content
        cout << "Enter protein content (grams): ";
        cin >> protein;

        // Prompt user to enter carbohydrate content
        cout << "Enter carbohydrate content (grams): ";
        cin >> carbs;

        // Prompt user to enter fat content
        cout << "Enter fat content (grams, if available. Enter 0 if not): ";
        cin >> fat;
        cin.ignore(); // Clear the newline character from the input buffer

        // Create FoodItem object
        FoodItem item(name, calculateCalories(carbs, protein, fat), fat, carbs, protein);

        // Output food item details
        cout << "Food Item Details:" << endl;
        cout << "Name: " << item.getName() << endl;
        cout << "Protein (g): " << item.getProtein() << endl;
        cout << "Carbs (g): " << item.getCarbs() << endl;
        cout << "Fat (g): " << item.getFat() << endl;
        cout << "Calculated Calories: " << item.getCalories() << endl;
    }

    return 0;
}