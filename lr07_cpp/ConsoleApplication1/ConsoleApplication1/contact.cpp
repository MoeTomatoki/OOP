#include "contact.h"

Contact::Contact(const std::string& name, const std::string& phoneNumber, const std::string& birthdate)
    : name(name), phoneNumber(phoneNumber), birthdate(birthdate) {}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << "Name: " << contact.name << "\nPhone Number: " << contact.phoneNumber << "\nBirthdate: " << contact.birthdate << "\n";
    return os;
}

const std::string& Contact::getName() const {
    return name;
}

const std::string& Contact::getPhoneNumber() const {
    return phoneNumber;
}

const std::string& Contact::getBirthdate() const {
    return birthdate;
}

const std::string Contact::getAllInfo() const {
    return "Name: " + name + "\nPhone Number: " + phoneNumber + "\nBirthdate: " + birthdate + "\n";
}
