//============================================================================
// Name        : PhonebookReader.cpp
// Author      : Robin Shaw
// Version     :
// Copyright   : Your copyright notice
// Description : A reader and array builder/editor for phonebook.txt
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "Contact.h"
#include "BinarySearchTree.h"
using namespace std;



int main() {
	char command;
	BinarySearchTree<Contact> phoneBook;
	string name;
	string lname;
	int number;


	cout << "Welcome to My Phonebook Operation!" << endl;

	for (;;) { //infinite loop until user closes it with Q
		cout << "Please select an operation:" << endl;
		cout << "A(Add)	| L(Load) | S(Search) | P(Print) | F(Filter) | Q(Quit): ";
		cin >> command;
		cout << endl;


		if (command == 'A') { //Add
			cout << "command = A" << endl;
			cout << "please enter a full name (first and last): ";
			cin >> name >> lname;
			name = name + " " + lname;
			cout << "please enter a number: ";
			int numberhere;
			cin >> numberhere;

			//build contact
			Contact tempCon;
			tempCon.setName(name);
			tempCon.setNumber(numberhere);

			//Insert into tree
			phoneBook.insert(tempCon);

			cout << tempCon.getName() << " " << tempCon.getNumber() << " has been added." << endl;


		} else if (command == 'L') { //Load
			cout << "command = L" << endl;
			string fileName;
			ifstream book;
			cout << "please enter a file name: ";
			cin >> fileName;
			cout << "Now reading" << fileName << "..." << endl;
			//FIND CHECK
			book.open (fileName);
			while (!book.eof()) {
				 book >> name;
				 book >> lname;
				 book >> number;
				 name = name + " " + lname;
				//build contact
				Contact tempCon;
				tempCon.setName(name);
				tempCon.setNumber(number);

				//Insert into tree
				phoneBook.insert(tempCon);
				 //These were used for testing to see if it was building right:
		//		 cout << phonebook[counter].getName() <<" "<< phonebook[counter].getNumber();
		//		 cout << " " << counter<<endl;
			}
			book.close();
			cout << "Your file has been loaded." << endl;

		}
		else if (command == 'S') { //Search
			cout << "command = S" << endl;
			cout << "please enter a full name (first and last): ";
			cin >> name >> lname;
			name = name + " " + lname;
			cout << "Number: ";
			phoneBook.search(name);

		}
		else if (command == 'P') { //Print
			cout << "command = P" << endl;
			phoneBook.inOrder();
			cout <<endl;
		}
		else if (command == 'F') { //Filter
			cout << "command = F" << endl;
			cout << "please enter a full name (first and last): ";
			cin >> name >> lname;
			name = name + " " + lname;
			phoneBook.filter(name);

		}
		else if (command == 'Q') { //Quit
			cout << "The program will now quit." << endl;
			cout << "Thanks for running!" << endl;
			break;

		} else {
			cout << "Valid command not given. Please try again." << endl;
		}
	}
	return 0;
}
