#include <iostream>
using namespace std;

class dynamic_array {
private:
    int *arr;
    int array_size;

public:
    // Constructor
    dynamic_array(int size) {
        array_size = size;
        arr = new int[array_size];
    }

    // Copy Constructor
    dynamic_array(const dynamic_array &obj) {
        cout << "COPY CONSTRUCTOR IS CALLED" << endl;
        array_size = obj.get_size();
        arr = new int[array_size];
        for (int i = 0; i < array_size; i++) {
            arr[i] = obj.arr[i];
        }
    }

    // Destructor
    ~dynamic_array() {
        cout << "DESTRUCTOR IS CALLED" << endl;
        delete[] arr;
    }

    // Print array function
    void print_array() const {
        for (int i = 0; i < array_size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Setter
    void set_value(int index, int value) {
        arr[index] = value;
    }

    // Getter for size
    int get_size() const {
        return array_size;
    }

    // Getter for value at index
    int get_value(int index) const {
        return arr[index];
    }
};

int main() {
    dynamic_array arr1(6);
    for (int i = 0; i < 6; i++) {
        arr1.set_value(i, i);
    }

    cout << "Array 1:" << endl;
    arr1.print_array();

    cout << endl;

    dynamic_array arr2(arr1);

    cout << "Array 2 (copy of Array 1):" << endl;
    arr2.print_array();

    return 0;
}
