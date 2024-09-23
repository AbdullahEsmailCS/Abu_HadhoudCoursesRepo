#include<iostream>
#include<string>
#include <bitset>
#include <sstream>
#include <cmath>
 
#include <cctype>
#include <algorithm>
using namespace std;

// 1. Function to Check Length
int evaluateLength(const string& password) {
	return password.length();
}

// 2. Function to Check Character Variety
int evaluateCharacterVariety(const string& password) {
	bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

	for (char c : password) {
		if (islower(c)) hasLower = true;
		else if (isupper(c)) hasUpper = true;
		else if (isdigit(c)) hasDigit = true;
		else hasSpecial = true;
	}

	int varietyScore = 0;
	if (hasLower) varietyScore++;
	if (hasUpper) varietyScore++;
	if (hasDigit) varietyScore++;
	if (hasSpecial) varietyScore++;

	return varietyScore;
}

// 3. Function to Check for Unpredictability
bool isUnpredictable(const string& password) {
	// Simple check for common patterns or dictionary words
	string commonPatterns[] = { "123", "password", "qwerty", "abc", "admin" };

	for (const string& pattern : commonPatterns) {
		if (password.find(pattern) != string::npos) {
			return false;
		}
	}
	return true;
}

// 4. Function to Calculate Entropy
double calculateEntropy(const string& password) {
	int charsetSize = 0;
	bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

	for (char c : password) {
		if (islower(c)) hasLower = true;
		else if (isupper(c)) hasUpper = true;
		else if (isdigit(c)) hasDigit = true;
		else hasSpecial = true;
	}

	if (hasLower) charsetSize += 26;
	if (hasUpper) charsetSize += 26;
	if (hasDigit) charsetSize += 10;
	if (hasSpecial) charsetSize += 32;

	return password.length() * log2(charsetSize);
}

// 5. Combine All into a Single Function
string assessPasswordComplexity(const string& password) {
	int lengthScore = evaluateLength(password);
	int varietyScore = evaluateCharacterVariety(password);
	bool unpredictable = isUnpredictable(password);
	double entropy = calculateEntropy(password);

	// Define thresholds for password strength
	string complexity;

	if (lengthScore >= 12 && varietyScore == 4 && unpredictable && entropy > 60) {
		complexity = "Very Strong";
	}
	else if (lengthScore >= 10 && varietyScore >= 3 && entropy > 50) {
		complexity = "Strong";
	}
	else if (lengthScore >= 8 && varietyScore >= 2 && entropy > 40) {
		complexity = "Moderate";
	}
	else {
		complexity = "Weak";
	}

	return complexity;
}

//--------------password related functions

//---------------string manipulation

// 1. Function to Convert String from Upper to Lower Case
string toLowerCase(const string& str) {
	string result = str;
	for (char& c : result) {
		c = tolower(c);
	}
	return result;
}

// 2. Function to Convert String from Lower to Upper Case
string toUpperCase(const string& str) {
	string result = str;
	for (char& c : result) {
		c = toupper(c);
	}
	return result;
}

// 3. Function to Capitalize the First Letter of Each Word
string capitalizeFirstLetter(const string& str) {
	stringstream ss(str);
	string word, result;
	while (ss >> word) {
		if (!word.empty()) {
			word[0] = toupper(word[0]);
		}
		result += word + " ";
	}
	// Remove the trailing space
	if (!result.empty()) {
		result.pop_back();
	}
	return result;
}

// 4. Function to Encrypt Password Using XOR
string xorEncrypt(const string& password, char key) {
	string encrypted = password;
	for (char& c : encrypted) {
		c ^= key; // XOR operation
	}
	return encrypted;
}

// 5. Function to Check if a String is Null or Empty
bool isNullOrEmpty(const string& str) {
	return str.empty(); // Checks if the string is empty
}



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


//----------------------------Start To Do List

enum class UserPermission : unsigned int {
	None = 0,        // No permission
	Read = 1 << 0,   // 0001
	Write = 1 << 1,   // 0010
	Execute = 1 << 2,   // 0100
	Delete = 1 << 3,   // 1000
	Admin = 1 << 4    // 10000
};

bool hasPermission(unsigned int permissions, UserPermission permission) {
	return permissions & static_cast<unsigned int>(permission);
}

void removePermission(unsigned int& permissions, UserPermission permission) {
	permissions &= ~static_cast<unsigned int>(permission);
}

void addPermission(unsigned int& permissions, UserPermission permission) {
	permissions |= static_cast<unsigned int>(permission);
}

//-----------------------End permissions sub system


enum class TaskStatus {
	Created,
	InProgress,
	Completed
};

enum class Priority {
	High,
	Medium,
	Low
};

enum class Gender {
	None,
	Male,
	Female
};

enum class MaritalStatus {
	Married,
	Single,
	Divorced
};
enum class UserStatus {
	Active,
	InActive,
	Suspended,
	Lock
};

enum class ThemeSetting {
	Light,
	Dark,

};

 
struct FullName {
	string FirstName;
	string SecondName;
	string ThirdName;
	string LastName;
};

struct HistoricalData {
	string CreationDate ="", UpdationDate="";
	int CreatedBy = -1, UpdatedBy=-1;
};

class IIdentity {
protected:
	int id;
};


class User: public IIdentity {
private:
	unsigned int permissions = static_cast<unsigned int>(UserPermission::None);  // Stores permissions as a bit field
	FullName name;
	Gender gender;
	MaritalStatus socialStatus;
	string userName;
	string email;
	long phoneNumber;
	string password;
	bool isVerified;
	UserStatus status;
	HistoricalData historyInfo;



public:

	// Default constructor
	User() {
		id = 0;
		name = { "", "", "", "" };
		gender = Gender::None;
		socialStatus = MaritalStatus::Single;
		userName = "";
		email = "";
		phoneNumber = 0;
		password = "";
		isVerified = false;
		status = UserStatus::Active;
		historyInfo = { "", "", 0, 0 };
	}
	// Methods to manage permissions
	void grantPermission(UserPermission permission) {
		addPermission(permissions, permission);
	}

	void revokePermission(UserPermission permission) {
		removePermission(permissions, permission);
	}

	bool checkPermission(UserPermission permission) const {
		return hasPermission(permissions, permission);
	}

	// Display permissions
	void displayPermissions() const {
		std::cout << "Permissions: " << std::bitset<8>(permissions) << std::endl;
	}
	// Constructor with essential parameters
	User(int id, const FullName& name, const string& userName, const string& email) {
		this->id = id;
		this->name = name;
		this->gender = Gender::None;
		this->socialStatus = MaritalStatus::Single;
		this->userName = userName;
		this->email = email;
		this->phoneNumber = 0;
		this->password = "";
		this->isVerified = false;
		this->status = UserStatus::Active;
		this->historyInfo = { "", "", 0, 0 };
	}

	// Parameterized constructor with all attributes
	User(int id, const FullName& name, Gender gender, MaritalStatus socialStatus,
		const string& userName, const string& email, long phoneNumber,
		const string& password, bool isVerified, UserStatus status,
		const HistoricalData& historyInfo) {
		this->id = id;
		this->name = name;
		this->gender = gender;
		this->socialStatus = socialStatus;
		this->userName = userName;
		this->email = email;
		this->phoneNumber = phoneNumber;
		this->password = password;
		this->isVerified = isVerified;
		this->status = status;
		this->historyInfo = historyInfo;
	}







	// Getters
	int getId() const { return id; }
	FullName getName() const { return name; }
	Gender getGender() const { return gender; }
	MaritalStatus getSocialStatus() const { return socialStatus; }
	string getUserName() const { return userName; }
	string getEmail() const { return email; }
	long getPhoneNumber() const { return phoneNumber; }
	string getPassword() const { return password; }
	bool getIsVerified() const { return isVerified; }
	UserStatus getStatus() const { return status; }
	HistoricalData getHistoryInfo() const { return historyInfo; }

	// Setters
	void setId(int id) { this->id = id; }
	void setName(const FullName& name) { this->name = name; }
	void setGender(Gender gender) { this->gender = gender; }
	void setSocialStatus(MaritalStatus socialStatus) { this->socialStatus = socialStatus; }
	void setUserName(const string& userName) { this->userName = userName; }
	void setEmail(const string& email) { this->email = email; }
	void setPhoneNumber(long phoneNumber) { this->phoneNumber = phoneNumber; }
	void setPassword(const string& password) { this->password = password; }
	void setIsVerified(bool isVerified) { this->isVerified = isVerified; }
	void setStatus(UserStatus status) { this->status = status; }
	void setHistoryInfo(const HistoricalData& historyInfo) { this->historyInfo = historyInfo; }








	
};


class Task :public IIdentity {
private:
 
	string title;
	string description;
	string dueDate;
	Priority priority;
	TaskStatus status;
	bool isCompleted;
	HistoricalData historyInfo;
	string notes;

public:

	// Default constructor
	Task() {
		id = 0;
		title = "";
		description = "";
		dueDate = "";
		priority = Priority::Medium;
		status = TaskStatus::Created;
		isCompleted = false;
		historyInfo = { "", "", 0, 0 };
		notes = "";
	}

	// Constructor with essential parameters
	Task(int id, const string& title, const string& description) {
		this->id = id;
		this->title = title;
		this->description = description;
		this->dueDate = "";
		this->priority = Priority::Medium;
		this->status = TaskStatus::Created;
		this->isCompleted = false;
		this->historyInfo = { "", "", 0, 0 };
		this->notes = "";
	}

	// Parameterized constructor with all attributes
	Task(int id, const string& title, const string& description, const string& dueDate,
		Priority priority, TaskStatus status, bool isCompleted,
		const HistoricalData& historyInfo, const string& notes) {
		this->id = id;
		this->title = title;
		this->description = description;
		this->dueDate = dueDate;
		this->priority = priority;
		this->status = status;
		this->isCompleted = isCompleted;
		this->historyInfo = historyInfo;
		this->notes = notes;
	}






	// Getters
	int getId() const { return id; }
	string getTitle() const { return title; }
	string getDescription() const { return description; }
	string getDueDate() const { return dueDate; }
	Priority getPriority() const { return priority; }
	TaskStatus getStatus() const { return status; }
	bool getIsCompleted() const { return isCompleted; }
	HistoricalData getHistoryInfo() const { return historyInfo; }
	string getNotes() const { return notes; }

	// Setters
	void setId(int id) { this->id = id; }
	void setTitle(const string& title) { this->title = title; }
	void setDescription(const string& description) { this->description = description; }
	void setDueDate(const string& dueDate) { this->dueDate = dueDate; }
	void setPriority(Priority priority) { this->priority = priority; }
	void setStatus(TaskStatus status) { this->status = status; }
	void setIsCompleted(bool isCompleted) { this->isCompleted = isCompleted; }
	void setHistoryInfo(const HistoricalData& historyInfo) { this->historyInfo = historyInfo; }
	void setNotes(const string& notes) { this->notes = notes; }





};


//Conversion functions

// Function to convert TaskStatus to string
 string TaskStatusToString(TaskStatus status) {
	switch (status) {
	case TaskStatus::Created:
		return "Created";
	case TaskStatus::InProgress:
		return "InProgress";
	case TaskStatus::Completed:
		return "Completed";
	default:
		return "Unknown";
	}
}

// Function to convert Priority to string
 string PriorityToString(Priority priority) {
	switch (priority) {
	case Priority::High:
		return "High";
	case Priority::Medium:
		return "Medium";
	case Priority::Low:
		return "Low";
	default:
		return "Unknown";
	}
}

// Function to convert Gender to string
 string GenderToString(Gender gender) {
	switch (gender) {
	case Gender::None:
		return "None";
	case Gender::Male:
		return "Male";
	case Gender::Female:
		return "Female";
	default:
		return "Unknown";
	}
}

// Function to convert MaritalStatus to string
 string MaritalStatusToString(MaritalStatus status) {
	switch (status) {
	case MaritalStatus::Married:
		return "Married";
	case MaritalStatus::Single:
		return "Single";
	case MaritalStatus::Divorced:
		return "Divorced";
	default:
		return "Unknown";
	}
}

// Function to convert UserStatus to string
 string UserStatusToString(UserStatus status) {
	switch (status) {
	case UserStatus::Active:
		return "Active";
	case UserStatus::InActive:
		return "InActive";
	case UserStatus::Suspended:
		return "Suspended";
	case UserStatus::Lock:
		return "Lock";
	default:
		return "Unknown";
	}
}

 // Function to create a full name string from a FullName struct
 string FullNameToString(const FullName& name) {
	 return name.FirstName + " " + name.SecondName + " " + name.ThirdName + " " + name.LastName;
 }

 // Function to convert a full name string back to a FullName struct
 FullName StringToFullName(const string& fullName) {
	 FullName name;
	 stringstream ss(fullName);
	 ss >> name.FirstName >> name.SecondName >> name.ThirdName >> name.LastName;
	 return name;
 }











//-----------end conversion functions








int main() {

	//User user;

	//// Grant permissions
	//user.grantPermission(UserPermission::Read);
	//user.grantPermission(UserPermission::Write);
	//user.grantPermission(UserPermission::Admin);

	//// Display current permissions
	//user.displayPermissions();

	//// Check if user has specific permissions
	//if (user.checkPermission(UserPermission::Write)) {
	//	std::cout << "User has write permission." << std::endl;
	//}

	//// Revoke a permission
	//user.revokePermission(UserPermission::Write);
	//user.displayPermissions();



	string text = "Hello World!";
	string password = "SecurePassword123";
	char encryptionKey = 'K'; // Example key for XOR encryption

	cout << "Original Text: " << text << endl;
	cout << "Lower Case: " << toLowerCase(text) << endl;
	cout << "Upper Case: " << toUpperCase(text) << endl;
	cout << "Capitalized: " << capitalizeFirstLetter(text) << endl;

	string encryptedPassword = xorEncrypt(password, encryptionKey);
	cout << "Encrypted Password: " << encryptedPassword << endl;

	// Decrypt the password to verify (XORing again with the same key)
	string decryptedPassword = xorEncrypt(encryptedPassword, encryptionKey);
	cout << "Decrypted Password: " << decryptedPassword << endl;

	cout << "Is the string null or empty? " << (isNullOrEmpty(text) ? "Yes" : "No") << endl;












	return 0;
}


/*


Here’s a comprehensive overview of the information typically found in a To-Do List Application, organized into various categories such as user interface elements, data models, functionalities, and features.

1. User Information
User ID: Unique identifier for each user.
Username: Name displayed in the application.
Email: Email address for account management and notifications.
Password: Encrypted password for user authentication.
Preferences: User settings (e.g., notification preferences, theme settings).
2. Task Information
Each task or item in the to-do list typically includes:

Task ID: Unique identifier for each task.
Title: Brief description of the task.
Description: Detailed information about the task (optional).
Due Date: Date and time by which the task should be completed.
Priority Level: Indication of task importance (e.g., High, Medium, Low).
Status: Current state of the task (e.g., Pending, Completed, Overdue).
Created Date: Date when the task was created.
Updated Date: Date when the task was last modified.
Subtasks: List of smaller tasks associated with the main task (optional).
Tags/Labels: Keywords to categorize or group tasks.
3. User Interface Elements
Dashboard: Overview of tasks, including a summary of completed, pending, and overdue tasks.
Task List View: Displays all tasks with options to filter and sort.
Task Details View: Detailed view for editing and viewing individual task information.
Add Task Button: Button to create a new task.
Edit Task Button: Button to modify an existing task.
Delete Task Button: Button to remove a task from the list.
Filter Options: Options to view tasks by status, priority, or due date.
Search Bar: For searching tasks by title or keywords.
Settings Menu: For user preferences and account management.
4. Functionalities
Create Task: Function to add a new task with relevant details.
Edit Task: Function to modify existing task details.
Delete Task: Function to remove a task from the list.
Complete Task: Function to mark a task as completed.
Filter and Sort Tasks: Functionality to filter tasks based on various criteria (e.g., due date, priority) and sort them.
Set Reminders: Option to set notifications for tasks before their due dates.
Categorize Tasks: Ability to assign tags or labels to tasks for organization.
Data Persistence: Mechanism to save tasks locally or in the cloud for retrieval later.
5. Notifications and Reminders
Push Notifications: Alerts sent to the user’s device regarding upcoming due dates or reminders.
Email Notifications: Optional email reminders for due tasks.
In-App Notifications: Alerts within the application regarding task status updates.
6. Data Models
User Model: Represents user information and preferences.
Task Model: Represents individual task details and status.
Subtask Model: Represents subtasks related to a main task (if applicable).
Tag/Label Model: Represents tags for categorizing tasks.
7. Security Features
User Authentication: Secure login/logout mechanisms.
Data Encryption: Encryption for user passwords and sensitive data.
Access Control: Permissions for editing or deleting tasks based on user roles.
8. Integration and API
External APIs: Possible integration with calendars, email services, or productivity tools.
Export/Import Options: Ability to export tasks to formats like CSV or import tasks from other applications.
9. User Experience Features
Dark Mode: Option for a darker theme for better visibility.
Customizable Themes: Ability to change the app’s appearance.
Help and Support: FAQs, user guides, and support contact information.
10. Performance Metrics
Task Completion Rate: Percentage of tasks completed versus created.
Average Time to Complete Tasks: Average duration taken to complete tasks.

-------------------------------------------------

To calculate Task Completion Rate and Average Time to Complete Tasks, follow these formulas and steps:

1. Task Completion Rate
The Task Completion Rate measures the percentage of tasks that have been completed out of the total tasks created.

Formula:
Task Completion Rate
=
(
Number of Completed Tasks
Total Number of Created Tasks
)
×
100
Task Completion Rate=(
Total Number of Created Tasks
Number of Completed Tasks
​
 )×100
Steps to Calculate:
Count the Number of Completed Tasks: This is the total number of tasks that have been marked as completed.
Count the Total Number of Created Tasks: This is the total number of tasks that have been created in the system, regardless of their status.
Apply the Formula: Substitute the values into the formula and calculate.
Example:
Number of Completed Tasks: 80
Total Number of Created Tasks: 100
Task Completion Rate
=
(
80
100
)
×
100
=
80
%
Task Completion Rate=(
100
80
​
 )×100=80%
2. Average Time to Complete Tasks
The Average Time to Complete Tasks measures the average duration taken to complete a task from the time it was created to when it was marked as completed.

Formula:
Average Time to Complete Tasks
=
Total Time to Complete All Tasks
Number of Completed Tasks
Average Time to Complete Tasks=
Number of Completed Tasks
Total Time to Complete All Tasks
​

Steps to Calculate:
Calculate Time for Each Task: For each task, determine the time taken to complete it. This is usually calculated as:
Time Taken
=
Completion Date
−
Creation Date
Time Taken=Completion Date−Creation Date
Sum the Total Time: Add up the time taken for all completed tasks to get the total time.
Count the Number of Completed Tasks: As before, count the number of tasks that have been completed.
Apply the Formula: Substitute the total time and the number of completed tasks into the formula and calculate.
Example:
Task 1: Created on Day 1, Completed on Day 5 → Time Taken = 4 days
Task 2: Created on Day 2, Completed on Day 6 → Time Taken = 4 days
Task 3: Created on Day 3, Completed on Day 7 → Time Taken = 4 days
Total Time Taken:
4
+
4
+
4
=
12
 days
4+4+4=12 days

Number of Completed Tasks: 3

Average Time to Complete Tasks
=
12
 days
3
=
4
 days
Average Time to Complete Tasks=
3
12 days
​
 =4 days
Summary
Task Completion Rate gives you the efficiency of task completion in the application, while Average Time to Complete Tasks provides insight into how long it takes to finish tasks, helping you analyze productivity and task management efficiency.





*/