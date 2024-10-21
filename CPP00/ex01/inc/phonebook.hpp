
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// CONTACT LIST
#define PIPE "|"
#define CONTACT_FN "FIRST NAME"
#define CONTACT_LN " LAST NAME"
#define CONTACT_NN " NICK NAME"
#define CONTACTS "             CONTACTS             "

// ERRORS AND INPUT REQUESTS
#define NO_CONTACT "No Contact Found!\n"
#define INVALID_INDEX "Invalid Index!\n"
#define INVALID_OPTION "Invalid option: "
#define NO_ARG "This program doesn't take any arguments"
#define INVALID_INPUT "Empty string is not a valid input"
#define OUT_OF_RANGE "The Requested Index Is Out Of Range"
#define INPUT_REQUIRED "Input is required in every field."
#define WRONG_PHONE_NUMBER "Error! Phone Number Should Contain Only Numbers!\n"

// SET CONTACT COLORS
#define AVAILABLE "The available options are:\n"
#define CHOOSE_INDEX "Choose One Index:	"
#define CHOOSE_OPTION "Choose an Option:	"
#define ADD "ADD    -> Add a new contact to the phonebook.\n"
#define SEARCH "SEARCH -> Search for an index from 1-8 in the phonebook.\n"
#define EXIT "EXIT   -> Quit the program."
#define ENTER_FN "Enter Your First Name:	"
#define ENTER_LN "Enter Your Last Name:	"
#define ENTER_NN "Enter Your Nick Name:	"
#define ENTER_PN "Enter Your Phone Number:	"
#define ENTER_DS "Enter Your Darkest Secret:	"
#define OUT "bye :-)"

// GET CONTACT COLORS
#define FN "First Name	:	"
#define LN "Last Name	:	"
#define NN "Nick Name	:	"
#define PN "Phone Number	:	"
#define DS "Darkest Secret	:	"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cctype>

class Contact {
   public:
	void SetFirstName(std::string input);
	void SetLastName(std::string input);
	void SetNickName(std::string input);
	void SetPhoneNumber(std::string input);
	void SetDarkestSecret(std::string input);
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();

   private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

class PhoneBook {
   public:
	void SetContactIndex(int i);
	int GetContactIndex();
	int GetContactDetails();
	class Contact GetContactData();

   private:
	int index;
	class Contact contact_list;
};


// MAIN
int AddNewContact(PhoneBook *contacts, int max);
void FindContactToPrint(PhoneBook *contacts, int max);
void PrintContactDetails(PhoneBook *contacts, int max);

// UTILS
void PrintBook(PhoneBook *contacts, int i);
int IndexCheck(std::string index);
int IsAllNum(std::string phone_number);
void ShortPrint(std::string contact_details);
int IsOnlySpace(std::string str);
int IsValid(std::string input);

#endif