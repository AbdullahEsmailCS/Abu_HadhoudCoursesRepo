#include<iostream>
#include<string>
using namespace std;

// Constants: Defining constant values
const int FirstPrime = 2;
const string ConstantAlert[] = { "Enter a Number ", "The number is " };

enum PrimeStatus {
    Prime,
    NotPrime
};

// Functions: Various functions to perform specific tasks
int Mod(int firstValue, int secondValue) {
    return firstValue % secondValue; // Modulus Operation: Finding the remainder
}

bool IsEqual(int firstValue, int secondValue) {
    return firstValue == secondValue;
}

bool IsLess(int firstValue, int secondValue) {
    return firstValue < secondValue;
}

bool IsZero(int value) {
    return IsEqual(value, 0);
}

bool IsDivisible(int number, int divisor) {
    return IsZero(Mod(number, divisor));
}

bool IsPrime(int number) {
    if (IsLess(number, FirstPrime)) // Any number less than 2 is not prime
        return false;

    for (int i = FirstPrime; i * i <= number; ++i) {
        if (IsDivisible(number, i)) // Check divisibility
            return false;
    }
    return true;
}

PrimeStatus CheckPrimeStatus(int number) {
    if (IsPrime(number))
        return PrimeStatus::Prime;
    else
        return PrimeStatus::NotPrime;
}

// Switch Statement: Returning a string based on the prime status
string GetPrimeStatusString(PrimeStatus status) {
    switch (status)
    {
    case Prime:
        return "Prime";
        break;
    case NotPrime:
        return "Not Prime";
        break;
    default:
        return "Unknown";
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

void PrintPrimeStatus(const string& strStatus) {
    Print(ConstantAlert[1], strStatus);
}

int main() {
    int number = ReadIntegerNumber(ConstantAlert[0]);
    PrintPrimeStatus(GetPrimeStatusString(CheckPrimeStatus(number)));
    return 0;
}
