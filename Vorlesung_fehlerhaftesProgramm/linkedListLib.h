//#pragma once

#ifndef LINKEDLISTLIB_H_
#define LINKEDLISTLIB_H_

struct listElem {

	char lastName[50];
	char firstName[50];
	int age;
	struct listElem* nextElem;

};

typedef struct listElem listElement;
void addListElem(listElement*);
void printList(listElement*);

#endif // !LINKEDLISTLIB_H_
