#include<iostream>
#include<iostream>

using namespace std;

void Print(const string& message) {
	cout << message << endl;
}
void Print(const string& title, const string& value) {
	cout << title<< " : "<< value << endl;
}

void Print(const string& title, int value) {
	cout << title << " : " << value << endl;
}

void Print(const string& title, float value) {
	cout << title << " : " << value << endl;
}

void Print(const string& title, double value) {
	cout << title << " : " << value << endl;
}
void Print(const string& title, char value) {
	cout << title << " : " << value << endl;
}
void Print(const string& title, bool value) {
	cout << title << " : " << (value) ? "Yes" : "No";
	cout << endl;
}

int ReadIntNumber(const string& message) {
	Print(message);
	int number;
	cin >> number;
	cin.ignore();
	return  number;
}

float ReadFloat(const string& message) {
	Print(message);
	float number;
	cin >> number;
	cin.ignore();
	return (float)number;
}

double ReadDouble(const string& message) {
	Print(message);
	double number;
	cin >> number;
	cin.ignore();
	return (double)number;
}

long ReadLong(const string& message) {
	Print(message);
	long number;
	cin >> number;
	cin.ignore();
	return (long)number;
}

char ReadChar(const string& message) {
	Print(message);
	char value;
	cin >> value;
	cin.ignore();
	return value;
}

bool ReadBool(const string& message) {
	Print(message);
	bool value;
	cin >> value;
	cin.ignore();
	return value;
}

string ReadString(const string& message) {
	Print(message);
	string value;
	cin >> value;
	cin.ignore();
	return value;
}

//-----------------------------------------------

int Add(int first, int second) {
	return first + second;
}

int Add(int first, int second, int third) {
	return first + second + third;
}
float Add(float first, float second, float third) {
	return(float) first + second + third;
}
float Add(float first, float second, float third, float fourth) {
	return(float)first + second + third + fourth;
}

int Sub(int first, int second) {
	return first - second;
}

int Mul(int first, int second) {
	return first * second;
}

int Mod(int first, int second) {
	return first % second;
}

int Div(int first, int second) {
	if (second == 0) return 0;
	return first / second;
}

bool IsEqual(int first, int second) {
	return first == second;
}

bool IsNotEqual(int first, int second) {
	return first != second;
}

bool IsGreaterThan(int first, int second) {
	return first > second;
}
bool IsGreaterThanOrEqual(int first, int second) {
	return first >= second;
}

bool IsLessThan(int first, int second) {
	return first < second;
}
bool IsLessThanOrEqual(int first, int second) {
	return first <= second;
}

//==============================helpers

int GetRemainderByTwo(int value) {
	return Mod(value, 2);
}

bool IsZero(int value) {
	return IsEqual(value, 0);
}
bool IsNotZero(int value) {
	return !IsZero(value);
}

//-------------------------------











int main() {


	return 0;
}