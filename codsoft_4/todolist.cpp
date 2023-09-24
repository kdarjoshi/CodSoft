#include <iostream>
#include <fstream>  // Include the necessary header for file operations
using namespace std;

// Structure to store a list item
struct todolist {
    int id;
    string task;
};

int Id;

/* This function is the header for this application
   which shows the heading as "MY TODO LIST" 
*/
void banner() {
    cout << "____________" << endl;
    cout << "\t      MY TODO LIST!" << endl;
    cout << "____________" << endl;
}

/* This function adds a task to the list by prompting 
   a message to add the required task
*/
void addTask() {
    system("clear");
    cout << "Enter the new task:" << endl;
    todolist todo;
    cin.get();
    getline(cin, todo.task);
    char save;
    cout << "Save? (y/n):";
    cin >> save;
    if (save == 'y') {
        Id++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout << "\n " << Id;
        fout << "\n" << todo.task;
        fout.close();
        char more;
        cout << "Do you want to add more? (y/n):";
        cin >> more;
        if (more == 'y') {
            addTask();
        }
        else {
            system("clear");
            cout << "Tasks added successfully!" << endl;
            return;
        }
    }
    system("clear");
}

/* This function displays all the tasks present in the list*/
void showTask() {
    system("clear");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");  // Open the file for reading
    cout << "Tasks:" << endl;
    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        if (todo.task != "") {
            cout << todo.id << ": " << todo.task << endl;
        }
        else {
            cout << "List Empty!" << endl;
            break;
        }
    }
    fin.close();  // Close the file
    char exit;
    cout << "Exit? (y/n):";
    cin >> exit;
    if (exit != 'y') {
        showTask();
    }
    system("clear");
} 

/* This function deletes the required task by copying all the tasks
   to another file and neglecting the item to be deleted
*/
void deleteTask() {
    system("clear");
    int id;
    cout << "Enter the task id to delete: ";
    cin >> id; 
    char del;
    cout << "Delete? (y/n):";
    cin >> del;
    if (del == 'y') {
        todolist todo;
        ofstream tempFile;
        tempFile.open("temp.txt");  // Open the temp file for writing
        ifstream fin;
        fin.open("todo.txt");  // Open the original file for reading
        int index = 1;
        while (fin >> todo.id) {
            fin.ignore();
            getline(fin, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << index;
                tempFile << "\n" << todo.task;
                index++;
                Id--;
            }
        }
        fin.close();  // Close the original file
        tempFile.close();  // Close the temp file
        remove("todo.txt");  // Remove the original file
        rename("temp.txt", "todo.txt");  // Rename the temp file
        system("clear");
        cout << "Deleted successfully!" << endl;
    }
    else {
        system("clear");
        cout << "Deletion unsuccessful!" << endl;
    }
}

/* Main function */
int main() {
    int choice;
    system("clear");
    while (true) {
        banner();
        cout << "1. Add Task" << endl;
        cout << "2. Show Task" << endl;
        cout << "3. Delete Task" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                showTask();
                break;
            case 3:
                deleteTask();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
