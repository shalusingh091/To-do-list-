#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string title;
    bool completed;
};

vector<Task> tasks;

// Add task
void addTask() {
    Task t;
    cin.ignore();
    cout << "Enter task: ";
    getline(cin, t.title);
    t.completed = false;
    tasks.push_back(t);
    cout << "Task added successfully!\n";
}

// View tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
             << tasks[i].title
             << " ["
             << (tasks[i].completed ? "Completed" : "Pending")
             << "]\n";
    }
}

// Mark task as completed
void markCompleted() {
    int num;
    viewTasks();
    cout << "Enter task number to mark as completed: ";
    cin >> num;

    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks[num - 1].completed = true;
    cout << "Task marked as completed!\n";
}

// Remove task
void removeTask() {
    int num;
    viewTasks();
    cout << "Enter task number to remove: ";
    cin >> num;

    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + num - 1);
    cout << "Task removed successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- TO-DO LIST MANAGER ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}