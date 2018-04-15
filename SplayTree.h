#ifndef SPLAYTREE_H
#define SPLAYTREE_H


class SplayNode
    {
        private:
                int data;            // Node value
    
        public:
                SplayNode *left;  	// pointer to left subtree
                SplayNode *right;    // pointer to right subtree
    
                //Constructor
                SplayNode( int val ) {data = val; left = right= 0;}
                SplayNode() {left = 0; right= 0;}
    
                //Accessors
                int getData()      const { return data; }
                SplayNode* getLeft()  const { return left;}
                SplayNode* getRight() const { return right;}
    
    
                //Mutators
                void setValue(int val)     { data = val; }
                void setLeft(SplayNode* ptr)  { left = ptr; }
                void setRight(SplayNode* ptr) { right = ptr; }
    };




class SplayTree
    {
        private:
                SplayNode *root;
    
                    // Utility functions
                SplayNode* RightRotate(SplayNode*);
                SplayNode* LeftRotate(SplayNode*);
                SplayNode* Splay(int, SplayNode*);
                SplayNode* InsertHelper(int, SplayNode*);
             //   SplayNode* removeHelper(SplayNode*);
                string InOrderHelper(SplayNode*);
                string PreOrderHelper(SplayNode*);
                string PostOrderHelper(SplayNode*);
                void insertSplayNodeHelper(SplayNode **, int );
                string displayNodesHelper( SplayNode * ) const;
    
    
            public:
                SplayTree(){ root = 0; };
    
                SplayNode* getRoot(){return root;}
                void Insert(int);
                string InOrder(){ return InOrderHelper(root);}
                string PreOrder(){ return PreOrderHelper(root);}
                string PostOrder(){ return PostOrderHelper(root);}
                void insertSplayNode( int );
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
            
                str.append( to_string(ptr->getData()) );
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
                str.append( PreOrderHelper(ptr->left) );
            
                str.append( to_string(ptr->getData()) );
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
                str.append( PostOrderHelper(ptr->left) );
            
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
		str.append( PostOrderHelper(ptr->left) );
		str.append( PostOrderHelper(ptr->right) );
              }
		return str;
    }
   
   
   
 /*  SplayNode* SplayTree::removeHelper(SplayNode* ptr, int clientID)
{
    SplayNode* successor;
    
    if ( ptr == NULL)           // Node location is empty i.e. Node not found!
    {
        return NULL;
    }
    else
    {
        if ( clientID> ptr->getData() )                // Search in Right subtree
        {
            ptr->right = removeHelper(ptr->right, clientID);
        }
        else if( clientID < ptr->getclientID() )           // Search in Left subtree
        {
            ptr->left = removeHelper(ptr->left, clientID);
        }
        else   //Node to to be deleted is found
        {
            if ( ptr->right != NULL )
            {
                // Delete its inorder succesor
                successor = ptr->right;                 // Go right...
                while ( successor->left != NULL )       // ...then go deep left
                    successor = successor->left;
                
                // Transfer data from successor to ptr
                ptr->setclientID( successor->getclientID() );
                ptr->setfirstName( successor->getfirstName() );
                ptr->setlastName( successor->getlastName() );
                ptr->setDestination( successor->getDestination() );
                ptr->setSeason( successor->getSeason() );
                ptr->setBooking(successor->getBooking());
                // Now reset ptr's right child
                ptr->right = removeHelper( ptr->right, ptr->getclientID() );
            }
            else
                return (ptr->left);
        }
    }
    return (ptr);
} */



#endif
