#include <iostream>
#include <string>
using namespace std;

// Implementation Interface (Color)
class Color {
public:
    virtual string applyColor() = 0;
    virtual ~Color() = default;
};

// Concrete Implementation (Red Color)
class Red : public Color {
public:
    string applyColor() override {
        return "Red";
    }
};

// Concrete Implementation (Blue Color)
class Blue : public Color {
public:
    string applyColor() override {
        return "Blue";
    }
};

// Abstraction (Shape)
class Shape {
protected:
    Color* color; // Bridge to the implementation

public:
    Shape(Color* c) : color(c) {}
    virtual void draw() = 0; // Abstract method to draw the shape
    virtual ~Shape() = default;
};

// Refined Abstraction (Circle)
class Circle : public Shape {
public:
    Circle(Color* c) : Shape(c) {}
    void draw() override {
        cout << "Drawing a Circle in " << color->applyColor() << " color." << endl;
    }
};

// Refined Abstraction (Square)
class Square : public Shape {
public:
    Square(Color* c) : Shape(c) {}
    void draw() override {
        cout << "Drawing a Square in " << color->applyColor() << " color." << endl;
    }
};

// Client Code
int main() {
    // Create Red and Blue colors
    Color* red = new Red();
    Color* blue = new Blue();

    // Create Shapes with different colors
    Shape* redCircle = new Circle(red);
    Shape* blueSquare = new Square(blue);

    // Draw shapes
    redCircle->draw();
    blueSquare->draw();

    // Clean up
    delete redCircle;
    delete blueSquare;
    delete red;
    delete blue;

    return 0;
}
