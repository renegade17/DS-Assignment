
#ifndef BST_BSTree_h
#define BST_BSTree_h


class BSTNode
    {
        private:
            int     guestID;
            string  name;
            string  surname;
            string  country;
            string  season;
            string  trip;

                // Utility function
            string formatName(string);
    
        public:
            BSTNode* left;
            BSTNode* right;
    
                // Constructor functions
            BSTNode(){right = left = NULL;}
            BSTNode(int, string, string, string, string, string);
    
                //Accessor functions
            int     getID()         { return guestID; }
            string  getName()       { return name; }
            string  getSurname()    { return surname; }
            string  getCountry()    { return country; }
            string  getSeason()     { return season; }
            string  getTrip()       { return trip; }
            BSTNode* getLeft()      { return left; }
            BSTNode* getRight()     { return right; }
            string  getRecord();
	    
            
                //Mutator functions
            void setID(int num)              { guestID = num; }
            void setName(string str)         { name = str; }
            void setSurname(string str)      { surname = str; }
            void setCountry(string str)      { country = str; }
            void setSeason(string str)       { season = str; }
            void setTrip(string str)         { trip = str; }
            void setLeft(BSTNode* ptr)       { left = ptr;}
            void setRight(BSTNode* ptr)      { right = ptr;}
            void copyData(BSTNode*);
     };


BSTNode::BSTNode(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
        guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
        left       = NULL;
        right      = NULL;
    }


string BSTNode::formatName(string val)
    {
        val[0] = toupper(val[0]);
        
        for (unsigned int x = 1; x < val.length(); x++)
            {
                val[x] = tolower(val[x]);
            }
        return val;
    }


string BSTNode::getRecord()
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
        
        return record;
    }





void BSTNode::copyData(BSTNode* ptr)
    {
        guestID    = ptr->guestID;
        name       = ptr->name;
        surname    = ptr->surname;
        country    = ptr->country;
        season     = ptr->season;
        trip       = ptr->trip;
    }



//==========================================================================
//      The Binary Search Tree Class
//==========================================================================

class BSTree
    {
        private:
            BSTNode* root;
    
                // Recursive counterpart of insert
            BSTNode* insertHelper(BSTNode*, int, string, string, string,  string, string);
            BSTNode* deleteNode(BSTNode*, long);       // Recursive counterpart of delete
            string   preOrderHelper(BSTNode* );        // Recursive counterpart of preorder
            string   postOrderHelper(BSTNode* );       // Recursive counterpart of postorder
            string   inOrderHelper(BSTNode* );         // Recursive counterpart of inorder
            
        public:
            BSTree()     { root = NULL;}
            void purgeBSTree() { root = NULL;}
            
            BSTNode* getRoot()    { return root;}
            void insert(int, string, string, string, string, string);
            void remove(long val) { root = deleteNode(root, val); }
            string preOrder()     { return preOrderHelper(root); }
            string postOrder()    { return postOrderHelper(root); }
            string inOrder()      { return inOrderHelper(root); }
    };




BSTNode* BSTree::insertHelper(BSTNode* ptr, int clientID, string firstName, string lastName, string destination, string period, string booking)
{
    if ( ptr == NULL )              // The tree is empty - new first node!
        {
            ptr = new BSTNode( clientID, firstName, lastName, destination, period, booking);
        }
    else                            // choose which sub-tree to follow
        {
            if (clientID >= ptr->getID())  // insert in right subtree - Operational defn.
                ptr->right = insertHelper(ptr->right, clientID, firstName, lastName, destination, period, booking);
            else
                ptr->left = insertHelper(ptr->left, clientID, firstName, lastName, destination, period, booking);
        }
    return ptr;
}



void BSTree::insert(int clientID, string firstName, string lastName, string destination, string period, string booking)
    {
        root = insertHelper(root, clientID, firstName, lastName, destination, period, booking);
    }



BSTNode*  BSTree::deleteNode(BSTNode* ptr, long val)
{
    BSTNode* successor;
    
    if ( ptr == NULL)           // Not found!
        {
            return NULL;
        }
    else
        if ( val > ptr->getID() )                // Search in Right subtree
            ptr->right = deleteNode(ptr->right, val);
        else if( val < ptr->getID() )           // Search in Left subtree
            ptr->left = deleteNode(ptr->left, val);
    
        else   //Node to to be deleted is found
            {
                if ( ptr->right != NULL)
                    {  // delete its inorder succesor
                        successor = ptr->right;
                        while ( successor->left != NULL)
                            successor = successor->left;
                        
                        ptr->copyData( successor );
                        ptr->right = deleteNode( ptr->right, ptr->getID() );
                    }
                else
                    return (ptr->left);
            }
    return(ptr);
}







string BSTree::inOrderHelper(BSTNode* ptr)
{
    string str = "";
    
    if ( ptr != NULL )
        {
            str.append( inOrderHelper(ptr->left) );
            
            str.append( ptr->getRecord());
            str.append( "\n");
            
            str.append( inOrderHelper(ptr->right) );
        }
    return str;
}




string BSTree::preOrderHelper(BSTNode* ptr)
{
    string str = "";
    
    if ( ptr != NULL )
        {
            str.append( ptr->getRecord() );
            str.append( "\n");
            
            str.append( preOrderHelper(ptr->left) );
            str.append( preOrderHelper(ptr->right) );
        }
    return str;
}




string BSTree::postOrderHelper(BSTNode* ptr)
{
    string str = "";
    
    if ( ptr != NULL )
        {
            str.append( inOrderHelper(ptr->left) );
            str.append( inOrderHelper(ptr->right) );
            
            str.append( ptr->getRecord() );
            str.append( "\n");
        }
    return str;
}




#endif
