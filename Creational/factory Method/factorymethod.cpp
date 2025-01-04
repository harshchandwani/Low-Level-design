#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Abstract Product
class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const = 0; // Pure virtual function to enforce implementation
};

// Concrete Product 1
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Woof! Woof!" << endl;
    }
};

// Concrete Product 2
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow! Meow!" << endl;
    }
};

// Abstract Factory
class AnimalFactory {
public:
    virtual ~AnimalFactory() = default;
    virtual unique_ptr<Animal> createAnimal() const = 0; // Factory Method
};

// Concrete Factory 1
class DogFactory : public AnimalFactory {
public:
    unique_ptr<Animal> createAnimal() const override {
        return make_unique<Dog>();
    }
};

// Concrete Factory 2
class CatFactory : public AnimalFactory {
public:
    unique_ptr<Animal> createAnimal() const override {
        return make_unique<Cat>();
    }
};

// Client Code
void clientCode(const AnimalFactory& factory) {
    // Use the factory to create an animal
    auto animal = factory.createAnimal();
    animal->makeSound(); // Use the created object
}

int main() {
    // Create Dog using DogFactory
    DogFactory dogFactory;
    clientCode(dogFactory); // Output: Woof! Woof!

    // Create Cat using CatFactory
    CatFactory catFactory;
    clientCode(catFactory); // Output: Meow! Meow!

    return 0;
}
