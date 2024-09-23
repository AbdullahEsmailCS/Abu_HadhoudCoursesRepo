#include<iostream>
#include<string>
using namespace std;

// Constants
const string ConstantAlert[] = { "Enter a Number ", "The factorial is " };

// Functions
int Multiply(int firstValue, int secondValue) {
    return firstValue * secondValue;
}

int Factorial(int number) {
    int result = 1;
    for (int i = 2; i <= number; ++i) {
        result = Multiply(result, i);
    }
    return result;
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

void PrintFactorial(int factorial) {
    Print(ConstantAlert[1], factorial);
}

int main() {
    int number = ReadIntegerNumber(ConstantAlert[0]);
    PrintFactorial(Factorial(number));
    return 0;
}
