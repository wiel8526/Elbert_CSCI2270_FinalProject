
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person
{
	private:
		node *head;
        node *tail;
        int queueSize;
        int queueHead;
        int queueTail;
        std::string *arrayQueue;
	public:
	//void set_name(char[], char[]);
	//char get_name();
	void buildNetwork();
	void addContact(std::string);
	std::string delete();
	//display
	void printPath();
	//find
	
	bool queueIsFull(); //send when full
	Person(int);
    virtual ~Person();
};

struct node{

    string first_name;
	string second_name;
	string name;
	int number;
	string address;
    node *next;
    node *previous;

};
	
#endif
