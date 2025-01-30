//********************************************************
// File name:  SortableArray.cpp
// Author:     chadd williams
// Date:       7/5/2013
// Class:      CS380
// Assignment: Basic Sorting
// Purpose:    Implementation for SortableArray
//********************************************************

#include "SortableArray.h"
#include <vector>
#include "SortAlgorithm.h"
//typedef std::vector<ComparableItem*> VectorData;

//#define ARRAY (*((VectorData*)m_arrayData))

//********************************************************
// Constructor: SortableArray
//
// Description: Initialize data members.
//
// Parameters: none
//
// Returned:	 none
//		
//********************************************************
SortableArray::SortableArray()
{
	//m_arrayData = new std::vector<ComparableItem*>();
}


//********************************************************
// Method:	deallocateItems
//
// Description: deallocate all items pointed to by the array
//
// Parameters: none
//
// Returned: none
//	
//********************************************************
void SortableArray::deallocateItems()
{
	for(unsigned int i=0;i<m_arrayData.size();i++)
	{
		Student *pItem = (m_arrayData)[i];
		delete pItem;
		(m_arrayData)[i] = NULL;
	}
}

//********************************************************
// Destructor:	SortableArray
//	
// Description: Deallocate data members
//	
//********************************************************
SortableArray::~SortableArray()
{
	//delete m_arrayData;
	m_arrayData.clear();
}



//********************************************************
// Method:	count
//
// Description: return the number of elements in the array
//
// Parameters: none
//
// Returned: the number of elements
//	
//********************************************************
int SortableArray::count() const
{
	return (int)(m_arrayData).size();
}

//********************************************************
// Method:	pushBack
//
// Description: add an int to the end of the array
//
// Parameters: val - the int to add
//
// Returned: none
//	
//********************************************************
bool SortableArray::pushBack(Student *pVal)
{
	(m_arrayData).push_back(pVal);
	return true;
}

//********************************************************
// Method:	getItem
//
// Description: get an item at a given location
//
// Parameters: index -  the index of the item
//
// Returned: the item, or NULL on error
//	
//********************************************************
Student* SortableArray::getItem(int index) const
{	
	if( static_cast<unsigned int>(index) >= (m_arrayData).size()  || index < 0)
	{
		return NULL;
	}
	return (m_arrayData)[index];
}

//********************************************************
// Method:	setItem
//
// Description: set an item at a given location
//
// Parameters: index -  the index of the item
//							pItem - the item
//
// Returned: true on success, false on failure
//	
//********************************************************
bool SortableArray::setItem(int index, Student* pItem)
{
	if(  static_cast<unsigned int>(index) >= (m_arrayData).size() || index < 0)
	{
		return false;
	}

	(m_arrayData)[index] = pItem;

	return true;
}




//********************************************************
// Method:	clear
//
// Description:  empty the array
//
// Parameters: none
//
// Returned: none
//	
//********************************************************
void SortableArray::clear()
{
	(m_arrayData).clear();
}


//********************************************************
// Method:	operator<<
//
// Description:  Provide an << operator.
//
// Parameters: std::ostream &os - the stream to write to
//						 const SortableArray &array - the array to write
//
// Returned: the ostream written to
//	
//********************************************************
std::ostream & operator << (std::ostream &os, const SortableArray &array)
{
	for(int i = 0; i < array.count(); i++)
	{
		
		os <<  ((array.m_arrayData))[i] << "\n";
	}
	return os;
}

//********************************************************
// Method:	sort
//
// Description: Invoke sort algorithm on the array
//
// Parameters: none
//
// Returned: none
//	
//********************************************************
void SortableArray::sort()
{
	if( NULL != mpSortBehavior)
	{
		mpSortBehavior->sort(*this);
	}
}
