#pragma once
#include<iostream>
#include<string>
#include"InterfaceCommunction.h"
using namespace std;
class clsPerson:public InterfaceCommunction
{
private:
	string _FirstName;
	string _LastName;
	string phone;
	string Email;
public:
	void SendEmail(string title, string body) {
		cout << "title";
	}
	void SendSMS(string title, string body) {

	}

};

