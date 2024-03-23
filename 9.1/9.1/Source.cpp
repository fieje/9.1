#include <iostream>
#include <string>

using namespace std;

enum Specialty { COMPUTER_SCIENCE, INFORMATICS, MATHEMATICS_AND_ECONOMICS, PHYSICS_AND_INFORMATICS, LABOR_TRAINING };

union Grades {
    int programming;  
    int numerical_methods; 
    int pedagogy;  
};

struct Student {
    string last_name;
    int course;
    Specialty specialty;
    int physics_grade;
    int math_grade;
    Grades additional_grade;
};

void createStudents(Student*& students, int& numStudents);
void printTableA(Student* students, int numStudents);
void printTableB(Student* students, int numStudents);
double calculateMinAverageGrade(Student* students, int numStudents);
int countGoodGrades(Student* students, int numStudents, string subject);

int main() {
    int numStudents;
    Student* students;

 
    createStudents(students, numStudents);


    cout << "Table for Level A:\n";
    printTableA(students, numStudents);

    cout << "\nTable for Level B:\n";
    printTableB(students, numStudents);

    cout << "\nMinimum average grade: " << calculateMinAverageGrade(students, numStudents) << endl;

    cout << "Number of 'good' grades for Physics: " << countGoodGrades(students, numStudents, "Physics") << endl;
    cout << "Number of 'good' grades for Mathematics: " << countGoodGrades(students, numStudents, "Mathematics") << endl;
    cout << "Number of 'good' grades for Programming/Numerical Methods/Pedagogy: "
        << countGoodGrades(students, numStudents, "Additional") << endl;

    delete[] students;

    return 0;
}

void createStudents(Student*& students, int& numStudents) {
    cout << "Enter the number of students: ";
    cin >> numStudents;

    students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Last name: ";
        cin >> students[i].last_name;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Specialty (0 - Computer Science, 1 - Informatics, 2 - Mathematics and Economics, "
            << "3 - Physics and Informatics, 4 - Labor Training): ";
        int specialty;
        cin >> specialty;
        students[i].specialty = static_cast<Specialty>(specialty);
        cout << "Grade in Physics: ";
        cin >> students[i].physics_grade;
        cout << "Grade in Mathematics: ";
        cin >> students[i].math_grade;
        if (students[i].specialty == COMPUTER_SCIENCE) {
            cout << "Grade in Programming: ";
            cin >> students[i].additional_grade.programming;
        }
        else if (students[i].specialty == INFORMATICS) {
            cout << "Grade in Numerical Methods: ";
            cin >> students[i].additional_grade.numerical_methods;
        }
        else {
            cout << "Grade in Pedagogy: ";
            cin >> students[i].additional_grade.pedagogy;
        }
    }
}

void printTableA(Student* students, int numStudents) {
    cout << "=================================================================================================\n";
    cout << "| ¹ | Last Name | Course | Specialty             | Physics | Mathematics | Informatics |" << endl;
    cout << "-------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "| " << i + 1 << " | " << students[i].last_name << " | " << students[i].course << "      | ";
        switch (students[i].specialty) {
        case COMPUTER_SCIENCE:
            cout << "Computer Science      | ";
            cout << students[i].physics_grade << "       | " << students[i].math_grade << "          | "
                << students[i].additional_grade.programming << "           |\n";
            break;
        case INFORMATICS:
            cout << "Informatics           | ";
            cout << students[i].physics_grade << "       | " << students[i].math_grade << "          | "
                << students[i].additional_grade.numerical_methods << "           |\n";
            break;
        default:
            cout << "Other                 | ";
            cout << students[i].physics_grade << "       | " << students[i].math_grade << "          |          |\n";
        }
    }
    cout << "=================================================================================================\n";
}

void printTableB(Student* students, int numStudents) {
    cout << "=============================================================================================================\n";
    cout << "| ¹ | Last Name | Course | Specialty             | Physics | Mathematics | Additional                |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "| " << i + 1 << " | " << students[i].last_name << " | " << students[i].course << "      | ";
        switch (students[i].specialty) {
        case COMPUTER_SCIENCE:
            cout << "Computer Science      | ";
            cout << students[i].physics_grade << "       | " << students[i].math_grade << "          | "
                << students[i].additional_grade.programming << "                           |\n";
            break;
        case INFORMATICS:
            cout << "Informatics           | ";
            cout << students[i].physics_grade << "       | " << students[i].math_grade << "          | "
                << students[i].additional_grade.numerical_methods << "                           |\n";
            break;
        default:
            cout << "Other                 | ";
            cout << students[i].physics_grade << "       | " << students[i].math_grade << "          | "
                << students[i].additional_grade.pedagogy << "                           |\n";
        }
    }
    cout << "=============================================================================================================\n";
}
double calculateMinAverageGrade(Student* students, int numStudents) {
    double minAverage = 100; 

    for (int i = 0; i < numStudents; ++i) {
        double average = static_cast<double>(students[i].physics_grade + students[i].math_grade) / 2.0;
        if (average < minAverage) {
            minAverage = average;
        }
    }

    return minAverage;
}

int countGoodGrades(Student* students, int numStudents, string subject) {
    int goodGradesCount = 0;

    for (int i = 0; i < numStudents; ++i) {
        if (subject == "Physics") {
            if (students[i].physics_grade >= 4) {
                goodGradesCount++;
            }
        }
        else if (subject == "Mathematics") {
            if (students[i].math_grade >= 4) {
                goodGradesCount++;
            }
        }
        else if (subject == "Additional") {
            switch (students[i].specialty) {
            case COMPUTER_SCIENCE:
                if (students[i].additional_grade.programming >= 4) {
                    goodGradesCount++;
                }
                break;
            case INFORMATICS:
                if (students[i].additional_grade.numerical_methods >= 4) {
                    goodGradesCount++;
                }
                break;
            default:
                if (students[i].additional_grade.pedagogy >= 4) {
                    goodGradesCount++;
                }
            }
        }
    }

    return goodGradesCount;
}