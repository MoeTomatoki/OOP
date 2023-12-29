#include <iostream>
#include "address_book.h"

int main() {
    AddressBook addressBook;

    // Добавление нескольких контактов
    addressBook.addContact(Contact("John Doe", "123456789", "01/01/1990"));
    addressBook.addContact(Contact("Alex Smith", "987654321", "02/15/1985"));
    addressBook.addContact(Contact("Bob Johnson", "555111222", "05/20/1978"));
    addressBook.addContact(Contact("Alice Smith", "555333444", "03/10/1995"));

    std::cout << "Sorted by name:\n";
    addressBook.sortByname();

    std::cout << "\nSorted by phone number:\n";
    addressBook.sortByPhoneNumber();

    std::cout << "\nSorted by birthdate:\n";
    addressBook.sortByBirthdate();

    std::cout << "\nSearch by name (Alice Smith):\n";
    addressBook.searchByName("Alice Smith");

    std::cout << "\nRemove contact (John Doe):\n";
    addressBook.removeContact("John Doe");
    addressBook.sortByname();

    return 0;
}
