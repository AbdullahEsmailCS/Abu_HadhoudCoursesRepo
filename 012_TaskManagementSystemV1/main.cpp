#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// constants
const string prompts[] = {
    "Enter Task ID: ",
    "Enter Task Title: ",
    "Enter Task Description: ",
    "Enter Task Category: ",
    "Task Added Successfully!"
};

// ------Output 
void Print(const string& message) {
    cout << message << endl;
}

//--input functions
//----------General functions
string ReadString(const string& message) {
    Print(message);
    string text;
    getline(cin, text);
    return text;
}

int ReadInteger(const string& message) {
    Print(message);
    int number;
    cin >> number;
    cin.ignore();
    return number;
}

//----------------Specific functions
int ReadTaskID(const string& message) {
    return ReadInteger(message);
}

string ReadTaskTitle(const string& message) {
    return ReadString(message);
}
string ReadTaskDescription(const string& message) {
    return ReadString(message);
}
string ReadTaskCategory(const string& message) {
    return ReadString(message);
}

// تعريف هيكل المهمة
struct Task {
    int ID = 0;
    string Title;
    string Description;
    string Category;
};

// دالة لعرض سجل واحد من نوع Task
void DisplayTask(const Task& task) {
    cout << "======================================================" << endl;
    cout << "Task ID: " << task.ID << endl;
    cout << "Title: " << task.Title << endl;
    cout << "Description: " << task.Description << endl;
    cout << "Category: " << task.Category << endl;
    cout << "======================================================" << endl;
}

// دالة للبحث عن مهمة باستخدام ID وإرجاع السجل
Task* SearchTaskByID(vector<Task>& tasks, int id) {
    for (Task& task : tasks) {
        if (task.ID == id) {
            return &task;  // إعادة إشارة إلى السجل
        }
    }
    return nullptr;  // إذا لم يتم العثور على المهمة
}
Task ReadTaskRecord() {
    Task t;
    t.ID = ReadTaskID(prompts[0]);
    t.Title = ReadTaskTitle(prompts[1]);
    t.Description = ReadTaskDescription(prompts[2]);
    t.Category = ReadTaskCategory(prompts[3]);
    return t;
}
// فئة لإدارة المهام
class TaskManager {
private:
    vector<Task> tasks;

public:
    // إضافة مهمة واحدة
    void AddTask(Task t) {
        tasks.push_back(t);
        Print(prompts[4]);
    }

    // عرض جميع المهام
    void DisplayTasks() {
        if (tasks.empty()) {
            Print("No tasks available.");
            return;
        }

        Print("Tasks List:");
        for (size_t i = 0; i < tasks.size(); ++i) {
            DisplayTask(tasks[i]);
        }
    }

    // تعديل مهمة معينة
    void EditTask() {
        int taskID = ReadTaskID("Enter task ID to edit: ");
        Task* taskToEdit = SearchTaskByID(tasks, taskID);

        if (taskToEdit == nullptr) {
            Print("No Task found with this ID.");
            return;
        }

        DisplayTask(*taskToEdit);

        string newTitle = ReadTaskTitle("Enter new title (leave blank to keep current): ");
        if (!newTitle.empty()) taskToEdit->Title = newTitle;

        string newDescription = ReadTaskDescription("Enter new description (leave blank to keep current): ");
        if (!newDescription.empty()) taskToEdit->Description = newDescription;

        string newCategory = ReadTaskCategory("Enter new category (leave blank to keep current): ");
        if (!newCategory.empty()) taskToEdit->Category = newCategory;

        Print("Task updated successfully!");
    }

    // حذف مهمة معينة
    void DeleteTask() {
        int taskID = ReadTaskID("Enter task ID to delete: ");
        Task* taskToDelete = SearchTaskByID(tasks, taskID);

        if (taskToDelete == nullptr) {
            Print("No Task found with this ID.");
            return;
        }

        tasks.erase(remove_if(tasks.begin(), tasks.end(), [taskID](Task& task) {
            return task.ID == taskID;
            }), tasks.end());

        Print("Task deleted successfully!");
    }

    // تصفية المهام حسب الفئة
    void FilterTasksByCategory() {
        string category = ReadTaskCategory("Enter category to filter by: ");

        vector<Task> filteredTasks;
        for (const Task& task : tasks) {
            if (task.Category == category) {
                filteredTasks.push_back(task);
            }
        }

        if (filteredTasks.empty()) {
            Print("No tasks found in this category.");
        }
        else {
            Print("Tasks in category '" + category + "':");
            for (const Task& task : filteredTasks) {
                cout << "- " << task.Title << "\n";
            }
        }
    }
};

// الدالة الرئيسية
int main() {
    TaskManager manager;
    int choice;

    do {
        cout << "\nTask Management System\n";
        cout << "1. Add New Task\n";
        cout << "2. Display All Tasks\n";
        cout << "3. Edit a Task\n";
        cout << "4. Delete a Task\n";
        cout << "5. Filter Tasks by Category\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // لتجاهل إدخال Enter السابق

        switch (choice) {
        case 1: {
            Task newTask = ReadTaskRecord();
            manager.AddTask(newTask);
            break;
        }
        case 2:
            manager.DisplayTasks();
            break;
        case 3:
            manager.EditTask();
            break;
        case 4:
            manager.DeleteTask();
            break;
        case 5:
            manager.FilterTasksByCategory();
            break;
        case 6:
            Print("Exiting...");
            break;
        default:
            Print("Invalid choice, please try again.");
        }
    } while (choice != 6);

    return 0;
}
