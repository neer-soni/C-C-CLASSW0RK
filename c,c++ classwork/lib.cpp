#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. ABSTRACTION: Abstract Base Class
class LibraryItem {
protected:
    string title;
    int id;
    bool isCheckedOut;

public:
    LibraryItem(string t, int i) : title(t), id(i), isCheckedOut(false) {}

    // Pure virtual function makes this class abstract
    virtual void displayDetails() = 0; 

    // 2. ENCAPSULATION: Getters and Setters
    int getId() const { return id; }
    string getTitle() const { return title; }
    
    void toggleStatus() { isCheckedOut = !isCheckedOut; }
    bool getStatus() const { return isCheckedOut; }

    virtual ~LibraryItem() {} // Virtual destructor for memory safety
};

// 3. INHERITANCE: Derived Class
class Book : public LibraryItem {
private:
    string author;

public:
    Book(string t, int i, string a) : LibraryItem(t, i), author(a) {}

    // 4. POLYMORPHISM: Overriding the base class function
    void displayDetails() override {
        cout << "[Book] ID: " << id << " | Title: " << title 
             << " | Author: " << author 
             << " | Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};

// Library Manager to handle the collection
class Library {
private:
    vector<LibraryItem*> items; // Polymorphic collection

public:
    void addItem(LibraryItem* item) {
        items.push_back(item);
    }

    void showAllItems() {
        cout << "\n--- Library Inventory ---\n";
        for (auto item : items) {
            item->displayDetails();
        }
    }

    void findItem(int searchId) {
        for (auto item : items) {
            if (item->getId() == searchId) {
                cout << "Found: ";
                item->displayDetails();
                return;
            }
        }
        cout << "Item with ID " << searchId << " not found." << endl;
    }

    ~Library() {
        for (auto item : items) delete item;
    }
};

int main() {
    Library myLibrary;

    // Adding items
    myLibrary.addItem(new Book("The Great Gatsby", 101, "F. Scott Fitzgerald"));
    myLibrary.addItem(new Book("1984", 102, "George Orwell"));
    myLibrary.addItem(new Book("The Catcher in the Rye", 103, "J.D. Salinger"));

    // Displaying items
    myLibrary.showAllItems();

    // Simulating a search
    cout << "\nSearching for ID 102...";
    myLibrary.findItem(102);

    return 0;
}