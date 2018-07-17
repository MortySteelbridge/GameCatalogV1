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

	while (target != 5)
	{	
		
		cout  << "Please select from the following." << endl;
		cout << "1. Check Catalog." << endl <<  "2. Add to Catalog." << endl << "3. Insert game in Catalog" << endl << "4. Lend game." << endl
			<< "5. Exit Program" << endl;
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
			
			list.insertNode(newCode, newName, searchNum);
		}
	}
}

void load_File()
{

}
