/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Thurday May 21, 2020

		 CS A250
		 Project 2 - Revised
*/

#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "CharacterType.h"

const int NUM_OF_KINGDOMS = 7;	// this is the capacity of the array
const std::string KINGDOMS[] = {
	"The North",
	"The Vale",
	"The Stormlands",
	"The Reach",
	"The Westerlands",
	"The Iron Islands",
	"Dorne"
};

class CandidateType : public CharacterType
{
public:
	// Constructors
	CandidateType();
	CandidateType(const CandidateType& otherType);

	// Copy assignment operator
	CandidateType& operator=(const CandidateType& rhs);

	// updateVotesByKingdom
	void updateVotesByKingdom(int kingdomIndex, int numOfVotes);

	// Getter Methods
	int getTotalVotes() const;
	int getVotesByKingdom(int index) const;

	// Print Functions
	void printCandidateInfo() const;
	void printCandidateTotalVotes() const;

	// Destructor
	~CandidateType();

private:
	int totalVotes;
	int numOfKingdoms;
	int* kingdomVotes;
};

#endif
