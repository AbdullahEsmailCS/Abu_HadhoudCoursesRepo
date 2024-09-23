#include<iostream>
#include<string>
#include<vector>

using namespace std;






struct OutputFunctions {
    static void Print(const string& message) {
        cout << message << endl;
    }
    static void Print(int value) {
        cout << value << endl;
    }
    static void Print(const string& title, const string& value) {
        cout << title << " : " << value << endl;
    }
    static void Print(const string& title, int value) {
        cout << title << " : " << value << endl;
    }
    static void Print(const string& title, float value) {
        cout << title << " : " << value << endl;
    }
    static void Print(const string& title, char value) {
        cout << title << " : " << value << endl;
    }
    static void Print(const string& title, bool value) {
        cout << title << " : " << ((value) ? "Yes" : "No") << endl;
    }
};

//---------------------------inputs functions
struct InputFunctions {
    static short ReadShort(const string& message) {
        OutputFunctions::Print(message);
        short number;
        cin >> number;
        cin.ignore();
        return number;
    }

    static int ReadInteger(const string& message) {
        OutputFunctions::Print(message);
        int number;
        cin >> number;
        cin.ignore();
        return number;
    }

    static long ReadLong(const string& message) {
        OutputFunctions::Print(message);
        long number;
        cin >> number;
        cin.ignore();
        return number;
    }

    static float ReadFloat(const string& message) {
        OutputFunctions::Print(message);
        float number;
        cin >> number;
        cin.ignore();
        return number;
    }

    static double ReadDouble(const string& message) {
        OutputFunctions::Print(message);
        double number;
        cin >> number;
        cin.ignore();
        return number;
    }

    static bool ReadBoolean(const string& message) {
        OutputFunctions::Print(message);
        bool value;
        cin >> value;
        cin.ignore();
        return value;
    }

    static char ReadChar(const string& message) {
        OutputFunctions::Print(message);
        char letter;
        cin >> letter;
        cin.ignore();
        return letter;
    }

    static string ReadString(const string& message) {
        OutputFunctions::Print(message);
        string letter;
        getline(cin, letter);
        return letter;
    }
};

//--------------------------End input functions
struct ArithmeticOperations {
    // Static method for addition
    static int Add(int a, int b) {
        return a + b;
    }

    // Static method for subtraction
    static int Subtract(int a, int b) {
        return a - b;
    }

    // Static method for multiplication
    static int Multiply(int a, int b) {
        return a * b;
    }

    // Static method for division
    static double Divide(int a, int b) {
        if (b == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return 0; // or handle the error appropriately
        }
        return static_cast<double>(a) / b;
    }

    // Static method for modulus
    static int Modulus(int a, int b) {
        if (b == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return 0; // or handle the error appropriately
        }
        return a % b;
    }
};

struct RelationalOperations {
    // Static method for checking equality
    static bool IsEqual(int a, int b) {
        return a == b;
    }

    // Static method for checking inequality
    static bool IsNotEqual(int a, int b) {
        return a != b;
    }

    // Static method for checking greater than
    static bool IsGreaterThan(int a, int b) {
        return a > b;
    }

    // Static method for checking less than
    static bool IsLessThan(int a, int b) {
        return a < b;
    }

    // Static method for checking greater than or equal to
    static bool IsGreaterThanOrEqual(int a, int b) {
        return a >= b;
    }

    // Static method for checking less than or equal to
    static bool IsLessThanOrEqual(int a, int b) {
        return a <= b;
    }
};

struct LogicalOperations {
    // Static method for logical AND
    static bool And(bool a, bool b) {
        return a && b;
    }

    // Static method for logical OR
    static bool Or(bool a, bool b) {
        return a || b;
    }

    // Static method for logical NOT
    static bool Not(bool a) {
        return !a;
    }
};
struct BitwiseOperations {
    // Static method for bitwise AND
    static int And(int a, int b) {
        return a & b;
    }

    // Static method for bitwise OR
    static int Or(int a, int b) {
        return a | b;
    }

    // Static method for bitwise XOR
    static int Xor(int a, int b) {
        return a ^ b;
    }

    // Static method for bitwise NOT
    static int Not(int a) {
        return ~a;
    }

    // Static method for left shift
    static int LeftShift(int a, int n) {
        return a << n;
    }

    // Static method for right shift
    static int RightShift(int a, int n) {
        return a >> n;
    }
};

//------------------------------------------End of My Tools or helpers

// ArrayManipulation struct
struct ArrayManipulation {

    // Function to read an array of integers
    static vector<int> ReadIntArray(int size) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = InputFunctions::ReadInteger("Enter an integer:");
        }
        return arr;
    }

    // Function to read an array of strings
    static vector<string> ReadStringArray(int size) {
        vector<string> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = InputFunctions::ReadString("Enter a string:");
        }
        return arr;
    }

    // Function to print an array of integers
    static void PrintIntArray(const vector<int>& arr) {
        for (int item : arr) {
            OutputFunctions::Print(item);
        }
    }

    // Function to print an array of strings
    static void PrintStringArray(const vector<string>& arr) {
        for (const string& item : arr) {
            OutputFunctions::Print(item);
        }
    }

    // Function to get the maximum value in an array of integers
    static int GetMax(const vector<int>& arr) {
        int maxVal = arr[0];
        for (int item : arr) {
            if (item > maxVal) {
                maxVal = item;
            }
        }
        return maxVal;
    }

    // Function to get the minimum value in an array of integers
    static int GetMin(const vector<int>& arr) {
        int minVal = arr[0];
        for (int item : arr) {
            if (item < minVal) {
                minVal = item;
            }
        }
        return minVal;
    }

    // Function to search for an item in an array of integers
    static int Search(const vector<int>& arr, int key) {
        for (size_t i = 0; i < arr.size(); i++) {
            if (arr[i] == key) {
                return i; // Return the index of the found item
            }
        }
        return -1; // Item not found
    }

    // Bubble sort
    static void BubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Selection sort
    static void SelectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    // Insertion sort
    static void InsertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Quick sort helper function
    static int Partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    // Quick sort
    static void QuickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = Partition(arr, low, high);
            QuickSort(arr, low, pi - 1);
            QuickSort(arr, pi + 1, high);
        }
    }

    // Merge sort helper function
    static void Merge(vector<int>& arr, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;
        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[middle + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Merge sort
    static void MergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;
            MergeSort(arr, left, middle);
            MergeSort(arr, middle + 1, right);
            Merge(arr, left, middle, right);
        }
    }

    // Binary search
    static int BinarySearch(const vector<int>& arr, int key) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (arr[middle] == key) {
                return middle;
            }
            else if (arr[middle] < key) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1; // Item not found
    }
};



enum class enStatus {
    Active,
    InActive,
    Suspended
};

enum enGender {
    Male,
    Female,
    None
};

enum enMaritalStatus {
    None,
    Married,
    Single,
    Divorced
};

struct FullName {
    string FirstName,SecondName,ThirdName,LastName;
};

struct Address {
    string City, State, Country;
};

struct IndentityDocument {
    string ID, DocumentNumber, IssueDate, ExpiryDate;

};

struct Contact {
    long MobileNumber, Email, PhoneNumber;
};


struct Person {
    long ID;
    FullName Name;
    Address Address;
    Contact Contact;
    enGender Gender;
    enMaritalStatus SocialStatus;
    IndentityDocument IndentityInformation;
    enStatus Status;
};














int main() {

    int size = InputFunctions::ReadInteger("Enter the size of the array:");
    vector<int> arr = ArrayManipulation::ReadIntArray(size);

    OutputFunctions::Print("Original array:");
    ArrayManipulation::PrintIntArray(arr);

    ArrayManipulation::BubbleSort(arr);
    OutputFunctions::Print("Array after Bubble Sort:");
    ArrayManipulation::PrintIntArray(arr);

    int maxVal = ArrayManipulation::GetMax(arr);
    OutputFunctions::Print("Maximum value in the array:", maxVal);

    int minVal = ArrayManipulation::GetMin(arr);
    OutputFunctions::Print("Minimum value in the array:", minVal);

    int searchKey = InputFunctions::ReadInteger("Enter a value to search for:");
    int searchResult = ArrayManipulation::BinarySearch(arr, searchKey);
    if (searchResult != -1) {
        OutputFunctions::Print("Item found at index:", searchResult);
    }
    else {
        OutputFunctions::Print("Item not found.");
    }














    return 0;
}