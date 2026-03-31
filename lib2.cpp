/*
 * ============================================================
 *        LIBRARY MANAGEMENT SYSTEM IN C++
 *  Demonstrates: Abstraction, Encapsulation, Inheritance,
 *                Polymorphism, and Function Overloading
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <memory>
#include <map>

using namespace std;

// ============================================================
//  UTILITY FUNCTIONS
// ============================================================

string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return to_string(1900 + ltm->tm_year) + "-" +
           to_string(1 + ltm->tm_mon) + "-" +
           to_string(ltm->tm_mday);
}

void printLine(char ch = '-', int len = 60) {
    cout << string(len, ch) << "\n";
}

void printHeader(const string& title) {
    printLine('=');
    cout << setw(30 + title.size() / 2) << title << "\n";
    printLine('=');
}

// ============================================================
//  ABSTRACT BASE CLASS: LibraryItem (Abstraction)
// ============================================================

class LibraryItem {
protected:
    string itemID;
    string title;
    string author;
    int    yearPublished;
    bool   isAvailable;

public:
    LibraryItem(const string& id, const string& title,
                const string& author, int year)
        : itemID(id), title(title), author(author),
          yearPublished(year), isAvailable(true) {}

    virtual ~LibraryItem() {}

    // Pure virtual functions → Abstraction
    virtual void displayInfo()  const = 0;
    virtual string getType()    const = 0;

    // Encapsulation: Getters
    string getID()        const { return itemID; }
    string getTitle()     const { return title; }
    string getAuthor()    const { return author; }
    int    getYear()      const { return yearPublished; }
    bool   getAvailable() const { return isAvailable; }

    // Encapsulation: Setters
    void setAvailable(bool status) { isAvailable = status; }

    // Overloaded operator for easy comparison
    bool operator==(const LibraryItem& other) const {
        return itemID == other.itemID;
    }
};

// ============================================================
//  DERIVED CLASS: Book  (Inheritance + Polymorphism)
// ============================================================

class Book : public LibraryItem {
private:
    string isbn;
    string genre;
    int    totalPages;

public:
    Book(const string& id, const string& title,
         const string& author, int year,
         const string& isbn, const string& genre, int pages)
        : LibraryItem(id, title, author, year),
          isbn(isbn), genre(genre), totalPages(pages) {}

    // Polymorphic override
    void displayInfo() const override {
        cout << left
             << "  [BOOK]  ID      : " << itemID        << "\n"
             << "          Title   : " << title         << "\n"
             << "          Author  : " << author        << "\n"
             << "          Year    : " << yearPublished  << "\n"
             << "          Genre   : " << genre         << "\n"
             << "          ISBN    : " << isbn          << "\n"
             << "          Pages   : " << totalPages    << "\n"
             << "          Status  : " << (isAvailable ? "✔ Available" : "✘ Borrowed") << "\n";
    }

    string getType() const override { return "Book"; }

    // Getters
    string getISBN()  const { return isbn; }
    string getGenre() const { return genre; }
    int    getPages() const { return totalPages; }
};

// ============================================================
//  DERIVED CLASS: Magazine  (Inheritance + Polymorphism)
// ============================================================

class Magazine : public LibraryItem {
private:
    int    issueNumber;
    string category;

public:
    Magazine(const string& id, const string& title,
             const string& author, int year,
             int issue, const string& category)
        : LibraryItem(id, title, author, year),
          issueNumber(issue), category(category) {}

    void displayInfo() const override {
        cout << left
             << "  [MAGAZINE] ID      : " << itemID       << "\n"
             << "             Title   : " << title        << "\n"
             << "             Editor  : " << author       << "\n"
             << "             Year    : " << yearPublished << "\n"
             << "             Issue   : " << issueNumber  << "\n"
             << "             Category: " << category     << "\n"
             << "             Status  : " << (isAvailable ? "✔ Available" : "✘ Borrowed") << "\n";
    }

    string getType() const override { return "Magazine"; }
};

// ============================================================
//  DERIVED CLASS: DVD  (Inheritance + Polymorphism)
// ============================================================

class DVD : public LibraryItem {
private:
    string director;
    int    durationMinutes;
    string rating;

public:
    DVD(const string& id, const string& title,
        const string& author, int year,
        const string& director, int duration, const string& rating)
        : LibraryItem(id, title, author, year),
          director(director), durationMinutes(duration), rating(rating) {}

    void displayInfo() const override {
        cout << left
             << "  [DVD]   ID       : " << itemID          << "\n"
             << "          Title    : " << title           << "\n"
             << "          Studio   : " << author          << "\n"
             << "          Year     : " << yearPublished   << "\n"
             << "          Director : " << director        << "\n"
             << "          Duration : " << durationMinutes << " mins\n"
             << "          Rating   : " << rating          << "\n"
             << "          Status   : " << (isAvailable ? "✔ Available" : "✘ Borrowed") << "\n";
    }

    string getType() const override { return "DVD"; }
};

// ============================================================
//  CLASS: Member  (Encapsulation)
// ============================================================

class Member {
private:
    string memberID;
    string name;
    string email;
    string phone;
    string membershipDate;
    vector<string> borrowedItemIDs;   // IDs of items currently borrowed
    vector<string> borrowHistory;     // full history log

public:
    Member(const string& id, const string& name,
           const string& email, const string& phone)
        : memberID(id), name(name), email(email),
          phone(phone), membershipDate(getCurrentDate()) {}

    // Getters
    string getMemberID()   const { return memberID; }
    string getName()       const { return name; }
    string getEmail()      const { return email; }
    string getPhone()      const { return phone; }
    string getMemberDate() const { return membershipDate; }

    const vector<string>& getBorrowedItems()  const { return borrowedItemIDs; }
    const vector<string>& getBorrowHistory()  const { return borrowHistory; }

    bool hasBorrowedItem(const string& itemID) const {
        return find(borrowedItemIDs.begin(), borrowedItemIDs.end(), itemID)
               != borrowedItemIDs.end();
    }

    void borrowItem(const string& itemID) {
        borrowedItemIDs.push_back(itemID);
        borrowHistory.push_back("[BORROW] " + itemID + " on " + getCurrentDate());
    }

    void returnItem(const string& itemID) {
        borrowedItemIDs.erase(
            remove(borrowedItemIDs.begin(), borrowedItemIDs.end(), itemID),
            borrowedItemIDs.end());
        borrowHistory.push_back("[RETURN] " + itemID + " on " + getCurrentDate());
    }

    void displayInfo() const {
        cout << "  Member ID  : " << memberID        << "\n"
             << "  Name       : " << name            << "\n"
             << "  Email      : " << email           << "\n"
             << "  Phone      : " << phone           << "\n"
             << "  Since      : " << membershipDate  << "\n"
             << "  Borrowed   : " << borrowedItemIDs.size() << " item(s)\n";
    }

    void displayHistory() const {
        cout << "  Borrow History for " << name << ":\n";
        if (borrowHistory.empty()) {
            cout << "  (No history)\n";
        } else {
            for (auto& h : borrowHistory)
                cout << "    " << h << "\n";
        }
    }
};

// ============================================================
//  CLASS: Library  (Core Manager — Encapsulation)
// ============================================================

class Library {
private:
    string libraryName;
    vector<shared_ptr<LibraryItem>> items;
    vector<shared_ptr<Member>>      members;

    // ---- Private helpers ----
    shared_ptr<LibraryItem> findItem(const string& id) const {
        for (auto& item : items)
            if (item->getID() == id) return item;
        return nullptr;
    }

    shared_ptr<Member> findMember(const string& id) const {
        for (auto& m : members)
            if (m->getMemberID() == id) return m;
        return nullptr;
    }

public:
    Library(const string& name) : libraryName(name) {}

    // ---- Item Management ----

    void addItem(shared_ptr<LibraryItem> item) {
        if (findItem(item->getID())) {
            cout << "  ⚠ Item with ID '" << item->getID() << "' already exists.\n";
            return;
        }
        items.push_back(item);
        cout << "  ✔ " << item->getType() << " '" << item->getTitle() << "' added successfully.\n";
    }

    bool removeItem(const string& id) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getID() == id) {
                if (!(*it)->getAvailable()) {
                    cout << "  ✘ Cannot remove a borrowed item.\n";
                    return false;
                }
                cout << "  ✔ '" << (*it)->getTitle() << "' removed.\n";
                items.erase(it);
                return true;
            }
        }
        cout << "  ✘ Item not found.\n";
        return false;
    }

    // ---- Member Management ----

    void addMember(shared_ptr<Member> member) {
        if (findMember(member->getMemberID())) {
            cout << "  ⚠ Member already exists.\n";
            return;
        }
        members.push_back(member);
        cout << "  ✔ Member '" << member->getName() << "' registered.\n";
    }

    bool removeMember(const string& id) {
        for (auto it = members.begin(); it != members.end(); ++it) {
            if ((*it)->getMemberID() == id) {
                if (!(*it)->getBorrowedItems().empty()) {
                    cout << "  ✘ Member has unreturned items.\n";
                    return false;
                }
                cout << "  ✔ Member '" << (*it)->getName() << "' removed.\n";
                members.erase(it);
                return true;
            }
        }
        cout << "  ✘ Member not found.\n";
        return false;
    }

    // ---- Borrow / Return (Polymorphism in action) ----

    bool borrowItem(const string& memberID, const string& itemID) {
        auto member = findMember(memberID);
        auto item   = findItem(itemID);

        if (!member) { cout << "  ✘ Member not found.\n";        return false; }
        if (!item)   { cout << "  ✘ Item not found.\n";          return false; }
        if (!item->getAvailable()) { cout << "  ✘ Item is not available.\n"; return false; }
        if (member->hasBorrowedItem(itemID)) {
            cout << "  ✘ Member already borrowed this item.\n";  return false;
        }

        item->setAvailable(false);
        member->borrowItem(itemID);
        cout << "  ✔ '" << member->getName() << "' borrowed '"
             << item->getTitle() << "' [" << item->getType() << "]\n";
        return true;
    }

    bool returnItem(const string& memberID, const string& itemID) {
        auto member = findMember(memberID);
        auto item   = findItem(itemID);

        if (!member) { cout << "  ✘ Member not found.\n";                    return false; }
        if (!item)   { cout << "  ✘ Item not found.\n";                      return false; }
        if (!member->hasBorrowedItem(itemID)) {
            cout << "  ✘ This member did not borrow this item.\n";            return false;
        }

        item->setAvailable(true);
        member->returnItem(itemID);
        cout << "  ✔ '" << member->getName() << "' returned '"
             << item->getTitle() << "'\n";
        return true;
    }

    // ---- Search (Function Overloading) ----

    // Search by title keyword
    void searchByTitle(const string& keyword) const {
        cout << "\n  Search results for title: \"" << keyword << "\"\n";
        printLine();
        bool found = false;
        for (auto& item : items) {
            if (item->getTitle().find(keyword) != string::npos) {
                item->displayInfo();
                printLine();
                found = true;
            }
        }
        if (!found) cout << "  No items matched.\n";
    }

    // Search by author
    void searchByAuthor(const string& author) const {
        cout << "\n  Search results for author: \"" << author << "\"\n";
        printLine();
        bool found = false;
        for (auto& item : items) {
            if (item->getAuthor().find(author) != string::npos) {
                item->displayInfo();
                printLine();
                found = true;
            }
        }
        if (!found) cout << "  No items matched.\n";
    }

    // Search by item type
    void searchByType(const string& type) const {
        cout << "\n  Search results for type: \"" << type << "\"\n";
        printLine();
        bool found = false;
        for (auto& item : items) {
            if (item->getType() == type) {
                item->displayInfo();
                printLine();
                found = true;
            }
        }
        if (!found) cout << "  No items matched.\n";
    }

    // ---- Display All ----

    void displayAllItems() const {
        printHeader("ALL LIBRARY ITEMS");
        if (items.empty()) { cout << "  No items in library.\n"; return; }
        for (auto& item : items) {
            item->displayInfo();   // Polymorphic call
            printLine();
        }
        cout << "  Total: " << items.size() << " item(s)\n";
    }

    void displayAvailableItems() const {
        printHeader("AVAILABLE ITEMS");
        int count = 0;
        for (auto& item : items) {
            if (item->getAvailable()) {
                item->displayInfo();
                printLine();
                ++count;
            }
        }
        if (count == 0) cout << "  No available items.\n";
        else cout << "  Total available: " << count << "\n";
    }

    void displayAllMembers() const {
        printHeader("ALL MEMBERS");
        if (members.empty()) { cout << "  No members registered.\n"; return; }
        for (auto& m : members) {
            m->displayInfo();
            printLine();
        }
        cout << "  Total: " << members.size() << " member(s)\n";
    }

    void displayMemberHistory(const string& memberID) const {
        auto member = findMember(memberID);
        if (!member) { cout << "  ✘ Member not found.\n"; return; }
        printLine();
        member->displayHistory();
        printLine();
    }

    void displayStats() const {
        printHeader("LIBRARY STATISTICS");
        int total = items.size(), available = 0, borrowed = 0;
        map<string, int> typeCounts;
        for (auto& item : items) {
            item->getAvailable() ? ++available : ++borrowed;
            typeCounts[item->getType()]++;
        }
        cout << "  Library     : " << libraryName        << "\n"
             << "  Total Items : " << total              << "\n"
             << "  Available   : " << available          << "\n"
             << "  Borrowed    : " << borrowed           << "\n"
             << "  Members     : " << members.size()     << "\n";
        printLine();
        cout << "  Item Breakdown:\n";
        for (auto& [type, cnt] : typeCounts)
            cout << "    " << left << setw(15) << type << ": " << cnt << "\n";
    }
};

// ============================================================
//  INTERACTIVE MENU
// ============================================================

void showMenu() {
    printLine('=');
    cout << "         LIBRARY MANAGEMENT SYSTEM\n";
    printLine('=');
    cout << "  ITEMS\n"
         << "   1. Add Book          2. Add Magazine      3. Add DVD\n"
         << "   4. Remove Item       5. Display All       6. Display Available\n"
         << "  MEMBERS\n"
         << "   7. Add Member        8. Remove Member     9. Display Members\n"
         << "  TRANSACTIONS\n"
         << "  10. Borrow Item      11. Return Item      12. Member History\n"
         << "  SEARCH\n"
         << "  13. By Title         14. By Author        15. By Type\n"
         << "  OTHER\n"
         << "  16. Statistics        0. Exit\n";
    printLine('=');
    cout << "  Choice: ";
}

int main() {
    Library lib("City Central Library");

    // ── Pre-load sample data ──────────────────────────────────
    lib.addItem(make_shared<Book>(
        "B001", "The Great Gatsby", "F. Scott Fitzgerald", 1925,
        "978-0743273565", "Classic Fiction", 180));
    lib.addItem(make_shared<Book>(
        "B002", "Clean Code", "Robert C. Martin", 2008,
        "978-0132350884", "Programming", 464));
    lib.addItem(make_shared<Book>(
        "B003", "Atomic Habits", "James Clear", 2018,
        "978-0735211292", "Self-Help", 320));
    lib.addItem(make_shared<Magazine>(
        "M001", "National Geographic", "Susan Goldberg", 2023, 101, "Science"));
    lib.addItem(make_shared<Magazine>(
        "M002", "Time Magazine", "Edward Felsenthal", 2024, 55, "News"));
    lib.addItem(make_shared<DVD>(
        "D001", "Inception", "Warner Bros.", 2010,
        "Christopher Nolan", 148, "PG-13"));
    lib.addItem(make_shared<DVD>(
        "D002", "The Dark Knight", "Warner Bros.", 2008,
        "Christopher Nolan", 152, "PG-13"));

    lib.addMember(make_shared<Member>("M001", "Alice Johnson", "alice@mail.com", "555-1001"));
    lib.addMember(make_shared<Member>("M002", "Bob Smith",    "bob@mail.com",   "555-1002"));
    lib.addMember(make_shared<Member>("M003", "Carol White",  "carol@mail.com", "555-1003"));

    cout << "\n  ✔ Sample data loaded.\n\n";

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();
        cout << "\n";

        if (choice == 1) {
            string id, title, author, isbn, genre;
            int year, pages;
            cout << "  ID: ";      getline(cin, id);
            cout << "  Title: ";   getline(cin, title);
            cout << "  Author: ";  getline(cin, author);
            cout << "  Year: ";    cin >> year; cin.ignore();
            cout << "  ISBN: ";    getline(cin, isbn);
            cout << "  Genre: ";   getline(cin, genre);
            cout << "  Pages: ";   cin >> pages; cin.ignore();
            lib.addItem(make_shared<Book>(id, title, author, year, isbn, genre, pages));

        } else if (choice == 2) {
            string id, title, author, category;
            int year, issue;
            cout << "  ID: ";       getline(cin, id);
            cout << "  Title: ";    getline(cin, title);
            cout << "  Editor: ";   getline(cin, author);
            cout << "  Year: ";     cin >> year; cin.ignore();
            cout << "  Issue#: ";   cin >> issue; cin.ignore();
            cout << "  Category: "; getline(cin, category);
            lib.addItem(make_shared<Magazine>(id, title, author, year, issue, category));

        } else if (choice == 3) {
            string id, title, studio, director, rating;
            int year, duration;
            cout << "  ID: ";       getline(cin, id);
            cout << "  Title: ";    getline(cin, title);
            cout << "  Studio: ";   getline(cin, studio);
            cout << "  Year: ";     cin >> year; cin.ignore();
            cout << "  Director: "; getline(cin, director);
            cout << "  Duration (mins): "; cin >> duration; cin.ignore();
            cout << "  Rating: ";   getline(cin, rating);
            lib.addItem(make_shared<DVD>(id, title, studio, year, director, duration, rating));

        } else if (choice == 4) {
            string id;
            cout << "  Item ID to remove: ";
            getline(cin, id);
            lib.removeItem(id);

        } else if (choice == 5) {
            lib.displayAllItems();

        } else if (choice == 6) {
            lib.displayAvailableItems();

        } else if (choice == 7) {
            string id, name, email, phone;
            cout << "  Member ID: "; getline(cin, id);
            cout << "  Name: ";      getline(cin, name);
            cout << "  Email: ";     getline(cin, email);
            cout << "  Phone: ";     getline(cin, phone);
            lib.addMember(make_shared<Member>(id, name, email, phone));

        } else if (choice == 8) {
            string id;
            cout << "  Member ID to remove: ";
            getline(cin, id);
            lib.removeMember(id);

        } else if (choice == 9) {
            lib.displayAllMembers();

        } else if (choice == 10) {
            string mid, iid;
            cout << "  Member ID: "; getline(cin, mid);
            cout << "  Item   ID: "; getline(cin, iid);
            lib.borrowItem(mid, iid);

        } else if (choice == 11) {
            string mid, iid;
            cout << "  Member ID: "; getline(cin, mid);
            cout << "  Item   ID: "; getline(cin, iid);
            lib.returnItem(mid, iid);

        } else if (choice == 12) {
            string mid;
            cout << "  Member ID: "; getline(cin, mid);
            lib.displayMemberHistory(mid);

        } else if (choice == 13) {
            string kw;
            cout << "  Title keyword: "; getline(cin, kw);
            lib.searchByTitle(kw);

        } else if (choice == 14) {
            string kw;
            cout << "  Author name: "; getline(cin, kw);
            lib.searchByAuthor(kw);

        } else if (choice == 15) {
            string t;
            cout << "  Type (Book/Magazine/DVD): "; getline(cin, t);
            lib.searchByType(t);

        } else if (choice == 16) {
            lib.displayStats();

        } else if (choice != 0) {
            cout << "  ⚠ Invalid option.\n";
        }

        cout << "\n";
    } while (choice != 0);

    cout << "  Goodbye!\n";
    return 0;
}