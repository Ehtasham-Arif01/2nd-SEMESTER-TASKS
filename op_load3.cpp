#include <iostream>
#include <string>

class Product {
protected:
    std::string productName;
    int productID;
    float price;
    int quantityAvailable;

public:
    Product(std::string name, int id, float p, int quantity) : productName(name), productID(id), price(p), quantityAvailable(quantity) {}

    float calculateProfit() const {
        return price * quantityAvailable;
    }

    bool operator<(const Product& other) const {
        return calculateProfit() < other.calculateProfit();
    }

    void displayDetails() const {
        std::cout << "Product Name: " << productName << std::endl;
        std::cout << "Product ID: " << productID << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Quantity Available: " << quantityAvailable << std::endl;
    }
};

int main() {
    Product p1("Laptop", 1001, 1200.50, 10);
    Product p2("T-Shirt", 2001, 25.75, 50);

    std::cout << "----- Product 1 Details -----" << std::endl;
    p1.displayDetails();
    std::cout << "Profit from selling: $" << p1.calculateProfit() << std::endl;

    std::cout << "\n----- Product 2 Details -----" << std::endl;
    p2.displayDetails();
    std::cout << "Profit from selling: $" << p2.calculateProfit() << std::endl;

    if (p1 < p2) {
        std::cout << "\nProduct 1 generates less profit compared to Product 2." << std::endl;
    } else {
        std::cout << "\nProduct 1 generates more profit compared to Product 2." << std::endl;
    }

    return 0;
}
