#pragma once
#include<iostream>
#include"clsDynamicArray.h"
template<class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T>MyQueue;
public:
	void Push(T Value) {
		MyQueue.InsertAtEnd(Value);
	}
	void Pop() {
		MyQueue.DeletFirstItem();
	}
	void Print() {
		MyQueue.Print();
	}

	int Size() {
		return	MyQueue.Size();
	}
	T Front() {
		return MyQueue.GetItem(0);
	}

	T Back() {
		return MyQueue.GetItem(Size()-1);
	}
	bool IsEmpty() {
		return  MyQueue.IsEmpty();
	}

	T GetItem(int Index) {
		return MyQueue.GetItem(Index);
	}
	void Reavers() {
		MyQueue.Revers();
	}

	bool UpdateItem(int Index, T value) {
		if (MyQueue.SetItem(Index,value))
			return true;
		return false;
	}
	bool InsertAfter(int Index, T value) {
		if (MyQueue.InsertAtAfter(Index,value))
			return true;
		return false;
	}

	void InsetAtFront(T value) {
		MyQueue.InsertAtBeginnen(value);
	}
	void InsertAtBack(T value) {
		MyQueue.InsertAtEnd(value);
	}

	void Clear() {
		MyQueue.Clear();
	}
};

