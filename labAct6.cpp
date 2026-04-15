#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Book
{
    string barcode;
    string title;
    int year;
    int rating;
};

string getCategory(int rating)
{
    if (rating == 5)
        return "Excellent";
    else if (rating == 4)
        return "Very Good";
    else if (rating == 3)
        return "Good";
    else if (rating == 2)
        return "Fair";
    else if (rating == 1)
        return "Poor";
    else
        return "No Rating";
}

bool isBarcodeUnique(Book books[], int count, string barcode)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].barcode == barcode)
            return false;
    }
    return true;
}

void displayTable(Book books[], int count)
{
    cout << "\n";
    cout << left << setw(15) << "Barcode" << setw(35) << "Title" << setw(8) << "Year" << setw(10) << "Rating" << setw(12) << "Category" << "\n";
    cout << string(80, '-') << "\n";

    for (int i = 0; i < count; i++)
    {
        cout << left << setw(15) << books[i].barcode << setw(35) << books[i].title << setw(8) << books[i].year << setw(10) << books[i].rating << setw(12) << getCategory(books[i].rating) << "\n";
    }
    cout << "\n";
}

int main()
{
    char again;
    int maxBooks = 1000;

    do
    {
        Book *books = new Book[maxBooks];
        int n, count = 0;

        cout << "============================\n";
        cout << "         BOOK RATING        \n";
        cout << "============================\n";
        cout << "How many books do you want to enter? ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++)
        {
            cout << "\n--- Book " << (i + 1) << " ---\n";

            string barcode;
            while (true)
            {
                cout << "Barcode: ";
                getline(cin, barcode);
                if (isBarcodeUnique(books, count, barcode))
                    break;
                cout << "That barcode already exists!\n";
            }

            cout << "Title: ";
            string title;
            getline(cin, title);

            cout << "Year Published: ";
            int year;
            cin >> year;
            cin.ignore();

            int rating;
            while (true)
            {
                cout << "Rating (0-5): ";
                cin >> rating;
                cin.ignore();
                if (rating >= 0 && rating <= 5)
                    break;
                cout << "Invalid!\n";
            }

            books[count].barcode = barcode;
            books[count].title = title;
            books[count].year = year;
            books[count].rating = rating;
            count++;
        }

        cout << "\n========== RESULTS ==========";
        displayTable(books, count);

        cout << "Run again? (Y/N): ";
        cin >> again;
        cin.ignore();

        delete[] books;

    } while (again == 'Y' || again == 'y');

    cout << "Goodbye!\n";
    return 0;
}
