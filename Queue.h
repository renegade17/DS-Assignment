
#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

//===========================================================================
//  Queue Class
//===========================================================================

class Queue
    {
        private:
            Node* head;
            Node* tail;
    
        public:
                // Constructor
            Queue() { head = tail = NULL; }
            Queue(Node*);
            
                // Mutator functions
            
            void   enqueueTail(int, string, string, string, string, string);
            string dequeueHead();
            string queueTail();
	    
           
	    void   purgeQueue(){ head = tail = NULL; }
    
                //Accessor functions
            string displayAll();
	    string showHeadQueue(){return (head == NULL)?"Queue is Empty" : head->getData();}
	    string showTailQueue(){return (tail == NULL)?"Queue is Empty" : tail->getData();}
            bool   find(int);
            bool   isEmpty(){return (head == NULL)?true:false;}
            int    position(int);
    };




Queue::Queue(Node* cur)
    {
        head = tail = cur;
    }





    


void Queue::enqueueTail(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
        Node* cur = new Node( clientID, firstName, lastName, destination, period, booking);

            // Is the Queue empty?
        if (head == NULL)
            {
                head = tail = cur;
                return;
            }
        else  // Add as the new tail
            {
                tail->setNext(cur);
                tail = cur;
                return;
            }
    }

string Queue::dequeueHead()
    {
            // is the queue empty
        if (isEmpty())
            {
                return ("\n\nThe QUEUE is Empty...\n\n");
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



string Queue::displayAll()
    {
        string str = "";
    
        if (head == NULL)
            return ("\nQueue is Empty...\n\n");
    
        for (Node* cur = head; cur != NULL; cur = cur->getNext())
            {
                str.append( cur->getData() );
                str.append("\n");
            }
        str.append("\nThe END\n\n");
        
        return str;
    }






bool Queue::find(int val)
    {
        for (Node* cur = head; cur != NULL; cur = cur->getNext())
            {
                if (cur->getID() == val)
                    return true;
            }
        return false;
    }





int Queue::position(int val)
    {
        int kount = 1;
        for (Node* cur = head; cur != NULL; cur = cur->getNext())
            {
                if (cur->getID() == val)
                    return kount;
                else
                    kount++;
            }
        return 0;
        
    }


#endif

