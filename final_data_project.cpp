#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int bookcode;
    string author;
    string title;
    double price;
    int stock;
    Book *next;

    Book()
    {
    }
};

class Linkedlist
{
public:
    Book *head;
    int listsize;
    Linkedlist()
    {
        head = NULL;
        listsize = 0;
    }

    void add_first()
    {
        cout << "\n\n {ADDING BOOK INFORMATION}  ";
        Book *newnode = new Book();
        cout << "\n 1-Book Name :";
        cin >> newnode->title;
        cout << "\n 2-Book Code :";
        cin >> newnode->bookcode;
        cout << "\n 3-Author Name :";
        cin >> newnode->author;
        cout << "\n 4-Stock :";
        cin >> newnode->stock;
        cout << "\n 5-Price :";
        cin >> newnode->price;

        if (listsize == 0)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        cout << "\n\t\t[ New Book added successfully ]\n";
        listsize++;
    }

    void add_last()
    {

        cout << "\n\n {ADDING BOOK INFORMATION}  ";
        Book *newnode = new Book();
        cout << "\n 1-Book Name :";
        cin >> newnode->title;
        cout << "\n 2-Book Code :";
        cin >> newnode->bookcode;
        cout << "\n 3-Author Name :";
        cin >> newnode->author;
        cout << "\n 4-Stock :";
        cin >> newnode->stock;
        cout << "\n 5-Price :";
        cin >> newnode->price;

        if (listsize == 0)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            Book *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode->next = NULL;
            temp->next = newnode;
        }
        cout << "\n\t\t[ New Book added successfully ]\n";
        listsize++;
    }

    void add_middle()
    {

        int counter = 0;

        int target;
        cout << "\n Target position you want :";
        cin >> target;

        Book *temp = head;
        if (target == listsize)
        {
            this->add_last();
            return;
        }
        while (counter < listsize)
        {
            if (counter == target)
            {

                cout << "\n\n {ADDING BOOK INFORMATION}  ";
                Book *newnode = new Book();
                cout << "\n 1-Book Name :";
                cin >> newnode->title;
                cout << "\n 2-Book Code :";
                cin >> newnode->bookcode;
                cout << "\n 3-Author Name :";
                cin >> newnode->author;
                cout << "\n 4-Stock :";
                cin >> newnode->stock;
                cout << "\n 5-Price :";
                cin >> newnode->price;

                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
            temp = temp->next;
            counter++;
        }
        cout << "\n\t\t[ New Book added successfully ]\n";
        listsize++;
    }

    void delete_first()
    {
        if (listsize == 0)
        {
            cout << "The  list is empty" << endl;
        }
        else if (listsize == 1)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Book *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "\n Book deleted sucessfully...." << endl;
        listsize--;
    }
    void delete_last()
    {
        if (listsize == 0)
        {
            cout << "Empty list" << endl;
            return;
        }
        else if (listsize == 1)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Book *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        cout << "\n Book deleted sucessfully...." << endl;
        listsize--;
    }

    void delete_middle()
    {
        string name;
        cout << "Name of book is : \n";
        cin >> name;

        if (listsize == 0)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        if (head->title == name)
        {
            delete_first();
            cout << "\n Book deleted sucessfully...." << endl;
            listsize--;
            return;
        }
        else
        {
            Book *temp = head->next;
            while (temp != NULL)
            {
                if (temp->title == name)
                {
                    break;
                }
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "the Book  not found..." << endl;
                cout << "The Only Books Found Is....." << endl;
                traverse();
                return;
            }
            else if (temp->next == NULL)
            {
                delete_last();
                cout << "\n Book deleted sucessfully...." << endl;
                listsize--;
            }
            else
            {
                Book *temp2 = temp->next;
                while (temp2 != NULL)
                {
                    if (temp->title == name)
                    {
                        break;
                    }
                    temp->next = temp->next->next;
                    delete temp2;
                    cout << "\n Book deleted sucessfully...." << endl;
                    listsize--;
                }
            }
        }
    }

    void search()
    { // searching the book in the list
        Book *temp;
        if (head == NULL)
        {
            cout << "the list is empty" << endl;
        }
        else
        {
            temp = head;
            int x;
            cout << "write code of book you want: " << endl;
            cin >> x;
            while (temp->bookcode != x)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << x << ": is not found in the list" << endl;
            }
            else
            {
                cout << x << ": is found in the list" << endl;
                cout << "Book Name: " << temp->title << endl;
                cout << "Book Code: " << temp->bookcode << endl;
                cout << "Book Author: " << temp->author << endl;
                cout << "Book Price: " << temp->price << endl;
                cout << "number of copies: " << temp->stock << endl;
            }
        }
    }

    void sort()
    { // sort book by code

        Book *ptr;
        Book *nextPtr;
        ptr = head;
        double temp;
        if (head == NULL)
        {
            cout << "the list is empty" << endl;
        }
        else if (head->next == NULL)
        {
            cout << "the list is sorted" << endl;
        }
        else
        {
            for (ptr = head; ptr->next != NULL; ptr = ptr->next)
            {
                for (nextPtr = ptr->next; nextPtr != NULL; nextPtr = nextPtr->next)
                {
                    if (ptr->bookcode > nextPtr->bookcode)
                    {
                        temp = ptr->bookcode;
                        ptr->bookcode = nextPtr->bookcode;
                        nextPtr->bookcode = temp;
                    }
                }
            }
        }
    }

    void update()
    { // Update data

        string x;
        cout << "update data" << endl;
        if (head == NULL)
        {
            cout << "Linked list is Empty...." << endl;
        }
        else
        {
            cout << "Enter Book Name " << endl;
            cin >> x;
            Book *temp = head;
            while (temp != NULL)
            {
                if (x == temp->title)
                {
                    int u;
                    cout << "Choose what you want to update : \n\n ";
                    cout << " 1. Title \n 2. Book code \n 3. Author Name \n 4. Stock \n 5. Price \n n6. Exit \n\n";
                    cin >> u;
                    if (u == 1)
                    {
                        cout << "Enter new Book Title :" << endl;
                        cin >> temp->title;
                    }
                    else if (u == 2)
                    {
                        cout << "Enter new Book Code :" << endl;
                        cin >> temp->bookcode;
                    }
                    else if (u == 3)
                    {
                        cout << "Enter new Author Name :" << endl;
                        cin >> temp->author;
                    }
                    else if (u == 4)
                    {
                        cout << "Enter new Stock :" << endl;
                        cin >> temp->stock;
                    }
                    else if (u == 5)
                    {
                        cout << "Enter new Price :" << endl;
                        cin >> temp->price;
                    }
                    else
                    {
                        break;
                    }
                    cout << "\n\n\t [ The Book has been Updated successfully ]" << endl;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void traverse()
    { // display book details

        Book *temp = head;
        while (temp != NULL)
        {
            cout << "\n\n Title :" << temp->title;
            cout << "\n\n Book Code :" << temp->bookcode;
            cout << "\n\n Book Author :" << temp->author;
            cout << "\n\n Stock :" << temp->stock;
            cout << "\n\n Price :" << temp->price << endl;
            cout << "\n\n__________________________________________________________\n";
            temp = temp->next;
        }
    }

    void noOfcopies(Book b1)
    { // checking no. of copies and calculating the total price

        int n;
        cout << "\nBook Details: " << endl;
        traverse();
        cout << "Enter required number of copies: ";
        cin >> n;
        if (n > b1.stock)
        {
            cout << "Required copies is not in stock" << endl;
        }
        else
        {
            cout << "Total cost of the books: " << n * b1.price << endl;
            b1.stock = b1.stock - n;
            cout << "\nRemaining stock: " << b1.stock << endl;
        }
    }

    void seller() // seller options
    {
        int a, n;
        while (1)
        {
            cout << "Enter ur choice: \n1.Show books\n2.Update\n3.Add books\n4.Delete books\n5.Search\n6.Sort\n7.Exit " << endl;
            cin >> a;
            cout << endl;
            if (a == 1)
            {
                cout << "\nBook Details: " << endl;
                traverse();
            }
            else if (a == 2)
            {
                update();
            }
            else if (a == 3)
            {
                cout << "Where you want to add: \n\n";
                cout << "1.first\n2.last\n3.middle\n4.Exit\n";
                cin >> n;
                if (n == 1)
                {
                    add_first();
                }
                else if (n == 2)
                {
                    add_last();
                }
                else if (n == 3)
                {
                    add_middle();
                }
                else
                    return;
            }
            else if (a == 4)
            {
                cout << "Where you want to delete: \n\n";
                cout << "1.first\n2.last\n3.middle\n4.Exit\n";
                cin >> n;
                if (n == 1)
                {
                    delete_first();
                }
                else if (n == 2)
                {
                    delete_last();
                }
                else if (n == 3)
                {
                    delete_middle();
                }
                else
                    return;
            }
            else if (a == 5)
            {
                search();
            }
            else if (a == 6)
            {
                sort();
            }
            else
                return;
        }
    }

    void customer(Book b1) // customer options
    {
        int x;
        while (1)
        {
            cout << "\nEnter a option \n1.Show Books\n2.Purchase a book\n3.Exit" << endl;
            cin >> x;
            if (x == 1)
            {
                cout << "\nBook Details: " << endl;
                traverse();
            }

            else if (x == 2)
            {
                string a;
                cout << "Enter Title : ";
                cin >> a;

                Book *temp = head;

                while (temp->next != NULL)
                {

                    if (temp->title == a)
                    {
                        noOfcopies(b1);
                        break;
                    }
                    else
                    {
                        temp = temp->next;
                    }
                }
                if (temp == NULL)
                {
                    cout << "This book is not available" << endl;
                }
                else
                    return;
            }
        }
    }
};

int main()
{
    Linkedlist l;
    Book b1;
    int a;
    while (1)
    {
        cout << "\nSelect any one\n1.Seller\n2.Customer\n3.Exit" << endl;
        cin >> a;
        cout << endl;
        if (a == 1)
        {
            l.seller();
        }
        else if (a == 2)
        {
            l.customer(b1);
        }
        else
        {
            return 0;
        }
    }
}
