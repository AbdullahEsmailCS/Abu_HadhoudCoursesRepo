#include<iostream>
#include<string>
#include "MathLib.h"

using namespace std;
using namespace  MathLibrary;

int main() {

    // Using Math class with double
    std::cout << "Power (2^3): " << Math<double>::Power(2, 3) << std::endl;
    std::cout << "Square root (9): " << Math<double>::Sqrt(9) << std::endl;
    std::cout << "Floor (5.7): " << Math<double>::Floor(5.7) << std::endl;
    std::cout << "Ceil (5.7): " << Math<double>::Ceil(5.7) << std::endl;
    std::cout << "Truncate (5.7): " << Math<double>::Truncate(5.7) << std::endl;

	return 0;
}