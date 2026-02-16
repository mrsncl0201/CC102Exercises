#include <iostream>
#include <iomanip>

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

        cout << "\nProduct\t1\t2\t3\t4\tTotal\n";

        double grandTotal = 0;

        for (int i = 0; i < 5; i++)
        {
            double rowTotal = 0;
            cout << i + 1 << "\t";
            for (int j = 0; j < 4; j++)
            {
                cout << fixed << setprecision(2) << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }
            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "Total\t";
        for (int j = 0; j < 4; j++)
        {
            double colTotal = 0;
            for (int i = 0; i < 5; i++)
            {
                colTotal += sales[i][j];
            }
            cout << colTotal << "\t";
        }
        cout << grandTotal << endl;

        cout << "\nWould you like to try again? (y/n): ";
        cin >> runAgain;
    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}