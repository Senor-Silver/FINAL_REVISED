/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Thurday May 21, 2020

		 CS A250
		 Project 2 - Revised
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <algorithm>
#include <iomanip>
#include <list>

class CandidateList
{
public:
	// Default constructor
	CandidateList() {};

	// addCandidate
	void addCandidate(const CandidateType& candidate);

	// getWinner
	int getWinner() const;

	// isEmpty
	// searchCandidate
	bool isEmpty() const;
	bool searchCandidate(int identity) const;

	// Print Functions 
	void printCandidateName(int identity) const;
	void printAllCandidates() const;
	void printKingdomVotes(int identity, int kingdom) const;
	void printCandidateTotalVotes(int identity) const;
	void printFinalResults() const;
	void printLastCandidate() const;         // Our Option #6
	
	// Destructor
	~CandidateList();

private:
	// Functions
	void printHeader() const;
	bool searchCandidate(int identity, std::list<CandidateType>::const_iterator& firstObj) const;
	void printCandidate(std::list<CandidateType>::const_iterator iter, int& rankPos) const;

	// Member variable
	std::list<CandidateType> candidates;
};

#endif