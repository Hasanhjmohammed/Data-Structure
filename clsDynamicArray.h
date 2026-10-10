#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
template<class T>
class clsDynamicArray
{
	int Min(int N1,int N2){
		if (N1 > N2)
			return N2;
		return N1;
	}
protected:

	int _SizeOfArray;
public:
	T* OrignalArray; 
	T* TempArray;

	clsDynamicArray(int Size=0) {
		if (Size < 0)
			Size = 0;
		_SizeOfArray = Size;
		OrignalArray = new T[_SizeOfArray];


	}

	~ clsDynamicArray() {
		delete[]OrignalArray;
	}

	bool SetItem(int Index, T Value) {
		if (Index <0 || Index >_SizeOfArray)
			return false;
		else
		{
			OrignalArray[Index] = Value;
		}
	}
	bool IsEmpty() {
		return _SizeOfArray == 0 ? true : false;
	}

	int Size() {
		return _SizeOfArray;
	}
	void Print() {
		for (int i = 0; i < _SizeOfArray; i++)
		{
			cout << OrignalArray[i] << " ";
		}
		cout << endl;
	}

	void ReSize(int Size=0) 
	{
		if (Size < 0)
			Size = 0;
		int length = Min(Size, _SizeOfArray);
		   TempArray = new T[Size];
		for (int i = 0; i < length; i++)
		{
			TempArray[i] = OrignalArray[i];
		}
		_SizeOfArray = Size;
		delete[]OrignalArray;

		OrignalArray = TempArray;
	}

	void Revers() {

		TempArray = new T[_SizeOfArray];
		for (int i = 0; i < _SizeOfArray; i++)
		{
			TempArray[i] = OrignalArray[_SizeOfArray - i-1 ];
	     }
		delete[] OrignalArray;
		OrignalArray = TempArray;
	}

	void Clear() {
		_SizeOfArray = 0;
		TempArray = new T[0];
		delete OrignalArray;
		 OrignalArray = TempArray ;
	}

	T GetItem(int Index) {
		if (Index >=0||Index <_SizeOfArray)
		return OrignalArray[Index];
	}
	
	void  DeletItemByIndex(int Index) {
		TempArray = new T[_SizeOfArray - 1];
		int Counter = 0;
		for (int i = 0; i < _SizeOfArray; i++)
		{
			if (i == Index)
			{
				continue;
		     }
			else
			{
				TempArray[Counter] = OrignalArray[i];
				Counter++;
			}

		}
		delete[]OrignalArray;
		_SizeOfArray--;
		OrignalArray = TempArray;
	}
	bool  DeletItemAboHad(int Index) {
		if (Index<0 || Index>_SizeOfArray)
			return false;
		TempArray = new T[_SizeOfArray - 1];
		for (int i = 0; i < Index; i++)
		{
			TempArray[i] = OrignalArray[i];
		}

		for (int i = Index + 1; i < _SizeOfArray; i++)
		{
			TempArray[i - 1] = OrignalArray[i];
		}
		_SizeOfArray--;
		delete[]OrignalArray;
		OrignalArray = TempArray;
		return true;
	}

	bool DeletFirstItem() {
		return DeletItemAboHad(0);
	}
	bool DeletLastItem() {
		return DeletItemAboHad(_SizeOfArray-1);
	}

	int Find(T Value) {

		for (int i = 0; i < _SizeOfArray; i++)
		{
			if (OrignalArray[i] == Value)
				return i;
		}
		return -1;
	}

	bool DeletItemByValue(T Value ) {

		int Index = Find(Value);
		if (Index == -1)
			return false;
		DeletItemAboHad(Index);
		return true;
	}

	bool InsertAt(int Index, T Value) {
		if (Index<0 || Index>_SizeOfArray)
			return false;
		TempArray = new T[_SizeOfArray +1 ];
		for (int i = 0; i < Index; i++)
		{
			TempArray[i] = OrignalArray[i];
		}
		TempArray[Index] = Value;
		for (int i = Index ; i < _SizeOfArray; i++)
		{
			TempArray[i+1] = OrignalArray[i];
		}
		_SizeOfArray++;
		delete[]OrignalArray;
		OrignalArray = TempArray;
		return true;
	}

	bool InsertAtBeginnen(T Value) {
		return InsertAt(0, Value);
	}
	bool InsertAtEnd(T Value) {
	return	InsertAt(_SizeOfArray, Value);
	}
	bool InsertAtAfter(int Index,T Value) {
		if (Index >= _SizeOfArray)
		return	InsertAt(_SizeOfArray,Value);

	return	InsertAt(Index+1, Value);
	}
	bool InsertAtBefor(int Index, T Value) {

		if (Index < 1)
			return InsertAt(0,Value);
	return	InsertAt(Index - 1, Value);
	}
};

