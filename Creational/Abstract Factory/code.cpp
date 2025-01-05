#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Abstract Product A
class Chair {
public:
    virtual ~Chair() = default;
    virtual void sitOn() const = 0; // Abstract method to be implemented by concrete chairs
};

// Abstract Product B
class Sofa {
public:
    virtual ~Sofa() = default;
    virtual void lieOn() const = 0; // Abstract method to be implemented by concrete sofas
};

// Concrete Product A1
class ModernChair : public Chair {
public:
    void sitOn() const override {
        cout << "You sit on a sleek Modern Chair." << endl;
    }
};

// Concrete Product A2
class VictorianChair : public Chair {
public:
    void sitOn() const override {
        cout << "You sit on an elegant Victorian Chair." << endl;
    }
};

// Concrete Product B1
class ModernSofa : public Sofa {
public:
    void lieOn() const override {
        cout << "You lie on a comfortable Modern Sofa." << endl;
    }
};

// Concrete Product B2
class VictorianSofa : public Sofa {
public:
    void lieOn() const override {
        cout << "You lie on a luxurious Victorian Sofa." << endl;
    }
};

// Abstract Factory
class FurnitureFactory {
public:
    virtual ~FurnitureFactory() = default;
    virtual unique_ptr<Chair> createChair() const = 0; // Factory method for chairs
    virtual unique_ptr<Sofa> createSofa() const = 0;   // Factory method for sofas
};

// Concrete Factory 1
class ModernFurnitureFactory : public FurnitureFactory {
public:
    unique_ptr<Chair> createChair() const override {
        return make_unique<ModernChair>();
    }
    unique_ptr<Sofa> createSofa() const override {
        return make_unique<ModernSofa>();
    }
};

// Concrete Factory 2
class VictorianFurnitureFactory : public FurnitureFactory {
public:
    unique_ptr<Chair> createChair() const override {
        return make_unique<VictorianChair>();
    }
    unique_ptr<Sofa> createSofa() const override {
        return make_unique<VictorianSofa>();
    }
};

// Client Code
void clientCode(const FurnitureFactory& factory) {
    // Use the factory to create products
    auto chair = factory.createChair();
    auto sofa = factory.createSofa();

    // Use the created products
    chair->sitOn();
    sofa->lieOn();
}

int main() {
    cout << "Modern Furniture Factory:" << endl;
    ModernFurnitureFactory modernFactory;
    clientCode(modernFactory); // Outputs Modern furniture

    cout << "\nVictorian Furniture Factory:" << endl;
    VictorianFurnitureFactory victorianFactory;
    clientCode(victorianFactory); // Outputs Victorian furniture

    return 0;
}
