#ifndef DEQUE
#define DEQUE

#include "node.h"




//===========================================================================
//  Deque Class
//===========================================================================

class Deque
    {
        private:
            Node* head;
            Node* tail;
    
        public:
                // Constructor
            Deque() { head = tail = NULL; }
            Deque(Node*);
            
                // Mutator functions
            void   enqueueHead(int, string, string, string, string, string);
            void   enqueueTail(int, string, string, string, string, string);
            string dequeueHead();
            string dequeueTail();
	    void   purgeDeque(){ head = tail = NULL; }
    
                //Accessor functions
            string displayAll();
	    string showHead(){return (head == NULL)?"Deque is Empty" : head->getData();}
	    string showTail(){return (tail == NULL)?"Deque is Empty" : tail->getData();}
            bool   find(int);
            bool   isEmpty(){return (head == NULL)?true:false;}
            int    position(int);
    };




Deque::Deque(Node* cur)
    {
        head = tail = cur;
    }




void Deque::enqueueHead(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
        Node* cur = new Node( clientID, firstName, lastName, destination, period, booking);
        
            // Is the Deque empty?
        if (head == NULL)
            {
                head = tail = cur;
                return;
            }
        else    // Add as the new head
            {
                cur->setNext(head);
                head = cur;
                return;
            }
    }




void Deque::enqueueTail(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
        Node* cur = new Node( clientID, firstName, lastName, destination, period, booking);

            // Is the Deque empty?
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




string Deque::dequeueHead()
    {
            // is the queue empty
        if (isEmpty())
            {
                return ("\n\nThe DEQUE is Empty...\n\n");
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





string Deque::dequeueTail()
    {
        string record;
    
            // is the queue empty
        if (isEmpty())
            {
                return ("\n\nThe DEQUE is Empty...\n\n");
            }
    
            // Is there ONLY one node in the queue
        if (head == tail)
            {
                record = head->getData();
                head = tail = NULL;
            }
        else
            {
                record = tail->getData();
            
                Node* temp;
            
                // walk down to the penultimate node
                for (temp = head; temp->getNext() != tail; temp = temp->getNext());
            
                delete tail;        // Delete the last node
                tail = temp;        // Re-assign the tail
                tail->setNext(NULL);
            }
        return record;
    }





string Deque::displayAll()
    {
        string str = "";
    
        if (head == NULL)
            return ("\nDeque is Empty...\n\n");
    
        for (Node* cur = head; cur != NULL; cur = cur->getNext())
            {
                str.append( cur->getData() );
                str.append("\n");
            }
        str.append("\nThe END\n\n");
        
        return str;
    }






bool Deque::find(int val)
    {
        for (Node* cur = head; cur != NULL; cur = cur->getNext())
            {
                if (cur->getID() == val)
                    return true;
            }
        return false;
    }





int Deque::position(int val)
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

