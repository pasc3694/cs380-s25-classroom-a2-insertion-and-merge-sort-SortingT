//********************************************************
// File name:  InsertionSort.h
// Author:     chadd williams
// Date:       7/5/2013
// Class:      CS380
// Assignment: Basic Sorting
// Purpose:    To define the header file the Insertion Sort 
//********************************************************


#ifndef _InsertionSortAlgorithm_H_
#define _InsertionSortAlgorithm_H_

#include "SortAlgorithm.h"

class InsertionSort : public SortAlgorithm
{

public:

	void sort(SortableArray &theArray);
	const  std::string name() const {return "Insertion Sort";};
};

#endif

