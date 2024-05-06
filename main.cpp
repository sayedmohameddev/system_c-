#include <iostream>
#include <string>
using namespace std;

const int max_number_of_student = 1000;
int student_count = 0;

struct student {
    string name_student;
    int id;
    int age;
    string address;
    string courses;
    float gpa;
    int student_phone_number;
    int student_parents_phone_number;
    string gender;
    int credit_hours;
    double grades;
};

student students[max_number_of_student];

// Function to add a new student
void add_student() {
    student new_student;
    if (student_count >= max_number_of_student)
        cout << "Max limit reached" << endl;
    else {
        cout << "Enter student name: ";
        cin >> new_student.name_student;
        cout << "Enter student id: ";
        cin >> new_student.id;
        cout << "Enter student age: ";
        cin >> new_student.age;
        cout << "Enter student address: ";
        cin >> new_student.address;
        cout << "Enter student phone number: ";
        cin >> new_student.student_phone_number;
        cout << "Enter parents phone number: ";
        cin >> new_student.student_parents_phone_number;
        cout << "Enter student gender: ";
        cin >> new_student.gender;
        cout << "Enter student GPA: ";
        cin >> new_student.gpa;
        cout << "Enter number of student courses: ";
        cin >> new_student.courses;
        cout << "Enter credit hours: ";
        cin >> new_student.credit_hours;
        cout << "Enter grades: ";
        cin >> new_student.grades;

        students[student_count] = new_student;
        student_count++;
        cout << "Student has been added successfully" << endl;
    }
}

// Function to display all students
void display_students() {
    if (student_count == 0)
        cout << "No students to display" << endl;
    else {
        for (int i = 0; i < student_count; i++) {
            cout << "Name: " << students[i].name_student << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Address: " << students[i].address << endl;
            cout << "Courses: " << students[i].courses << endl;
            cout << "GPA: " << students[i].gpa << endl;
            cout << "Gender: " << students[i].gender << endl;
            cout << "Student phone number: " << students[i].student_phone_number << endl;
            cout << "Parents phone number: " << students[i].student_parents_phone_number << endl;
            cout << "Grades: " << students[i].grades << endl;
            cout << "Credit hours: " << students[i].credit_hours << endl;
            cout << "------------------------" << endl;
        }
    }
}

// Function to edit student information
void edit_student() {
    int search_id;
    cout << "Enter student id to edit: ";
    cin >> search_id;

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == search_id) {
            cout << "Enter new id for student: ";
            cin >> students[i].id;
            cout << "Enter new name for student: ";
            cin >> students[i].name_student;
            cout << "Enter new grades for student: ";
            cin >> students[i].grades;
            cout << "Enter new GPA for student: ";
            cin >> students[i].gpa;
            cout << "Enter new courses for student: ";
            cin >> students[i].courses;
            cout << "Enter new age for student: ";
            cin >> students[i].age;
            cout << "Enter new address for student: ";
            cin >> students[i].address;
            cout << "Enter new gender for student: ";
            cin >> students[i].gender;
            cout << "Enter new student phone number: ";
            cin >> students[i].student_phone_number;
            cout << "Enter new parents phone number: ";
            cin >> students[i].student_parents_phone_number;
            cout << "Student details edited successfully." << endl;
            return;
        }
    }

    cout << "Student with ID " << search_id << " not found." << endl;
}

// Function to delete a student by ID
void delete_student() {
    int search_id;
    cout << "Enter student id to delete: ";
    cin >> search_id;

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == search_id) {
            // Shift all students after the found student to fill the gap
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }

            // Decrement the student count
            student_count--;

            cout << "Student with ID " << search_id << " deleted successfully." << endl;
            return;
        }
    }

    cout << "Student with ID " << search_id << " not found." << endl;
}

int main() {
    int choice;

    do {
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Edit Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                edit_student();
                break;
            case 4:
                delete_student();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
