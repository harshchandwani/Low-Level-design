#include <iostream>

// Abstract base class defining the template method
class AbstractClass {
public:
    // The template method defining the algorithm structure
    void templateMethod() {
        stepOne();
        stepTwo();
        if (hook()) {
            stepThree();
        }
    }

    // Steps to be implemented by subclasses
    virtual void stepOne() = 0;
    virtual void stepTwo() = 0;

    // Hook method that can be optionally overridden
    virtual bool hook() {
        return true;
    }

    // Common step across subclasses
    void stepThree() {
        std::cout << "AbstractClass: Performing step three.\n";
    }
};

// Concrete subclass implementing the steps
class ConcreteClass : public AbstractClass {
public:
    void stepOne() override {
        std::cout << "ConcreteClass: Performing step one.\n";
    }

    void stepTwo() override {
        std::cout << "ConcreteClass: Performing step two.\n";
    }

    bool hook() override {
        std::cout << "ConcreteClass: Overridden hook method.\n";
        return false; // Optionally changing the behavior
    }
};

int main() {
    AbstractClass* obj = new ConcreteClass();
    obj->templateMethod();

    delete obj;
    return 0;
}
