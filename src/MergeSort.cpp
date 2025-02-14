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
    mergeSort (theArray, 0, theArray.count()-1);
}

void MergeSort::mergeSort  (SortableArray &theArray, int leftIndex, int rightIndex)
{
    SortableArray cTempOne;
    SortableArray cTempTwo;

    int middle;
    if (leftIndex < rightIndex){
        middle = ((leftIndex + rightIndex) / 2);
        MergeSort::mergeSort (theArray, leftIndex, middle);
        MergeSort::mergeSort (theArray, middle + 1, rightIndex);

        MergeSort::merge (theArray, leftIndex, middle, rightIndex);

    }
}

void MergeSort :: merge (SortableArray &theArray, int leftIndex, int middle, int rightIndex) {

    SortableArray cTempOne;
    SortableArray cTempTwo;
    int arrayOneIndex = 0, arrayTwoIndex = 0;

    for (int index = 0; index < (middle + 1) - leftIndex; index++) {
        cTempOne.pushBack (theArray.getItem (index + leftIndex));
        if (index <= rightIndex - (middle + 1)) {
            cTempTwo.pushBack (theArray.getItem (index + (middle + 1)));
        }
    }

    for (int index = 0; index < (rightIndex - leftIndex) + 1; index++) {
        if (arrayOneIndex == cTempOne.count()) {
            theArray.setItem (index + leftIndex, cTempTwo.getItem(arrayTwoIndex));
            arrayTwoIndex++;
        }
        else if (arrayTwoIndex == cTempTwo.count()) {
            theArray.setItem (index + leftIndex, cTempOne.getItem(arrayOneIndex));
            arrayOneIndex++;
        }
        else if (needSwap (cTempOne.getItem (arrayOneIndex), cTempTwo.getItem(arrayTwoIndex))) {
            theArray.setItem (index + leftIndex, cTempTwo.getItem(arrayTwoIndex));
            arrayTwoIndex++;
        }
        else {
            theArray.setItem (index + leftIndex, cTempOne.getItem(arrayOneIndex));
            arrayOneIndex++; 
        }
    }
}