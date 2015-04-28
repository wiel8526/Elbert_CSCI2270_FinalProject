//CONSTRUCTOR FILE
//by William Elbert
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;
/*CONSTRUCTOR*/
/* All the inputs must be entered. The constructor creates the first contact
 * known as the head, it can be deleted and replaced later.
 */
Person::Person(string Fname, string NicName, string Number, string Address)
{ //create the first contact
	node *contact1 = new node;
	contact1->full_name = Fname;
	contact1->nickname = NicName;
	contact1->number = Number;
	contact1->address = Address;
	head = contact1;
}
/*DESTRUCTOR*/
/* Deletes the linked list to prevent memory leaks.
 */
Person::~Person()
{
	node *cursor = head;
	node *temporary;
	temporary = cursor->next;
	while(cursor->next != NULL)
	{
		delete cursor;
		cursor = temporary;
		temporary = temporary->next;
	}
	head = NULL;
}
/*Takes 4 inputs and adds it to the end of the linked list.
 */
void Person::addContact(string fullname, string Nickname, string numb, string Address)
{
	node *newcontact = new node;
	newcontact->full_name = fullname;
	newcontact->nickname = Nickname;
	newcontact->number = numb;
	newcontact->address = Address;
	newcontact->previous = head;
	newcontact->next = NULL;
	
	node* cursor = head;
	
	if(head == NULL){
		head = newcontact;
		return;
	}
	while(cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	cursor->next = newcontact;
}
//finds the node that needs to be deleted, then deletes it.
void Person::deleteContact(std::string NicName)
{
	if(head == NULL){
		 cout<<"=========="<<endl;
		 cout<< NicName<<" was not found."<<endl;
		 cout<<"=========="<<endl;
		 return;
	}
	else if(head->nickname == NicName)
	 {
		 if(head->next == NULL){
			head = NULL;
		}
		 else{
			 node *temp = head;
			 head = head -> next;
			 delete temp;
		}
		cout<<"=========="<<endl;
		cout<< NicName<<" was deleted."<<endl;
		cout<<"=========="<<endl;
	 }
	 else
	 {
		 node *temp1 = head;
		 node *temp2 = new node;
		 while(temp1->next->nickname != NicName)//while head's temporary node's next node is not the one being looked for...
		 {
			 temp1 = temp1->next;//..head's temporary node is set to the next node 
		 }
		 temp2 = temp1->next; // now temp1's next is the node that is to be deleted
		 temp1->next = temp1->next->next;
		 delete temp2;
		 cout<<"=========="<<endl;
		 cout<< NicName<<" was deleted."<<endl;
		 cout<<"=========="<<endl;
	 }
}
// uses one input and the searchList function to print the information of the desired node
void Person::findContact(std::string NicName)
{
	node *temp;
	temp = searchList(head, NicName); //calls the function searchList to find the specific name
	if(temp == NULL)
	{
		cout<<"=========="<<endl;
		cout<< NicName<<" was not found."<<endl;
		cout<<"=========="<<endl;
	}
	else{
		cout<<temp->nickname<<"'s Information:"<<endl;
		cout<<"=========="<<endl;
		cout<<temp->full_name<<endl;
		cout<<temp->number<<endl;
		cout<<temp->address<<endl;
		cout<<"=========="<<endl;
	}
}
// prints all nodes in the linked list and their information 
void Person::displayAllContacts()
{
	node *current = head;
	if(current == NULL)
	{
		cout<<"=========="<<endl;
		cout<<"Contacts list is empty."<<endl;
		cout<<"=========="<<endl;
	}
	while(current != NULL)
	{
		cout<<"=========="<<endl;
		cout<<current->full_name<<" also known as "<<current->nickname<<endl;
		//cout<<current->nickname<<endl;
		cout<<current->number<<endl;
		cout<<current->address<<endl;
		current = current->next;
	}
	cout<<"=========="<<endl;
}
//takes in the head node and a nickname to find a specific node.
node *Person::searchList(node* node, string Nickname)
{
	if(node == NULL){
		return node;
	}
	else if(node->nickname == Nickname){
		return node;
	}
	else{
		return searchList(node->next, Nickname);
	}
}
//Finds the node using the searchList function and changes the address.
//takes two inputs: a nickname and a new number to replace the old one
void Person::changeNumber(string NicName, string newNumber)
{
	node *temp;
	temp = searchList(head, NicName); //calls the function searchList to find the specific name
	if(temp == NULL)
	{
		cout<<"=========="<<endl;
		cout<< NicName<<" was not found."<<endl;
		cout<<"=========="<<endl;
	}
	else{
		temp->number = newNumber;
	}
}
//Finds the node using the searchList function and changes the address
//takes two inputs: a nickname and a new address to replace the old one
void Person::changeAddress(string NicName, string newAddress)
{
	node *temp;
	temp = searchList(head, NicName); //calls the function searchList to find the specific name
	if(temp == NULL)
	{
		cout<<"=========="<<endl;
		cout<< NicName<<" was not found."<<endl;
		cout<<"=========="<<endl;
	}
	else{
		temp->address = newAddress;
	}
}
