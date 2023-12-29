#pragma once
#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <map>
#include <string>
#include <vector>
#include "contact.h"

class AddressBook {
public:
    // Добавление контакта
    void addContact(const Contact& contact);

    // Удаление контакта по имени
    void removeContact(const std::string& name);

    // Поиск контакта по имени
    void searchByName(const std::string& name) const;

    // Сортировка по имени
    void sortByname() const;

    // Сортировка по номеру телефона
    void sortByPhoneNumber() const;

    // Сортировка по дате рождения
    void sortByBirthdate() const;

    const std::multimap<std::string, Contact>& getContacts() const {
        return contacts;
    }
private:
    std::multimap<std::string, Contact> contacts;
};

#endif
