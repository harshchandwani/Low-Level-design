#include <iostream>
#include "logger.hpp"
using namespace std;

Logger::Logger(){
    cout << "Logger created" << endl;
}

void Logger:: Log(string msg){
    cout<<msg<<endl;
}