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
    switch (rating)
    {
    case 5:
        return "Excellent";
    case 4:
        return "Very Good";
    case 3:
        return "Good";
    case 2:
        return "Fair";
    case 1:
        return "Poor";
    case 0:
        return "No Rating";
    default:
        return "Invalid";
    }
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

void input(Book books[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Book " << (i + 1) << " ---\n";

        string barcode;
        bool valid = false;
        while (!valid)
        {
            cout << "Barcode: ";
            getline(cin, barcode);
            if (isBarcodeUnique(books, i, barcode))
            {
                valid = true;
            }
            else
            {
                cout << "Barcode \"" << barcode << "\" already exists. Try again.\n";
            }
        }
        books[i].barcode = barcode;

        cout << "Title: ";
        getline(cin, books[i].title);

        cout << "Year Published: ";
        cin >> books[i].year;
        cin.ignore();

        int rating_val;
        bool valid_rating = false;
        while (!valid_rating)
        {
            cout << "Rating (0-5): ";
            cin >> rating_val;
            cin.ignore();
            if (rating_val >= 0 && rating_val <= 5)
            {
                books[i].rating = rating_val;
                valid_rating = true;
            }
            else
            {
                cout << "Invalid rating. Enter 0-5.\n";
            }
        }
    }
}

void display(Book books[], int n)
{
    cout << "\n========== BOOK RATING RESULTS ==========\n";
    cout << left
         << setw(15) << "Barcode"
         << setw(35) << "Title"
         << setw(8) << "Year"
         << setw(10) << "Rating"
         << setw(12) << "Category" << "\n";
    cout << string(15, '-') << " "
         << string(34, '-') << " "
         << string(7, '-') << " "
         << string(9, '-') << " "
         << string(12, '-') << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(15) << books[i].barcode
             << setw(35) << books[i].title
             << setw(8) << books[i].year
             << setw(10) << books[i].rating
             << setw(12) << getCategory(books[i].rating) << "\n";
    }
}

int main()
{
    char again = 'Y';

    while (again == 'Y' || again == 'y')
    {
        int n;

        cout << "============================\n";
        cout << "     BOOK RATING SYSTEM     \n";
        cout << "============================\n";
        cout << "How many books do you want to enter? ";
        cin >> n;
        cin.ignore();

        if (n <= 0)
        {
            cout << "Invalid number. Enter at least 1.\n";
            continue;
        }

        Book books[n];

        input(books, n);
        display(books, n);

        cout << "Run again? (Y/N): ";
        cin >> again;
        cin.ignore();
        cout << "\n";
    }

    cout << "Goodbye!\n";
    return 0;
}