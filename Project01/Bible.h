// Class Bible
// Computer Science, MVNU
//
// Bible is a class for representing a particular version of the Bible
// A Bible object is constructed by giving it a file reference containing 
// the entire text of the version.

#ifndef Bible_H
#define Bible_H

#include "Ref.h"
#include "Verse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


enum LookupResult { SUCCESS, NO_BOOK, NO_CHAPTER, NO_VERSE, OTHER };					// status codes to be returned when looking up a reference
static const string LookupResultStrings[] = { "Success", "No Book Found", "No Chapter Found", "No Verse Found", "Failed for an unknown reason" };

class Bible {																		    // A class to represent a version of the bible
 private:
   static const int MIN_BOOK = 1, MAX_BOOK = 66;										//Book number must fall between 1 and 66
   string infile;																		// file path name
   ifstream instream;																	// input stream, used when file is open
   bool isOpen;																			// true if file is open
   int currentLine;


 public:
   Bible();																				// Default constructor
   Bible(const string s);																// Constructor – pass name of bible file
   
   //// REQUIRED: Find and return a verse in this Bible, given a reference
   //const Verse lookup(Ref ref, LookupResult& status); 
   //// REQUIRED: Return the reference after the given ref
   //const Ref next(const Ref ref, LookupResult& status);
   //// OPTIONAL: Return the reference before the given ref
   //const Ref prev(const Ref ref, LookupResult& status);

   Verse* lookup(Ref ref, LookupResult& status);										//Find and return a verse in the Bible using a given reference
   Verse* lookup(const int numberOfVerses, Ref ref, LookupResult& status);			    //Find more than one verse in the Bible using a given reference
   Verse* lookup(const int numberOfVerses, Ref ref, LookupResult& status, Ref& prev);   //Find more than one verse in the Bible and refer to previous verses

   const Ref next(const Ref ref, LookupResult& status);									//Returns the reference following this reference (the next reference)
   const Ref prev(const Ref ref, LookupResult& status);									//Returns the reference before this reference (the previous reference)

   const string error(LookupResult status);
   void display();																	    // Show the name of the bible file on cout
};
#endif //Bible_H
