#include <iostream>
#include <iomanip>
using namespace std;

void analyzeGrades(int *grades, int students, int subjects)
{
    cout << "\n========== GRADE MATRIX ==========\n";
    cout << left << setw(12) << "Student";
    for (int j = 0; j < subjects; j++)
        cout << setw(10) << "Subject " << (j + 1);
    cout << setw(10) << "Average" << "\n";
    cout << string(12 + subjects * 10 + 10, '-') << "\n";

    int highest = 0;
    int highStudent = 0, highSubject = 0;

    for (int i = 0; i < students; i++)
    {
        cout << left << setw(12) << "Student " << (i + 1);

        int sum = 0;
        for (int j = 0; j < subjects; j++)
        {
            int grade = *(grades + i * subjects + j);
            cout << setw(10) << grade;
            sum += grade;

            if (grade > highest)
            {
                highest = grade;
                highStudent = i + 1;
                highSubject = j + 1;
            }
        }

        double avg = (double)sum / subjects;
        cout << fixed << setprecision(2) << avg << "\n";
    }

    cout << "\nHighest Grade: " << highest << " (Student " << highStudent
         << ", Subject " << highSubject << ")\n";
}

int main()
{
    char again;

    do
    {
        int students, subjects;

        cout << "========== GRADE ANALYZER ==========\n";
        cout << "Enter number of students: ";
        cin >> students;
        cout << "Enter number of subjects: ";
        cin >> subjects;

        if (students <= 0 || subjects <= 0)
        {
            cout << "Invalid input!\n";
            continue;
        }

        int grades[students][subjects];

        for (int i = 0; i < students; i++)
        {
            cout << "\nStudent " << (i + 1) << ":\n";
            for (int j = 0; j < subjects; j++)
            {
                while (true)
                {
                    cout << "  Subject " << (j + 1) << ": ";
                    cin >> grades[i][j];
                    if (grades[i][j] >= 0 && grades[i][j] <= 100)
                        break;
                    cout << "  Grade must be 0-100!\n";
                }
            }
        }

        analyzeGrades(&grades[0][0], students, subjects);

        cout << "Again? (Y/N): ";
        cin >> again;
        cout << "\n";

    } while (again == 'Y' || again == 'y');

    cout << "Done.\n";
    return 0;
}
