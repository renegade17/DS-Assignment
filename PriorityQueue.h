#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "node.h"


class PriorityQueue
    {
	private:
	      Node* head;
	      Node* tail;
	      
	public:
	      PriorityQueue(){head = tail = NULL;}		//Constructor for Priority Queue
	    
          
	      //Mutator functions
	      void   enqueuePQ(int, string, string, string, string, string);
	      string dequeuePQ();
	      
	      
	      void   purgePQ(){ head = tail = NULL; }
	      
	      
	      //accessor functions
	      string displayAll();
	      bool find(int);
	      int sizePriorityQueue();
	      string showHead(){return (head == NULL)?"PriorityQueue is Empty" : head->getData();}
	      string showTail(){return (tail == NULL)?"PriorityQueue is Empty" : tail->getData();}
	      bool   isEmpty(){return (head == NULL)?true:false;}
    };



void PriorityQueue::enqueuePQ(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
	Node* temp = new Node(clientID, firstName, lastName, destination, period, booking);
	
	if (head == NULL)			//PriorityQueue is empty
	  {
	      head = temp;
	      return;
	  }
      
	if (head->getID() > clientID)		//New node first in PriorityQueue
	  {
	      temp->setNext(head);
	      head = temp;
	      return;
	  }
      
	Node* cur = head->getNext();
	Node* pre = head;
	
	
	while((cur != NULL) && (cur->getID() < clientID))
	  {
	      pre = cur;
	      cur = cur->getNext();
	  }

      if (cur == NULL)		//End reached
	  {
	    pre->setNext(temp);
	    return;
	  }
	
      temp->setNext(cur);
      pre->setNext(temp);
      return;
    }



    
    
    

string PriorityQueue::dequeuePQ()
    {
	   // is the queue empty
        if (isEmpty())
            {
                return ("\n\nThe PriorityQueue is Empty...\n\n");
            }
    
        string record;
    
            // Is there ONLY one node in the queue
        if (head == tail)
            {
                record = head->getData();
                head = tail = NULL;
                return record;
            }
        else
            {
                record = head->getData();
                Node* temp = head;
                head =  head->getNext();
                delete temp;
                return record;
            }
    }   


    
    
    
    
string PriorityQueue::displayAll()
    {

    
        if (head == NULL)
	  {
            return ("\nPriorityQueue is Empty...\n\n");
	  }
	string str = "Displaying Priority Queue:\n\n";
        for (Node* cur = head; cur != NULL; cur = cur->getNext())
            {
                str.append( cur->getData() );
                str.append("\n");
            }
        str.append("\nThe END\n\n");
        
        return str;
 
    }



    
    
    
bool PriorityQueue::find(int clientID)
  {
     if (head == NULL)
	return false;
    else
	{
	    Node* temp = head;
	    while(temp != NULL)
		{
		    if (temp->getID() == clientID)
			return true;
		    temp = temp->getNext();
		}
	    return false;
	}
  }
 
 
 
 
 
 
 
int PriorityQueue::sizePriorityQueue()
    {
	int kount = 0;
      
	Node* temp = head;
	while (temp != NULL)
	    {
		kount++;
		temp = temp->getNext();
	    }
	return kount;
    }

    
    
 

#endif
