//
//  SplayTree.h
//  Splay
//


#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <string>
#include <vector>
#include <iterator>
#include <sstream>


class SplayNode
    {
        private:
            int     guestID;
            string  name;
            string  surname;
            string  country;
            string  season;
            string  trip;          
    
        public:
                SplayNode *left;  	// pointer to left subtree
                SplayNode *right;    // pointer to right subtree
    
                //Constructor
                SplayNode( int, string, string, string, string, string)
                SplayNode() {left = NULL; right= NULL;}
    
                //Accessors
                int getClientID()      { return guestID; }
            string getName()	{ return name; }
            string getSurname()	{ return surname; }
            string getCountry()	{ return country; }
            string getSeason()	{ return season; }
            string getTrip()	{ return Trip; }
            string getData();
                SplayNode* getLeft()  const { return left;}
                SplayNode* getRight() const { return right;}
    
    
                //Mutators
                void setClientID(int num)      { guestID = num;}
            void setName(string val)	{ name = val; }
            void setSurname(string val)	{ surname = val; }
            void setCountry(string val)	{ country = val; }
            void setSeason(string val)	{ season = val; }
            void setTrip(string val)	{ trip = val; }
            void setData(int, string, string, string, string, string);
                void setLeft(SplayNode* ptr)  { left = ptr; }
                void setRight(SplayNode* ptr) { right = ptr; }
    };

SplayNode::SplayNode(int clientID, string firstName, string lastName, string destination, string period, string booking)
{
        guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
	left = NULL;
	right = NULL;
}

void SplayNode::setData(int clientID, string firstName, string lastName, string destination, string period, string booking)
{
        guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
} 

string SplayNode::getData()
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


class SplayTree
    {
        private:
                SplayNode *root;
    
                    // Utility functions
                SplayNode* RightRotate(SplayNode*);
                SplayNode* LeftRotate(SplayNode*);
                SplayNode* Splay(int, SplayNode*);
                SplayNode* InsertHelper(int, SplayNode*);
                string InOrderHelper(SplayNode*);
		string PreOrderHelper(SplayNode*);
		string PostOrderHelper(SplayNode*);
                void insertSplayNodeHelper(SplayNode**, int, string, string, string, string, string);
                string displayNodesHelper( SplayNode * ) const;
    
    
            public:
                SplayTree(){ root = 0; };
    
                SplayNode* getRoot(){return root;}
                void Insert(int);
                string InOrder(){ return InOrderHelper(root);}
                string PreOrder(){ return PreOrderHelper(root); };
		string PostOrder(){ return PostOrderHelper(root); };
                void insertSplayNode(int, string, string, string, string, string);
                string displayNodes();
		void   emptySplay() { root = NULL;}
    };




SplayNode* SplayTree::RightRotate(SplayNode* ptr)
{
    SplayNode* leftchild = ptr->left;
    ptr->left = leftchild->right;
    leftchild->right = ptr;
    return leftchild;
}




SplayNode* SplayTree::LeftRotate(SplayNode* ptr)
{
    SplayNode* rightchild = ptr->right;
    ptr->right = rightchild->left;
    rightchild->left = ptr;
    return rightchild;
}





SplayNode* SplayTree::Splay(int key, SplayNode* root)
    {
        if(root == NULL)
            return NULL;
        
        SplayNode* header = new SplayNode();
        
        SplayNode* LeftTreeMax = header;
        SplayNode* RightTreeMin = header;
        
        /* loop until root->left == NULL || root->right == NULL; then break!
         The zig/zag mode would only happen when cannot find key and will reach
         null on one side after RR or LL Rotation.
         */
        while(root->left != NULL || root->right != NULL)
            {
                if(key < root->getData())
                    {
                        if(root->left == NULL)
                            break;
                    
                        if(key < root->left->getData())
                            {
                                root = RightRotate(root); /* Only zig-zig mode need to rotate once,
                                                        because zig-zag mode is handled as zig
                                                        mode, which doesn't require rotate,
                                                        just linking it to R Tree */
                                if(!root->left)
                                    break;
                            }
                    
                        /* Link to Right Tree */
                        RightTreeMin->left = root;
                        RightTreeMin = RightTreeMin->left;
                        root = root->left;
                        RightTreeMin->left = NULL;
                    }
                else if(key > root->getData())
                        {
                            if(root->right == NULL)
                                break;
                            if(key > root->right->getData())
                                {
                                    root = LeftRotate(root);/* only zag-zag mode need to rotate once,
                                                        because zag-zig mode is handled as zag
                                                        mode, which doesn't require rotate,
                                                        just linking it to L Tree */
                                    if(root->right == NULL)
                                        break;
                                }
                            /* Link to Left Tree */
                            LeftTreeMax->right = root;
                            LeftTreeMax = LeftTreeMax->right;
                            root = root->right;
                            LeftTreeMax->right = NULL;
                        }
                    else
                        break;
                }
            /* assemble Left Tree, Middle Tree and Right tree together */
            LeftTreeMax->right = root->left;
            RightTreeMin->left = root->right;
            root->left = header->right;
            root->right = header->left;
            return root;
    }



SplayNode* SplayTree::InsertHelper(int key, SplayNode* root)
    {
        SplayNode* newnode = new SplayNode(key);
    
        if(root == NULL)
            return newnode;
    
        SplayNode* parent_temp = new SplayNode();
        SplayNode* temp = root;
    
        while(temp != NULL)
            {
                parent_temp = temp;
            
                if(key <= temp->getData())
                    temp = temp->left;
                else
                    temp = temp->right;
            }
    
        if(key <= parent_temp->getData())
            parent_temp->left = newnode;
        else
            parent_temp->right = newnode;
    
        root = Splay(key, root);
        return (root);
    }




void SplayTree::Insert(int key)
{
    root = InsertHelper(key, root);

}



string SplayTree::InOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( InOrderHelper(ptr->left) );
            
                str.append(ptr->getData() );
                str.append( "  ");
            
                str.append( InOrderHelper(ptr->right) );
              }
		return str;
    }
    
    string SplayTree::PreOrderHelper(SplayNode* ptr)
	{
		
	       string str = "";
		
	       if ( ptr != NULL )
	       {
		  str.append( ptr->getData() );
		  str.append( "  ");
            
		  str.append( PreOrderHelper(ptr->left) );
		  str.append( PreOrderHelper(ptr->right) );
               }
	       return str;
	}
    
    string SplayTree::PostOrderHelper(SplayNode* ptr)
	{
		
	       string str = "";
		
	       if ( ptr != NULL )
	       {
		  str.append( ptr->getData() );
		  str.append( "  ");
            
		  
               }
	       return str;
	}
	
	void SplayTree::insertSplayNode(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
        insertSplayNode( &root, clientID, firstName, lastName, destination, period, booking);
    }

	
 void SplayTree::insertSplayNodeHelper( SplayNode** ptr, int clientID, string firstName, string lastName, string destination, string period, string booking)
{
        if ( *ptr == NULL )               // tree/sub-tree is empty
        {
           *ptr = new SplayNode(clientID, firstName, lastName, destination, period, booking);
        }
        else                              // tree is not empty
		{
			if ( idNo < ( *ptr )->getClientID() )
			{
				insertSplayNodeHelper( &( (*ptr)->leftPtr ), clientID, firstName, lastName, destination, period, booking);

					if(height((*ptr)->getLeftPtr()) - height((*ptr)->getRightPtr()) == 2)
					{
						if( clientID < (*ptr)->leftPtr->getClientID())
							(*ptr) = LeftRotate(*ptr);
						else
							(*ptr) = RightRotate(*ptr);
					}
			}
		else
		{
			if ( idNo > ( *ptr )->getClientID() )
			{
				insertSplayNodeHelper( &( ( *ptr )->rightPtr ), clientID, firstName, lastName, destination, period, booking);
					if(height((*ptr)->getRightPtr()) - height((*ptr)->getLeftPtr()) == 2)
					{
						if( idNo > (*ptr)->rightPtr->getClientID())
							(*ptr) = RightRotate(*ptr);
						else
							(*ptr) = LeftRotate(*ptr);
					}
			}
		}
		}

	(*ptr)->setBalance( max(height((*ptr)->getLeftPtr() ),height((*ptr)->getRightPtr()))+1);

}

string SplayTree::displayNodesHelper( )
{
  return displayNodeHelper( rootPtr );
}



#endif
