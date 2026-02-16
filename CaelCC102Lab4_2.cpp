#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    char runAgain;
    do
    {
        double sales[5][4] = {0};
        int salesperson, product;
        double amount;
        char choice;

        do
        {
            cout << "Salesperson: ";
            cin >> salesperson;
            cout << "Product: ";
            cin >> product;
            cout << "Amount: ";
            cin >> amount;

            if (salesperson >= 1 && salesperson <= 4 && product >= 1 && product <= 5)
            {
                sales[product - 1][salesperson - 1] += amount;
            }

            cout << "Would you like to input more? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        cout << "-------- --------- --------- --------- --------- -------\n";
        cout << "Product ";
        for (int j = 1; j <= 4; j++)
        {
            cout << setw(8) << j << " ";
        }
        cout << " Total  \n";
        cout << "-------- --------- --------- --------- --------- -------\n";

        double grandTotal = 0;

        for (int i = 0; i < 5; i++)
        {
            double rowTotal = 0;
            cout << "   " << i + 1 << "    ";
            for (int j = 0; j < 4; j++)
            {
                cout << fixed << setprecision(2) << setw(8) << sales[i][j] << " ";
                rowTotal += sales[i][j];
            }
            cout << fixed << setprecision(2) << setw(7) << rowTotal << "\n";
            grandTotal += rowTotal;
        }

        cout << "-------- --------- --------- --------- --------- -------\n";
        cout << " Total  ";
        for (int j = 0; j < 4; j++)
        {
            double colTotal = 0;
            for (int i = 0; i < 5; i++)
            {
                colTotal += sales[i][j];
            }
            cout << fixed << setprecision(2) << setw(8) << colTotal << " ";
        }
        cout << fixed << setprecision(2) << setw(7) << grandTotal << "\n";
        cout << "-------- --------- --------- --------- --------- -------\n";

        cout << "\nWould you like to try again? (y/n): ";
        cin >> runAgain;
    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}
