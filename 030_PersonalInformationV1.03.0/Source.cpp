#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
using namespace std;

// Constants for BMI thresholds
const double UNDERWEIGHT_THRESHOLD = 18.5;
const double NORMAL_WEIGHT_THRESHOLD = 25;
const double OVERWEIGHT_THRESHOLD = 30;

// ---------------Structures of data elements
//------------------Arithmatic functions

int Modulus(int fistValue, int secondValue) {
    return fistValue % secondValue;
}
int Multiply(int fistValue, int secondValue) {
    return fistValue * secondValue;
}

int Divide(int fistValue, int secondValue) {
    if (secondValue != 0) {
        return fistValue / secondValue;
    }
    return 0;
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

enum class MaritalStatus {
    Single,    // S
    Married,   // M
    Divorced,  // D
    Widowed,   // W
    Separated, // P
    Other      // O
};

enum class AgeGroup {
    Child,
    Teen,
    Adult,
    Senior
};

struct PersonDimensions {
    double Weight = 0;  // in kilograms
    double Height = 0; // in meters 
};

// Enum for BMI status
enum class BmiStatus {
    None,
    Underweight,
    NormalWeight,
    Overweight,
    Obese
};

enum class BloodType {
    A_Positive,   // A+
    A_Negative,   // A-
    B_Positive,   // B+
    B_Negative,   // B-
    O_Positive,   // O+
    O_Negative,   // O-
    AB_Positive,  // AB+
    AB_Negative   // AB-
};

// Struct to store phone numbers (mobile and landline)
struct PhoneNumber {
    string Mobile;
    string Landline;
};

// Struct to store email addresses (primary and secondary)
struct EmailAddress {
    string Primary;
    string Secondary;
};

// Struct to store address (street, city, state, zip code, and country)
struct Address {
    string Street;
    string City;
    string State;
    string ZipCode;
    string Country;
};

// Struct to store social media profiles (Facebook, Twitter, LinkedIn, Instagram)
struct SocialMediaProfiles {
    string Facebook;
    string Twitter;
    string LinkedIn;
    string Instagram;
};

// Class to encapsulate all contact information
class ContactInfo {
public:
    PhoneNumber phoneNumber;
    EmailAddress emailAddress;
    Address homeAddress;
    Address mailingAddress; // Separate mailing address if different from home
    SocialMediaProfiles socialMediaProfiles;

    // Function to display contact information
    void displayContactInfo() const {
        cout << "Phone Number (Mobile): " << phoneNumber.Mobile << endl;
        cout << "Phone Number (Landline): " << phoneNumber.Landline << endl;
        cout << "Primary Email: " << emailAddress.Primary << endl;
        cout << "Secondary Email: " << emailAddress.Secondary << endl;
        cout << "Home Address: " << homeAddress.Street << ", "
            << homeAddress.City << ", " << homeAddress.State << ", "
            << homeAddress.ZipCode << ", " << homeAddress.Country << endl;
        cout << "Mailing Address: " << mailingAddress.Street << ", "
            << mailingAddress.City << ", " << mailingAddress.State << ", "
            << mailingAddress.ZipCode << ", " << mailingAddress.Country << endl;
        cout << "Facebook: " << socialMediaProfiles.Facebook << endl;
        cout << "Twitter: " << socialMediaProfiles.Twitter << endl;
        cout << "LinkedIn: " << socialMediaProfiles.LinkedIn << endl;
        cout << "Instagram: " << socialMediaProfiles.Instagram << endl;
    }
};

struct FullName {
    string FirstName = "";
    string FatherName = "";
    string GrandFatherName = "";
    string FamilyName = "";
    string PseudoName = "";
};

enum EmploymentType {
    FullTime,
    PartTime,
    Internship,
    Freelance,
    SelfEmployed
};

enum LocationType {
    OnSite,
    Remote,
    Hybrid
};

struct Position {
    string Title;
    string Company;
    EmploymentType EmpType;
    string Location;
    LocationType LocationType;
    string StartDate;
    string EndDate;
    string Description;
};

struct WorkExperience {
    int ExperienceId;          // Primary Key
    int UserId;                // Foreign Key to Users table
    string CompanyName;
    string Title;
    string StartDate;          // Could use date types if necessary
    string EndDate;            // Could use date types if necessary
    string Description;
};

struct Education {
    int EducationId;           // Primary Key
    int UserId;                // Foreign Key to Users table
    string InstitutionName;
    string Degree;
    string FieldOfStudy;
    int StartYear;
    int EndYear;
    string Description;
};

struct Certifications {
    int CertificationId;       // Primary Key
    int UserId;                // Foreign Key to Users table
    string CertificationName;
    string Institution;
    string DateEarned;         // Could use a date type
};

struct Project {
    string Name;
    string Description;
    string StartDate;
    string EndDate;
};

struct Person {
    short ID = 0;
    FullName FullName;
    int Age = 0;
    Gender Gender = Gender::None;
    MaritalStatus MaritalStatus = MaritalStatus::Other;
    ContactInfo Contacts;
    string Nationality;
    string DateOfBirth;
    string PlaceOfBirth;
    PersonDimensions Dimensions;
    BmiStatus BMIStatus = BmiStatus::None;
    string About;



    bool IsActive = false;
    bool IsPseudoNameVisible = false;

    Position CurrentPosition;
    WorkExperience WorkExperiences[10]; // Example array size
    Education Educations[5]; // Example array size
    Certifications Certs[5]; // Example array size
    Project Projects[5]; // Example array size






};

//------------Calculate the body mass index

double CalculateBodyMassIndex(PersonDimensions pd) {
    double result = Multiply(pd.Height, pd.Height);
    double bmi = Divide(pd.Weight, result);
    return bmi;
}

// Function to determine BMI status
BmiStatus DetermineBMIStatus(double bmi) {
    if (bmi < UNDERWEIGHT_THRESHOLD) {
        return BmiStatus::Underweight;
    }
    else if (bmi < NORMAL_WEIGHT_THRESHOLD) {
        return BmiStatus::NormalWeight;
    }
    else if (bmi < OVERWEIGHT_THRESHOLD) {
        return BmiStatus::Overweight;
    }
    else {
        return BmiStatus::Obese;
    }
}

// Function to get the BMI status string from an enum
string GetBodyMassIndexStatusAsString(BmiStatus status) {
    switch (status) {
    case BmiStatus::Underweight:
        return "Underweight";
    case BmiStatus::NormalWeight:
        return "Normal weight";
    case BmiStatus::Overweight:
        return "Overweight";
    case BmiStatus::Obese:
        return "Obese";
    default:
        return "Invalid BMI status";
    }
}

//_------------------Helpers Functions

string GetFullName(FullName p) {
    return p.FirstName + " " + p.FatherName + " " + p.GrandFatherName + " " + p.FamilyName;
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
    return IsZero(Modulus(number, 2));
}

bool IsChild(int age) {
    return IsGreaterThanOrEqual(age, 0) && IsLessThanOrEqual(age, 12);
}

bool IsTeen(int age) {
    return IsGreaterThanOrEqual(age, 13) && IsLessThanOrEqual(age, 19);
}

bool IsAdult(int age) {
    return IsGreaterThanOrEqual(age, 20) && IsLessThanOrEqual(age, 64);
}

bool IsSenior(int age) {
    return IsGreaterThanOrEqual(age, 65);
}

// Main Age Classification Function
AgeGroup ClassifyAge(int age) {
    if (IsChild(age)) {
        return AgeGroup::Child;
    }
    else if (IsTeen(age)) {
        return AgeGroup::Teen;
    }
    else if (IsAdult(age)) {
        return AgeGroup::Adult;
    }
    else if (IsSenior(age)) {
        return AgeGroup::Senior;
    }
    else {
        throw invalid_argument("Invalid age");
    }
}

string AgeGroupToString(AgeGroup ageGroup) {
    switch (ageGroup) {
    case AgeGroup::Child:
        return "Child";
    case AgeGroup::Teen:
        return "Teen";
    case AgeGroup::Adult:
        return "Adult";
    case AgeGroup::Senior:
        return "Senior";
    default:
        throw invalid_argument("Unknown age group");
    }
}

bool CheckPseudoNameVisible(bool value) {
    return value;
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
 





//
//int main() {
//    Person person;
//
//    // Get Full Name
//    cout << "Enter First Name: ";
//    cin >> person.FullName.FirstName;
//    cout << "Enter Father's Name: ";
//    cin >> person.FullName.FatherName;
//    cout << "Enter Grandfather's Name: ";
//    cin >> person.FullName.GrandFatherName;
//    cout << "Enter Family Name: ";
//    cin >> person.FullName.FamilyName;
//    cout << "Enter Pseudo Name: ";
//    cin >> person.FullName.PseudoName;
//
//    // Get Personal Information
//    cout << "Enter Age: ";
//    cin >> person.Age;
//
//    char genderChar;
//    cout << "Enter Gender (M/F): ";
//    cin >> genderChar;
//    person.Gender = ConvertLetterToGender(genderChar);
//
//    char maritalChar;
//    cout << "Enter Marital Status (S/M/D/W/P/O): ";
//    cin >> maritalChar;
//    person.MaritalStatus = (MaritalStatus)maritalChar;
//
//    // Get Contact Information
//    cout << "Enter Mobile Phone Number: ";
//    cin >> person.Contacts.phoneNumber.Mobile;
//    cout << "Enter Landline Phone Number: ";
//    cin >> person.Contacts.phoneNumber.Landline;
//    cout << "Enter Primary Email: ";
//    cin >> person.Contacts.emailAddress.Primary;
//    cout << "Enter Secondary Email: ";
//    cin >> person.Contacts.emailAddress.Secondary;
//    cout << "Enter Home Address (Street, City, State, Zip, Country): ";
//    cin >> person.Contacts.homeAddress.Street >> person.Contacts.homeAddress.City >> person.Contacts.homeAddress.State >> person.Contacts.homeAddress.ZipCode >> person.Contacts.homeAddress.Country;
//    cout << "Enter Mailing Address (Street, City, State, Zip, Country): ";
//    cin >> person.Contacts.mailingAddress.Street >> person.Contacts.mailingAddress.City >> person.Contacts.mailingAddress.State >> person.Contacts.mailingAddress.ZipCode >> person.Contacts.mailingAddress.Country;
//    cout << "Enter Facebook Profile: ";
//    cin >> person.Contacts.socialMediaProfiles.Facebook;
//    cout << "Enter Twitter Profile: ";
//    cin >> person.Contacts.socialMediaProfiles.Twitter;
//    cout << "Enter LinkedIn Profile: ";
//    cin >> person.Contacts.socialMediaProfiles.LinkedIn;
//    cout << "Enter Instagram Profile: ";
//    cin >> person.Contacts.socialMediaProfiles.Instagram;
//
//    // Get Dimensions
//    cout << "Enter Weight (kg): ";
//    cin >> person.Dimensions.Weight;
//    cout << "Enter Height (m): ";
//    cin >> person.Dimensions.Height;
//
//    // Calculate and Display BMI
//    double bmi = CalculateBodyMassIndex(person.Dimensions);
//    person.BMIStatus = DetermineBMIStatus(bmi);
//    cout << "Your BMI is: " << bmi << endl;
//    cout << "BMI Status: " << GetBodyMassIndexStatusAsString(person.BMIStatus) << endl;
//
//    // Classify Age and Display
//    try {
//        AgeGroup ageGroup = ClassifyAge(person.Age);
//        cout << "Age Group: " << AgeGroupToString(ageGroup) << endl;
//    }
//    catch (const invalid_argument& e) {
//        cout << e.what() << endl;
//    }
//
//    // Display Full Name
//    cout << "Full Name: " << GetFullName(person.FullName) << endl;
//
//    // Display Contact Information
//    person.Contacts.displayContactInfo();
//
//    return 0;
//}
