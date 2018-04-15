#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>

class AVLNode
    {
      private:
            int     guestID;
            string  name;
            string  surname;
            string  country;
            string  season;
            string  trip;
	    int balance;	// 0 = Balanced; 1 = Right-heavy; -1 = Left-heavy
	    
       public:
            AVLNode* leftPtr;    // pointer to left subtree
            AVLNode* rightPtr;   // pointer to right subtree
        
            //Constructor functions
            AVLNode()   {leftPtr = NULL; rightPtr= NULL;}
            AVLNode(int, string, string, string, string, string);
        
            //Accessor functions
            int getClientID()    { return guestID; }
            string getName()	{ return name; }
            string getSurname()	{ return surname; }
            string getCountry()	{ return country; }
            string getSeason()	{ return season; }
            string getTrip()	{ return trip; }
            string getAllData();
            AVLNode* getLeftPtr()  { return leftPtr;}
            AVLNode* getRightPtr() { return rightPtr;}
			int getBalance()	{ return balance;}
        
            //Mutator functions
            void setClientID(long num)  { guestID = num;}
            void setName(string val)	{ name = val; }
            void setSurname(string val)	{ surname = val; }
            void setCountry(string val)	{ country = val; }
            void setSeason(string val)	{ season = val; }
            void setTrip(string val)	{ trip = val; }
            void setData(int, string, string, string, string, string);
            void setBalance(int bal)		{balance = bal;}
            void setLeftPtr(AVLNode* ptr)  { leftPtr = ptr;}
            void setRightPtr(AVLNode* ptr) { rightPtr = ptr;}
    };

    
    

AVLNode::AVLNode(int clientID, string firstName, string lastName, string destination, string period, string booking)
{
        guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
        leftPtr = NULL; 
        rightPtr= NULL;
} 
    

    
    
void AVLNode::setData(int clientID, string firstName, string lastName, string destination, string period, string booking)
{
       guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
} 
    
   
   
   
   
string AVLNode::getAllData()
{
        string record = to_string(guestID);
        record.append("\t");
        record.append(name);
        record.append("\t");
        record.append(surname);
        record.append("\t");
        record.append(country);
        record.append("\t");
        record.append(season);
        record.append("\t");
        record.append(trip);
        record.append("\n");
        return record;
        
        
}
   



   
   
   



class AVL
{
      private:
            AVLNode *rootPtr;
	
            // utility functions  - These helper functions take the root address of the tree (or sub tree)as their parameter
            void insertAVLNodeHelper( AVLNode**, int, string, string, string, string, string);
            string preOrderHelper( AVLNode* ) const;
            string inOrderHelper( AVLNode* ) const;
            string postOrderHelper( AVLNode* ) const;
            string deleteNodeHelper(AVLNode* &, long);
			
	    AVLNode * singleRotateLeft(AVLNode  * );
	    AVLNode * singleRotateRight(AVLNode * );
	    AVLNode * doubleRotateLeft(AVLNode  * );
	    AVLNode * doubleRotateRight(AVLNode * );

	    inline int height(AVLNode * pos) const; 	

	    inline int max(int a, int b) const;

	    string displayNodeHelper( AVLNode * ) const;
	
    public:
            AVL() { rootPtr = NULL; };
            void emptyAVL() { rootPtr = NULL; };
            void insertAVLNode(int, string, string, string, string, string);
            string preOrderTraversal() const;
            string inOrderTraversal() const;
            string postOrderTraversal() const;
            string displayNodes();
            
            
};


    
    
//Input: None
//Output: The nodes to be displayed
//Purpose: To display the nodes in the tree
string AVL::displayNodes( )
{
  return displayNodeHelper( rootPtr );
}


//Input: The root ptr
//Output: The nodes to be displayed
//Purpose: To display the nodes in the tree
string AVL::displayNodeHelper(AVLNode *ptr ) const
{
  string record;

  if ( ptr != NULL )
  {
    record.append(ptr->getAllData() );
    record.append(" [Left = ");
    record.append(" ]\n");

    if (ptr->leftPtr != NULL)
      record.append(ptr->leftPtr->getAllData());	
      record.append(" \t Right = ");
      record.append(" ]\n");

    if (ptr->rightPtr != NULL)
      record.append(ptr->rightPtr->getAllData());

    
    record.append(" ]\n");

    record.append(displayNodeHelper( ptr->leftPtr ));
    record.append(displayNodeHelper( ptr->rightPtr ));
  }

  return record;
}




void AVL::insertAVLNode(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
        insertAVLNodeHelper( &rootPtr, clientID, firstName, lastName, destination, period, booking);
    }



    
    


// This function receives a POINTER to a pointer so the POINTER can be modified.
void AVL::insertAVLNodeHelper( AVLNode** ptr, int clientID, string firstName, string lastName, string destination, string period, string booking)
{
        if ( *ptr == NULL )               // tree/sub-tree is empty
        {
           *ptr = new AVLNode(clientID, firstName, lastName, destination, period, booking);
        }
        else                              // tree is not empty
		{
			if ( clientID < ( *ptr )->getClientID() )
			{
				insertAVLNodeHelper( &( (*ptr)->leftPtr ), clientID, firstName, lastName, destination, period, booking);

					if(height((*ptr)->getLeftPtr()) - height((*ptr)->getRightPtr()) == 2)
					{
						if( clientID < (*ptr)->leftPtr->getClientID())
							(*ptr) = singleRotateLeft(*ptr);
						else
							(*ptr) = doubleRotateLeft(*ptr);
					}
			}
		else
		{
			if ( clientID > ( *ptr )->getClientID() )
			{
				insertAVLNodeHelper( &( ( *ptr )->rightPtr ), clientID, firstName, lastName, destination, period, booking);
					if(height((*ptr)->getRightPtr()) - height((*ptr)->getLeftPtr()) == 2)
					{
						if( clientID > (*ptr)->rightPtr->getClientID())
							(*ptr) = singleRotateRight(*ptr);
						else
							(*ptr) = doubleRotateRight(*ptr);
					}
			}
		}
		}

	(*ptr)->setBalance( max(height((*ptr)->getLeftPtr() ),height((*ptr)->getRightPtr()))+1);

}
  


//Input: None
//Output: Displays all nodes 
//Purpose: Goes through the tree and display all nodes using the in order method
string AVL::inOrderTraversal() const
    {
        string record = inOrderHelper( rootPtr );

        if (record.empty()) 
            record.append("Tree is empty...\n\n");
        
        return record;
    }


//Input: the root address of the node
//Output: Displays all nodes 
//Purpose: Goes through the tree and display all nodes using the in order method
string AVL::inOrderHelper(AVLNode* ptr ) const
{
        string record;
    
        if ( ptr != NULL )
            {
                record = inOrderHelper( ptr->leftPtr );	
                record.append( ptr->getAllData() );
                record.append(inOrderHelper( ptr->rightPtr ) );
            }
        return record;
}


string AVL::preOrderTraversal() const
    {
        string record = preOrderHelper( rootPtr );
	
        if (record.empty())
            record.append("Tree is empty...\n\n");
	
        return record;
    }

    
    

string AVL::preOrderHelper(AVLNode* ptr ) const
    {
        string record;
        
        if ( ptr != NULL )
            {
                record = ptr->getAllData();
                record.append(preOrderHelper( ptr->leftPtr) );
                record.append(preOrderHelper( ptr->rightPtr) );
            }
        return record;
    }
    




    
 //Input: None
//Output: Displays all nodes 
//Purpose: Goes through the tree and display all nodes using the post order method   
string AVL::postOrderTraversal() const
    {
         string record = postOrderHelper( rootPtr );
        
        if (record.empty()) 
            record.append("Tree is empty...\n\n");
        
        return record;
    }





//Input: the root address of the node
//Output: Displays all nodes 
//Purpose: Goes through the tree and display all nodes using the post order method
string AVL::postOrderHelper( AVLNode* ptr ) const
    {
        string record;
    
        if ( ptr != NULL )
            {		
                record = postOrderHelper( ptr->leftPtr );		
                record.append( postOrderHelper( ptr->rightPtr ) );	
                record.append( ptr->getAllData() );
            }
        return record;
    }


    
    
//Input: root ptr
//Output: The left child
//Purpose: to perform a single left rotation on a node in the tree
AVLNode* AVL::singleRotateLeft(AVLNode* ptr)
{
  AVLNode* leftChild = ptr->getLeftPtr();

  ptr->setLeftPtr(leftChild->getRightPtr());
  leftChild->setRightPtr(ptr);

  ptr->setBalance(max(height(ptr->getLeftPtr()), height(ptr->getRightPtr()))+1);
  leftChild->setBalance(max(height(leftChild->getLeftPtr()), ptr->getBalance()+1));

  return leftChild;
}



//Input: root ptr
//Output: The right child
//Purpose: to perform a single right rotation on a node in the tree
AVLNode * AVL::singleRotateRight(AVLNode *ptr)
{
  AVLNode* rightChild = ptr->getRightPtr();
  ptr->setRightPtr(rightChild->getLeftPtr());
  rightChild->setLeftPtr(ptr);

  ptr->setBalance( max(height(ptr->getLeftPtr()), height(ptr->getRightPtr()))+1);
  rightChild->setBalance (max(height(rightChild->getRightPtr()), ptr->getBalance()+1));

  return rightChild;  // new root
}



//Input: root ptr
//Output: The left child
//Purpose: to perform a double left rotation on a node in the tree
AVLNode * AVL::doubleRotateLeft(AVLNode *ptr)
{
  ptr->setLeftPtr(singleRotateRight(ptr->getLeftPtr()));

  return singleRotateLeft(ptr);
}



//Input: root ptr
//Output: The right child
//Purpose: to perform a double left rotation on a node in the tree
AVLNode * AVL::doubleRotateRight(AVLNode *ptr)
{
  ptr->setRightPtr(singleRotateLeft(ptr->getRightPtr()));

  return singleRotateRight(ptr);
}


inline int AVL::height( AVLNode * ptr ) const
{
  if( ptr == NULL ) 
    return -1;
  else 
    return ptr->getBalance();
}


inline int AVL::max( int a, int b ) const
{
  return a > b ? a : b;
}
    


	
#endif


