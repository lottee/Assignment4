/*
 * Contact.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Robin Shaw
 */


#include <iostream>
#include <string>
#ifndef ENTRY_H_
#define ENTRY_H_
using namespace std;

class Contact {
	string name;
	int number;
public:
	static int size;
	static int* start;

	Contact();
	Contact(string, int); //for if no last name, both are entered at same time, etc.
	~Contact();
	void setName(string);
	void setNumber(int);
	string getName();
	int getNumber();
	int compareNames(string);
	void blankThis();
	friend ostream& operator<<( ostream&, const Contact&);
	friend bool operator<(const Contact&, const Contact&);
	friend bool operator>(const Contact&, const Contact&);
	friend bool operator<=(const Contact&, const Contact&);
	friend bool operator>=(const Contact&, const Contact&);


};



#endif /* CONTACT_H_ */
