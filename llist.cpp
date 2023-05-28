
// ====================================================
// Program : Singly Linked List
// Your name: Konrad Kucharek
// Complier: G++
// File type: Singly Linked List Program file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

// Constructor
// Initialize Front and Rear to be NULL and Count = 0.
// This does not create any node.  The new list is empty.
llist::llist()
{
 Front = Rear = NULL;
 Count = 0; 
}


// Destructor  
llist::~llist()
{
  cout << endl << "Calling the llist destructor." << endl;
  el_t x;
  while (!isEmpty())
  deleteFront(x); 
  cout << "Llist destructor is done." << endl;
}

// Return true if Front and Rear are both pointing to NULL and Count is 0.
bool llist::isEmpty()
  {
    if(Front == NULL && Rear == NULL && Count == 0)
    return true;
    else
    return false;
  }

// Displays each element of the list horizontally starting from Front in [ ].
// If the list is empty, display [ empty ] ).
void llist::displayAll()
{
	cout<<"[";
    if(!isEmpty())
    {
		Node *temp=Front;
		while(temp!=NULL)
		{
			cout << temp->Elem << " ";
			temp = temp->Next;
		}
		cout << "]" << endl;
    }
    else 
		cout << "empty]" << endl;
}


void llist::addRear(el_t NewNum) 
/*2 cases:
  - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum and
    Count is updated.
  - Regular: adds a new node at the rear and puts NewNum in the Elem field
    of this new node. Count is updated.
    Regular case:
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL; */
    {
      Node *t = new Node;
      t->Elem = NewNum;
      t->Next = NULL;
      if(isEmpty())
        Front = Rear = t;
        
      else
      {
        Rear->Next = t;
        Rear = t;

      }
      Count++;
    }

void llist::addFront(el_t NewNum)
/*2 cases:
- Special case: if this is going to be the very first node, you must
   create a new node and make Front and Rear point to it. Place NewNum and
   Count is updated.
- Regular: add a new node to the front of the list and 
  Count is updated.
  Regular case:
  Node *x;
  x = new Node;
  x->Next = Front;
  Front = x;
  Front->Elem = NewNum;*/
  {
    Node *x = new Node;
    x->Elem = NewNum;
    x->Next = NULL;
    if(isEmpty())
      Front = Rear = x;
      else
      {
        x->Next = Front;
        Front = x;
      } 
      Count++;
  }

void llist::deleteFront(el_t& OldNum)
/*
3 cases:
- Error case: if the List is empty, throw Underflow
- Special case: if currently only one Node,
   give back the front node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the front node element through OldNum (pass by reference)
  and also removes the front node.  Count is updated.
  Regular case:
  OldNum = Front->Elem;
  Node *Second;
  Second = Front->Next;
  delete Front;
  Front = Second; 
*/
{
	if(isEmpty())
		throw Underflow();
	else
	{ 
		if (Count > 1)
		{
			OldNum = Front->Elem;
			Node *Second;
			Second = Front->Next;
			delete Front;
			Front = Second;
			Count--;
		}
		else 
		{
			OldNum = Front->Elem;
			delete Front;
			Front = NULL;
			Rear = NULL;
			Count--;
		}
	}
}
void llist::deleteRear(el_t& OldNum)
 /*
 3 cases:
- Error case: if empty, throw Underflow
- Special case: if currently only one node,
   give back the rear node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
  Regular case:
  OldNum = Rear->Elem;
  Node *p;
  Make p go to the one right before rear (using while)
  delete Rear;
  Rear = p; 
*/
{
	if(isEmpty())
		throw Underflow();
	else
	{
		if (Count > 1)
		{
			OldNum = Rear->Elem;
			Node *p = Front;
			while(p->Next!=Rear)
			{
				p = p->Next;
			}
			delete Rear;
			Rear = p;
			Count--;
			p->Next = NULL;
		}
		else
		{
			OldNum = Rear->Elem;
			delete Rear;
			Front = NULL;
			Rear = NULL;
			Count--;
		}
	}
}

void llist::deleteIth(int I, el_t& OldNum)
/*
4 cases:
- Error case: 
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or 
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers> 
*/
{
	if (I>Count || I<1)
	{
		throw OutOfRange();
	}

	else if (I==1)
	{
		deleteFront(OldNum);
	}  

	else if (I==Count)
	{
		deleteRear(OldNum);
	}

	else
	{
		if(I<Count && I>1)
		{
			Node *p = Front;
			int j = 0;
			while(p->Next != NULL && j<I-2)
			{
				p=p->Next;
				j++;
			}
			OldNum = p->Next->Elem;
			p->Next = p->Next->Next;
			Count--;
		}
	}
}

void llist::addbeforeIth(int I, el_t newNum)
/*
4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers> 
*/
{
	if (I>Count+1 || I<1)
	{  
		throw OutOfRange();
	}
  
	else if (I==1)
	{
		cout << "a" << endl;
		addFront(newNum);
	}

	else if (I==Count+1)
	{
		addRear(newNum);
	}

	else
	{
		if(I<Count && I>=1)
		{
			Node *p = Front;
			int j=0;
			while(p->Next != NULL && j<I-2)
			{
				p=p->Next;
				j++;
			}
			Node *x;
			x = new Node;
			x->Elem = newNum;
			x->Next = p->Next;
			p->Next = x;
			Count++;
		}
	}
}
