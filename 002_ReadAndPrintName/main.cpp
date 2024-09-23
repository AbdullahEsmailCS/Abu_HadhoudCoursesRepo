#include<iostream>
#include<string>

using namespace std;

void Print(const string& text) {
	cout << text << endl;
}

void PrintName(const string& name) {
	Print(name);
}

string ReadName(const string& message) {
	Print(message);
	string name;
	getline(cin, name);
	return name;
}

int main() {
	string name = ReadName("Enter your name please");
	PrintName(name);

	return 0;
}