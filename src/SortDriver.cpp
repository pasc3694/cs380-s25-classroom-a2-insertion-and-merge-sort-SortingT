//********************************************************
// File name:  SortDriver.cpp
// Author:     chadd williams
// Date:       1/30/2023
// Class:      CS380
// Assignment: Basic Sorting Driver.
// Purpose:    Validate and time various sort algorithms
//********************************************************
#include "SortableArray.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "Student.h"


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

//********************************************************
// Function:    printArray
//
// Description: Print the array to the screen
//
// Parameters:  rcTheArray - the array to print
//
// Returned:    none
//	
//********************************************************
void	printArray(SortableArray &rcTheArray)
{
	Student *pStudent;
	for(int i=0;i< rcTheArray.count();i++)
	{
		pStudent = (rcTheArray.getItem(i));
		std::cout << *pStudent << "\n";
	}

}

//********************************************************
// Function:    runSort
//
// Description: set the sort direction and call sort
//
// Parameters:  rcTheArray - the array to sort
//              pTheAlgorithm - the sort algorithm to use
//              dir - the sort direction
//
// Returned:    none
//	
//********************************************************
void runSort(SortableArray &rcTheArray, SortAlgorithm *pTheAlgorithm, SortAlgorithm::Direction dir)
{
	// Sort the array
	rcTheArray.setSortBehavior(pTheAlgorithm);
	pTheAlgorithm->setSortDirection(dir);
	rcTheArray.sort();
}

//********************************************************
// Function:    validateSort
//
// Description: Validate the array is sorted
//
// Parameters:  rcSortableArray - the array to check
//              dir - the sort direction
//
// Returned:    true if the array is correctly sorted
//              false otherwise
//	
//********************************************************
bool validateSort(const SortableArray &rcSortableArray, SortAlgorithm::Direction dir)
{
	Student *pThis, *pPrev;
	bool bSorted = true;

	pPrev =  (rcSortableArray.getItem(0));

	for(int i = 0; i < rcSortableArray.count()-1 && bSorted; ++i) {
	
  	pThis = (rcSortableArray.getItem(i+1));

	  if (*pPrev < *pThis && dir==SortAlgorithm::Direction::DESC)	
  	{
			bSorted = false;
		}
		else if (*pPrev > *pThis && dir==SortAlgorithm::Direction::ASC)	
		{
			bSorted = false;
		}
		pPrev = pThis;
	}

	return bSorted;
}

//********************************************************
// Function:    resetFromOriginal
//
// Description: Reset the array to is unsorted form
//
// Parameters:  rcOut - the array to set
//              rcIn - the unsorted form
//
// Returned:    none
//	
//********************************************************
void resetFromOriginal(SortableArray &rcOut, SortableArray cIn)
{
  rcOut.clear();

  for(int i = 0;i< cIn.count(); ++i)  
  {
    rcOut.pushBack(cIn.getItem(i));
  }
}

//********************************************************
// Function:    loadFromFile
//
// Description: Read the data from the file
//
// Parameters:  rcOut - the array to fill
//              filename - the file to open
//              studentCount - the MAX number of students
//                              to read
//
// Returned:    the actual number of students read
//	
//********************************************************
int loadFromFile(SortableArray &rcOut, std::string filename, int studentCount)
{
  std::ifstream inFile;
  Student *pStudent;
  int counter = 0;

  inFile.open(filename);
  while( !inFile.eof() && counter < studentCount)
	{
		pStudent = new Student();
		if ( inFile >> *pStudent )
		{
			rcOut.pushBack(pStudent);
      counter++;
		}
		else
		{
			delete pStudent;
		}
	}

	inFile.close();

  return counter;
}

//********************************************************
// Function:    timedSort
//
// Description: Sort the array and time the sort
//
// Parameters:  rcSortableArray - the array to sort
//              pTheAlgoritm - the algorithm to use
//              dir - the direction to sort
//
// Returned:    none
//	
//********************************************************
void timedSort(SortableArray &rcSortableArray, 	SortAlgorithm* pTheAlgoritm, SortAlgorithm::Direction dir)
{
	
  auto t_start = std::chrono::high_resolution_clock::now();
  runSort(rcSortableArray, pTheAlgoritm, dir);
	auto t_end = std::chrono::high_resolution_clock::now();
  
  std::cout << "Time for "<< pTheAlgoritm->name() <<" Sort " <<  std::chrono::duration<double, std::milli>(t_end-t_start).count();
	std::cout << " milliseconds\n";

}


//********************************************************
// Function:    main
//
// Description: Run, validate, and time each sort algorithm
//
// Parameters:  argc - the number of command line args
//              argv - the command line args
//              argv[1] - the file to open
//              argv[2] - the number of students to read
//
// Returned:    EXIT_SUCCESS
//	
//********************************************************
int main(int argc, char *argv[] )
{
  SortAlgorithm::Direction aDirs[]= { SortAlgorithm::Direction::ASC, SortAlgorithm::Direction::DESC};
  std::string aDirStr[] = {"ASC", "DESC"};

  std::vector<SortAlgorithm *> cVecAlgos;

	SortableArray cSortableArray, cOriginalArray;
	bool bSorted;
	int studentCount = 10;
	
	if (3 == argc)
	{
		studentCount = atoi(argv[2]);
	}

  // ADD YOUR ALGORITHMS HERE
  cVecAlgos.push_back (new BubbleSort());

  studentCount = loadFromFile(cOriginalArray, argv[1], studentCount);
  //writeToFile(cOriginalArray, "data/out.txt", 100000);

	std::cerr<<"\nArray Size: "<< cOriginalArray.count() << std::endl << std::endl;
	
  for(SortAlgorithm *pAlgo : cVecAlgos)
  {
   
    for(auto dir : aDirs)
    {
      
      std::cout << pAlgo->name() << " " << aDirStr[static_cast<int>(dir)] << std::endl;

      resetFromOriginal(cSortableArray, cOriginalArray);

      timedSort(cSortableArray, pAlgo, dir);
      bSorted = validateSort(cSortableArray, dir);
      if ( !bSorted )
      {
        std::cout << "ERROR: " << pAlgo->name() << 
        " DIR : " << aDirStr[static_cast<int>(dir) ]<< " Not Sorted" << std::endl; 
      }		
      else 
      {
        std::cout << "SUCCESS: " << pAlgo->name() << 
        " DIR : " << aDirStr[static_cast<int>(dir) ] << " Sorted" << std::endl; 
      }
      std::cout << std::endl << std::endl;
    }
  
  }
  for(SortAlgorithm *pAlgo : cVecAlgos)
  {
		delete pAlgo;
	}

  cSortableArray.deallocateItems();

	return EXIT_SUCCESS;
}
