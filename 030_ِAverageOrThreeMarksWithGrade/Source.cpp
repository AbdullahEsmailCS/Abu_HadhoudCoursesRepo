#include<iostream>
#include<string>

using namespace std;

enum class TestResult {
	None,
	Pass,
	Fail
};

float ReadMark(const string& message) {
	cout << message << endl;
	float mark;
	cin >> mark;
	cin.ignore();
	return (float)mark;
}

short ReadShort(const string& message) {
	cout << message << endl;
	short number;
	cin >> number;
	cin.ignore();
	return  number;
}

string ReadString(const string& message) {
	cout << message << endl;
	string str;
	getline(cin, str);
	return str;
}

string ReadName(const string& alert) {
	return ReadString(alert);
}

struct ThreeMarks {
	float FirstMark, SecondMark, ThirdMark;
};

ThreeMarks ReadThreeMark() {
	ThreeMarks tm;
	tm.FirstMark = ReadMark("Enter first mark: ");
	tm.SecondMark = ReadMark("Enter second Mark: ");
	tm.ThirdMark = ReadMark("Enter third mark: ");
	return tm;
}


struct Student {
	short ID = 01;
	string FirstName, LastName;
	ThreeMarks Marks;
	TestResult Status;
	float Average = 0.0;
	float Summation = 0.0;
	char Grade = 'a';

};



string GetFullName(const string& firstName, const string& lastName) {
	return firstName + " " + lastName;
}

float SumThreeMark(float first, float second, float third) {
	return (float)first + second + third;
}

float CalculateAverage(float sum, short n) {
	return (float)sum / n;
}

TestResult CheckPassOrFail(float average) {
	return (average >= 50) ? TestResult::Pass : TestResult::Fail;
}


char GetGradeLetter(float avg) {

	if (avg >= 90 && avg < 99)
		return 'A';
	else if (avg >= 80 && avg < 90)
		return 'B';
	else if (avg >= 70 && avg < 80)
		return 'C';
	else if (avg >= 60 && avg < 70)
		return 'D';
	else
		return 'E';

}

// Function to convert enum to string
string TestResultToString(TestResult status) {
	switch (status) {
	case TestResult::Pass: return "Pass";
	case TestResult::Fail: return "Fail";
	default: return "None";
	}
}

Student ReadStudentInfo() {
	Student st;
	st.ID = ReadShort("Enter Student ID: ");
	st.FirstName = ReadName("Enter first Name: ");
	st.LastName = ReadName("Enter second Name: ");
	st.Marks = ReadThreeMark();
	st.Summation = SumThreeMark(st.Marks.FirstMark, st.Marks.SecondMark, st.Marks.ThirdMark);
	st.Average = CalculateAverage(st.Summation, 3);
	st.Status = CheckPassOrFail(st.Average);
	st.Grade = GetGradeLetter(st.Average);
	return st;
}

void PrintStudentInformation(Student st) {
	cout << "ID         :" << st.ID << endl;
	cout << "FullName   :" << GetFullName(st.FirstName, st.LastName) << endl;
	cout << "First Mark :" << st.Marks.FirstMark << endl;
	cout << "Second Mark:" << st.Marks.SecondMark << endl;
	cout << "Third Mark :" << st.Marks.ThirdMark << endl;
	cout << "Summation  :" << st.Summation << endl;
	cout << "Average    :" << st.Average << endl;
	cout << "Status     :" << TestResultToString(st.Status) << endl;
	cout << "Grade      :" << st.Grade << endl;
}


int main() {

	PrintStudentInformation(ReadStudentInfo());

	return 0;
}