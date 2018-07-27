// Game Catalog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gameCatalog.h"
#include "newNode.h"
int main()
{
	cout << "Opening Menu..." << endl;
	Menu();
}

void Menu()
{
	double target = 0, newCode = 0, searchNum = 0;
	string newName;
	gameList list;

	cout << "Welcome to The Catalog." << endl;

	while (target != 6)
	{	
		
		cout  << "Please select from the following." << endl;
		cout << "1. Check Catalog." << endl <<  "2. Add to Catalog." << endl << "3. Insert game in Catalog" << endl << "4. Lend game." << endl
			<< "5. Delete Game from Catalog" << endl << "6. Exit Program" << endl;
		cin >> target;
		if (target == 1)
		{
			system("CLS");
			list.displayList();
			cout << endl << endl;
		} 
		else if (target == 2)
		{
			cout << "Please enter the game identifier." << endl;
			cin >> newCode;
			cout << "Please enter the game's name." << endl;
			std::cin.ignore();
			getline(cin, newName);
			
		//	newName = Remove_Spaces(newName);

			list.appendNode(newCode, newName);
			list.displayList();

			cout << endl << endl << endl;
		}
		else if (target == 3)
		{
			cout << "Please enter the game identifier." << endl;
			cin >> newCode;
			
			cout << "Please enter the game's name." << endl;
			std::cin.ignore();
			getline(cin, newName);
			
			cout << "Please enter the game ID where you would like to insert the new game." << endl;
			cin >> searchNum;
			
			cout << "Running insertNode" << endl;
			list.insertNode(newCode, newName, searchNum);
			cout << "insertNode has been run." << endl;
		}
    else if (target ==4)
    {
      cout << "You have selected option 4." << endl; // remove later.
    }
    else if (target == 5)
    {
       double toBeDeleted;
      cout << "You have the following games in the catalog:" << endl;
      list.displayList();
      cout << "Which game would you like to remove from the catalog?" << endl
             << "NOTE: Please enter the Game Code of the game, not the name of the game." << endl;
      cin >> toBeDeleted;
      list.deleteNode(toBeDeleted);
    }
	}
}

void load_File()
{

}
