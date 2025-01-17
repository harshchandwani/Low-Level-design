#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Receiver
class Light {
public:
    void turnOn() {
        std::cout << "The light is ON\n";
    }
    void turnOff() {
        std::cout << "The light is OFF\n";
    }
};

// Command Interface
class Command {
public:
    virtual void execute() = 0; // Executes the command
    virtual ~Command() = default;
};

// Concrete Command: Turn On
class TurnOnCommand : public Command {
private:
    Light& light; // Receiver
public:
    explicit TurnOnCommand(Light& light) : light(light) {}
    void execute() override {
        light.turnOn();
    }
};

// Concrete Command: Turn Off
class TurnOffCommand : public Command {
private:
    Light& light; // Receiver
public:
    explicit TurnOffCommand(Light& light) : light(light) {}
    void execute() override {
        light.turnOff();
    }
};

// Invoker
class RemoteControl {
private:
    std::vector<std::shared_ptr<Command>> commands; // Commands to execute
public:
    void addCommand(const std::shared_ptr<Command>& command) {
        commands.push_back(command);
    }
    void pressButton() {
        for (const auto& command : commands) {
            command->execute();
        }
    }
};

int main() {
    // Receiver
    Light livingRoomLight;

    // Commands
    auto turnOnCommand = std::make_shared<TurnOnCommand>(livingRoomLight);
    auto turnOffCommand = std::make_shared<TurnOffCommand>(livingRoomLight);

    // Invoker
    RemoteControl remote;

    // Add commands to the remote control
    remote.addCommand(turnOnCommand);
    remote.addCommand(turnOffCommand);

    // Simulate pressing the button
    remote.pressButton();

    return 0;
}
