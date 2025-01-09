#include <iostream>
using namespace std;

// Target Interface (Type-C charger)
class TypeCCharger {
public:
    virtual void chargeLaptop() = 0;
    virtual ~TypeCCharger() = default;
};

// Adaptee Class (Micro-USB charger)
class MicroUSBCharger {
public:
    void chargeWithMicroUSB() {
        cout << "Charging laptop with Micro-USB charger." << endl;
    }
};

// Adapter Class (Converts Micro-USB to Type-C)
class MicroUSBToTypeCAdapter : public TypeCCharger {
private:
    MicroUSBCharger* microUSBCharger;

public:
    MicroUSBToTypeCAdapter(MicroUSBCharger* charger) : microUSBCharger(charger) {}

    void chargeLaptop() override {
        microUSBCharger->chargeWithMicroUSB();
    }
};

// Client Code
int main() {
    // Adaptee: Micro-USB charger
    MicroUSBCharger microUSB;

    // Adapter: Converts Micro-USB to Type-C
    MicroUSBToTypeCAdapter adapter(&microUSB);

    // Client uses Type-C interface
    adapter.chargeLaptop();

    return 0;
}
