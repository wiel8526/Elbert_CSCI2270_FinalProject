//final project P2 + P3
//Ashley Garg & William Elbert

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Person.h"
using namespace std; 

int main()
{
	string Fname, Nname, address, number;
	cout << "Welcome To My Address Book Program" << endl;
	cout<<"=========="<<endl;
	cout<<"Please enter the full name of your first contact:"<<endl;
	getline(cin, Fname);
	cout<<"Enter a nick name:"<<endl;
	getline(cin, Nname);
	cout<<"Enter the phone number:"<<endl;
	getline(cin, number);
	cout<<"Finally enter an address:"<<endl;
	getline(cin, address);
	//create initial contact
	Person *contacts = new Person(Fname, Nname, number, address);
	 
	string userInput;
	string toFind, toDelete, toChangeNumber, newNumber, toChangeAddress, newAddress;
	string Fname2, Nname2, address2, number2;
	while(userInput != "7")
	{
		//Menu	
		cout << "Welcome To My Address Book Program" << endl;
		cout << "1. Add a contact" << endl;
		cout << "2. Find a contact" << endl;
		cout << "3. Delete a name from the address book"  << endl;
		cout << "4. Display all contacts"<< endl;
		cout << "5. Change the number of a contact"<<endl;
		cout << "6. Change the address of a contact"<<endl;
		cout << "7. Quit" << endl;
		getline(cin, userInput);
		if(userInput == "1") // Add a contact
		{
			cout<<"Enter the full name of your contact:"<<endl;
			getline(cin, Fname2);
			cout<<"Enter a nick name:"<<endl;
			getline(cin, Nname2);
			cout<<"Enter the phone number:"<<endl;
			getline(cin, number2);
			cout<<"Finally enter an address:"<<endl;
			getline(cin, address2);
			contacts->addContact(Fname2, Nname2, number2, address2);
		}
		else if (userInput == "2")// find a person
		{
			cout<<"Enter the nickname:"<<endl;
			getline(cin, toFind);
			contacts->findContact(toFind);
		}
		else if (userInput == "3")// delete a name from the address book
		{
			cout<<"Enter the nickname:"<<endl;
			getline(cin, toDelete);
			contacts->deleteContact(toDelete);
		}
		else if (userInput == "4")//display contacts
		{
			contacts->displayAllContacts();
		}
		else if(userInput == "5")// Change number
		{
			cout<<"Enter the nickname:"<<endl;
			getline(cin, toChangeNumber);
			cout<<"Enter the new number:"<<endl;
			getline(cin, newNumber);
			contacts->changeNumber(toChangeNumber, newNumber);
		}
		else if(userInput == "6")// change address
		{
			cout<<"Enter the nickname:"<<endl;
			getline(cin, toChangeAddress);
			cout<<"Enter the new address:"<<endl;
			getline(cin, newAddress);
			contacts->changeAddress(toChangeAddress, newAddress);
		}
}
cout << "Goodbye!" << endl;

return 0;
}
