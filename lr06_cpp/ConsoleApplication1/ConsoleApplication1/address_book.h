#pragma once
#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <map>
#include <string>
#include <vector>
#include "contact.h"

class AddressBook {
public:
    // ���������� ��������
    void addContact(const Contact& contact);

    // �������� �������� �� �����
    void removeContact(const std::string& name);

    // ����� �������� �� �����
    void searchByName(const std::string& name) const;

    // ���������� �� �����
    void sortByname() const;

    // ���������� �� ������ ��������
    void sortByPhoneNumber() const;

    // ���������� �� ���� ��������
    void sortByBirthdate() const;

    const std::multimap<std::string, Contact>& getContacts() const {
        return contacts;
    }
private:
    std::multimap<std::string, Contact> contacts;
};

#endif
