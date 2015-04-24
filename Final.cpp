//final project P2 + P3
//Ashley Garg

#include <iostream>
#include "Final.h"
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std; 

int main()
{
	string userInput;
	getline(cin,input);
	
	
	//ifstream infile;
	//infile.open("messageIn.txt");
	
	int x = 0;
	int i = 0;
	//int queueSize = 10;
	string array[50]; 
	node *head = new node;
	//node *tail = new node;
	
	 Person Info(10);
	 //creating a communication network object. 
	
	while(userInput != 5)
	{
//Menu	
cout << "Welcome To My Address Book Program" << endl;
cout << "1. Add a contact." << endl;
cout << " Enter 2 to find a person." << endl;
cout << "Enter 3, Delete a name from the address book"  << endl;
cout << "4. Display address/contact"<< endl;
cout << "5. Quit." << endl;
if(userInput != "1")
{
	//function call
}
else if (userInput != "2")
{
	//function call
}
else if (userInput != "3")
{
	//function call
}
else if (userInput != "4")
{
	//function call
}
}
cout << "Goodbye!" << endl;

return 0;
}
