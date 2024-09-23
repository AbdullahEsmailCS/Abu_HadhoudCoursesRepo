
#pragma once


namespace MathLibrary {

    //------------start math class
    template <typename T>
    class Math {
    public:
        static T Add(T a, T b) {
            return a + b;
        }

        static T Sub(T a, T b) {
            return a - b;
        }

        static T Mul(T a, T b) {
            return a * b;
        }

        static T Divide(T a, T b) {
            if (b == 0) {
                throw std::invalid_argument("Division by zero");
            }
            return a / b;
        }

        static T Power(T base, int exponent) {
            T result = 1;
            bool isNegativeExponent = (exponent < 0);
            exponent = isNegativeExponent ? -exponent : exponent;

            for (int i = 0; i < exponent; ++i) {
                result *= base;
            }

            return isNegativeExponent ? (T)(1) / result : result;
        }

        static T Sqrt(T a) {
            if (a < 0) {
                throw std::invalid_argument("Cannot take square root of a negative number");
            }

            T low = 0;
            T high = a;
            T mid;

            while (high - low > 0.0001) { // Precision to 4 decimal places
                mid = (low + high) / 2;
                if (mid * mid < a) {
                    low = mid;
                }
                else {
                    high = mid;
                }
            }

            return (low + high) / 2; // Return the average as the square root
        }

        static T Floor(T a) {
            T intPart = static_cast<int>(a);
            return (a < intPart) ? (intPart - 1) : intPart; // Adjust if it's not an integer
        }

        static T Ceil(T a) {
            T intPart = static_cast<int>(a);
            return (a > intPart) ? (intPart + 1) : intPart; // Adjust if it's not an integer
        }

        static T Truncate(T a) {
            return static_cast<int>(a); // Simply cast to int
        }
    };
    //---------- end math class
    template<typename T>
    class clsRelationalOperations {
    public:
        // Equality operator
     static   bool isEqual(const T& a, const T& b) const {
            return a == b;
        }

        // Inequality operator
      static  bool isNotEqual(const T& a, const T& b) const {
            return a != b;
        }

        // Less than operator
      static  bool isLessThan(const T& a, const T& b) const {
            return a < b;
        }

        // Greater than operator
      static  bool isGreaterThan(const T& a, const T& b) const {
            return a > b;
        }

        // Less than or equal operator
     static   bool isLessThanOrEqual(const T& a, const T& b) const {
            return a <= b;
        }

        // Greater than or equal operator
     static   bool isGreaterThanOrEqual(const T& a, const T& b) const {
            return a >= b;
        }
    };


}