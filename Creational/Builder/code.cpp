#include <iostream>
#include <string>
using namespace std;

// Product Class: Pizza
class Pizza {
private:
    string size;
    string crustType;
    bool cheese;
    bool pepperoni;
    bool mushrooms;

    // Private Constructor
    Pizza(const string& size, const string& crustType, bool cheese, bool pepperoni, bool mushrooms)
        : size(size), crustType(crustType), cheese(cheese), pepperoni(pepperoni), mushrooms(mushrooms) {}

public:
    // Display pizza details
    void display() const {
        cout << "Pizza Details:" << endl;
        cout << "Size: " << size << endl;
        cout << "Crust Type: " << crustType << endl;
        cout << "Cheese: " << (cheese ? "Yes" : "No") << endl;
        cout << "Pepperoni: " << (pepperoni ? "Yes" : "No") << endl;
        cout << "Mushrooms: " << (mushrooms ? "Yes" : "No") << endl;
    }

    // Nested Builder Class
    class Builder {
    private:
        string size = "Medium"; // Default size
        string crustType = "Regular"; // Default crust type
        bool cheese = false; // Default toppings
        bool pepperoni = false;
        bool mushrooms = false;

    public:
        Builder& setSize(const string& size) {
            this->size = size;
            return *this;
        }
        Builder& setCrustType(const string& crustType) {
            this->crustType = crustType;
            return *this;
        }
        Builder& addCheese() {
            this->cheese = true;
            return *this;
        }
        Builder& addPepperoni() {
            this->pepperoni = true;
            return *this;
        }
        Builder& addMushrooms() {
            this->mushrooms = true;
            return *this;
        }

        // Build method to create a Pizza object
        Pizza build() const {
            return Pizza(size, crustType, cheese, pepperoni, mushrooms);
        }
    };
};

int main() {
    // Create a custom pizza using the builder
    Pizza customPizza = Pizza::Builder()
                            .setSize("Large")
                            .setCrustType("Thin Crust")
                            .addCheese()
                            .addPepperoni()
                            .build();

    Pizza veggiePizza = Pizza::Builder()
                             .setSize("Small")
                             .setCrustType("Cheese Burst")
                             .addCheese()
                             .addMushrooms()
                             .build();

    // Display the pizzas
    cout << "Custom Pizza:" << endl;
    customPizza.display();

    cout << "\nVeggie Pizza:" << endl;
    veggiePizza.display();

    return 0;
}
