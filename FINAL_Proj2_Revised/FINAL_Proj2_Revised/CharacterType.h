/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Thurday May 21, 2020

		 CS A250
		 Project 2 - Revised
*/

#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <iostream>
#include <string>

class CharacterType
{
public:
	// Default constructor
	CharacterType() : id(0) {};

	// Overloaded constructor
	CharacterType(const std::string& fName,
		const std::string& lName, int identity);

	// setCharacterInfo Function
	void setCharacterInfo(const std::string& fName,
		const std::string& lName, int identity);

	// Getters Functions
	std::string getFirstName() const;
	std::string getLastName() const;
	int getID() const;

	// Printing Functions
	void printName() const;
	void printCharacterInfo() const;
	void printID() const;

	// Destructor
	~CharacterType();

private:
	std::string firstName;
	std::string lastName;
	int id;
};

#endif 
