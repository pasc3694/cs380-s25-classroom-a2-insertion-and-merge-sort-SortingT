//********************************************************
// File name:  BubbleSort.h
// Author:     chadd williams
// Date:       7/5/2013
// Class:      CS380
// Assignment: Basic Sorting
// Purpose:    To define the header file the Bubble Sort 
//********************************************************


#ifndef _BubbleSortAlgorithm_H_
#define _BubbleSortAlgorithm_H_

#include "SortAlgorithm.h"

class BubbleSort : public SortAlgorithm
{

public:

	void sort(SortableArray &theArray);
	const std::string name() const {return "Bubble Sort";};
};

#endif

