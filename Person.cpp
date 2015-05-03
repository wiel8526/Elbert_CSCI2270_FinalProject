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

/*
    This uses an algorithm to determine percentage of similarity
    it looks like this:

    similarity(s1,s2) = (2*(pairs(s1) *union* pairs(s2))) / (NumPairs(s1) + NumPairs(s2))
*/

int Person::string_similarity(string str1, string str2)
{

    //Makes sure that strLen is of the smaller string
    int strLen = str1.size();
    if(str2.size() < strLen)
    {
        strLen = str2.size();
    }

    float Num_Sim = numPairSimilar(str1, str2, strLen);

    float Num_Pairs1 = str1.size()-1;
    float Num_Pairs2 = str2.size()-1;

    float percentage = 2*Num_Sim;
    cout << percentage << endl;
    percentage = percentage / (Num_Pairs1 + Num_Pairs2);
    cout << Num_Pairs1 + Num_Pairs2 << endl;

    return percentage*100;
}

int Person::numPairSimilar(string str1, string str2, int strLen)
{
    int index1 = 0;
    int index2 = index1++;

    int counter = 0;

    for(int i = 0; i < strLen -1; i++)
    {
        string currentPair1 = str1.substr(index1,2);
        string currentPair2 = str2.substr(index1,2);


        if(currentPair1 == currentPair2)
        {
            counter++;
        }

        index1++;
        index2++;
    }

    return counter;
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
	else if(string_similarity(node->nickname,Nickname) > 50)
    {
        cout << node->nickname << "is " << string_similarity(node->nickname,Nickname) << "% similar to " << Nickname << endl;
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
