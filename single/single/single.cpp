#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Device {
protected:
    string manufacturer;
    string model;
    string name;
    int capacity;
    int quantity;

public:
    Device(const string& manufacturer, const string& model, const string& name, int capacity, int quantity) {
        this->manufacturer = manufacturer;
        this->model = model;
        this->name = name;
        this->capacity = capacity;
        this->quantity = quantity;
    }

    const string& GetManufacturer() const {
        return manufacturer;
    }

    const string& GetModel() const {
        return model;
    }

    const string& GetName() const {
        return name;
    }

    int GetCapacity() const {
        return capacity;
    }

    int GetQuantity() const {
        return quantity;
    }

    virtual void PrintInfo() const {
        cout << "Manufacturer: " << manufacturer << " Model: " << model << " Name: " << name << " Capacity: " << capacity << " GB, Quantity: " << quantity << "\n";
    }

    virtual void load() const {
        cout << "Loading data " << name << "\n";
    }

    virtual void store() const {
        cout << "Storing data " << name << "\n";
    }
};

class FlashDrive : public Device {
public:
    FlashDrive(const string& manufacturer, const string& model, const string& name, int capacity, int quantity)
        : Device(manufacturer, model, name, capacity, quantity) {}

    void PrintInfo() const override {
        cout << "Flash Drive ";
        Device::PrintInfo();
    }

    void load() const override {
        cout << "Insert the Flash Drive for data loading.\n";
    }

    void store() const override {
        cout << "Eject the Flash Drive after storing data.\n";
    }
};

class HardDrive : public Device {
public:
    HardDrive(const string& manufacturer, const string& model, const string& name, int capacity, int quantity)
        : Device(manufacturer, model, name, capacity, quantity) {}

    void PrintInfo() const override {
        cout << "Hard Drive ";
        Device::PrintInfo();
    }

    void load() const override {
        cout << "Power on the Hard Drive for data loading.\n";
    }

    void store() const override {
        cout << "Disconnect the Hard Drive after storing data.\n";
    }
};

class Phone : public Device {
public:
    Phone(const string& manufacturer, const string& model, const string& name, int capacity, int quantity)
        : Device(manufacturer, model, name, capacity, quantity) {}

    void PrintInfo() const override {
        cout << "Phone ";
        Device::PrintInfo();
    }

    void load() const override {
        cout << "Connect Phone to the computer for data loading.\n";
    }

    void store() const override {
        cout << "Use phone's storage to save and store data.\n";
    }
};

int main() {
    vector<Device*> devices;

    devices.push_back(new FlashDrive("KrytieFleshki", "Ultra", "Flash Drive E", 64, 5));
    devices.push_back(new HardDrive("Konami", "Plus Ultra", "Hard Drive S", 2000, 2));
    devices.push_back(new Phone("Apple", "brandnewiphon", "iPhone 5", 256, 3));

    for (const auto& device : devices) {
        device->PrintInfo();
        device->load();
        device->store();
    }

    for (const auto& device : devices) {
        delete device;
    }

    return 0;
}


