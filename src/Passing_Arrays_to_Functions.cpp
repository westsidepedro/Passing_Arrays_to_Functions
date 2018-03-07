//============================================================================
// Name        : Passing_Arrays_to_Functions.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

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

string *getMemory()
    {
    string *pMem = new string[3]; //remember to use delete! or make below (freeMemory) b/c used 'new'
    cout << "Arrays created." << endl;
    return pMem;
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
