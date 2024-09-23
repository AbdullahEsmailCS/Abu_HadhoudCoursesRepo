#include<iostream>
#include<string>
#include <cctype>
#include <stdexcept>
using namespace std;


// ---------------Structures of data elements
//------------------Arithmatic funcitons

int Modulus(int fistValue, int secondValue) {
	return fistValue % secondValue;
}


struct Statistics {
	bool IsAgePositive;
	bool IsAgeOdd;
	bool IsAgeEven;
	bool IsAgePrime;
};

enum class Gender {
	None,
	Male,
	Female
};
enum class MaritalStatus
{
	Single,    // S
	Married,   // M
	Divorced,  // D
	Widowed,   // W
	Separated, // P
	Other      // O
};


enum class AgeGroup
{
	Child,
	Teen,
	Adult,
	Senior
};




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
	Gender Gender = Gender::None;
	MaritalStatus MaritalStatus = MaritalStatus::Other;
	bool IsActive = false;

};

//_------------------Helpers Functions

string GetFullName(FullName p) {
	string FullName = "";
	FullName = p.FirstName + " " + p.FatherName + " " + p.GrandFatherName + " " + p.FamilyName;
	return FullName;
}


bool IsGreaterThanOrEqual(int firstValue, int secondValue) {
	return firstValue >= secondValue;
}
bool IsLessThanOrEqual(int firstValue, int secondValue) {
	return firstValue <= secondValue;
}

bool IsEqual(int firstValue, int secondValue) {
	return firstValue == secondValue;
}

bool IsZero(int value) {
	return IsEqual(value, 0);
}

bool IsEven(int number) {
	int remainder = Modulus(number, 2);
	return IsZero(remainder);
}


bool IsChild(int age)
{
	return IsGreaterThanOrEqual(age, 0) && IsLessThanOrEqual(age, 12);
}

bool IsTeen(int age)
{
	return IsGreaterThanOrEqual(age, 13) && IsLessThanOrEqual(age, 19);
}

bool IsAdult(int age)
{
	return IsGreaterThanOrEqual(age, 20) && IsLessThanOrEqual(age, 64);
}

bool IsSenior(int age)
{
	return IsGreaterThanOrEqual(age, 65);
}

// Main Age Classification Function
AgeGroup ClassifyAge(int age)
{
	if (IsChild(age))
	{
		return AgeGroup::Child;
	}
	else if (IsTeen(age))
	{
		return AgeGroup::Teen;
	}
	else if (IsAdult(age))
	{
		return AgeGroup::Adult;
	}
	else if (IsSenior(age))
	{
		return AgeGroup::Senior;
	}
	else
	{
		throw std::invalid_argument("Invalid age");
	}
}

string AgeGroupToString(AgeGroup ageGroup)
{
	switch (ageGroup)
	{
	case AgeGroup::Child:
		return "Child";
	case AgeGroup::Teen:
		return "Teen";
	case AgeGroup::Adult:
		return "Adult";
	case AgeGroup::Senior:
		return "Senior";
	default:
		throw std::invalid_argument("Unknown age group");
	}
}




Gender ConvertLetterToGender(char letter) {

	switch (toupper(letter)) {
	case 'M':
		return Gender::Male;
	case 'F':
		return Gender::Female;
	default:
		return Gender::None;
	}
}

static char ConvertGenderToLetter(Gender gender) {
	switch (gender) {
	case Gender::Male:
		return 'M';
	case Gender::Female:
		return 'F';
	default:
		return 'N';
	}
}

MaritalStatus ConvertCharToMaritalStatus(char statusChar)
{
	switch (toupper(statusChar))
	{
	case 'S':
		return MaritalStatus::Single;
	case 'M':
		return MaritalStatus::Married;
	case 'D':
		return MaritalStatus::Divorced;
	case 'W':
		return MaritalStatus::Widowed;
	case 'P':
		return MaritalStatus::Separated;
	case 'O':
		return MaritalStatus::Other;
	default:
		throw std::invalid_argument("Invalid marital status character");
	}
}

char ConvertMaritalStatusToChar(MaritalStatus status)
{
	switch (status)
	{
	case MaritalStatus::Single:
		return 'S';
	case MaritalStatus::Married:
		return 'M';
	case MaritalStatus::Divorced:
		return 'D';
	case MaritalStatus::Widowed:
		return 'W';
	case MaritalStatus::Separated:
		return 'P';
	case MaritalStatus::Other:
		return 'O';
	default:
		throw std::invalid_argument("Invalid marital status");
	}
}

 
string GetEvenOddString(bool value) {
	return (value) ? "Even Age " : "Odd Age";
}



string GetPersonStatus(bool value) {
	return (value) ? "Active " : "Inactive";
}






//----------------Output functions

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
void Print(char value, const string& title) {
	cout << title << " :" << value << endl;
}

void PrintFullName(const string& name) {
	Print(name);
}

void PrintPersonInfo(Person p) {
	Print(p.ID, "Person ID   ");
	Print(GetFullName(p.FullName), "Full Name   ");
	Print(p.Age, "Person Age  ");
	Print(ConvertGenderToLetter(p.Gender), "Gender   ");
	Print(ConvertMaritalStatusToChar(p.MaritalStatus), "Marital Status   ");
	Print(GetPersonStatus(p.IsActive), "Status   ");

	// Classify and print the age group
	AgeGroup ageGroup = ClassifyAge(p.Age);
	Print(AgeGroupToString(ageGroup), "Age Group");
	Print(GetEvenOddString(IsEven(p.Age)), "Is Age Even or Odd");
}

//------------------------------Input funcitons
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

char ReadLetter(const string& message) {
	Print(message);
	char letter;
	cin >> letter;
	return letter;
}

char ReadMaritalStatusCharacter(const string& message) {
	return ReadLetter(message);
}

bool ReadBoolean(const string& message) {
	Print(message);
	bool value;
	cin >> value;
	return value;
}

bool ReadPersonStatus(const string& message) {
	return ReadBoolean(message);
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

Person ReadPersonInfo() {
	Person p;
	p.ID = ReadID("Enter Person ID: ");
	p.FullName = ReadFullName();
	p.Age = ReadAge("Enter Person Age: ");
	p.Gender = ConvertLetterToGender(ReadLetter("Enter Gender of person (M for Male, F for Female)"));
	p.MaritalStatus = ConvertCharToMaritalStatus(ReadMaritalStatusCharacter("Enter your marital status (S: Single, M: Married, D: Divorced, W: Widowed, P: Separated, O: Other): "));
	p.IsActive = ReadPersonStatus("Enter the person status account(1 for active, 0 for inactive ");
	return p;
}





int main() {

	Person p = ReadPersonInfo();
	PrintPersonInfo(p);

	return 0;
}