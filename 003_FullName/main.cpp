#include<iostream>
#include<string>

using namespace std;

struct Person {
	string FirstName = "";
	string LastName = "";
};

void Print(const string& text) {
	cout << text << endl;
}

void PrintFullName(const string& name) {
	Print(name);
}

string ReadString(const string& message) {
	Print(message);
	string name;
	getline(cin, name);
	return name;
}
string ReadFirstName(const string& message) {
	return ReadString(message);
}
string ReadLastName(const string& message) {
	return ReadString(message);
}

Person ReadFullName() {
	Person p;
	p.FirstName = ReadFirstName("Enter First Name: ");
	p.LastName = ReadLastName("Enter Last Name: ");
	return p;
}
string GetFullName(Person p) {
	string FullName = "";
	FullName = p.FirstName + " " + p.LastName;
	return FullName;
}
int main() {

	Person p = ReadFullName();
	PrintFullName(GetFullName(p));

	return 0;
}