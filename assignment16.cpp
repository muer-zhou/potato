#include <iostream>
using namespace std;

namespace average
{
    int mean(int grades[], int totalStudents) {
        int sum = 0;
        int average = 0;

        for (int i = 0; i < totalStudents; i++) {
            sum += grades[i];
        }
        average = sum / totalStudents;

        return average;
    }
}

namespace high 
{
    int highest(int grades[], int totalStudents) {
        int highestGrade = grades[0]; // Assume first grade is highest

        for (int i = 1; i < totalStudents; i++) {
            if (grades[i] > highestGrade) {
                highestGrade = grades[i]; // Update highest grade
            }
        }
        return highestGrade;
    }
}

namespace low
{
    int lowest(int grades[], int totalStudents) {
        int lowestGrade = grades[0]; // Assume first grade is lowest

        for (int i = 1; i < totalStudents; i++) {
            if (grades[i] < lowestGrade) {
                lowestGrade = grades[i]; // Update lowest grade
            }
        }
        return lowestGrade;
    }
}

int main() {   
    int totalStudents; 
    cout << "Insert the number of students: ";
    cin >> totalStudents;

    string* names = new string[totalStudents];
    int* grades = new int[totalStudents];

    for (int i = 0; i < totalStudents; i++) {
        cout << "Insert the name of student " << i + 1 << ": ";
        cin >> names[i];

        cout << "Insert the grade of student " << i + 1 << ": ";
        cin >> grades[i];
    }

    cout << "\nList of Students and Grades: \n";
    for (int i = 0; i < totalStudents; i++) {
        cout << "Student " << i + 1 << ": " << names[i] << " - Grade: " << grades[i] << endl;
    }

    // Find and output the highest, lowest, and average grades
    int highestGrade = high::highest(grades, totalStudents);
    int lowestGrade = low::lowest(grades, totalStudents);
    int averageGrade = average::mean(grades, totalStudents);

    cout << "\nThe highest grade is: " << highestGrade << endl;
    cout << "The lowest grade is: " << lowestGrade << endl;
    cout << "The average grade is: " << averageGrade << endl;

    // Students above average
    cout << "\nStudents scoring above average: \n";
    for (int i = 0; i < totalStudents; i++) {
        if (grades[i] > averageGrade) {
            cout << names[i] << " - Grade: " << grades[i] << endl;
        }
    }

    // Free dynamically allocated memory
    delete[] names;
    delete[] grades;

    return 0;
}
