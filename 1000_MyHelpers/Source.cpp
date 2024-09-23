#include<iostream>
#include<string>
#include <vector>
#include <limits>


using namespace std;

struct Output {
	static void Print(const string& text) {
		cout << text << endl;
	}
	static	void Print(const string& title, const string& value) {
		cout << title << " : " << value << endl;
	}
};


struct Input {
    static short ReadShortNumber(const string& message) {
        Output::Print(message);
        short number;
        while (true) {
            cin >> number;
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                Output::Print("Invalid input. Please enter a valid short number.");
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
                return number;
            }
        }
    }

    static int ReadIntegerNumber(const string& message) {
        Output::Print(message);
        int number;
        while (true) {
            cin >> number;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Output::Print("Invalid input. Please enter a valid integer.");
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return number;
            }
        }
    }

    static long ReadLongNumber(const string& message) {
        Output::Print(message);
        long number;
        while (true) {
            cin >> number;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Output::Print("Invalid input. Please enter a valid long number.");
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return number;
            }
        }
    }

    static float ReadFloatNumber(const string& message) {
        Output::Print(message);
        float number;
        while (true) {
            cin >> number;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Output::Print("Invalid input. Please enter a valid float number.");
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return number;
            }
        }
    }

    static double ReadDoubleNumber(const string& message) {
        Output::Print(message);
        double number;
        while (true) {
            cin >> number;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Output::Print("Invalid input. Please enter a valid double number.");
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return number;
            }
        }
    }

    static char ReadChar(const string& message) {
        Output::Print(message);
        char letter;
        cin >> letter;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character from buffer
        return letter;
    }

    static string ReadString(const string& message) {
        Output::Print(message);
        string value;
        getline(cin, value);
        return value;
    }

    static bool ReadBoolean(const string& message) {
        Output::Print(message);
        bool value;
        while (true) {
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Output::Print("Invalid input. Please enter a valid boolean (0 or 1).");
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

    // New function: Read an array of integers
    static vector<int> ReadIntegerArray(const string& message, int size) {
        Output::Print(message);
        vector<int> numbers(size);
        for (int i = 0; i < size; ++i) {
            numbers[i] = ReadIntegerNumber("Enter number " + to_string(i + 1) + ":");
        }
        return numbers;
    }


    // New function: Read a specified number of characters
    static string ReadFixedLengthString(const string& message, size_t length) {
        Output::Print(message);
        string value;
        while (true) {
            getline(cin, value);
            if (value.length() != length) {
                Output::Print("Invalid input. Please enter exactly " + to_string(length) + " characters.");
            }
            else {
                return value;
            }
        }
    }
};


int main() {

    //==================================================
    long ID = 1001046464654798701;
    short Age = 26;
    string FullName = "Abdullah Abdo Mohammed Esmail";
    int Phone = 738807541;
    char Gender = 'M';
    char MaritalStatus = 'S';
    float Height = 1.5;
    double Weight = 53.5;
    bool IsHappy = false;
    bool IsSad = true;
    //=====================================================

    int a = 10, b = 5;

    // Arithmetic Operators
    cout << "Arithmetic Operators:" << endl;
    cout << "a + b = " << (a + b) << endl; // Addition
    cout << "a - b = " << (a - b) << endl; // Subtraction
    cout << "a * b = " << (a * b) << endl; // Multiplication
    cout << "a / b = " << (a / b) << endl; // Division
    cout << "a % b = " << (a % b) << endl; // Modulus (remainder)

    // Relational (Comparison) Operators
    cout << "\nRelational Operators:" << endl;
    cout << "a == b: " << (a == b) << endl; // Equal to
    cout << "a != b: " << (a != b) << endl; // Not equal to
    cout << "a > b: " << (a > b) << endl;   // Greater than
    cout << "a < b: " << (a < b) << endl;   // Less than
    cout << "a >= b: " << (a >= b) << endl; // Greater than or equal to
    cout << "a <= b: " << (a <= b) << endl; // Less than or equal to

    // Logical Operators
    bool x = true, y = false;
    cout << "\nLogical Operators:" << endl;
    cout << "x && y: " << (x && y) << endl; // Logical AND
    cout << "x || y: " << (x || y) << endl; // Logical OR
    cout << "!x: " << (!x) << endl;         // Logical NOT

    // Bitwise Operators
    cout << "\nBitwise Operators:" << endl;
    cout << "a & b = " << (a & b) << endl;  // AND
    cout << "a | b = " << (a | b) << endl;  // OR
    cout << "a ^ b = " << (a ^ b) << endl;  // XOR
    cout << "~a = " << (~a) << endl;        // NOT
    cout << "a << 1 = " << (a << 1) << endl; // Left shift
    cout << "a >> 1 = " << (a >> 1) << endl; // Right shift

    // Assignment Operators
    cout << "\nAssignment Operators:" << endl;
    a = 10; // Assign
    cout << "a = " << a << endl;
    a += 5; // Add and assign
    cout << "a += 5: " << a << endl;
    a -= 5; // Subtract and assign
    cout << "a -= 5: " << a << endl;
    a *= 2; // Multiply and assign
    cout << "a *= 2: " << a << endl;
    a /= 2; // Divide and assign
    cout << "a /= 2: " << a << endl;
    a %= 3; // Modulus and assign
    cout << "a %= 3: " << a << endl;

    // Increment and Decrement Operators
    cout << "\nIncrement and Decrement Operators:" << endl;
    a = 10;
    cout << "a++: " << a++ << endl; // Post-increment
    cout << "Now a = " << a << endl;
    cout << "++a: " << ++a << endl; // Pre-increment
    cout << "a--: " << a-- << endl; // Post-decrement
    cout << "Now a = " << a << endl;
    cout << "--a: " << --a << endl; // Pre-decrement

    // Ternary Operator
    cout << "\nTernary Operator:" << endl;
    int max = (a > b) ? a : b;
    cout << "Max of a and b: " << max << endl;

    // sizeof Operator
    cout << "\nsizeof Operator:" << endl;
    cout << "Size of int: " << sizeof(a) << " bytes" << endl;

    // Pointer Operators
    cout << "\nPointer Operators:" << endl;
    int* p = &a;
    cout << "Address of a: " << p << endl; // Address of operator (&)
    cout << "Value at address p: " << *p << endl; // Dereference operator (*)










	return 0;
}