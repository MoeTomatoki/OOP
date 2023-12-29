#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include <iostream>
#include "..\ConsoleApplication1\contact.h"
#include "..\ConsoleApplication1\contact.cpp"
#include "..\ConsoleApplication1\address_book.h"
#include "..\ConsoleApplication1\address_book.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(AddressBookTests)
{
public:
    TEST_METHOD(TestAddContact)
    {
        AddressBook addressBook;
        Contact contact("John Doe", "123456789", "01/01/1990");

        addressBook.addContact(contact);

        Assert::AreEqual(static_cast<size_t>(1), addressBook.getContacts().size());
    }

    TEST_METHOD(TestRemoveContact)
    {
        AddressBook addressBook;
        Contact contact("John Doe", "123456789", "01/01/1990");

        addressBook.addContact(contact);
        addressBook.removeContact("John Doe");

        Assert::IsTrue(addressBook.getContacts().empty());
    }

    TEST_METHOD(TestSearchByName)
    {
        AddressBook addressBook;
        Contact contact1("John Doe", "123456789", "01/01/1990");
        Contact contact2("Alice Smith", "987654321", "02/15/1985");

        addressBook.addContact(contact1);
        addressBook.addContact(contact2);

        std::vector<Contact> searchResults;
        for (const auto& entry : addressBook.getContacts()) {
            if (entry.second.getName() == "Alice Smith") {
                searchResults.push_back(entry.second);
            }
        }

        Assert::AreEqual(static_cast<size_t>(1), searchResults.size());
        Assert::AreEqual("Name: Alice Smith\nPhone Number: 987654321\nBirthdate: 02/15/1985\n", searchResults[0].getAllInfo().c_str());
    }
};

