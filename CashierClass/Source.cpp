//************ PROGRAM IDENTIFICATION  ************************
//*                                                           *
//*PROGRAM FILE NAME: Source.cpp  Assisgnment #:3			  *
//*                                                           *
//* PROGRAM AUTHOR:    _________________________              *
//*                        Rishika Swarnkar                   *
//*                                                           *
//*COURSE: CSC 36000 11        Due: Feb 26,2018               *
//*                                                           *
//**************************************************************

//*************** PROGRAM DESCRIPTION ***************************
//*                                                             *
//PROCESS:The  program employes queues to simulate customer     * 
//*processing at supermarket. Input has an unknown number of    *
//*records which includes information about each customer i.e.: *
//*the customer's arrival time, FULL NAME and the amount of     *
//*processing time.											    *
//*The arrival time is the instant at which the customer enters *
//*one of three checkout lines. Each one represented by a queue *
//*Processing Time is the time it takes the checkout clerk to   *
//*process the customer's purchases(includes all actions such as*
//*ringing up the sale, collecting the money, returning change, *
//*bagging the items purchased, etc.							*                          
//*A customer’s Arrival Time of -99 will act as the sentinel    *
//*The program is to process customers as they enter one of THREE (3)
//*checkout line (each line being represented as a queue).Each customer always wants
//*to be processed as quickly as possible so the following rules apply:
//*1.  Each customer arrives at the “checkout area” at the appointed arrival time.
//*2.  If a queue is empty, place the customer in the queue and begin to process the customer.
//*3.  If all queues have customers, place the customer in the queue with the shortest 
//*    total processing time for that queue.In case of a tie, select the queue with 
//* the LOWEST numeric value(i.e.queue1, queue2, then queue3).
//*	4.  No processing is done until the customer is at the head of the queue. 
//*	5.  Once a customer's processing time is zero, the customer leaves the store
//*(i.e. remove the customer from the queue.)
//*When scanning queues for adding, always start with #1 and proceed numerically to #2 then #3.
/**************************************************/
//*OUTPUT:Output for this program is to consist of two lists.
//*The first list is the order in whch the customers entered the queues
//*(an echo print of the list of names as they entered the queues without arrival or 
//*processing times).The second list is the order in which each customer was processed
//*(a list of customers as they leave the store.)  
//* “linked list” to maintain each list.
//*Each list has a label and is printed out vertically sidebyside 
/***********************************************/
//* USER DEFINED                                                     *
//* MODULES :														 *
//*CashierClass():sets all the value of pointer and counters to null *
//*inc_timer()   : Increase timer by 1									 *
//*get_timer()   : Returns timer value
//*inc_counter() : Increase counter by 1
//*get_counter() : Returns counter time 
//*resetTimer()  : Resest timer to zero
//*~CashierClass():Deletes the queues
//*IsFull()       :Check if the Queue is full
//*First()        :returns the first node of the queue
//* Last()        :returns the last node of the queue
//*Add(NodeType*) : Adds a node to the Queue   
//*processTime()  : process time of front node of the queue
//*print(ofstream): Print the Queue
//*IsEmpty()      :Checks if the queue is empty
//*Remove(NodeType*): Removes the top of the queue
//*Addfinal(NodeType *, NodeType *): Adds the two Queue to one linked list 
//*							for the echo print
//*printFinal(ofstream &): Prints the two list side by side
//***************************************************************
#include "CashierClass.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	CashierClass q1, r1; // The main Queue where all coustmer stand to be processed
	CashierClass cashier1, cashier2, cashier3; // The three cashier Queues 
	CashierClass CustOut, InputQueue, FinalQueue;//One output Queue
	char flaga = 'n', flagb = 'n', flagc = 'n'; // Flags for all Cashiers set to 'n'
	int serva = 0, servb = 0, servc = 0;
	
	fstream infile;
	infile.open("queue_in.txt");// open input File

	ofstream fout;
	fout.open("final.txt");// open output File

	NodeType *Node = new NodeType; // Node pointer to create a Queue 
	do
	{
		infile >> Node->at >> ws;
		getline(infile, Node->name);
		infile >> ws;
		infile >> Node->pt;
		q1.Add(Node);
	} while (!infile.eof());
	// The main Queue has been created 
	//NodeType *cust = new NodeType; 
	while (!q1.IsEmpty())
	{
		cashier1.inc_timer();
		cashier2.inc_timer(); 
		cashier3.inc_timer();
		cashier1.inc_counter();
		cashier2.inc_counter();
		cashier3.inc_counter();
		//if (cashier1.get_counter() == q1.First()->at)
		if ((serva <= servb) && (serva <= servc))

		{
			if (flaga == 'n')
			{
				cout << " Add to Cahsier1 " << endl;
				cashier1.Add(q1.First());
				serva = serva + q1.First()->pt;
				flaga = 'y';
				//removing customer from Main Queue
				if (!q1.IsEmpty())
				{
					InputQueue.Add(q1.First());
					q1.Remove(q1.First());
				}
			}
		}
		if ((servb <= serva) && (servb <= servc))// checks service time
		{
			if (flagb == 'n')
			{
				cout << "Add to Cashier 2  " << endl;
				cashier2.Add(q1.First());
				servb = servb + q1.First()->pt;
				flagb = 'y';
				//removing customer from input we added to queue
				if (!q1.IsEmpty())
				{
					InputQueue.Add(q1.First());
					q1.Remove(q1.First());
				}
			}
		}
		//if (cashier3.get_counter() == q1.First()->at)
		if ((servc <= serva) && (servc <= servb))
		{
			if (flagc == 'n')
			{
				cout << "add to cashier 3 " << endl;
				cashier3.Add(q1.First());
				servc = servc + q1.First()->pt;
				flagc = 'y';
				//removing customer from input we added to queue
				if (!q1.IsEmpty())
				{
					InputQueue.Add(q1.First());
					q1.Remove(q1.First());
				}
			}
		}
		if (!cashier1.IsEmpty())
		{
			if (cashier1.get_timer() == cashier1.processTime())
			{
				cout << " Cashier  1 " << endl;
				serva = serva - cashier1.processTime();
				CustOut.Add(cashier1.First());
				cashier1.Remove(cashier1.First());
				cashier1.resetTimer();
				flaga = 'n';
			}
		}
		if (!cashier2.IsEmpty())
		{
			if (cashier2.get_timer() == cashier2.processTime())
			{
				servb = servb - cashier2.processTime();
				CustOut.Add(cashier2.First());
				cashier2.Remove(cashier2.First());
				cashier2.resetTimer();
				flagb = 'n';
			}
		}
		if (!cashier3.IsEmpty())
		{
			if (cashier3.get_timer() == cashier3.processTime())
			{
				cout << "Cashier 3" << endl;
				servc = servc - cashier3.processTime();
				CustOut.Add(cashier3.First());
				cashier3.Remove(cashier3.First());
				cashier3.resetTimer();
				flagc = 'n';
			}
		}
	};
	while ((!InputQueue.IsEmpty()) && (!CustOut.IsEmpty()))
	{
		r1.Addfinal(InputQueue.First(), CustOut.First());
		InputQueue.Remove(InputQueue.First());
		CustOut.Remove(CustOut.First());
	};
	r1.printFinal(fout); // final print 
	infile.close();
	fout.close();
	system("pause");
	return 0;
}