//********************************************************
// File name:  MergeSort.cpp
// Author:     
// Date:       
// Class:      CS380
// Assignment: Basic Sorting
// Purpose:    Implementation for MergeSort
//********************************************************

#include "MergeSort.h"
#include "SortableArray.h"
//********************************************************
// Method: sort
//
// Description: invoke MergeSort on the array 
//
// Parameters:  theArray - the array to sort
//
// Returned:  none
//	
//********************************************************
void MergeSort::sort(SortableArray &theArray) 
{
    mergeSort (theArray, 0, theArray.count());
}

void MergeSort::mergeSort  (SortableArray &theArray, int leftIndex, int rightIndex)
{

    int middle;
    if (leftIndex < rightIndex){
        middle = ((leftIndex + rightIndex) / 2);
        MergeSort::mergeSort (theArray, leftIndex, middle);
        MergeSort::mergeSort (theArray, middle, rightIndex);

    }
}