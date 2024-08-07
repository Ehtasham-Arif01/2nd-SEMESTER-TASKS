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

    virtual ~Product() {}

    virtual void displayDetails() {
        std::cout << "Product Name: " << productName << std::endl;
        std::cout << "Product ID: " << productID << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Quantity Available: " << quantityAvailable << std::endl;
    }

    virtual float calculateProfit() {
        return price * quantityAvailable;
    }

    friend float Profit_Calculator(Product product, int salesQuantity);
};

class Electronics : public Product {
private:
    int warrantyPeriod;
    float powerConsumption;

public:
    Electronics(std::string name, int id, float p, int quantity, int warranty, float power) : Product(name, id, p, quantity), warrantyPeriod(warranty), powerConsumption(power) {}

    void displayDetails() override {
        Product::displayDetails();
        std::cout << "Warranty Period: " << warrantyPeriod << " months" << std::endl;
        std::cout << "Power Consumption: " << powerConsumption << " watts" << std::endl;
    }
};

class Clothing : public Product {
private:
    std::string size;
    std::string material;

public:
    Clothing(std::string name, int id, float p, int quantity, std::string s, std::string m) : Product(name, id, p, quantity), size(s), material(m) {}

    void displayDetails() override {
        Product::displayDetails();
        std::cout << "Size: " << size << std::endl;
        std::cout << "Material: " << material << std::endl;
    }
};

float Profit_Calculator(Product product, int salesQuantity) {
    return product.price * salesQuantity;
}

bool operator<(Product const &p1, Product const &p2) {
    return p1.calculateProfit() < p2.calculateProfit();
}

int main() {
    Product* e1 = new Electronics("Laptop", 1001, 1200.50, 10, 12, 65.5);
    Product* c1 = new Clothing("T-Shirt", 2001, 25.75, 50, "Medium", "Cotton");

    std::cout << "----- Electronic Product Details -----" << std::endl;
    e1->displayDetails();
    std::cout << std::endl;

    std::cout << "----- Clothing Product Details -----" << std::endl;
    c1->displayDetails();
    std::cout << std::endl;

    std::cout << "Profit from selling Laptop (5 units): $" << Profit_Calculator(*e1, 5) << std::endl;
    std::cout << "Profit from selling T-Shirt (20 units): $" << Profit_Calculator(*c1, 20) << std::endl;

    if (*e1 < *c1) {
        std::cout << "Laptop generates less profit compared to T-Shirt." << std::endl;
    } else {
        std::cout << "Laptop generates more profit compared to T-Shirt." << std::endl;
    }

    delete e1;
    delete c1;

    return 0;
}
