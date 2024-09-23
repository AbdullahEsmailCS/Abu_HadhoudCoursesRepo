#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

using namespace std;

// Constants
const string ConstantAlert[] = { "Enter a String ", "The string is " };

enum PalindromeStatus {
    Palindrome,
    NotPalindrome
};

string ReverseString(const string& str) {
    // Create an empty string to hold the reversed result
    string reversed = "";

    // Iterate through the input string from the end to the beginning
    for (int i = str.length() - 1; i >= 0; i--) {
        // Append each character to the reversed string
        reversed += str[i];
    }

    return reversed;
}


// Functions
//string ReverseString(const string& str) {
//    string reversed = str;
//    reverse(reversed.begin(), reversed.end());
//    return reversed;
//}

bool IsEqual(const string& str1, const string& str2) {
    return str1 == str2;
}

PalindromeStatus CheckPalindromeStatus(const string& input) {
    string reversed = ReverseString(input);
    if (IsEqual(input, reversed))
        return PalindromeStatus::Palindrome;
    else
        return PalindromeStatus::NotPalindrome;
}

string GetPalindromeStatusString(PalindromeStatus status) {
    switch (status) {
    case Palindrome:
        return "Palindrome";
    case NotPalindrome:
        return "Not Palindrome";
    default:
        return "Unknown";
    }
}

void Print(const string& text) {
    cout << text << endl;
}

void Print(const string& title, const string& value) {
    cout << title << " : " << value << endl;
}

string ReadString(const string& message) {
    Print(message);
    string input;
    getline(cin, input); // Use getline to read the entire line
    return input;
}

void PrintPalindromeStatus(const string& strStatus) {
    Print(ConstantAlert[1], strStatus);
}

int main() {
    string input = ReadString(ConstantAlert[0]);
    PrintPalindromeStatus(GetPalindromeStatusString(CheckPalindromeStatus(input)));
    return 0;
}
