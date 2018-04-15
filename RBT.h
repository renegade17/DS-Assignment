
#ifndef RBTREE_H
#define RBTREE_H

#include <string>
#include <sstream>

class RBTNode
    {
        private:
            int     guestID;
            string  name;
            string  surname;
            string  country;
            string  season;
            string  trip;
            string color;
    
        public:
            RBTNode* left;
            RBTNode* right;
            RBTNode* parent;

            // Constructor functions
            RBTNode(){right = left = parent= NULL; color = "RED";}
            RBTNode(int, string, string, string, string, string);
             

	    // Accessor functions
            int     getID()         { return guestID; }
            string  getName()       { return name; }
            string  getSurname()    { return surname; }
            string  getCountry()    { return country; }
            string  getSeason()     { return season; }
            string  getTrip()       { return trip; }
            string getAllData();
            string getAllDataRBT();
            string strip(string);	
            string getColor(){return color;}
			
			
            // Mutator functions
            void setID(int num)              { guestID = num; }
            void setName(string str)         { name = str; }
            void setSurname(string str)      { surname = str; }
            void setCountry(string str)      { country = str; }
            void setSeason(string str)       { season = str; }
            void setTrip(string str)         { trip = str; }
            void setData(int, string, string, string, string, string);	
            void setColor(string col){color = col;}


     };

RBTNode::RBTNode(int clientID, string firstName, string lastName, string destination, string period, string booking)
{
        guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
   
   color = "RED";
   
   left = NULL;
   right = NULL;
   parent = NULL;
}//RBTNode




void RBTNode::setData(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
         guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
    } 
    
    
string RBTNode::getAllData()
    {
        string str = "";
      
    
        stringstream numStr;
        numStr << getID();
        str.append(numStr.str());
    
        str.append("\t");
        str.append(strip(getName()));	
        str.append("\t");
        str.append(strip(getSurname()));
        str.append("\t");
        str.append(strip(getCountry()));
        str.append("\t");
        str.append(strip(getSeason()));
        str.append("\t");
        str.append(strip(getTrip()));	
        str.append("\n");
        
        return str;
    }
    
string RBTNode::getAllDataRBT()
    {
        string str = "";
	string child;  
	
	stringstream leftChild;	
	stringstream rightChild;	
	
	
        stringstream numStr;
        numStr << getID();
        str.append(numStr.str());
    
        str.append("\t");
        str.append(strip(getName()));	
        str.append("\t");
        str.append(strip(getSurname()));
        str.append("\t");
        str.append(strip(getCountry()));
        str.append("\t");
        str.append(strip(getSeason()));
        str.append("\t");
        str.append(strip(getTrip()));	
        str.append("\n");
        str.append("[ ");
        str.append(strip(getColor())); 
        str.append(" ]");
        str.append("\t");
	
	if (left != NULL && right != NULL) //No ptr's are NULL
	{
	  child.append("[ ");
	  leftChild << left->getID();
	  child.append(leftChild.str());
	  child.append(" , ");
	  
	  rightChild << right->getID();
	  child.append(rightChild.str());
	  child.append(" ]");
	  
	  //Add left & right ptr IDs to str
	  str.append(child);
	  str.append("\n");
	}
	
	if (left == NULL && right != NULL) //left ptr is NULL
	{
	  child.append("[ NULL");
	  child.append(" , ");
	  rightChild << right->getID();
	  child.append(rightChild.str());
	  child.append(" ]");
	  
	  //Add left & right ptr IDs to str
	  str.append(child);
	  str.append("\n");
	}
	
	
	if (left != NULL && right == NULL) //right ptr is NULL
	{
	  child.append("[ ");
	  leftChild << left->getID();
	  child.append(leftChild.str());
	  child.append(" , ");
	  child.append("Null ]");
	  
	  //Add left & right ptr IDs to str
	  str.append(child);
	  str.append("\n");
	}
	
	if (left == NULL && right == NULL) //both left & right are NULL
	{
	  str.append("[ NULL , NULL ]");
	  str.append("\n");
	}
        
        
        return str;
    }    
  
string RBTNode::strip(string str)
   {
      for (unsigned int x = 0; x < str.size(); x++)
      if ( (!isalpha(str[x]) ) && (str[x] != '-') && (str[x] != ' ') )
	  str[x] = ' ';

      return str; 
   }
   



class RBT
    {
        private:
            RBTNode* root;
    
            // Utility functions
            void     rotateLeft( RBTNode* );
            void     rotateRight(RBTNode* );
            void     fixUp(RBTNode* );
            string   inOrderHelper(RBTNode* );
            string   preOrderHelper(RBTNode* );
            string   postOrderHelper(RBTNode* );
            string   deleteNode(RBTNode* );
            RBTNode* findNode(int);
            RBTNode* getMinimum(RBTNode *);
            RBTNode* getSuccessor(RBTNode *);
    
        public:
            // Constructor function
            RBT(){ root = NULL;}
    
            // Mutator functions
            void   insertRBT(int, string, string, string, string, string);
            string remove( int );
	    void   emptyRBT() { root = NULL;}
	    
            // Accessor functions
            string inOrder(){ return inOrderHelper(root); }
            string preOrder(){ return preOrderHelper(root); };
            string postOrder(){ return postOrderHelper(root); };
            string showLevels();
     };





void RBT::rotateLeft( RBTNode* ptr )
	{
        RBTNode* rightChild = ptr->right;
        ptr->right = rightChild->left;
        
        if (rightChild->left != NULL)
            rightChild->left->parent = ptr;
        
        rightChild->parent = ptr->parent;
        
        if (ptr == root)
            root = rightChild;
        else
            {
                if( ptr == ptr->parent->left)
                    ptr->parent->left = rightChild;
                 else
                    ptr->parent->right = rightChild;
            }
    
        rightChild->left = ptr;
        ptr->parent = rightChild;
 	}


 	
void RBT::rotateRight(RBTNode* ptr)
	{
        RBTNode* leftChild = ptr->left;
        ptr->left = leftChild->right;
        
        if (leftChild->right != NULL)
            leftChild->right->parent = ptr;
        
        leftChild->parent = ptr->parent;
        
        if (ptr == root)
            root = leftChild;
        else
            {
                if( ptr == ptr->parent->right)
                    ptr->parent->right = leftChild;
                 else
                    ptr->parent->left = leftChild;
            }
    
        leftChild->right = ptr;
        ptr->parent = leftChild;
    
    }


    

RBTNode* RBT::findNode(int clientID)
	{
		RBTNode* ptr = root;
		
		while ( ptr != NULL )
            {
                if  (ptr->getID() == clientID)        // Found it!
                    {
                        return ptr;
                    }
            
                if (clientID < ptr->getID() )
                    ptr = ptr->left;
                else 
                    ptr = ptr->right;
            }
    
        return NULL;            // Tree is empty OR did not find it
	}


	
	

void RBT::insertRBT(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
    
        RBTNode* newnode = new RBTNode(clientID, firstName, lastName, destination, period, booking);      // Create the new node
        
        if (root == NULL)                   // Tree is empty - newnode is first node
            {
                newnode->setColor("BLACK");
                root = newnode;
                return;
            }
        else                                // Tree is NOT empty
            {
                RBTNode* ancestor = NULL;
                RBTNode* current = root;
                while (current != NULL)
                    {
                        ancestor = current;
                        
                        if ( newnode->getID() < current->getID() )
                            current = current->left;
                        else
                            current = current->right;
                    }
            
                newnode->parent = ancestor;
                
                if ( newnode->getID() < ancestor->getID() )
                    ancestor->left = newnode;
                else
                    ancestor->right= newnode;
            
                fixUp(newnode);
            }
	}




void RBT::fixUp( RBTNode *ptr )
    {
        RBTNode *ptrsUncle = NULL;
    
        while ( ptr != root && ptr->parent->getColor() == "RED" )
            {
                if ( ptr->parent == ptr->parent->parent->left )
                    {       // ptr's parent is a LEFT child
                        ptrsUncle = ptr->parent->parent->right;
                        
                        if (  ptrsUncle != NULL && ptrsUncle->getColor() == "RED" )
                            {
                                ptr->parent->setColor("BLACK");
                                ptrsUncle->setColor("BLACK");
                                ptr->parent->parent->setColor("RED");
                                ptr = ptr->parent->parent;
                            }
                        else
                            {
                                if ( ptr == ptr->parent->right )
                                    {
                                        ptr = ptr->parent;
                                        rotateLeft( ptr );
                                    }
                                
                                ptr->parent->setColor("BLACK");
                                ptr->parent->parent->setColor("RED");
                                rotateRight( ptr->parent->parent );
                            }
                    }
                else            // ptr's parent is a RIGHT child
                    {
                        ptrsUncle = ptr->parent->parent->left;
                        
                        if ( ptrsUncle != NULL && ptrsUncle->getColor() == "RED" )
                            {
                                ptr->parent->setColor("BLACK");
                                ptrsUncle->setColor("BLACK");
                                ptr->parent->parent->setColor("RED");
                                ptr = ptr->parent->parent;
                            }
                        else
                            {
                                if ( ptr == ptr->parent->left )
                                    {
                                        ptr = ptr->parent;
                                        rotateRight( ptr );
                                    }
                                ptr->parent->setColor("BLACK");
                                ptr->parent->parent->setColor("RED");
                                rotateLeft( ptr->parent->parent );
                            }
                    }
            }
        
        root->setColor("BLACK");
        
        ptrsUncle = NULL;
    }

    
    

    
string RBT::remove(int clientID)
    {
        RBTNode* markedNode = findNode(clientID);
        return deleteNode(markedNode);
    }

    
    


string RBT::deleteNode(RBTNode* node2Zap)
    {
        if (node2Zap == NULL)    //If node being deleted is NULL then do nothing.
            return ("\nRecord is not found!");
        else
            {
			      
                RBTNode *successor, *successorChild;
		string str = "Record found :    ";
                str.append(node2Zap->getAllData());
		successor = node2Zap;
            
                if (node2Zap->left == NULL || node2Zap->right == NULL)
                        //If either of the children is NULL
                    successor = node2Zap;
                else                    // node2Zap has 2 children
                    successor = getSuccessor(node2Zap);
            
                if (successor->left == NULL)
                    successorChild = successor->right;
                else
                    successorChild = successor->right;
                
                if (successorChild != NULL)
                    successorChild->parent = successor->parent;
                
                if (successor->parent == NULL)
                    root = successorChild;
                else if (successor == successor->parent->left)
                        successor->parent->left = successorChild;
                    else
                        successor->parent->right = successorChild;
                
                if (successor != node2Zap)
                    node2Zap->setData( successor->getID(),
				       successor->getName(),
				       successor->getSurname(),
                       successor->getCountry(),
				       successor->getSeason(),
				       successor->getTrip()
				     );

                // Finally... If color is black call fixup otherwise no fixup required
                if (successor->getColor() == "BLACK" && successorChild != NULL)
                    fixUp(successorChild);
		
		return str;
            }
    }

    
    
    

RBTNode* RBT::getSuccessor(RBTNode* ptr)
    {
        if (ptr->right == NULL)
            return ptr->left;
        else
            return(getMinimum(ptr->right));
    }




RBTNode* RBT::getMinimum(RBTNode *ptr)
    {
        while(ptr->left != NULL)
            ptr = ptr->left;
    
        return ptr;
    }




string RBT::inOrderHelper(RBTNode* ptr)
{
	    string str = "";
	    
	    if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->left) );
            
                str.append( ptr->getAllDataRBT() );  
                str.append( "  ");
                str.append( inOrderHelper(ptr->right) );
            }   
	    return str;
	    
}




string RBT::preOrderHelper(RBTNode* ptr)
	{
		
	       string str = "";
		
	       if ( ptr != NULL )
	       {
		  str.append( ptr->getAllDataRBT() );
		  str.append( "  ");
            
		  str.append( preOrderHelper(ptr->left) );
		  str.append( preOrderHelper(ptr->right) );
               }
	       return str;
	}




string RBT::postOrderHelper(RBTNode* ptr)
	{
	    string str = "";
		    
	    if ( ptr != NULL )
		{
		    str.append( inOrderHelper(ptr->left) );
		    str.append( inOrderHelper(ptr->right) );
		
		    str.append( ptr->getAllDataRBT() );
		    str.append( "  ");
		}
	    return str;
	}




string RBT::showLevels()
    {
        vector <RBTNode*> listA;
        vector <RBTNode*> listB;
    
        string str = "";
        
        listA.resize(0);
        listB.resize(0);
        
        if (root == NULL)
            {
                str.append("Tree is Empty...\n");
                return str;
            }
        else
            listA.push_back(root);

    
        while (!listA.empty())
            {
                //Display the contents of listA
                for (int x = 0; x < listA.size(); x++)
                    {
                        str.append(listA[x]->getAllDataRBT());
                        str.append("{");
                        str.append(listA[x]->getColor());
                        str.append("} \t");
                     }
                str.append("\n");
            
                //Transfer contents of listA to listB
                listB = listA;
            
                // Now purge listA and copy listB's children into listA
                listA.resize(0);

                for (int x = 0; x < listB.size(); x++)
                    {
                        if (listB[x]->left != NULL)
                            listA.push_back(listB[x]->left);
                        if (listB[x]->right != NULL)
                            listA.push_back(listB[x]->right);
                    }
            }
        return str;
    }




#endif
