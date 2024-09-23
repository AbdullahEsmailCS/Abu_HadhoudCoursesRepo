#include<iostream>
#include<string>
using namespace std;

// Constants
const string ConstantAlert[] = { "Enter a Number ", "The sum of digits is " };

// Functions
int SumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
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

void PrintSumOfDigits(int sum) {
    Print(ConstantAlert[1], sum);
}

int main() {
    int number = ReadIntegerNumber(ConstantAlert[0]);
    PrintSumOfDigits(SumOfDigits(number));
    return 0;
}
