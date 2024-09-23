#include<iostream>
#include<string>
#include<cmath>
using namespace std;

// Constants
const string ConstantAlert[] = { "Enter a Number ", "The number is " };

enum ArmstrongStatus {
    Armstrong,
    NotArmstrong
};

// Functions
//int Power(int base, int exponent) {
//    return pow(base, exponent);
//}

// Function to calculate power without using the built-in pow function
int Power(int base, int exponent) {
    // Initialize the result to 1 (base^0 = 1)
    int result = 1;

    // Multiply the base exponent times
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}


// Helper Functions
bool IsGreaterThan(int firstValue, int secondValue) {
    return firstValue > secondValue;
}

int Modulus(int dividend, int divisor) {
    return dividend % divisor;
}

int Divide(int dividend, int divisor) {
    return dividend / divisor;
}

 

// Refactored SumOfPowers Function
int SumOfPowers(int number, int power) {
    int sum = 0;
    while (IsGreaterThan(number, 0)) {
        int digit = Modulus(number, 10);
        sum += Power(digit, power);
        number = Divide(number, 10);
    }
    return sum;
}

ArmstrongStatus CheckArmstrongStatus(int number) {
    int power = to_string(number).length();
    int sum = SumOfPowers(number, power);
    if (sum == number)
        return ArmstrongStatus::Armstrong;
    else
        return ArmstrongStatus::NotArmstrong;
}

string GetArmstrongStatusString(ArmstrongStatus status) {
    switch (status)
    {
    case Armstrong:
        return "Armstrong";
    case NotArmstrong:
        return "Not Armstrong";
    default:
        return "Unknown";
    }
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

void PrintArmstrongStatus(const string& strStatus) {
    Print(ConstantAlert[1], strStatus);
}

int main() {
    int number = ReadIntegerNumber(ConstantAlert[0]);
    PrintArmstrongStatus(GetArmstrongStatusString(CheckArmstrongStatus(number)));
    return 0;
}
