#include <iostream>
#include "logger.hpp"
using namespace std;

int main() {
    Logger* logger1 = Logger::GetInstance();
    logger1->Log("Hello log from Logger 1");
    Logger* logger2 = Logger::GetInstance();
    logger2->Log("Hello log fro Logger 2");
    
    return 0; 
}