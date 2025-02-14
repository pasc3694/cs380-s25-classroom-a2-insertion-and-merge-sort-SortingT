//********************************************************
// File name:  InsertionSort.cpp
// Author:     
// Date:       
// Class:      
// Assignment: Basic Sorting
// Purpose:    Implementation for InsertionSort
//********************************************************

#include "InsertionSort.h"
#include "SortableArray.h"
//********************************************************
// Method: sort
//
// Description: invoke InsertionSort on the array
//
// Parameters:  theArray - the array to sort
//
// Returned:  none
//	
//********************************************************
void InsertionSort::sort(SortableArray &theArray)
{
    int size = theArray.count();
    Student *pcStudentStore;

    for (int index = 1; index < size; index++) {
        pcStudentStore = theArray.getItem(index);
        int behind = index - 1;

        while (behind >= 0 && needSwap(theArray.getItem(behind), pcStudentStore)) {
            theArray.setItem (behind + 1, theArray.getItem(behind));
            behind = behind - 1;
        }
        
        theArray.setItem (behind + 1, pcStudentStore);
    }
}
