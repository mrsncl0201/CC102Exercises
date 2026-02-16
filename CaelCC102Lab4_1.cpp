#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char repeat;
    do
    {
        int numStudents, numQuizzes;

        cout << "Enter number of students: ";
        cin >> numStudents;
        cout << "Enter number of quizzes: ";
        cin >> numQuizzes;

        double scores[50][50];

        for (int i = 0; i < numStudents; i++)
        {
            cout << "Enter scores for Student " << i + 1 << ": ";
            for (int j = 0; j < numQuizzes; j++)
            {
                cin >> scores[i][j];
            }
        }

        cout << "\nStudent\t";
        for (int j = 0; j < numQuizzes; j++)
        {
            cout << "Q" << j + 1 << "\t";
        }
        cout << "Average" << endl;

        for (int i = 0; i < numStudents; i++)
        {
            double sum = 0;
            cout << i + 1 << "\t";

            for (int j = 0; j < numQuizzes; j++)
            {
                cout << scores[i][j] << "\t";
                sum += scores[i][j];
            }

            double average = sum / numQuizzes;
            cout << fixed << setprecision(2) << average << endl;
        }

        cout << "\nDo you want to try again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
