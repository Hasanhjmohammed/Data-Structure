#pragma once
#include<iostream>
using namespace std;

template<class T>
class clsDblLinkedList
{
protected:
	int _Size = 0;

public:
	class Node
	{
	public:
		T _Date;
		Node* Next;
		Node* Prev;
	};
	Node* Head = NULL;
	Node* Last = NULL;
	void InsertAtBeginning( T value) {

		Node* CurrentNode = new Node();
		CurrentNode->_Date = value;

		CurrentNode->Next = Head;
		CurrentNode->Prev = NULL;
		if (Head != NULL)
			Head->Prev = CurrentNode;
		Head = CurrentNode;
		_Size++;
	}

	void PrintList() {
		Node* Current = Head;
		while (Current != NULL)
		{
			cout << Current->_Date <<"  ";
			Current = Current->Next;	
		}
		cout << "\n";
	}

	Node* Find( int value) {
		Node* Current = Head;
		while (Current != NULL)
		{
			if (Current->_Date == value)
				return Current;
			Current = Current->Next;

		}
		return NULL;
	}

	void insertAfter(Node*& PrevNode, T value) {
		Node* CurrentNode = new Node();
		CurrentNode->_Date = value;
		CurrentNode->Next = PrevNode->Next;
		CurrentNode->Prev = PrevNode;

		if (PrevNode->Next != NULL)
			PrevNode->Next->Prev = CurrentNode;
		PrevNode->Next = CurrentNode;
		_Size++;
	}
	bool  insertAfter(int Index, T value) {
		Node* prev = GetNodeByIndex(Index);
		if (prev != NULL)
		{
			insertAfter(prev, value);
			return true;
		}
		else
			return false;
	}
	void DeletNode( Node*& NodeDelet) {
		Node* Current = Head;
		if (Current == NULL || NodeDelet == NULL)
			return;
		if (Current == NodeDelet)
		{
			Current = NodeDelet->Next;
			Head = Current;
			_Size--;
			return;
		}
		if (NodeDelet->Next == NULL)
		{
			NodeDelet->Prev->Next = NULL;
			delete NodeDelet;
			
		}

		else
		{
			NodeDelet->Prev->Next = NodeDelet->Next;
			NodeDelet->Next->Prev = NodeDelet->Prev;
		}
		_Size--;

	}

	void InsertAtEnd( int value) {
		Node* HeadTemp = Head;
		Node* CurrentNode = new Node();
		CurrentNode->_Date = value;
		CurrentNode->Next = NULL;

		if (HeadTemp == NULL)
		{
			CurrentNode->Prev = NULL;
			HeadTemp = CurrentNode;
			Head = HeadTemp;
		}
		else
		{
			Node* prev = HeadTemp;

			while (prev->Next != NULL)
			{
				prev = prev->Next;

			}
			prev->Next = CurrentNode;
			CurrentNode->Prev = prev;
		}
		_Size++;
	}

	void DeletFirstNod() {
		if (Head == NULL)
			return;

		Node* Current = Head;
		Head = Current->Next;
		if (Head != NULL)
		{
			Head->Prev = NULL;
		}
		delete Current;

		_Size--;
		return;
	}

	void DeletLastNod() {
		Node* Currenttemp = Head;
		if (Currenttemp == NULL)
			return;
		if (Currenttemp->Next == NULL)
		{
			delete Currenttemp;
			Currenttemp = NULL;
			Head = Currenttemp;
			Last = Currenttemp;
			_Size--;
			return;
		}
		Node* Current = Head;
		while (Current->Next->Next != NULL)
		{
			Current = Current->Next;
		}
		Last = Current;
		Node* temp = Current->Next;
		Current->Next = NULL;
		delete temp;
		_Size--;

	}

	int SizeOf() {
		int Counter = 0;
		Node* Current = Head;
		while (Current != NULL)
		{
			Counter++;
			Current = Current->Next;
		}
		return Counter;
	}
	int Size() {
		return _Size;
	}

	bool IsEmpty() {
		return (_Size == 0 ? true :false );
	}

	void Clear() {

		while (_Size>0)
		{
			DeletFirstNod();
		}
	}

	void Revers() {
		Node* temp = nullptr;  
		Node* Current = Head; 

		while (Current!= NULL)
		{
			temp = Current->Prev;
			Current->Prev = Current->Next; 
			Current->Next = temp; 
			Current = Current->Prev;
		}

		if (temp != nullptr) 
		{
			Head = temp->Prev; 
		}
         
	}

	Node* GetNodeByIndex(int Index) {
		int Count = 0;

		if (Index > _Size - 1 || Index < 0)
			return NULL;
		Node* Current = Head;
		while (Current!= NULL && (Current->Next !=NULL))
		{
			
			if (Count == Index)
			{
				break;
			}
			Current = Current->Next;
			Count++;
			
		}
		return Current;
	}

	T GetItem(int Index) {
		
		Node* ItemNode = GetNodeByIndex(Index);
		if (ItemNode !=NULL)
		return ItemNode->_Date;
		else
		{
			return NULL;
		}
	}
	bool  UpdateItem(int Index, T UpdateValue) {
		Node* ItemNode = GetNodeByIndex(Index);
		if (ItemNode != NULL)
		{
			ItemNode->_Date = UpdateValue;
			return true;
		}
		else
		{
			return false;
		}
	}

};

