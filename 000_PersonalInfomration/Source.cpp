#include <iostream>
#include <string>
#include<vector>

// Social Status Enum
enum class SocialStatus {
    Married,
    Single,
    Divorced
};

// Qualification Enum
enum class QualificationType {
    Doctorate,
    Masters,
    Bachelors,
    Diploma,
    HighSchool,
    Intermediate,
    Elementary
};

// Gender Enum
enum class Gender {
    Male,
    Female
};

// Full Name Struct
struct FullName {
    std::string first;
    std::string second;
    std::string third;
    std::string fourth;
};

// Email Type Enum
enum class EmailType {
    Work,
    Personal,
    Other
};

// Address Struct
struct Address {
    std::string country;
    std::string governorate;
    std::string city;
    std::string neighborhood;
    std::string street;
    std::string building;
    std::string apartment;
};

// ID Type Enum
enum class IDType {
    Passport,
    IDCard,
    DriverLicense,
    UniversityID,
    AcademicCard
};


// Enum for Phone Types
enum class PhoneType {
    Landline,       // ثابت
    Mobile,         // محمول
    Smartphone,     // ذكي
    Emergency,      // طوارئ
    TollFree,       // مجاني
    Fax,            // فاكس
    VoIP,           // Voice over IP
    Business        // أعمال
};





// Enum for ID Types
enum class IDType {
    Passport,       // جواز
    IDCard,         // بطاقة هوية
    DriverLicense,  // رخصة قيادة
    UniversityID,   // بطاقة جامعية
    AcademicCard    // بطاقة أكاديمية
};

// Struct for Identity Information
struct IdentityInfo {
    std::string idNumber;       // رقم الهوية
    std::string issueDate;      // تاريخ الإصدار
    std::string expirationDate; // تاريخ الانتهاء
    std::string issuingAuthority; // جهة الإصدار
    std::string nationalNumber; // رقم الوطني
    IDType idType;              // نوع الهوية
};



// Struct for Apartment
struct Apartment {
    std::string apartmentNumber; // Apartment number
};

// Struct for Building
struct Building {
    std::string buildingNumber; // Building number
    Apartment apartment;         // Apartment information
};
// Class for Apartment
class Apartment {
public:
    std::string apartmentNumber; // Apartment number

    Apartment(const std::string& number) : apartmentNumber(number) {}
};

// Class for Building
class Building {
public:
    std::string buildingNumber;  // Building number
    std::vector<Apartment> apartments; // List of apartments

    Building(const std::string& number) : buildingNumber(number) {}

    void addApartment(const Apartment& apartment) {
        apartments.push_back(apartment);
    }
};

// Class for Street
class Street {
public:
    std::string streetName; // Street name
    std::vector<Building> buildings; // List of buildings

    Street(const std::string& name) : streetName(name) {}

    void addBuilding(const Building& building) {
        buildings.push_back(building);
    }
};

// Class for Neighborhood
class Neighborhood {
public:
    std::string neighborhoodName; // Neighborhood name
    std::vector<Street> streets;   // List of streets

    Neighborhood(const std::string& name) : neighborhoodName(name) {}

    void addStreet(const Street& street) {
        streets.push_back(street);
    }
};

// Class for City
class City {
public:
    std::string cityName;         // City name
    std::vector<Neighborhood> neighborhoods; // List of neighborhoods

    City(const std::string& name) : cityName(name) {}

    void addNeighborhood(const Neighborhood& neighborhood) {
        neighborhoods.push_back(neighborhood);
    }
};

// Class for Governorate
class Governorate {
public:
    std::string governorateName; // Governorate name
    std::vector<City> cities;     // List of cities

    Governorate(const std::string& name) : governorateName(name) {}

    void addCity(const City& city) {
        cities.push_back(city);
    }
};

// Class for Country
class Country {
public:
    std::string countryName;      // Country name
    std::vector<Governorate> governorates; // List of governorates

    Country(const std::string& name) : countryName(name) {}

    void addGovernorate(const Governorate& governorate) {
        governorates.push_back(governorate);
    }
};
 




struct Identity {
    std::string idNumber;       // رقم الهوية
    std::string issueDate;      // تاريخ الاصدار
    std::string expiryDate;     // تاريخ الانتهاء
    std::string issuingAuthority; // جهة الاصدار
    std::string nationalNumber;  // رقم الوطني
    std::string idType;         // نوع الهوية

    Identity(const std::string& idNum, const std::string& issueDt, const std::string& expiryDt,
        const std::string& authority, const std::string& natNum, const std::string& type)
        : idNumber(idNum), issueDate(issueDt), expiryDate(expiryDt),
        issuingAuthority(authority), nationalNumber(natNum), idType(type) {}
};


// هيكل لتمثيل معلومات الهاتف
struct PhoneNumber {
    std::string nationalNumber; // الرقم الوطني
    std::string phoneNumber;    // رقم الهاتف
    PhoneType phoneType;      // نوع رقم الهاتف
 
};

// هيكل لتمثيل معلومات البريد الإلكتروني
struct Email {
    std::string nationalNumber; // الرقم الوطني
    std::string email;          // الايميل
    EmailType emailType;      // نوع الايميل
 
};


 

// هيكل لتمثيل بيانات المؤهل
struct Qualification {
    std::string nationalNumber; // الرقم الوطني
   QualificationType  qualificationType; // نوع المؤهل
    std::string specializationField; // مجال التخصص
    std::string specializationType; // نوع التخصص
    std::string institution; // مكان الحصول عليه
    std::string acquisitionDate; // تاريخ الحصول عليه

     
};



int main() {
    // Example usage
    SocialStatus status = SocialStatus::Married;
  
    Gender gender = Gender::Male;
    EmailType emailType = EmailType::Work;

    FullName name = { "John", "Doe", "Smith", "Johnson" };
    Address address = {
        "Yemen",
        "Taiz",
        "Taiz City",
        "Al-Mudhaffar",
        "Al-Qadi Street",
        "Building 5",
        "Apartment 10"
    };

    IDType idType = IDType::Passport;

    // Output example
    std::cout << "Social Status: " << static_cast<int>(status) << std::endl;
    std::cout << "Qualification: " << static_cast<int>(qual) << std::endl;
    std::cout << "Gender: " << static_cast<int>(gender) << std::endl;
    std::cout << "Email Type: " << static_cast<int>(emailType) << std::endl;

    std::cout << "Full Name: " << name.first << " "
        << name.second << " "
        << name.third << " "
        << name.fourth << std::endl;

    std::cout << "Address: " << address.country << ", "
        << address.governorate << ", "
        << address.city << ", "
        << address.neighborhood << ", "
        << address.street << ", "
        << address.building << ", "
        << address.apartment << std::endl;

    std::cout << "ID Type: " << static_cast<int>(idType) << std::endl;
    // Example usage
    IdentityInfo identity = {
        "123456789",                // idNumber
        "2023-01-01",               // issueDate
        "2033-01-01",               // expirationDate
        "Government Authority",      // issuingAuthority
        "987654321",                // nationalNumber
        IDType::IDCard              // idType
    };

    // Output example
    std::cout << "ID Number: " << identity.idNumber << std::endl;
    std::cout << "Issue Date: " << identity.issueDate << std::endl;
    std::cout << "Expiration Date: " << identity.expirationDate << std::endl;
    std::cout << "Issuing Authority: " << identity.issuingAuthority << std::endl;
    std::cout << "National Number: " << identity.nationalNumber << std::endl;
    std::cout << "ID Type: " << static_cast<int>(identity.idType) << std::endl;

    // Example usage
    Country country = {
        "Yemen",
        {
            "Taiz",
            {
                "Taiz City",
                {
                    "Al-Mudhaffar",
                    {
                        "Al-Qadi Street",
                        {
                            "Building 5",
                            {
                                "Apartment 10"
                            }
                        }
                    }
                }
            }
        }
    };

    // Output example
    std::cout << "Country: " << country.countryName << std::endl;
    std::cout << "Governorate: " << country.governorate.governorateName << std::endl;
    std::cout << "City: " << country.governorate.city.cityName << std::endl;
    std::cout << "Neighborhood: " << country.governorate.city.neighborhood.neighborhoodName << std::endl;
    std::cout << "Street: " << country.governorate.city.neighborhood.street.streetName << std::endl;
    std::cout << "Building: " << country.governorate.city.neighborhood.street.building.buildingNumber << std::endl;
    std::cout << "Apartment: " << country.governorate.city.neighborhood.street.building.apartment.apartmentNumber << std::endl;






    return 0;
}
