#include "sensors/gyro.hpp"
#include <iostream>
#include "uart.hpp"
using namespace std;
//global variables
UART uart(115200);
MPU6050 gyro;

float mapValue(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void checkArduinoConnection(){
    string in = uart.read();
    while(in != "rr"){
        in = uart.read();
        cout << "no connection" << endl;
    }
    uart.write("ar");
    cout << "connection established" << endl;
}
int main(){


    checkArduinoConnection();
    while(1){
    }
    
}