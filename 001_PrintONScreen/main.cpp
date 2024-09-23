#include<iostream>

using namespace std;

void Print(const string& text) {
	cout << text << endl;
}

void PrintName(const string& name) {
	Print(name);
}

int main() {
	string name = "Abdullah Abdo MOhammed Esmail Ali";
	PrintName(name);

	return 0;
}