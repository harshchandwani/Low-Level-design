#include <iostream>
#include <memory>

using namespace std;

// Base Component
class Component {
public:
    virtual void operation() const {
        cout << "Base Component\n";
    }
    virtual ~Component() = default;
};

// Concrete Component
class ConcreteComponent : public Component {
public:
    void operation() const override {
        cout << "Concrete Component\n";
    }
};

// Base Decorator
class Decorator : public Component {
protected:
    shared_ptr<Component> component; // Wrapped component
public:
    Decorator(shared_ptr<Component> comp) : component(comp) {}
    void operation() const override {
        component->operation();
    }
};

// Concrete Decorators
class DecoratorA : public Decorator {
public:
    DecoratorA(shared_ptr<Component> comp) : Decorator(comp) {}
    void operation() const override {
        Decorator::operation();
        cout << "Decorator A adds behavior.\n";
    }
};

class DecoratorB : public Decorator {
public:
    DecoratorB(shared_ptr<Component> comp) : Decorator(comp) {}
    void operation() const override {
        Decorator::operation();
        cout << "Decorator B adds behavior.\n";
    }
};

int main() {
    // Create a ConcreteComponent
    shared_ptr<Component> component = make_shared<ConcreteComponent>();

    // Wrap it with DecoratorA
    shared_ptr<Component> decoratedA = make_shared<DecoratorA>(component);

    // Further wrap it with DecoratorB
    shared_ptr<Component> decoratedB = make_shared<DecoratorB>(decoratedA);

    // Call operation on the fully decorated object
    decoratedB->operation();

    return 0;
}
