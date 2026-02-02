#include <iostream>
#define MAX_ITEMS 100
using namespace std;

class LibraryItem
{
private:
    string title;
    string author;
    string duedate;

public:
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        duedate = newDueDate;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return duedate;
    }
};

class Book : public LibraryItem
{
public:
    void checkOut()
    {
        cout << "Checkout book: " << getTitle() << endl;
    }

    void returnItem()
    {
        cout << "Return book: " << getTitle() << endl;
    }

    void displayDetails()
    {
        cout << "Book Title: " << getTitle() << endl;
        cout << "Book Author: " << getAuthor() << endl;
        cout << "Book DueDate: " << getDueDate() << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(int newduration = 0)
    {
        duration = newduration;
    }

    void checkOut()
    {
        cout << "Checkout DVD: " << getTitle() << endl;
    }

    void returnItem()
    {
        cout << "Return DVD: " << getTitle() << endl;
    }

    void displayDetails()
    {
        cout << "DVD Title: " << getTitle() << endl;
        cout << "DVD Author: " << getAuthor() << endl;
        cout << "DVD DueDate: " << getDueDate() << endl;
        cout << "DVD Duration: " << duration << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(int newissueNumber = 0)
    {
        issueNumber = newissueNumber;
    }

    void checkOut()
    {
        cout << "Checkout Magazine: " << getTitle() << endl;
    }

    void returnItem()
    {
        cout << "Return Magazine: " << getTitle() << endl;
    }

    void displayDetails()
    {
        cout << "Magazine Title: " << getTitle() << endl;
        cout << "Magazine Author: " << getAuthor() << endl;
        cout << "Magazine DueDate: " << getDueDate() << endl;
        cout << "Magazine Issue Number: " << issueNumber << endl;
    }
};

int main()
{
    LibraryItem *libraryItems[MAX_ITEMS];
    int count = 0, choice, duration, issueNumber;
    string title, author, dueDate;

    do
    {
        cout << endl;
        cout << "Library Management System" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add DVD" << endl;
        cout << "3. Add Magazine" << endl;
        cout << "4. Display All Items" << endl;
        cout << "5. Checkout Item" << endl;
        cout << "6. Return Item" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting the Library Management System..." << endl;
            for (int i = 0; i < count; i++)
            {
                delete libraryItems[i];
            }
            break;

        case 1:
            if (count >= MAX_ITEMS)
            {
                cout << "Library is full!" << endl;
                break;
            }

            libraryItems[count] = new Book;

            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Book Author: ";
            getline(cin, author);

            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            libraryItems[count]->setTitle(title);
            libraryItems[count]->setAuthor(author);
            libraryItems[count]->setDueDate(dueDate);

            count++;
            cout << "Book added successfully." << endl;
            break;

        case 2:
            if (count >= MAX_ITEMS)
            {
                cout << "Library is full!" << endl;
                break;
            }

            cin.ignore();
            cout << "Enter DVD Title: ";
            getline(cin, title);

            cout << "Enter DVD Author: ";
            getline(cin, author);

            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            cout << "Enter DVD Duration (minutes): ";
            cin >> duration;

            libraryItems[count] = new DVD(duration);
            libraryItems[count]->setTitle(title);
            libraryItems[count]->setAuthor(author);
            libraryItems[count]->setDueDate(dueDate);

            count++;
            cout << "DVD added successfully." << endl;
            break;

        case 3:
            if (count >= MAX_ITEMS)
            {
                cout << "Library is full!" << endl;
                break;
            }

            cin.ignore();
            cout << "Enter Magazine Title: ";
            getline(cin, title);

            cout << "Enter Magazine Author: ";
            getline(cin, author);

            cout << "Enter Magazine Date: ";
            getline(cin, dueDate);

            cout << "Enter Magazine Issue Number: ";
            cin >> issueNumber;

            libraryItems[count] = new Magazine(issueNumber);
            libraryItems[count]->setTitle(title);
            libraryItems[count]->setAuthor(author);
            libraryItems[count]->setDueDate(dueDate);

            count++;
            cout << "Magazine added successfully." << endl;
            break;

        case 4:
            if (count == 0)
            {
                cout << "No items in the library." << endl;
                break;
            }

            cout << "Library Items:" << endl;
            for (int i = 0; i < count; i++)
            {
                cout << endl;
                cout << "Item " << i + 1 << " Details:" << endl;
                libraryItems[i]->displayDetails();
            }
            break;

        case 5:
            if (count == 0)
            {
                cout << "No items in the library." << endl;
                break;
            }

            int chindex;
            cout << "Enter index to checkout (0 to " << count - 1 << "): ";
            cin >> chindex;

            if (chindex >= 0 && chindex < count)
            {
                libraryItems[chindex]->checkOut();
            }
            else
            {
                cout << "Invalid index." << endl;
            }
            break;

        case 6:
            if (count == 0)
            {
                cout << "No items in the library." << endl;
                break;
            }

            int index;
            cout << "Enter index to return (0 to " << count - 1 << "): ";
            cin >> index;

            if (index >= 0 && index < count)
            {
                libraryItems[index]->returnItem();
            }
            else
            {
                cout << "Invalid index." << endl;
            }
            break;
        }
    } while (choice > 0);
}
