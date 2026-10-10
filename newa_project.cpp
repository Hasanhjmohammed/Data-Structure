#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<Map>
#include"clsPerson.h"
#include"clsDblLinkedList.h"
#include "InterfaceCommunction.h"
#include"clsMyQueue.h"
#include"clsMyStack.h"
#include"clsDynamicArray.h"
#include"clsMyQueueArr.h"
#include"clsMyStackArr.h"
#include"clsString.h"
#include"clsQueueLine.h"
using namespace std;
/*void PrintMasseg(string title) {
    cout << title << endl;
}
class Node
{
   
public:
    int _Date;
    Node* Next;
    Node* Prev;

};

void InsertAtBeginnen(Node* & head, int value) {

    
    Node* CurrentNode = new Node();
    CurrentNode->_Date = value;
    CurrentNode->Next = head;
    head = CurrentNode;
}
void PrintListNode(Node *Head) {
    while (Head!=NULL)
    {
        cout <<" Count = " << Head->_Date << endl;
        Head = Head->Next;
    }
}
void insertAfter(Node*& PrevNode, int value) {
    Node* CurrentNode = new Node();
    CurrentNode->_Date = value;
    CurrentNode->Next = PrevNode->Next;
    PrevNode->Next = CurrentNode;

}

void insertAfterDouble(Node*& PrevNode, int value) {
    Node* CurrentNode = new Node();
    CurrentNode->_Date = value;
    CurrentNode->Next = PrevNode->Next;
    CurrentNode->Prev = PrevNode;

    if (PrevNode->Next!=NULL)
    PrevNode->Next->Prev = CurrentNode;
    PrevNode->Next = CurrentNode;

}
void insertEnd(Node * & Head,int value){
    Node* CurrentNode = new Node();
    CurrentNode->_Date = value;
    CurrentNode->Next = NULL;
    if (Head == NULL)
    {
        Head = CurrentNode;
        return;
    }
    Node* LastNode = Head;
    while (LastNode->Next!=NULL)
    {
        LastNode = LastNode->Next;
    }
   
    LastNode->Next =  CurrentNode;
}
Node* Find(Node* head, int value) {
    Node* CurrentNode = head;
    while (CurrentNode !=NULL)
    {
        if (CurrentNode->_Date == value)
            return CurrentNode;
        CurrentNode = CurrentNode->Next;

    }
    return NULL;
}
void InsertDoubleEnd(Node * & head,int value ){
    Node* CurrentNode = new Node();
    CurrentNode->_Date = value;
    CurrentNode->Next = NULL;

    if (head == NULL)
    {
        CurrentNode->Prev = NULL;
        head = CurrentNode;
    }
    else
    {
        Node* prev = head;

        while (prev->Next != NULL)
        {
            prev = prev->Next;

        }
        prev->Next = CurrentNode;
        CurrentNode->Prev = prev;
    }
 


}
void DeletNode(Node* head, int value) {
    Node* Prev = head;
    Node* Current = head;
    if (head == NULL)
        return;
    if (Current->_Date == value)
    {
        head = Current->Next;
        delete Current;
        return;
    }
    while (Current->_Date!=value && Current!=NULL ) {
        Prev = Current;
        Current = Current->Next;
    }
    if (Current == NULL)
        return ;

    Prev->Next = Current->Next;
    delete Current;

}

void DeletNodeDouble(Node* head, int value) {
    Node* Prev = head;
    Node* Current = head;
    if (head == NULL)
        return;
    if (Current->_Date == value)
    {
        head = Current->Next;
        delete Current;
        return;
    }
    while (Current->_Date != value && Current != NULL) {
        Prev = Current;
        Current = Current->Next;
    }
    if (Current == NULL)
        return;

    Prev->Next = Current->Next;
    Current->Next->Prev = Prev;

    delete Current;

}

void DeletNodeDouble(Node* & head, Node* & NodeDelet){

    if (head == NULL || NodeDelet == NULL)
        return;
    if (head == NodeDelet)
    {
        head = NodeDelet->Next;
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


}
void DeletFirstNod(Node* &head) {
    Node* Current = head;
    if (head == NULL)return;

    head = Current->Next;
    delete Current;
    return;
}
void DeletFirstNodDouble(Node* & head) {
  
    if (head == NULL)
        return;

    Node* Current = head;
    if (Current != NULL)
    {
        Current->Next->Prev = NULL;
        head = Current->Next;
    }

    delete Current;
    return;
}
void DeletLastNod(Node*& head) {
    Node* Prev = head;
    Node* Current = head;
    if (head == NULL)
        return;
  
    while (Current->Next != NULL &&Current!=NULL) {
        Prev = Current;
        Current = Current->Next;
    }
    delete Current; 
    Prev->Next = NULL;
   
}
void DeletLastNodDouble(Node*& head) {
    if (head == NULL)
        return;
    if (head->Next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node* Current = head;
    while (Current->Next->Next!=NULL)
    {
        Current = Current->Next;
    }
    Node* temp = Current->Next;
    Current->Next = NULL;
    delete temp;


}

void InsertAtDoubleBeginning(Node* & Head, int value) {

   Node* CurrentNode = new Node();
   CurrentNode->_Date = value;
  
   CurrentNode->Next = Head;
   CurrentNode->Prev = NULL;
   if (Head != NULL)
       Head->Prev = CurrentNode;


   Head = CurrentNode;
}


struct MyStruct
{
    string name;
    int age;
};
union MyUnion
{
    int age;
    char jj;
  //  float salary;
   
};*/

int main()
{
    clsQueueLine PayBillsQueue("AI",10);
    clsQueueLine NewBillQueue("BX", 7);
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
 
    cout << "\n Pay Bills Queue Info \n";
    PayBillsQueue.PrintInfo();
    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintTicketsLineLTR();
    PayBillsQueue.PrintAllTickts();
    PayBillsQueue.ServedNextCleint();
    cout << "pay Bill After Served Cleint \n";
    PayBillsQueue.PrintInfo();
    PayBillsQueue.ServedNextCleint();
    PayBillsQueue.PrintInfo();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.PrintInfo();
    PayBillsQueue.PrintAllTickts();
    PayBillsQueue.PrintInfo();
    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintTicketsLineLTR();

 //   MyStruct sHasan;
 //   sHasan.name = "hasan";
 //   sHasan.age = 26;

 //   cout << &sHasan << endl;
 //   cout << &sHasan.name << endl;
 //   cout << &sHasan.age << endl;
 //   MyUnion hh;
 //   hh.age = 15;
 //   hh.jj = 'p' ;
 //  // hh.salary = 25.14;
 //   cout << "============================\n";
 //   cout << & hh.age << endl;
 //   cout << & hh.jj << endl;
 //  // cout << & hh.salary << endl;
 // /*  MyUnion uHasan;
 //   uHasan.name = "hasan";
 //   uHasan.age = 26;*/

 //   Node* Head;
 //   Head = NULL;
 //   Node* Node1 = new Node();
 //   Node* Node2 = new Node();
 //   Node* Node3 = new Node();
 //   Node* Node4 = new Node();

 //   Node1->_Date = 1;
 //   Node2->_Date = 2;
 //   Node3->_Date = 3;
 //   Node4->_Date = 4;
 //   Head = Node1;

 //   Node1->Prev = NULL;
 //   Node1->Next = Node2;
 //   Node2->Prev = Node1;
 //   Node2->Next = Node3;
 //   Node3->Prev=  Node2;
 //   Node3->Next = Node4;
 //   Node4->Prev = Node3;
 //   Node4->Next = NULL;

 ///*   while (Head!=NULL)
 //   {
 //       cout << Head->_Date<<endl;
 //       Head = Head->Next;

 //   }*/

 //  // InsertAtDoubleBeginning(Head, 250);

 //   //Node* N1 = Find(Head, 4);
 ///*   cout << N1->_Date << endl;
 //   if (N1 != NULL)
 //       cout << "the Node found :-)";
 //   else
 //   {
 //       cout << "Is Not Found  :-(";
 //   }*/

 //  // insertAfterDouble(N1, 300);
 //  // DeletNodeDouble(Head, Node4);
 //   cout << "\n_____________________________\n";
 //   map<string,int>mapping;

 //   mapping["Hasan"]  = 85;
 //   mapping["Jaffer"] = 74;
 //   mapping["Abbas"] = 96;
 //   mapping["jabber"] = 63;
 //   mapping["jamal"] = 56 ;

 //   for (auto pair : mapping)
 //       cout << pair.first << "  " << pair.second << endl;
 //   cout << "\n_____________________________\n";

 //   string name = "jabber";
 //   if (mapping.find(name) != mapping.end())
 //       cout << name << "  " << mapping[name] << endl;
 //   else
 //       cout << "the student is not found \n";
 //   
 //    name = "ma;s";
 //   if (mapping.find(name) != mapping.end())
 //       cout << name << "  " << mapping[name] << endl;
 //   else
 //       cout << "the student is not found \n";

 // /*  for (int i=0 ;i<mapping.size();i++)
 //   {
 //       cout << mapping[i] << endl;
 //       
 //   }*/


 // //  InsertDoubleEnd(Head, 780);
 //   //Head = Node1;
 //  /* DeletLastNodDouble(Head);
 //   while (Head != NULL)
 //   {
 //       cout << Head->_Date << endl;
 //       Head = Head->Next;
 //   }*/

    system("pause>0");

}

