#ifndef STACK_H
#define STACK_H

#include "node.h"

class Stack
{

//Data members
private:
  Node* Summit;	//Last Node
  Node* Peak;	//First Node

public:

	Stack(void){Summit = NULL, Peak = NULL;}		//Constructor for Stack
  
		//Mutator functions
          string popStack();
	      void pushStack(int, string, string, string, string, string);
	      void purgeStack(){ Peak = Summit = NULL; }		// Flush the Stack
		  
		  
		//Accessor functions
	      string displayStack();
          string showHeadStack(){return (Peak == NULL)?"Stack is Empty" : Peak->getData();}
	      string showTailStack(){return (Summit == NULL)?"Stack is Empty"
          :Summit->getData();}
	      bool   isEmpty(){return (Peak == NULL)?true:false;}
	      
	      
  
}; //end class Stack



string Stack::popStack()
{
		if (Peak==NULL)
            {
                return ("\n\nThe Stack is Empty...\n\n");
            }
		
    
            // Is there ONLY one node in the queue
	    else
            {
	      if (Peak == Summit)
	      {
		string record;
	      
                record = Peak->getData();
                Peak = NULL;
		delete Summit;
		Summit=Peak;
                return record;
	      }
            
        else
            {
		string record;
		Node* temp;
		temp = Peak;
		Peak=Peak->getNext();
		record= temp->getData();
                delete temp;
                return record;
            }
	    }
 }

 void Stack::pushStack( int clientID, string firstName, string lastName, string destination, string period, string booking)
{
	Node* newNode = new Node(clientID, firstName, lastName, destination, period, booking);

		if (Peak == NULL)       //Stack is empty
		{
			Peak = newNode;
			Summit = Peak;
			
	

			return;
		}

	newNode->setNext(Peak);
	Peak = newNode;

  return;
}




 
string Stack::displayStack()
{
	string str = "";
    
        if (Peak == NULL)
            return ("\nStack is Empty...\n\n");
    
        for (Node* cur = Peak; cur != NULL; cur = cur->getNext())
            {
                str.append( cur->getData() );
                str.append("\n");
            }
        str.append("\nThe END\n\n");
        
        return str;
 
}


#endif
