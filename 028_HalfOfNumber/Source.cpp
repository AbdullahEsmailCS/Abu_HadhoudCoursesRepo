#include<iostream>
#include<string>

using namespace std;

int ReadNumber(const string& message) {
	cout << message << endl;
	int number;
	cin >> number;
	return number;
}

int Divide(int first, int second) {
	if (second == 0)
		return -1;

	return first / second;
}

int ComputeHalfOfNumber(int number) {
	return Divide(number, 2);
}

void Print(int number) {
	cout << "Half Of Number is : " << number << endl;;
}

int main() {

	Print(ComputeHalfOfNumber(ReadNumber("Enter a number")));

	return 0;
}