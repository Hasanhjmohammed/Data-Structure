#pragma once
#pragma warning (disable :4996)
#include<iostream>
#include<string>
#include<stack>
#include<Queue>
using namespace std;
class clsQueueLine
{private:
	string _Pref;
	int _CountServedCleint = 0;
	float _MinuteForCleint;
	int _TotalTickts = 0;

	void _Revers() {
		stack<Bill>TempStack;
		Temp = _List;
		while (!Temp.empty() )
		{
			TempStack.push(Temp.front());
			Temp.pop();
		}

		while (!TempStack.empty())
		{
			Temp.push(TempStack.top());
			TempStack.pop();
		}
        
	}
	
	class Bill
	{
		string _Pref;
		string _Date;
		int _Number;
		short watingCeints;
		float _ServedMinuteBill;
	public:
		Bill(string Pref,int Number,short watingCeints,float ServedMinuteBill){
			this->_Pref = Pref;
			this->watingCeints = watingCeints;
			this->_Number = Number;
			this->_Date = GetSysteamDateTimeString();
			this->_ServedMinuteBill = ServedMinuteBill;
		}

		string FullName() {
				return this->_Pref + to_string(_Number );
		}
		static string GetSysteamDateTimeString() {
			short Sec, Min, Hou, Day, Month, Year;
			time_t t = time(0);
			tm* now = localtime(&t);
			Year = now->tm_year + 1900;
			Month = now->tm_mon + 1;
			Day = now->tm_mday;
			Hou = now->tm_hour;
			Min = now->tm_min;
			Sec = now->tm_sec;
			return to_string(Day) + "/" + to_string(Month) + "/" +
				to_string(Year) + " - " + to_string(Hou) + ":" + to_string(Min) + ":" + to_string(Sec);
		}
		float getServedMinuteBill() {
			return _ServedMinuteBill;
		}

		int ExpectServedTime() {
			return watingCeints * _ServedMinuteBill;
		}
	void PrintBill() {
		cout << "\n\n\t\t\t\t\t__________________________________\n\n";
		cout << "\t\t\t\t\t " << FullName() << endl;
		cout << "\n";
		 cout << "\t\t\t\t\t " << _Date << endl;
		 cout << "\t\t\t\t\t Wating Cleint = " << watingCeints << endl;
		 cout << "\t\t\t\t\tServe Time In \n";
		 cout << "\t\t\t\t\t" << ExpectServedTime() << endl;
		 cout << "\n\n\t\t\t\t\t__________________________________\n";
		}
	string getPref() {
		return this->_Pref;
	 }
	};
protected :
	
	queue<Bill>_List;
	queue<Bill>Temp;
public:
	clsQueueLine(string pref,float MinuteForCleint) {
		this->_Pref = pref;
		this->_TotalTickts = 0;
		this->_MinuteForCleint = MinuteForCleint;
	}

	
	int getCountServedCleint() {
		return _CountServedCleint;
	}

	int getTotalTickts() {
		return _TotalTickts;;
	}

	string getPref() {
		return this->_Pref;
	}
	void setPref(string Name) {
		this->_Pref = Name;
	}
	int Size(){
		return _List.size();
	}
	
	void IssueTicket(){
		if (_CountServedCleint < 500)
		{
			_TotalTickts++;
			Bill bill(_Pref,getTotalTickts(),Size(), _MinuteForCleint);
			_List.push(bill);
			
		}
		else
		{
			cout << "the Systeam today is Full , Excause me \n";
		}

	}

	void ServedNextCleint() {
		if (!_List.empty())
		{
			_List.pop();
			_CountServedCleint++;
		}
		else
		{
			cout << "there are not cleint to Served \n";
		}

	}


	void PrintInfo(){
		cout << "\n\n\t\t\t\t\t===================================\n";
		cout << "\n\t\t\t\t\t Queue InFo \n\n";
		cout << "\t\t\t\t\t=======================================\n";
		cout << "\t\t\t\t\t PreFix = " << getPref() << endl;
		cout << "\t\t\t\t\t Total Tickets = " << getTotalTickts() << endl;
		cout << "\t\t\t\t\t Served Cleint = " << getCountServedCleint() << endl;
		cout << "\t\t\t\t\t Wating Cleint = " << Size() << endl;
		cout << "\n\n\t\t\t\t\t====================================\n";

	}

	void PrintTicketsLineRTL(){

		if (_List.empty())
		{
			cout <<"\n\t\t\t\t\t No Tickts Found \n";
				return;
		}
		Temp = _List;
		cout << "\n\t\t\t\t\t ";
		cout << "Tickts = ";
		while(!Temp.empty())
		{
			Bill bill = Temp.front();
			cout <<bill.FullName() << "<-- ";
			Temp.pop();
		}
		cout << endl;
	}

	void PrintTicketsLineLTR() {
		_Revers();
		cout << "\n\t\t\t\t\t ";
		cout << "Tickts = ";
		for (int i = 0; i < _List.size(); i++)
		{
			Bill bill = Temp.front();
			cout << "--> " << bill.FullName();
			Temp.pop();
		}
		cout << endl;
	}


	void PrintAllTickts() {
		queue<Bill>TempQueue = _List;
		for (int i = 0; i < _List.size(); i++)
		{
			Bill bill = TempQueue.front();
			bill.PrintBill();
			//bill.Print();
			TempQueue.pop();
		}
	}

	
};

