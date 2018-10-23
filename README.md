PROGRAM DESCRIPTION 

PROCESS:The  program employes queues to simulate customer processing at supermarket. Input has an unknown number of records which includes information about each customer i.e.: the customer's arrival time, FULL NAME and the amount of processing time.				         
The arrival time is the instant at which the customer enters one of three checkout lines. Each one represented by a queue.
Processing Time is the time it takes the checkout clerk to process the customer's purchases(includes all actions such as ringing up the sale, collecting the money, returning change, bagging the items purchased, etc.						              	
A customer’s Arrival Time of -99 will act as the sentinel  
The program is to process customers as they enter one of THREE (3)checkout line (each line being represented as a queue).The customer always wants to be processed as quickly as possible so the following rules apply:
1.  Each customer arrives at the “checkout area” at the appointed arrival time.		
2.  If a queue is empty, place the customer in the queue and begin to process the customer.							             
3.  If all queues have customers, place the customer in the queue with the shortest total processing time for that queue.In case of a       tie,select the queue with the LOWEST numeric value(i.e.queue1, queue2, then queue3).
4.  No processing is done until the customer is at the head of the queue.											                    
5.  Once a customer's processing time is zero, the customer leaves the store(i.e. remove the customer from the queue)
When scanning queues for adding, always start with #1 and proceed numerically to #2 then #3.							            
/****************************************************************/
OUTPUT:Output for this program is to consist of two lists.   
The first list is the order in whch the customers entered the queues(an echo print of the list of names as they entered the queues without arrival or processing times)The second list is the order in which each customer was processed(a list of customers as they leave the store. )
“Linked list” and "Structures" are used to maintain each list
Each list has a label and is printed out vertically	sidebyside												                          
/****************************************************************/
//* USER DEFINED                                                *
//* MODULES :									                      	     	    *
//*CashierClass():sets all the value of pointer and counters    *
//*               to null									                      *
//*inc_timer()   : Increase timer by 1				        	        * 
//*get_timer()   : Returns timer value							            *
//*inc_counter() : Increase counter by 1					            	*
//*get_counter() : Returns counter time						            	*
//*resetTimer()  : Resest timer to zero						            	*
//*~CashierClass():Deletes the queues							              *
//*IsFull()       :Check if the Queue is full					          *
//*First()        :returns the first node of the queue			    *
//* Last()        :returns the last node of the queue			      *
//*Add(NodeType*) : Adds a node to the Queue					          *
//*processTime()  : process time of front node of the queue		  *
//*print(ofstream): Print the Queue								              *
//*IsEmpty()      :Checks if the queue is empty					        *
//*Remove(NodeType*): Removes the top of the queue				      *
//*Addfinal(NodeType *, NodeType *): Adds the two Queue to one  *
//*						          linked list for the echo print          *
//*printFinal(ofstream &): Prints the two list side by side		  *
//***************************************************************
