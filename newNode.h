#pragma once

class gameList
{
public:
	// Constructor
	gameList() 
	{
		head = nullptr; // When created it sets the head to null.
	}
	// Destructor
	~gameList()
	{
	
	}
	// Linked list 
	void appendNode(double num, string newName)
	{
		singleList *newNode; // Used to point to a new node
		singleList *nodePtr; // Used to traverse through the list

		// Create's a new node and loads it up.
		newNode = new singleList; 
		newNode->gameCode = num;  
		newNode->gameName = newName;
		newNode->next = nullptr;

		// if there are no nodes in the list made newNode the first.
		if (!head)
		{
			head = newNode;
		} else
		{
			// Initialize nodePtr to head of list.
			nodePtr = head;
			
			// Find the last node in the list.
			while (nodePtr->next)
				nodePtr = nodePtr->next;
	
			// Insert newNode as the last node.
			nodePtr->next = newNode;
		}
	}
	void insertNode(double num, string newName, double search)
	{
		singleList *newNode; // Used to point to a new node.
		singleList *nodePtr; // Used to traverse through the list.
		singleList *previousNode; // Used to track the previous node.
    
		// Create's a new node and loads it up.
		newNode = new singleList;
		newNode->gameCode = num;  
		newNode->gameName = newName;
		cout << "node created and values added." << endl;
		// Position nodePtr at the head of the list.
		nodePtr = head;
		cout << "nodePtr set to Head" << endl;
		// Set Previousnode to null
		previousNode = nullptr;
		cout << "Previousnode set to null" << endl;
		// Find the game you'd like to insert the new node after.
		while (nodePtr != nullptr && nodePtr->gameCode != search)
		{
			cout << "I have entered the while loop" << endl;
			if (nodePtr->gameCode == search)
			{
				cout << "I have found the matching Gamecode." << endl;
			}
			else
			{
				cout << "I have not found the matching gameCode" << endl;
			}
			previousNode = nodePtr;
			// Move to the next node.
			nodePtr = nodePtr->next;		
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
		
	}
	void deleteNode(double)
	{

	}
	void displayList() const
	{
		singleList *nodePtr; // To move through the list
		
		// Position nodePtr at the head of the list.
		nodePtr = head;
		
		// While nodePtr points to a node, traverse
		// the list.
		system("CLS");
		while (nodePtr)
		{
			// Display the values in this node.
			cout << endl;
			cout << "ID Code: " << nodePtr->gameCode << endl;
			cout << "Name: " << nodePtr->gameName << endl;
			cout << endl;
			// Move to the next node.
			nodePtr = nodePtr->next;
		}
		nodePtr = head;
	}

private:
	// Declares a structure for the list.
	struct singleList
	{
	// The Data for the list--in this case it's game data.
		int gameCode;
		string gameName;
	// Pointer to the next node in the list.
		singleList *next;

	};
	// List head pointer.
	singleList *head;
};

