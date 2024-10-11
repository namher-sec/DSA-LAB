#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class StudentGrades {
private:
    string studentName;
    int firstGrade;
    int secondGrade;
    int thirdGrade;
public:
    StudentGrades() : studentName(""), firstGrade(0), secondGrade(0), thirdGrade(0) {}

    void InputName() {
        cout << "Enter Student Name: ";
        cin >> studentName;
    }

    void InputFirstGrade() {
        cout << "Enter First Grade: ";
        cin >> firstGrade;
    }

    void InputSecondGrade() {
        cout << "Enter Second Grade: ";
        cin >> secondGrade;
    }

    void InputThirdGrade() {
        cout << "Enter Third Grade: ";
        cin >> thirdGrade;
    }

    string GetStudentName() const {
        return studentName;
    }

    int GetFirstGrade() const {
        return firstGrade;
    }

    int GetSecondGrade() const {
        return secondGrade;
    }

    int GetThirdGrade() const {
        return thirdGrade;
    }

    void ShowDetails() const {
        cout << left << setw(25) << studentName
             << left << setw(15) << firstGrade
             << left << setw(15) << secondGrade
             << left << setw(15) << thirdGrade << endl;
    }
};

int main() {
    const int maxStudents = 5;
    StudentGrades students[maxStudents];
    int numberOfStudents = 0;
    int studentIndex = 0;
    const int gradesPerStudent = 3;
    char continueOption;

    do {
        if (numberOfStudents >= maxStudents) {
            cout << "Maximum number of students reached." << endl;
            break;
        }

        cout << "Enter details for student " << numberOfStudents + 1 << " :" << endl;
        students[numberOfStudents].InputName();
        students[numberOfStudents].InputFirstGrade();
        students[numberOfStudents].InputSecondGrade();
        students[numberOfStudents].InputThirdGrade();
        numberOfStudents++;

        cout << "Do you want to add grades for another student? (Y/N): ";
        cin >> continueOption;
    } while (continueOption == 'Y' || continueOption == 'y');

    cout << endl << "Total number of students: " << numberOfStudents << endl;
    cout << "Number of grades (per student): " << gradesPerStudent << endl << endl;

    cout << left << setw(25) << "STUDENT NAME"
         << left << setw(15) << "GRADE 1"
         << left << setw(15) << "GRADE 2"
         << left << setw(15) << "GRADE 3" << endl;

    for (int i = 0; i < numberOfStudents; i++) {
        students[i].ShowDetails();
    }

    string searchName;
    cout << endl << "Enter the name of the student you want to search for: ";
    cin.ignore();  // To ignore the newline character left in the buffer
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < numberOfStudents; i++) {
        if (searchName == students[i].GetStudentName()) {
            studentIndex = i;
            found = true;
            break;
        }
    }

    if (found) {
        cout << endl;
        cout << left << setw(25) << "STUDENT NAME"
             << left << setw(15) << "GRADE 1"
             << left << setw(15) << "GRADE 2"
             << left << setw(15) << "GRADE 3" << endl;
        students[studentIndex].ShowDetails();
    } else {
        cout << "Student not found." << endl;
    }

    return 0;
}
