#include<iostream>
#include<string>

using namespace std;

struct FullName {
	string FirstName = "";
	string FatherName = "";
	string GrandFatherName = "";
	string FamilyName = "";
};


struct Person {
	short ID = 0;
	FullName FullName;
	int Age = 0;
};

void Print(const string& text) {
	cout << text << endl;
}

void Print(const string& text, const string& title) {
	cout << title << " :" << text << endl;
}
void Print(int value, const string& title) {
	cout << title << " :" << value << endl;
}
void Print(short value, const string& title) {
	cout << title << " :" << value << endl;
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

short ReadShortNumber(const string& message) {
	Print(message);
	short number;
	cin >> number;
	cin.ignore();
	return number;
}

int ReadIntegerNumber(const string& message) {
	Print(message);
	int number;
	cin >> number;
	cin.ignore();
	return number;
}

short ReadID(const string& message) {
	return ReadShortNumber(message);
}

int ReadAge(const string& message) {
	return ReadIntegerNumber(message);
}

string ReadFirstName(const string& message) {
	return ReadString(message);
}
string ReadLastName(const string& message) {
	return ReadString(message);
}
string ReadFatherName(const string& message) {
	return ReadString(message);
}
string ReadGrandFatherName(const string& message) {
	return ReadString(message);
}

FullName ReadFullName() {
	FullName fullName;
	fullName.FirstName = ReadFirstName("Enter First Name: ");
	fullName.FatherName = ReadFatherName("Enter Father Name: ");
	fullName.GrandFatherName = ReadGrandFatherName("Enter Third Name: ");
	fullName.FamilyName = ReadLastName("Enter Last Name: ");
	return fullName;
}
string GetFullName(FullName p) {
	string FullName = "";
	FullName = p.FirstName + " " + p.FatherName + " " + p.GrandFatherName + " " + p.FamilyName;
	return FullName;
}

Person ReadPersonInfo() {
	Person p;
	p.ID = ReadID("Enter Person ID: ");
	p.FullName = ReadFullName();
	p.Age = ReadAge("Enter Person Age: ");
	return p;
}

void PrintPersonInfo(Person p) {
	Print(p.ID, "Person ID");
	Print(GetFullName(p.FullName), "Full Name ");
	Print(p.Age, "Person Age ");
}


int main() {

	Person p = ReadPersonInfo();
	PrintPersonInfo(p);

	return 0;
}