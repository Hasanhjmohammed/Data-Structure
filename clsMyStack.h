#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
#include"clsMyQueue.h"
template<class T>
class clsMyStack: public clsMyQueue<T>
{
public:

	void Push(T value) {
		clsMyQueue<T>::myLinkedList.InsertAtBeginning(value);
		
		};
	T Top() {
		return clsMyQueue<T>::Front();
	}
	
	T Bottem() {
		return clsMyQueue<T>::Back();
	}
	
};

