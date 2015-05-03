#ifndef PERSON_H
#define PERSON_H
#include <string>

struct node{
    std::string full_name;
	std::string nickname;
	std::string number;
	std::string address;
    node *next;
    node *previous;
};

class Person
{
	private:
		node *head;
        node *tail;
		node* searchList(node * node, std::string Nickname);
	public:
	    int string_similarity(std::string str1, std::string str2);
	    int numPairSimilar(std::string str1, std::string str2, int strLen);
		void addContact(std::string, std::string, std::string, std::string);
		void deleteContact(std::string NicName);
		void findContact(std::string NicName);
		void displayAllContacts();
		void changeNumber(std::string NicName, std::string newNumber);
		void changeAddress(std::string NicName, std::string newAddress);

		Person(std::string Fname, std::string NicName, std::string Number, std::string Address);
		virtual ~Person();
};

#endif
