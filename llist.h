// =======================================================
// Program: Singly Linked List
// Name: Konrad Kucharek
// Compiler: G++ 
// File type: Header file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // el_t is an alias for the data type
					// el_t is unknown to the client

// List node is defined here as a struct Node
struct Node
{
	el_t Elem; // Elem is the element stored
	Node *Next; // Next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
	private:
		Node *Front;       // pointer to the front node
		Node *Rear;        // pointer to the rear node
		int  Count;        // counter for the number of nodes
  
	public:

	// Exception handling classes 
	class Underflow{};
	class OutOfRange{};  // thrown when the specified Node is out of range

	llist ();     // constructor to create a list object
	~llist();     // destructor to destroy all nodes
  
	// Checks if the linked list is empty or not
	bool isEmpty();
    
	// Displays the entire linked list
	void displayAll();

	// Adds a node to the front of the linked list
	void addFront(el_t);
    
	// Adds a node to the rear of the linked list
	void addRear(el_t);

	// Deletes the front node of the linked list
	void deleteFront(el_t&);
    
	// Deletes the rear node of the linked list
	void deleteRear(el_t&);
    
	// Deletes the Ith node in the linked list
	void deleteIth(int, el_t&);

	// Adds a node before the Ith node in the linked list
	void addbeforeIth(int, el_t);
};
