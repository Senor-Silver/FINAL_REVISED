/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Thurday May 21, 2020

		 CS A250
		 Project 2 - Revised
*/

#include "CandidateList.h" 

using namespace std;

void CandidateList::addCandidate(const CandidateType& candidate)
{
	candidates.push_back(candidate);
}

// Getter Function
int CandidateList::getWinner() const
{
	list<CandidateType>::const_iterator iter = candidates.begin();

	int winnerID = 0;
	int winnerTtlVotes = 0;

	while (iter != candidates.end())
	{
		if (winnerTtlVotes < iter->getTotalVotes())
		{
			winnerTtlVotes = iter->getTotalVotes();
			winnerID = iter->getID();
		}

		iter++;
	}

	return winnerID;
}

bool CandidateList::isEmpty() const
{
	// Use ternary operator...
	return candidates.empty() ? true : false;
}

// Public Search function
bool CandidateList::searchCandidate(int identity) const
{
	list<CandidateType>::const_iterator firstObj = candidates.begin();
	return CandidateList::searchCandidate(identity, firstObj);
}

// Overloaded Assignment Op
bool operator==(CandidateType cand, int identity)
{
	return (cand.getID() == identity);
}

// Print Functions
void CandidateList::printCandidateName(int identity) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	searchCandidate(identity, iter);
	iter->printName();
}

void CandidateList::printAllCandidates() const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	list<CandidateType>::const_iterator iterEnd = candidates.end();

	while (iter != iterEnd)
	{
		iter->printID();
		cout << " - ";
		iter->printName();
		cout << "\n";
		iter++;
	}
}

void CandidateList::printKingdomVotes(int identity, int kingdom) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();

	if (CandidateList::searchCandidate(identity, iter))
	{
		cout << right << setw(5) << setfill(' ')
			<< "*" << setw(3) << iter->getVotesByKingdom(kingdom)
			<< "( => )" << KINGDOMS[kingdom] << "\n";
	}
}

void CandidateList::printCandidateTotalVotes(int identity) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();

	if (CandidateList::searchCandidate(identity, iter))
	{
		cout << "    => Total votes: "
			<< iter->getTotalVotes() << endl;
	}
}

void CandidateList::printFinalResults() const
{
	// Initialize <list>iterators
	list<CandidateType>::const_iterator iter = candidates.begin();
	list<CandidateType>::const_iterator iterEnd = candidates.end();
	list<CandidateType>::const_iterator ceilingIter = iter;
	int ceilingVotes = 0;
	
	// Find Winner
	while (++iter != iterEnd)
	{
		// Check for highest TtlVotes
		if (ceilingIter->getTotalVotes() < iter->getTotalVotes())
			ceilingIter = iter;
	}

	ceilingVotes = ceilingIter->getTotalVotes();

	// Print Table Header
	printHeader();

	// Loop amount of Candidates times, 
	// Print Candidate currently at ceiling
	// Search for nextRunnerUp and assign to ceiling
	// All while seperating every 5 Candidates printed with dashes
	for (int i = 1; i <= static_cast<int>(candidates.size()); ++i)
	{
		// Print candidate that is currently at ceiling of list
		printCandidate(ceilingIter, i);

		// Reset iter to beginning and newMax to 0
		iter = candidates.begin();
		int newMax = 0;
		
		do
		{
			if (newMax < iter->getTotalVotes())
			{
				if (iter->getTotalVotes() < ceilingVotes)
				{
					if (iter->getTotalVotes() != ceilingVotes - 1)
					{
						ceilingIter = iter;
						newMax = ceilingIter->getTotalVotes();
					}
					else
					{
						ceilingIter = iter;
						newMax = ceilingIter->getTotalVotes();
						iterEnd--;
						iter = iterEnd++;
					}
				}
			}
		} while (++iter != iterEnd);

		// Update ceilingVotes to newMax for Cap of votes
		ceilingVotes = newMax;

		// Put dashes in between every 5 Candidates
		if (!(i % 5))
			cout << right << setw(40) << setfill('-') << "-\n";
	}
}


// Our Option#6
void CandidateList::printLastCandidate() const
{
	list<CandidateType>::const_iterator iter = candidates.end();
	iter--;
	cout << "Candidate to enter Election Last: "; 
	iter->printCandidateInfo();
}


// Destructor
CandidateList::~CandidateList() {}

//~~~Private Implementation
// Functions
void CandidateList::printHeader() const
{
	// Print Top of Table Before Results
	cout << right << setw(18) << setfill('*') << " FINAL"
		<< left << setw(21) << " RESULTS ";

	cout << left << setw(17) << setfill(' ') << "\n\nLAST"
		<< setw(10) << "FIRST"
		<< setw(5) << "TOTAL"
		<< right << setw(8) << "POS\n";

	cout << left << setw(15) << "NAME"
		<< setw(10) << "NAME"
		<< setw(5) << "VOTES"
		<< right << setw(8) << "#\n"
		<< setw(41) << setfill('_') << "_\n\n";
}
// Overloaded Private search function
bool CandidateList::searchCandidate(int identity,
	list<CandidateType>::const_iterator& iter) const
{
	list<CandidateType>::const_iterator endObj = candidates.end();
	iter = find(iter, endObj, identity);

	if (iter != endObj)
	{
		return true;
	}

	cerr << "ID not found." << "\n";
	return false;
}

void CandidateList::printCandidate(list<CandidateType>::const_iterator iter, int& rankPos) const
{ 
	/*
	iter->printID();
	cout << " - " << iter->getLastName()
		<< ", " << iter->getFirstName() << "\n";
	*/
	// Going to use this function to print out Final Results
	cout << left << setw(15) << setfill(' ')
		<< iter->getLastName() << setw(12)
		<< iter->getFirstName() << setw(3)
		<< iter->getTotalVotes() << right
		<< setw(7) << rankPos << endl;
}

/*
// Loop to find next ceiling candidate
// To then pass back an iterator
while (iter != iterEnd)
{
	if (iter->getTotalVotes() <= (ceilingVotes - 1))
	{
		if (iter->getTotalVotes() == (ceilingVotes - 1))
		{
			ceilingIter = iter;
			iter = iterEnd;
		}
		else if (iter->getTotalVotes() > ceilingIter->getTotalVotes())
		{
			ceilingIter = iter;
		}
	}
}

ceilingVotes = ceilingIter->getTotalVotes(); */