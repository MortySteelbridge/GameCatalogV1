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
		// Position nodePtr at the head of the list.
		nodePtr = head;
		// Set Previousnode to null
		previousNode = nullptr;
		// Find the game you'd like to insert the new node after.
		while (nodePtr != nullptr && nodePtr->gameCode != search)
		{
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
	void deleteNode(double num)
	{
		singleList *newNode; // Used to point to a new node.
		singleList *nodePtr; // Used to traverse through the list.
		singleList *previousNode; // Used to track the previous node.
    
    if(!head)
    {
      //if the list is empty, do nothing.
        return;
    }
    
    // Check the first node to see if it's the target.
    if (head->gameCode == num)
    {
      nodePtr = head->next;
      delete head;
      head =nodePtr;
    } else
    {
      // Set node to the head of the list.
      nodePtr = head;
      // Skip all nodes whose value member is not num
      while (nodePtr != nullptr && nodePtr->gameCode != num)
      {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
      }
      // if nodePtr is not at the end of the list
      // link the previous node to the node after
      // nodePtr, then delete node Ptr.
      if (nodePtr)
      {
        previousNode ->next = nodePtr->next;
        delete nodePtr;
      }
    }
  }
    
	void displayList() const
	{
		singleList *nodePtr; // To move through the list
		
		// Position nodePtr at the head of the list.
		nodePtr = head;
		
		// While nodePtr points to a node, traverse
		// the list.

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
  
  void write_File()
  {
    std::ofstream myFile;
    singleList *nodePtr; 
		
		// Position nodePtr at the head of the list.
		nodePtr = head;
		
    // Opens the file for writing.
    myFile.open("Game_List.txt");
		// While nodePtr points to a node, traverse
		// the list.

		while (nodePtr)
		{
			// Display the values in this node.
			
			myFile << nodePtr->gameCode << std::endl;
			myFile << nodePtr->gameName << std::endl;
			// Move to the next node.
			nodePtr = nodePtr->next;
		}
		nodePtr = head;
    myFile.close();
  }
  
void load_File()
{
  std::vector <string> data;
  string line, tempString;
  stringstream converted;
  
  std::ifstream myFile;
  singleList *newNode;
  singleList *nodePtr;
  
  double newDouble;
  // Position nodePtr at the head of hte list.
  nodePtr = head;
  
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
  
  // Opens the file for writing.
  myFile.open("Game_List.txt");
 
 		// Create's a new node and loads it up.
	newNode = new singleList;
  while(std::getline(myFile, line))
  {
    //Put something here that  takes the info from the txt file and loads it into the link list.
    data.push_back(line);
    newNode->next = nullptr;
  } 
    for (int i=0; i< (data.size() - 1); i++)
  {
    // If the Vector is even it will contain a Name, so place the name in the Linked List.
    if ( (i % 2  == 0))
    {
      tempString = data[i];
      nodePtr->gameName = boost::lexical_cast<double>(tempString);
    } else
    // If the Vector is odd it will contain the Number, so place the code in the Linked List.  FIX
    {
     /* 
      tempString = data[i];
      newDouble = boost::lexical_cast<double>(tempString);
      nodePtr->gameCode = newDouble;
    */
    }  
    cout << data[i] << endl;
  }  
}

private:
	// Declares a structure for the list.
	struct singleList
	{
	// The Data for the list--in this case it's game data.
		double gameCode;
		string gameName;
	// Pointer to the next node in the list.
		singleList *next;

	};
	// List head pointer.
	singleList *head;
};

