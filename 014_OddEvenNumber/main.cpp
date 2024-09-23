#include<iostream>
#include<string>
using namespace std;

// Constants: Defining constant values
const int NumberFactor = 2;
const int Zero = 0;
const string ConstantAlert[] = { "Enter a Number ", "Number is " };

// Enumeration: Defining an enum to represent number types (Even, Odd)
enum NumberType {
    Even,
    Odd
};

// Functions: Various functions to perform specific tasks
int Mod(int firstValue, int secondValue) {
    return firstValue % secondValue; // Modulus Operation: Finding the remainder
}

bool IsEqual(int firstValue, int secondValue) {
    return firstValue == secondValue;
}

bool IsZero(int value) {
    return IsEqual(value, Zero);
}

bool IsEven(int number) {
    int remainder = Mod(number, NumberFactor);
    return IsZero(remainder);
}

NumberType CheckNumberType(int number) {
    if (IsEven(number)) // Conditional Statement: Checking if the number is even
        return NumberType::Even;
    else
        return NumberType::Odd;
}

// Switch Statement: Returning a string based on the number type
string GetNumberTypeString(NumberType t) {
    switch (t)
    {
    case Even:
        return "Even ";
        break;
    case Odd:
        return "Odd";
        break;
    default:
        return "None";
        break;
    }
}

// Function Overloading: Overloaded Print functions
void Print(const string& text) {
    cout << text << endl; // Basic Input/Output: Printing to console
}
void Print(const string& title, const string& value) {
    cout << title << " : " << value << endl;
}

// Pass by Reference: Passing strings by reference for efficiency
int ReadIntegerNumber(const string& message) {
    Print(message);
    int number;
    cin >> number; // Basic Input/Output: Reading input from user
    return number;
}

void PrintNumberType(const string& strType) {
    Print(ConstantAlert[1], strType);
}

int main() {
    int number = ReadIntegerNumber(ConstantAlert[0]);
    PrintNumberType(GetNumberTypeString(CheckNumberType(number)));
    return 0;
}
