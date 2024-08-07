#include <iostream>
#include <string>

using namespace std;

// Base class for vehicles
class Vehicle {
protected:
    float mileage;
    float price;

public:
    // Constructor
    Vehicle(float _mileage, float _price) : mileage(_mileage), price(_price) {}

    // Display vehicle information
    void display() {
        cout << "Mileage: " << mileage << "\n";
        cout << "Price: " << price << "\n";
    }

    // Virtual destructor for proper cleanup
    ~Vehicle() {}
};

// Class for cars
class Car : public Vehicle {
protected:
    float ownershipCost;
    int warranty;
    int seatingCapacity;
    string fuelType;

public:
    // Constructor
    Car(float _mileage, float _price, float _ownershipCost, int _warranty, int _seatingCapacity, string _fuelType)
        : Vehicle(_mileage, _price), ownershipCost(_ownershipCost), warranty(_warranty),
          seatingCapacity(_seatingCapacity), fuelType(_fuelType) {}

    // Display car information
    virtual void display() {
        cout << "Car\n";
        Vehicle::display();
        cout << "Ownership Cost: " << ownershipCost << "\n";
        cout << "Warranty: " << warranty << " years\n";
        cout << "Seating capacity: " << seatingCapacity << "\n";
        cout << "Fuel type: " << fuelType << "\n";
    }
};

// Class for bikes
class Bike : public Vehicle {
protected:
    int numberCylinders;
    int numberGears;
    string coolingType;

public:
    // Constructor
    Bike(float _mileage, float _price, int _numberCylinders, int _numberGears, string _coolingType)
        : Vehicle(_mileage, _price), numberCylinders(_numberCylinders), numberGears(_numberGears),
          coolingType(_coolingType) {}

    // Display bike information
    virtual void display() {
        cout << "Bike\n";
        Vehicle::display();
        cout << "Number cylinders: " << numberCylinders << "\n";
        cout << "Number gears: " << numberGears << "\n";
        cout << "Cooling type: " << coolingType << "\n";
    }
};

// Subclasses of Car
class Audi : public Car {
public:
    // Constructor
    Audi(float _mileage, float _price, float _ownershipCost, int _warranty, int _seatingCapacity, string _fuelType)
        : Car(_mileage, _price, _ownershipCost, _warranty, _seatingCapacity, _fuelType) {}

    // Display Audi information
    virtual void display() {
        cout << "Audi\n";
        Car::display();
    }
};

class Ford : public Car {
public:
    // Constructor
    Ford(float _mileage, float _price, float _ownershipCost, int _warranty, int _seatingCapacity, string _fuelType)
        : Car(_mileage, _price, _ownershipCost, _warranty, _seatingCapacity, _fuelType) {}

    // Display Ford information
    virtual void display() {
        cout << "Ford\n";
        Car::display();
    }
};

// Subclasses of Bike
class Bajaj : public Bike {
public:
    // Constructor
    Bajaj(float _mileage, float _price, int _numberCylinders, int _numberGears, string _coolingType)
        : Bike(_mileage, _price, _numberCylinders, _numberGears, _coolingType) {}

    // Display Bajaj information
    virtual void display() {
        cout << "Bajaj\n";
        Bike::display();
    }
};

class TVS : public Bike {
public:
    // Constructor
    TVS(float _mileage, float _price, int _numberCylinders, int _numberGears, string _coolingType)
        : Bike(_mileage, _price, _numberCylinders, _numberGears, _coolingType) {}

    // Display TVS information
    virtual void display() {
        cout << "TVS\n";
        Bike::display();
    }
};

// Function to increment size of the array
void incrementArraySize(Vehicle**& vehicles, int& size, int& vehicleCount) {
    size++; // Increment size by 1
    Vehicle** temp = new Vehicle*[size];
    for (int i = 0; i < vehicleCount; ++i) {
        temp[i] = vehicles[i];
    }
    delete[] vehicles;
    vehicles = temp;
}

// Function to remove a vehicle at a specific index
void removeVehicle(Vehicle**& vehicles, int& vehicleCount, int index) {
    if (index >= 0 && index < vehicleCount) {
        delete vehicles[index]; // Deallocate memory for the vehicle
        for (int i = index; i < vehicleCount - 1; ++i) {
            vehicles[i] = vehicles[i + 1]; // Shift the elements to fill the gap
        }
        vehicleCount--; // Decrease the vehicle count
        cout << "Vehicle removed successfully.\n";
    } else {
        cout << "Invalid index.\n";
    }
}
int main() {
    int choice;
    int size = 10; // Initial size of the array
    Vehicle** vehicles = new Vehicle*[size]; // Dynamically allocate array of vehicle pointers
    int vehicleCount = 0;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add Audi\n";
        cout << "2. Add Ford\n";
        cout << "3. Add Bajaj\n";
        cout << "4. Add TVS\n";
        cout << "5. Display All Vehicles\n";
        cout << "6. Remove Vehicle\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add Audi
                float mileage, price, ownershipCost;
                int warranty, seatingCapacity;
                string fuelType;

                cout << "Enter Audi details:\n";
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Price: ";
                cin >> price;
                cout << "Ownership Cost: ";
                cin >> ownershipCost;
                cout << "Warranty: ";
                cin >> warranty;
                cout << "Seating capacity: ";
                cin >> seatingCapacity;
                cout << "Fuel type: ";
                cin >> fuelType;

                if (vehicleCount >= size) { // Resize array if needed
                    incrementArraySize(vehicles, size, vehicleCount);
                }

                vehicles[vehicleCount] = new Audi(mileage, price, ownershipCost, warranty, seatingCapacity, fuelType);
                vehicleCount++;
                break;
            }
            case 2: {
                // Add Ford
                float mileage, price, ownershipCost;
                int warranty, seatingCapacity;
                string fuelType;

                cout << "Enter Ford details:\n";
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Price: ";
                cin >> price;
                cout << "Ownership Cost: ";
                cin >> ownershipCost;
                cout << "Warranty: ";
                cin >> warranty;
                cout << "Seating capacity: ";
                cin >> seatingCapacity;
                cout << "Fuel type: ";
                cin >> fuelType;

                if (vehicleCount >= size) { // Resize array if needed
                    incrementArraySize(vehicles, size, vehicleCount);
                }

                vehicles[vehicleCount] = new Ford(mileage, price, ownershipCost, warranty, seatingCapacity, fuelType);
                vehicleCount++;
                break;
            }
            case 3: {
                // Add Bajaj
                float mileage, price;
                int numberCylinders, numberGears;
                string coolingType;

                cout << "Enter Bajaj details:\n";
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Price: ";
                cin >> price;
                cout << "Number cylinders: ";
                cin >> numberCylinders;
                cout << "Number gears: ";
                cin >> numberGears;
                cout << "Cooling type: ";
                cin >> coolingType;

                if (vehicleCount >= size) { // Resize array if needed
                    incrementArraySize(vehicles, size, vehicleCount);
                }

                vehicles[vehicleCount] = new Bajaj(mileage, price, numberCylinders, numberGears, coolingType);
                vehicleCount++;
                break;
            }
            case 4: {
                // Add TVS
                float mileage, price;
                int numberCylinders, numberGears;
                string coolingType;

                cout << "Enter TVS details:\n";
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Price: ";
                cin >> price;
                cout << "Number cylinders: ";
                cin >> numberCylinders;
                cout << "Number gears: ";
                cin >> numberGears;
                cout << "Cooling type: ";
                cin >> coolingType;

                if (vehicleCount >= size) { // Resize array if needed
                    incrementArraySize(vehicles, size, vehicleCount);
                }

                vehicles[vehicleCount] = new TVS(mileage, price, numberCylinders, numberGears, coolingType);
                vehicleCount++;
                break;
            }
            case 5: {
                // Display All Vehicles
                cout << "Displaying all vehicles:\n";
                for (int i = 0; i < vehicleCount; ++i) {
                    cout << "Vehicle " << i + 1 << ":\n";
                    vehicles[i]->display();
                    cout << "\n";
                }
                break;
            }
            case 6: {
                // Remove Vehicle
                int index;
                cout << "Enter the index of the vehicle to remove: ";
                cin >> index;
                removeVehicle(vehicles, vehicleCount, index);
                break;
            }
            case 7: {
                // Exit
                cout << "Exiting program.\n";
                // Delete allocated memory for vehicles
                for (int i = 0; i < vehicleCount; ++i) {
                    delete vehicles[i];
                }
                delete[] vehicles; // Free the dynamically allocated memory
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 7.\n";
            }
        }
    }

    return 0;
}
