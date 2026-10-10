#pragma once
#include<iostream>
#include "clsDblLinkedList.h"
using namespace std;
template<class T>
class clsMyQueue
{

protected:
	clsDblLinkedList <int>myLinkedList;
public:

	void Push(T value ) {
		myLinkedList.InsertAtEnd(value);
	}
	void Pop() {
		myLinkedList.DeletFirstNod();
	}
	void Print() {
		myLinkedList.PrintList();
	}
	int Size() {
	return	myLinkedList.Size();
	}

	T Front() {
		return myLinkedList.GetItem(0);
	}
	T Back() {
		int siz = myLinkedList.Size();
		return myLinkedList.GetItem(siz-1);
	}

	bool IsEmpty() {
		return  myLinkedList.IsEmpty();
	}

	T GetItem(int Index) {
		return myLinkedList.GetItem(Index);
	}

	void Reavers() {
		myLinkedList.Revers();
	}

	bool UpdateItem(int Index, T value) {
		if (myLinkedList.UpdateItem(Index, value))
			return true;
		return false;
		
	}

	bool InsertAfter(int Index, T value) {
		if (myLinkedList.insertAfter(Index, value))
			return true;
		return false;
	}

	void InsetAtFront(T value) {
		myLinkedList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value) {
		myLinkedList.InsertAtEnd(value);
	}

	void Clear() {
		myLinkedList.Clear();
	}
};

