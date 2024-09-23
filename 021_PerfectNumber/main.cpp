#include<iostream>
#include<string>
using namespace std;

// Constants
const string ConstantAlert[] = { "Enter a Number ", "The number is " };

enum PerfectNumberStatus {
    Perfect,
    NotPerfect
};

// Functions
int SumOfDivisors(int number) {
    int sum = 1; // 1 is a divisor of every number
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            sum += i;
            if (i != number / i) {
                sum += number / i;
            }
        }
    }
    return sum;
}

PerfectNumberStatus CheckPerfectNumberStatus(int number) {
    if (SumOfDivisors(number) == number && number != 1)
        return PerfectNumberStatus::Perfect;
    else
        return PerfectNumberStatus::NotPerfect;
}

string GetPerfectNumberStatusString(PerfectNumberStatus status) {
    switch (status)
    {
    case Perfect:
        return "Perfect Number";
    case NotPerfect:
        return "Not Perfect Number";
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

void PrintPerfectNumberStatus(const string& strStatus) {
    Print(ConstantAlert[1], strStatus);
}

int main() {
    int number = ReadIntegerNumber(ConstantAlert[0]);
    PrintPerfectNumberStatus(GetPerfectNumberStatusString(CheckPerfectNumberStatus(number)));
    return 0;
}
