#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Structure to store course information
struct Course
{
    string name;
    char grade;
    int credit;
    float gradePoint;
};

// Function to convert grade into grade point
float getGradePoint(char grade)
{
    switch (grade)
    {
        case 'A': return 10.0;
        case 'B': return 8.0;
        case 'C': return 7.0;
        case 'D': return 6.0;
        case 'E': return 5.0;
        case 'F': return 0.0;
        default: return -1;
    }
}

int main()
{
    int n;

    cout << "===== CGPA CALCULATOR =====\n";

    cout << "Enter number of courses: ";
    cin >> n;

    vector<Course> courses(n);

    float totalCredits = 0;
    float totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        cin >> courses[i].name;

        cout << "Enter grade (A/B/C/D/E/F): ";
        cin >> courses[i].grade;

        // Convert lowercase to uppercase
        if (courses[i].grade >= 'a' && courses[i].grade <= 'z')
            courses[i].grade -= 32;

        courses[i].gradePoint = getGradePoint(courses[i].grade);

        if (courses[i].gradePoint == -1)
        {
            cout << "Invalid grade!\n";
            return 0;
        }

        cout << "Enter credit hours: ";
        cin >> courses[i].credit;

        totalCredits += courses[i].credit;

        totalGradePoints +=
            courses[i].gradePoint * courses[i].credit;
    }

    // Calculate CGPA
    float cgpa = totalGradePoints / totalCredits;

    // Display result
    cout << "\n===== COURSE DETAILS =====\n";

    cout << left
         << setw(15) << "Course"
         << setw(10) << "Grade"
         << setw(10) << "Credit"
         << setw(15) << "Grade Point"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(15) << courses[i].name
             << setw(10) << courses[i].grade
             << setw(10) << courses[i].credit
             << setw(15) << courses[i].gradePoint
             << endl;
    }

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nCGPA: " << fixed << setprecision(2) << cgpa;

    return 0;
}