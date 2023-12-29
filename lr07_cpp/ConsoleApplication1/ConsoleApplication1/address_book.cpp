#include "address_book.h"

void AddressBook::addContact(const Contact& contact) {
    contacts.insert(std::make_pair(contact.getName(), contact));
}

void AddressBook::removeContact(const std::string& name) {
    auto it = contacts.find(name);
    if (it != contacts.end()) {
        contacts.erase(it);
    }
}

void AddressBook::searchByName(const std::string& name) const {
    auto range = contacts.equal_range(name);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second;
    }
}

void AddressBook::sortByname() const {
    for (const auto& entry : contacts) {
        std::cout << entry.second;
    }
}

void AddressBook::sortByPhoneNumber() const {
    std::multimap<std::string, Contact, std::less<>> sortedContacts;

    for (const auto& entry : contacts) {
        sortedContacts.insert(std::make_pair(entry.second.getPhoneNumber(), entry.second));
    }

    for (const auto& entry : sortedContacts) {
        std::cout << entry.second;
    }
}

void AddressBook::sortByBirthdate() const {
    std::multimap<std::string, Contact, std::less<>> sortedContacts;

    for (const auto& entry : contacts) {
        sortedContacts.insert(std::make_pair(entry.second.getBirthdate(), entry.second));
    }

    for (const auto& entry : sortedContacts) {
        std::cout << entry.second;
    }
}
