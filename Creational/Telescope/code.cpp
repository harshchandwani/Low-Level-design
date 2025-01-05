//The Telescope Constructor Pattern is a design pattern used to deal with the construction of objects with multiple optional parameters. The name "telescope" comes from the way constructors are nested or chained to handle different combinations of parameters.

#include <iostream>
#include <string>

using namespace std;

class Telescope {
private:
    double apertureSize;  // in mm
    double focalLength;   // in mm
    string mountType;     // e.g., "Alt-Azimuth" or "Equatorial"
    double weight;        // in kg

public:
    // Constructor with 1 parameter
    Telescope(double apertureSize)
        : apertureSize(apertureSize), focalLength(0), mountType("None"), weight(0) {}

    // Constructor with 2 parameters
    Telescope(double apertureSize, double focalLength)
        : apertureSize(apertureSize), focalLength(focalLength), mountType("None"), weight(0) {}

    // Constructor with 3 parameters
    Telescope(double apertureSize, double focalLength, const string& mountType)
        : apertureSize(apertureSize), focalLength(focalLength), mountType(mountType), weight(0) {}

    // Constructor with 4 parameters
    Telescope(double apertureSize, double focalLength, const string& mountType, double weight)
        : apertureSize(apertureSize), focalLength(focalLength), mountType(mountType), weight(weight) {}

    // Display method
    void display() const {
        cout << "Telescope Details:" << endl;
        cout << "Aperture Size: " << apertureSize << " mm" << endl;
        cout << "Focal Length: " << focalLength << " mm" << endl;
        cout << "Mount Type: " << mountType << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    // Create objects using different constructors
    Telescope t1(200); // Only aperture size
    Telescope t2(200, 1200); // Aperture size and focal length
    Telescope t3(200, 1200, "Alt-Azimuth"); // Aperture size, focal length, and mount type
    Telescope t4(200, 1200, "Equatorial", 15); // All parameters

    // Display telescope details
    cout << "Telescope 1:" << endl;
    t1.display();
    cout << "\nTelescope 2:" << endl;
    t2.display();
    cout << "\nTelescope 3:" << endl;
    t3.display();
    cout << "\nTelescope 4:" << endl;
    t4.display();

    return 0;
}
