#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
    int studentID;
    string name;
    string course;
    float gpa;
};

bool isUniqueID(const vector<Student>& students, int id) {
    for (const auto& s : students) {
        if (s.studentID == id) {
            return false;
        }
    }
    return true;
}

string getStanding(float gpa) {
    if (gpa >= 90) return "Excellent";
    else if (gpa >= 80) return "Very Good";
    else if (gpa >= 70) return "Good";
    else if (gpa >= 60) return "Passing";
    else return "Failed";
}

void addStudent(vector<Student>& students) {
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.studentID;

    while (!isUniqueID(students, s.studentID)) {
        cout << "ID already exists! Enter another ID: ";
        cin >> s.studentID;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Course: ";
    getline(cin, s.course);

    cout << "Enter GPA (0-100): ";
    cin >> s.gpa;

    students.push_back(s);
    cout << "Student added successfully!\n";
}

void editStudent(vector<Student>& students) {
    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    for (auto& s : students) {
        if (s.studentID == id) {
            cin.ignore();
            cout << "Enter new Name: ";
            getline(cin, s.name);

            cout << "Enter new Course: ";
            getline(cin, s.course);

            cout << "Enter new GPA: ";
            cin >> s.gpa;

            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}


void deleteStudent(vector<Student>& students) {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].studentID == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}


void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No records found.\n";
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Course"
         << setw(10) << "GPA"
         << setw(15) << "Standing" << endl;

    cout << "---------------------------------------------------------------\n";

    for (const auto& s : students) {
        cout << left << setw(10) << s.studentID
             << setw(20) << s.name
             << setw(15) << s.course
             << setw(10) << s.gpa
             << setw(15) << getStanding(s.gpa) << endl;
    }
}


int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Students\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: editStudent(students); break;
            case 3: deleteStudent(students); break;
            case 4: displayStudents(students); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
