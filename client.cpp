//=========================================================
// Program : Singly Linked List
// Your name: Konrad Kucharek
// Complier: G++
// File type: Client file
//===========================================================

using namespace std;
#include <iostream>
#include "llist.h"

void caseOne()
{
  
	cout << "CASE 1:------------------- " << endl;
	llist L; // This is the list
	int x; // Will hold a removed element

	// Check empty and report the result  
	cout << endl << 1 << endl;
	cout << "List Empty:" << L.isEmpty() << endl;
  
	// Display the list  
	cout << endl << 2 << endl;
	cout << "List: ";
	L.displayAll();

	// Add 4 integers 1,2,3,4    
	cout << endl << 3 << endl;
	L.addRear(1);
	L.addRear(2);
	L.addRear(3);
	L.addRear(4);
  
	// Display the list  
	cout << endl << 4 << endl;
	cout << "List: ";
	L.displayAll();
  
	// Remove from front twice (and display the elements removed)
	cout << endl << 5 << endl;
	L.deleteFront(x);
	cout << "Deleted element: " << x << endl;
	L.deleteFront(x);
	cout << "Deleted element: " << x << endl;
  
	// Display the list
	cout << endl << 6 << endl;
	cout << "List: ";
	L.displayAll();

	// Check empty and report the result 
	cout << endl << 7 << endl;
	cout << "List Empty: " << L.isEmpty() << endl;
  
	// Remove from the rear twice (display the element removed)
	cout << endl << 8 << endl;
	L.deleteRear(x);
	cout << "Deleted element: " << x << endl;
	L.deleteRear(x);
	cout << "Deleted element: " << x << endl;
  
	// Check empty again and report the result
	cout << endl << 9 << endl; 
	cout << "List Empty: " << L.isEmpty() << endl;
}
 
void caseTwo()
{ 
	cout << "Case 2: -----------------------" << endl;
	llist L2;  // another list
	int x; // Will hold a removed element 
	int c = 1;  // displayed step number

	// Add to front once   (element 5)
	cout << endl << c << endl; c++;
	L2.addFront(5);
	
	// Add to front again  (element 4)
	cout << endl << c << endl; c++;
	L2.addFront(4);
	
	// Delete Front
	cout << endl << c << endl; c++;
	L2.deleteFront(x);
	cout << "Deleted element: " << x << endl;
	
	// Add to rear 3 times (elements 6,8,9)
	cout << endl << c << endl; c++;
	L2.addRear(6);
	L2.addRear(8);
	L2.addRear(9);
	
	// displayAll
	cout << endl << c << endl; c++;
	cout << "List: ";
	L2.displayAll();
	
	// Add before the 1st  (element 4) . 4 5 6 8 9
	cout << endl << c << endl; c++;
	L2.addbeforeIth(1,4);
	L2.displayAll();
	
	// Add before the 4th  (element 7) . 4 5 6 7 8 9
	cout << endl << c << endl; c++;
	L2.addbeforeIth(4,7);
	L2.displayAll();
	
	// Add before the 7th  (element 10) . 4 5 6 7 8 9 10
	cout << endl << c << endl; c++;
	try
	{
		L2.addbeforeIth(7,10);
	}
	
	catch (llist::OutOfRange)
	{
		cout << "ERROR: Out of Range";
	};
	
	// Add before the 9th  (element 12) . error (out of range)
	L2.displayAll();
	cout << endl << c << endl; c++;
	try
	{
		L2.addbeforeIth(9,12);
	} 
	catch(llist::OutOfRange)
	{
		cout << "ERROR: Out Of Range";
	};
	
	// Add before the 0th (element 0) . error (out of range)
	cout << endl << endl << c << endl; c++;
	try
	{
		L2.addbeforeIth(0,0);
	} 
	catch(llist::OutOfRange)
	{
		cout << "ERROR: Out Of Range";
	};
  
	// displayAll
	cout << endl <<  endl << c << endl; c++;
	cout << "List: ";
	L2.displayAll();
	
	// Delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
	cout << endl << c << endl; c++;
	L2.deleteIth(1,x);
	cout << "Deleted element: " << x << endl;
	
	// Delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
	cout << endl << c << endl; c++;
	L2.deleteIth(6,x);
	cout << "Deleted element: " << x << endl;
	
	// Delete Ith I==3 (indicate the element removed)  - 5 6 8 9
	cout << endl << c << endl; c++;
	L2.deleteIth(3,x);
	cout << "Deleted element: " << x << endl;
	
	// Delete Ith I==5 . error (out of range)
	cout << endl << c << endl; c++;
	try 
	{
		L2.deleteIth(5,x);
		cout << "Deleted element: " << x << endl;  
	}
	catch(llist::OutOfRange)
	{
		cout << "ERROR: Out Of Range";
	};
 
	// Delete Ith I==0 . error (out of range)
	cout << endl << endl << c << endl; c++;
	try 
	{
		L2.deleteIth(0,x);
		cout << "Deleted element: " << x << endl;
	}
	catch(llist::OutOfRange)
	{
		cout << "ERROR: Out Of Range";
	};
	
	// displayAll
	cout << endl << endl << c << endl; c++;
	cout << "List: ";
	L2.displayAll();

	// Delete from rear until it is empty (indicate the elements removed)
	cout << endl << c << endl; c++;
	while(!L2.isEmpty())
	{
		L2.deleteRear(x);
		cout << "Deleted element: " << x << endl;
	}
  
	// displayAll  
	cout << endl << c << endl; c++;
	cout << "List: ";
	L2.displayAll();
}

void caseThree()
{
	cout << "Case 3:-------------------- " << endl;
	llist L3;
	int x; // Will hold a removed element

	// Add before the 0th . error (out of range)
	cout << endl << 1 << endl;;
	try 
	{
		L3.addbeforeIth(0,x);
	}
	catch (llist::OutOfRange)
	{
		cout << "ERROR: Out Of Range" << endl;
	}
	// Delete front . error (underflow)
	cout << endl << 2 << endl;
	try 
	{
		L3.deleteFront(x);
	}
	catch (llist::Underflow)
	{
		cout << "ERROR: Underflow" << endl;
	}
}

void caseFour()
{
	cout << "Case 4:------------------------ " << endl;
	llist L4;
	int x; // Will hold a removed element

	// Delete 2nd . error (out of range)
	cout << endl << 1 << endl;
	try 
	{
		L4.deleteIth(2,x);
	}
	catch (llist::OutOfRange)
	{
		cout << "ERROR: Out Of Range" << endl;
	}
	// Delete rear . error (underflow)
	cout << endl << 2 << endl;
	try 
	{
		L4.deleteRear(x);
	}
	catch (llist::Underflow)
	{
		cout << "ERROR: Underflow" << endl;
	}
}

int main()
{
	int selection; // This will indicate what the user wants to do
	do
	{
		cout << endl << "MENU: These are your options: " << endl << endl;
		cout << "   (1) Case 1  " << endl;
		cout << "   (2) Case 2  " << endl;
		cout << "   (3) Case 3  " << endl;
		cout << "   (4) Case 4 " << endl;
		cout << "    Enter ( 0 ) to quit " << endl;
		cout << "===>";
      
		cin >> selection;
      
		switch(selection)
		{
			case 1: caseOne(); break;
			case 2: caseTwo(); break;
			case 3: caseThree(); break;
			case 4: caseFour(); break;
		}
	}
	while(selection !=0);
}
