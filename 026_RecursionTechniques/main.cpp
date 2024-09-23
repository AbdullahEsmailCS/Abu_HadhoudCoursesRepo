#include<iostream>

using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;  // Base case
    return n * factorial(n - 1);  // Recursive case
}

int fibonacci(int n) {
    if (n <= 1) return n;  // Base case
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

int main() {

    int x = 10;
    int result = factorial(x);
    cout << result << endl;
	return 0;
}