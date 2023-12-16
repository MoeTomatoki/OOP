#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phoneNumber, const std::string& birthdate);

    // Перегрузка оператора вывода для удобного вывода контакта
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

    // Дополнительные методы для получения значений полей
    const std::string& getName() const;
    const std::string& getPhoneNumber() const;
    const std::string& getBirthdate() const;
    const std::string getAllInfo() const;

private:
    std::string name;
    std::string phoneNumber;
    std::string birthdate;
};

#endif
