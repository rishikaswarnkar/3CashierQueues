#include "CashierClass.h"
#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;
/*************************************/
CashierClass::CashierClass()
{
	//Receives - Nothing
	//Task     - sets all the value to null
	//Returns  - Nothing
	front1 = NULL;
	rear = NULL;
	r = NULL;
	f = NULL;
	timer = 0;
}
/************************************/
void CashierClass::inc_timer()
{
	//Receives - Nothing
	//Task     - Increase timer by 1 
	//Returns  - Nothing 
	timer++;
}
/*************************************/
int CashierClass::get_timer()
{
	//Receives - Nothing
	//Task     - Nothing 
	//Returns  - Timer Value
	return timer;
}
/************************************/
void CashierClass::inc_counter()
{
	//Receives - Nothing
	//Task     - Increase counter by 1 
	//Returns  - Nothing 
	counter++;
}
/*************************************/
int CashierClass::get_counter()
{
	//Receives - Nothing
	//Task     - Nothing 
	//Returns  - Counter Value
	return counter;
}
/***********************************/
void CashierClass::resetTimer()
{
	//Receives - Nothing
	//Task     - To reset timer to 0 
	//Returns  - Nothing 
	timer = 0;
}
/***********************************/
CashierClass::~CashierClass()
{
	//Receives - Nothing
	//Task     - Deletes the queue
	//Returns  - Nothing
	NodeType * temp;
	while (front1 != NULL)
	{
		temp = front1;
		front1 = front1->next;
		delete temp;
	}
}
/***********************************/
bool CashierClass::IsFull()
{
	//Receives - Nothing
	//Task     - Check if the Queue is full 
	//Returns  - Nothing
	NodeType *temp = new NodeType;
	if (temp == NULL)
	{
		delete temp;
		cout << "Out of Space" << endl;
		return true;
	}
	return false;
}
/***********************************/
NodeType * CashierClass::First()
{
	//Receives - Nothing
	//Task     - Nothing
	//Returns  - Returns the first of the queue 
	return front1;
}
/***********************************/
NodeType * CashierClass::Last()
{
	//Receives - Nothing
	//Task     - Nothing
	//Returns  - Returns rear of the Queue 
	return rear;
}
/***********************************/
bool CashierClass::Add(NodeType *freshNode)
{
	//Receives - Nothing
	//Task     - Adds a node to the Queue
	//Returns  - Nothing 
	NodeType * temp = new NodeType;
	cout << freshNode->name;
	cout << freshNode->pt << endl;
	temp->at = freshNode->at;
	temp->name = freshNode->name;
	temp->pt = freshNode->pt;
	temp->next = NULL;
	if (IsFull())
		return false;
	if (front1 == NULL)
	{
		front1 = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
	return true;
}
/************************************/
int CashierClass::processTime()
{
	//Receives - Nothing
	//Task     - Nothing
	//Returns  - process time of front node of the queue
	return First()->pt;
}
/***********************************/
void CashierClass::print(ofstream &fout)
{
	//Receives - Nothing
	//Task     - Print the Queue
	//Returns  - Nothing 
	fout << "********************" << endl;
	do
	{
		fout << front1->name;
		fout << endl;
		front1 = front1->next;
		if (front1 == NULL)
		{
			cout << "temp is null pointer" << endl;
			return;
		}
	} while (front1 != NULL);
}
/***********************************/
bool CashierClass::IsEmpty()
{
	//Receives - Nothing
	//Task     - Checks if the queue is empty
	//Returns  - Nothing 
	if ((front1 == NULL) || (front1->name == "Too Many            "))
		return true;
	else
		return false;
}
/*****************************************/
bool CashierClass::Remove(NodeType *Node)
{
	//Receives - NodeType Node Pointer
	//Task     - Removes the top of the queue
	//Returns  - Nothing 
	if (IsEmpty())
	{
		cout << "Q is empty cant remove" << endl;
		return false;
	}
	NodeType * temp = new NodeType;
	//delete the node
	temp = front1;
	front1 = front1->next;
	//cout << "The new front is " << front1->name << endl;
	return true;
}
/****************************************/
bool CashierClass::Addfinal(NodeType *freshNode, NodeType *t)
{
	//Receives - Two pointer of two Queues
	//Task     - Add to the Queue
	//Returns  - Nothing 
	cout << "Inside add final" << endl;
	OutputQueue * temp = new OutputQueue;
	cout << freshNode->name;
	cout << t->name;


	temp->namea = freshNode->name;
	temp->nameb = t->name;
	temp->n = NULL;
	cout << temp->namea;// = freshNode->name;
	cout << temp->nameb;
	if (IsFull())
		return false;
	if (f == NULL)
	{
		f = temp;
		r = temp;
	}
	else
	{
		r->n = temp;
		r = temp;
	}
	return true;
}
/****************************************/
void CashierClass::printFinal(ofstream &fout)
{
	//Receives - Nothing
	//Task     - Print the Queue
	//Returns  - Nothing 
	fout << "The order of customer arrival is :" << setw(5) 
		<< "The order of customer departure is :" << endl;
	fout << "--------------------------------" << "|" 
		<< "--------------------------" << endl;
	do
	{
		fout << f->namea << setw(13) << "|" << "        " << setw(15) << f->nameb;
		fout << endl;
		f = f->n;
		if (f == NULL)
		{
			cout << "temp is null pointer" << endl;
			return;
		}
	} while (f != NULL);
}
/****************************************************************/