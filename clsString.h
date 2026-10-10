#pragma once
#include<iostream>
#include<stack>
using namespace std;
class clsString
{private:

	stack <string>_Undo;
	stack <string>_Redo;
	string _value;
	clsMyStackArr<string>Memory;
	clsMyStackArr <string>TempMemory;
public:
	void setValue(string value){
		this->_Undo.push(_value);
		this->_value = value;
	}
	string getValue(){
		return this->_value;
	}
	void Undo() {
		if (!this->_Undo.empty())
		{
			this->_Redo.push(_value);
			_value = this->_Undo.top();
			this->_Undo.pop();
	    }
	}
	void Redo() {
		if (! this->_Redo.empty())
		{
			this->_Undo.push(this->_value);
			_value = _Redo.top();
			_Redo.pop();
	     }
	}
};

