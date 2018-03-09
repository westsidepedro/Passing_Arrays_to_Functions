//============================================================================
// Name        : Passing_Arrays_to_Functions.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// PASSING AN ARRAY TO A FRUNCTION.....

void show1(const int nElements, string array[]) //loose how many elem are in an array so (nElements, array)
    {
    for (int i = 0; i < nElements; i++)
	{
	cout << array[i] << endl;
	}
    }
//----------------------------------------------------------------------------
void show2(const int nElements, string *array)
    {
    for (int i = 0; i < nElements; i++)
	{
	cout << array[i] << endl;
	}
    }
//----------------------------------------------------------------------------
void show3(string (&array)[3]) //need () around the ref AND correct number in []
    {
    for (int i = 0; i < 3; i++)
	{
	cout << array[i] << endl;
	}
    }
//----------------------------------------------------------------------------

//  RETURNING ARRAY FROM A FUNCTION.....
string *getMemory()
    {
    string *pMem = new string[]; //creat a pointer that will hold the array
    cout << "Arrays created." << endl;
    return pMem;// return that pointer that holds a new array inside of it
    //remember to use delete! or make below (freeMemory) b/c used 'new'
    }

void freeMemory(string *pFreeMe)
    {
    cout << "Arrays deleted" << endl;
    delete[] pFreeMe;
    }
/*DON'T RETURN POINTERS TO LOCAL VARIABLES!!! ie...

 //string *getArray()
 //  {
 //  string words[] =
 //	 {
 //	 "one", "two", "three"  <<<<this will be gone as soon as it hits the '}' at end of this function
 //	 };
 //   return words;
 //  }
 //
 */

//----------------------------------------------------------------------------
int main()
    {
    string texts[] =
	{
	"apple", "orange", "banana"
	};
    cout << "-------------------- show1" << endl;
    show1(3, texts);			//1 and 2 are the same thing really
    cout << "-------------------- show2" << endl;
    show2(3, texts);
    cout << "-------------------- show3" << endl;
    show3(texts);

    string *pBill = getMemory();

    freeMemory(pBill);

    return 0;
    }
