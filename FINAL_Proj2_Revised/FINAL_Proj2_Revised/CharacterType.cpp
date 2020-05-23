/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Thurday May 21, 2020

		 CS A250
		 Project 2 - Revised
*/

#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

// Overloaded Constructor
CharacterType::CharacterType(const string& fName,
	const string& lName, int identity)
{
	firstName = fName;
	lastName = lName;
	id = identity;
}

// Setter Function
void CharacterType::setCharacterInfo(const string& fName,
	const string& lName, int identity)
{
	firstName = fName;
	lastName = lName;
	id = identity;
}

// Getter Functions
string CharacterType::getFirstName() const
{
	return firstName;
}
string CharacterType::getLastName() const
{
	return lastName;
}
int CharacterType::getID() const
{
	return id;
}

// Printing Functions
void CharacterType::printName() const
{
	cout << lastName << ", " << firstName;
}
void CharacterType::printCharacterInfo() const
{
	printID();
	cout << " " << firstName << " " << lastName;
}
void CharacterType::printID() const
{
	cout << "ID# " << id;
}

// Destructor
CharacterType::~CharacterType() {}