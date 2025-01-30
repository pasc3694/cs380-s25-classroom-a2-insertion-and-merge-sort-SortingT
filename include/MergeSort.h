//********************************************************
// File name:  MergeSort.h
// Author:     chadd williams
// Date:       7/5/2013
// Class:      CS380
// Assignment: Basic Sorting
// Purpose:    To define the header file the Merge Sort 
//********************************************************


#ifndef _MergeSortAlgorithm_H_
#define _MergeSortAlgorithm_H_

#include "SortAlgorithm.h"

class MergeSort : public SortAlgorithm
{

public:

	void sort(SortableArray &theArray);
	virtual const  std::string name() const {return "Merge Sort";};

private:

};

#endif

