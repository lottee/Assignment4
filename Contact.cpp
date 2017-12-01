/*
 * Entry.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Robin Shaw
 */

#include "Contact.h" //link cpp with the header file
#include <iostream>
#include <string>
using namespace std;


Contact::Contact(string tname, int tnumber) {
	name = tname;
	number = tnumber;
}

Contact::Contact() {
	name = "";
	number = 0;
}

Contact::~Contact() {
}

void Contact::setName(string tname) {
	name = tname;
}
void Contact::setNumber(int tnumber) {
	number = tnumber;
}
string Contact::getName() {
	return name;
}
int Contact::getNumber() {
	return number;
}


int Contact::compareNames (string sent) {
	return (name.find(sent));
}

void Contact::blankThis () {
	setName("");
	setNumber(0);
}

ostream& operator<<(ostream& os, const Contact& obj) {
	if (obj.number == 0) {
		os << obj.name;
		return os;
	}
	os<< obj.name << " " << obj.number;
	return os;
}

bool operator<(const Contact& l, const Contact& r) {
	return l.name < r.name;
}
bool operator>(const Contact& l, const Contact& r) {
	return l.name > r.name;
}
bool operator<=(const Contact& l, const Contact& r) {
	return l.name <= r.name;
}
bool operator>=(const Contact& l, const Contact& r) {
	return l.name >= r.name;
}




