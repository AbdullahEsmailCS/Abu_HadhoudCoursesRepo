#include<iostream>
#include<string>
using namespace std;

// Constants
const string ConstantAlert[] = { "Enter first number ", "Enter second number ", "The GCD is " };

// Functions
 // Helper Functions
bool IsZero(int value) {
    return value == 0;
}

bool IsNotEqual(int firstValue, int secondValue) {
    return firstValue != secondValue;
}

int Mod(int dividend, int divisor) {
    return dividend % divisor;
}

// Refactored GCD Function
int GCD(int firstValue, int secondValue) {
    while (IsNotEqual(secondValue, 0)) {
        int temp = secondValue;
        secondValue = Mod(firstValue, secondValue);
        firstValue = temp;
    }
    return firstValue;
}


void Print(const string& text) {
    cout << text << endl;
}

void Print(const string& title, int value) {
    cout << title << " : " << value << endl;
}

int ReadIntegerNumber(const string& message) {
    Print(message);
    int number;
    cin >> number;
    return number;
}

void PrintGCD(int gcd) {
    Print(ConstantAlert[2], gcd);
}

int main() {
    int number1 = ReadIntegerNumber(ConstantAlert[0]);
    int number2 = ReadIntegerNumber(ConstantAlert[1]);
    PrintGCD(GCD(number1, number2));
    return 0;
}
