#include<iostream>
#include<string>

using namespace std;

 


void Print(const string& value) {
	cout << value << endl;
}

void Print(const string& title,const string& value) {
	cout <<title<<" :"<< value << endl;
}

string ReadString(const string& message) {
	cout << message << endl;
	string text;
	getline(cin, text);
	return text;
}

string ReadFirstName() {
	return ReadString("Enter First Name: ");
}

string ReadSecondName() {
	return ReadString("Enter Second Name: ");
}
string ReadThirdName() {
	return ReadString("Enter Third Name: ");
}
string ReadLastName() {
	return ReadString("Enter Last Name: ");
}


struct FullName {
	string FirstName, SecondName, ThirdName, LastName;
	bool IsFirstLast = false;
	bool IsLastFirst = false;
};

string JoinString(const string& s1, const string& s2) {
	return s1 + " " + s2;
}


FullName ReadFullName() {
	FullName fn;
	fn.FirstName = ReadFirstName();
	fn.SecondName = ReadSecondName();
	fn.ThirdName = ReadThirdName();
	fn.LastName = ReadLastName();
	return fn;
}

string GetFullName(FullName fn) {
	return fn.FirstName + " " + fn.SecondName + " " + fn.ThirdName + " " + fn.LastName;
}


void DisplayName(FullName fn) {

	if (fn.IsFirstLast) {
		Print("Full Name", JoinString(fn.FirstName, fn.LastName));
	}
	else if (fn.IsLastFirst) {
		Print("Full Name", JoinString(fn.LastName, fn.FirstName));
	}
	else {
		Print("FullName ", GetFullName(fn));
	}

}



int main() {

	FullName name = ReadFullName();
	name.IsFirstLast = true;
	DisplayName(name);


	return 0;
}
