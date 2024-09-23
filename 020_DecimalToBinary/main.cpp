#include<iostream>
#include<string>
using namespace std;

// Constants
const string ConstantAlert[] = { "Enter a Number ", "The binary representation is " };

// Functions
string DecimalToBinary(int number) {
    string binary = "";
    while (number > 0) {
        binary = to_string(number % 2) + binary;
        number /= 2;
    }
    return binary.empty() ? "0" : binary;
}

void Print(const string& text) {
    cout << text << endl;
}

void Print(const string& title, const string& value) {
    cout << title << " : " << value << endl;
}

int ReadIntegerNumber(const string& message) {
    Print(message);
    int number;
    cin >> number;
    return number;
}

void PrintBinaryRepresentation(const string& binary) {
    Print(ConstantAlert[1], binary);
}

int main() {
    int number = ReadIntegerNumber(ConstantAlert[0]);
    PrintBinaryRepresentation(DecimalToBinary(number));
    return 0;
}
