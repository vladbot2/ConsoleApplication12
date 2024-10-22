#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
    string fullName;
    string mobilePhone;

public:
    Contact() {}

    Contact(string name, string mobilePhone) {
        fullName = name;
        this->mobilePhone = mobilePhone;
    }

    string getFullName() {
        return fullName;
    }

    void showContact() {
        cout << "Full Name: " << fullName << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
    }
};

class PhoneBook {
    vector<Contact> contacts;

    void addContact() {
        string name, mobilePhone;
        cout << "Enter full name: ";
        getline(cin, name);
        cout << "Enter mobile phone: ";
        getline(cin, mobilePhone);
        contacts.push_back(Contact(name, mobilePhone));
    }

    void searchContact() {
        string name;
        cout << "Enter full name to search: ";
        getline(cin, name);
        for (auto& contact : contacts) {
            if (contact.getFullName() == name) {
                contact.showContact();
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    void showAllContacts() {
        if (contacts.empty()) {
            cout << "Phone book is empty." << endl;
        }
        else {
            for (auto& contact : contacts) {
                contact.showContact();
                cout << "---------------------" << endl;
            }
        }
    }

public:
    void menu() {
        int choice;

        while (true) {
            cout << "Phone Book Menu:" << endl;
            cout << "1. Add Contact" << endl;
            cout << "2. Search Contact" << endl;
            cout << "3. Show All Contacts" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                showAllContacts();
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }
};

int main() {
    PhoneBook phoneBook;
    phoneBook.menu();
}
