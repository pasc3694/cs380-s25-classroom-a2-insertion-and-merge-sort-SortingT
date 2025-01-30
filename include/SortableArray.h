//********************************************************
// File name:  SortableArray.h
// Author:     chadd williams
// Date:       7/5/2013
// Class:      CS380
// Assignment: Basic Sorting
// Purpose:    To define the header file for a sortable array
//********************************************************


#ifndef _SortableArray_H_
#define _SortableArray_H_
#include <iostream>
#include <vector>
//#include "SortableContainer.h"
class SortAlgorithm;
#include "Student.h"

class SortableArray //: public SortableContainer
{

public:

	// SortableArray is a concrete implementation of SortableContainer
	// this array is backed by an stl vector
	
	// constructor
	SortableArray();

	// destructor
	virtual ~SortableArray();

	
	// adds a new element to the back of the array
	virtual bool pushBack(Student *val);


	// SortableContainer
	// returns the number of elements in the array
	virtual int	count() const;

	// returns the ith element of the array
	//virtual Student * operator [](int index);
	virtual Student * getItem(int index) const;
	virtual bool setItem(int index, Student *pItem);
	virtual void deallocateItems();

	void setSortBehavior(SortAlgorithm *sortAlgorithm) 
		{mpSortBehavior = sortAlgorithm;};

	void sort();
	
	//////////////////////

	// clears the array 
	virtual void clear();

	friend std::ostream & operator << (std::ostream &os, const SortableArray &array);

private:


	SortAlgorithm *mpSortBehavior;
	std::vector<Student*> m_arrayData;


};

#endif
