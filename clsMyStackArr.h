#pragma once
#include<iostream>
#include"clsDynamicArray.h"
#include"clsMyQueueArr.h"
template<class T>
class clsMyStackArr:public clsMyQueueArr<T>
{
public:
	void Push(T value) {
		clsMyQueueArr<T>::MyQueue.InsertAtBeginnen(value);

	};
	T Top() {
		return clsMyQueueArr<T>::Front();
	}

	T Bottem() {
		return clsMyQueueArr<T>::Back();
	}
};

