//********************************************************
// File name:  SortAlgorithm.cpp
// Author:     chadd williams
// Date:       7/5/2013
// Class:      CS380
// Assignment: Basic Sorting
// Purpose:    Implementation for SortAlgorithm
//********************************************************

#include "SortAlgorithm.h"
#include "SortableArray.h"

//********************************************************
// Method:	setSortDirection 
//
// Description: Set the sort direction (ASC/DESC) of this algorithm.
//
// Parameters: A Direction
//
// Returned: none
//	
//********************************************************
void SortAlgorithm::setSortDirection(SortAlgorithm::Direction dir )
{
	mDirection = dir;
}

//********************************************************
// Method:	getSortDirection 
//
// Description: get the sort direction (ASC/DESC) of this algorithm.
//
// Parameters: none
//
// Returned: the current sort Direction
//	
//********************************************************
SortAlgorithm::Direction SortAlgorithm::getSortDirection() { 
	return mDirection; 
}

//********************************************************
// Constructor: SortAlgorithm
//
// Description: Initialize data members.  Set sort Direction to ASC
//
// Parameters: none
//
// Returned:	 none
//		
//********************************************************
SortAlgorithm::SortAlgorithm() { 
	mDirection = Direction::ASC; 
}

//********************************************************
// Destructor: SortAlgorithm
//
// Description: Delete data members
//
// Parameters: none
//
// Returned:	 none
//		
//********************************************************
SortAlgorithm::~SortAlgorithm()
{
}

bool SortAlgorithm::needSwap(Student *pLeft, Student *pRight)
{
	return (Direction::ASC == getSortDirection() && *pLeft > *pRight) ||
				(Direction::DESC == getSortDirection() && *pLeft < *pRight);
}

//********************************************************
// Method:			dirToString 
//
// Description: return a string representing a Direction
//
// Parameters: 	dir - the Direction
//
// Returned: 		string representing the Direction
//	
//********************************************************
std::string SortAlgorithm::dirToString(SortAlgorithm::Direction dir )
{
	if ( Direction::ASC == dir )
	{
		return "ASC";
	}
	return "DESC";
}
