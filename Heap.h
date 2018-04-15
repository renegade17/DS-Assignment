#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iterator>
#include <sstream>

class HeapNode
{
	private:
            int     guestID;
            string  name;
            string  surname;
            string  country;
            string  season;
            string  trip;
  
   
	  public:
			HeapNode *left;    // pointer to left subtree
			HeapNode *right;   // pointer to right subtree

			HeapNode(){left = NULL; right = NULL;}
			HeapNode(int, string, string, string, string, string);

			//Accessor functions
			int getClientID()      { return guestID; }
            string getName()	{ return name; }
            string getSurname()	{ return surname; }
            string getCountry()	{ return country; }
            string getSeason()	{ return season; }
            string getTrip()	{ return trip; }
			HeapNode *getLeftPtr(){ return left;}
			HeapNode *getRightPtr(){ return right;}
			

			//Mutator functions
			void setClientID(int num)      { guestID = num;}
            void setName(string val)	{ name = val; }
            void setSurname(string val)	{ surname = val; }
            void setCountry(string val)	{ country = val; }
            void setSeason(string val)	{ season = val; }
            void setTrip(string val)	{ trip = val; }
			void setLeftPtr(HeapNode &ptr) { left = &ptr;}
			void setRightPtr(HeapNode &ptr){ right = &ptr;}
};//HeapNode


HeapNode::HeapNode(int clientID, string firstName, string lastName, string destination, string period, string booking)
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

class Heap
{
  private:
		vector<HeapNode> heap; 
		
		int left(int parent);
		int right(int parent);
		int parent(int child);
		void minheapify(int index);
		void heapifydown(int index);
		void swap(HeapNode &nodeA, HeapNode &nodeB)
		{
			HeapNode Temp = nodeA; 
			nodeA = nodeB; 
			nodeB = Temp;
		}
		
		string strip(string);
    
  public:
		Heap(){emptyHeap();}
		void emptyHeap(){heap.resize(0);}
		void insertHeap(const int &, const string &, const string &, const string &, const string &, const string &);
		string displayHeap();
		string addChildren(int);
		string HeapSort();
		string DeleteNode (int idNo);
  
};//Heap




void Heap::insertHeap(const int &clientID, const string &firstName, const string &lastName, const string &destination, const string &period, const string &booking)
{
  HeapNode temp(clientID, firstName, lastName, destination, period, booking);
  
  vector <HeapNode >::iterator pos = heap.begin();
  while (pos != heap.end())
  {
    if(pos->getClientID() == clientID)
      return;
    pos++;
  }
  
  
  heap.push_back(temp);
  minheapify(heap.size() -1);
  
  pos = heap.begin();
  int count = 0;
  while (pos != heap.end())
  {
    if(heap.size() > 2 * count + 1)
    {
      (*pos).setLeftPtr( heap[2*count+1] );
    }
    
    if(heap.size() > 2 * count + 2)
    {
      (*pos).setRightPtr(heap[2*count+2]);
    }
    count++;
    pos++;
  }
}


string Heap::DeleteNode (int idNum)
{
  vector <HeapNode>::iterator pos = heap.begin();
  
  int  size = heap.size();
  int  count = 0;
  bool popBack = false;
  bool reheapify = false;
  int  element;
  
  string str;
  string searchStr;
  string deletedStr = "Record found :    ";
  
  stringstream searchVal;
  
  searchVal << idNum;
  searchStr = str.append(searchVal.str()); //Contains id of node to be deleted 
  
  
  while (pos != heap.end())
  {
	stringstream numStr;
	
        numStr << pos->getClientID();
	
	//Store only the new id in str
        str = numStr.str();
	
    if (count != size - 1 && strcmp(str.c_str(),searchStr.c_str()) == 0) //found heap node 
    {
      swap(heap[count],heap[size - 1]);
      popBack = true; //Flag to determine if last node is to be removed 
      
      reheapify = true;      //Flag for reheapification to be performed
      element   = count;    //Location of node to be reheapified
   
    }
    
    else 
      if (count == size - 1 && strcmp(str.c_str(), searchStr.c_str()) == 0) // heap node to be removed is the last node 
      {
	popBack = true; //Flag to determine if last node is to be removed 
	element = count;
      }
  
    pos++;
    count++;
  }
  
   if (reheapify == true)
  {
    heapifydown(element); //Fix heap tree after deleting 
    reheapify = false;
  }
  
  if (popBack == true)
  {
	//Retrieve data to be removed 
	// Older C++ method of converting number to a string
        stringstream numStr;
        numStr << heap[element].getClientID();
        deletedStr.append(numStr.str());
    
        deletedStr.append("\t");
        deletedStr.append(strip(heap[element].getName()));	
        deletedStr.append("\t");
        deletedStr.append(strip(heap[element].getSurname()));
        deletedStr.append("\t");
        deletedStr.append(strip(heap[element].getCountry()));
        deletedStr.append("\t");
        deletedStr.append(strip(heap[element].getSeason()));
        deletedStr.append("\t");
        deletedStr.append(strip(heap[element].getTrip()));	
        deletedStr.append("\n");
        
    
    heap.pop_back(); //Remove last logical node in heap
    popBack == false;
    
    return deletedStr;
  }
  
  return ("\nRecord is not found!");
}




void Heap::minheapify(int index)
{
    if (index >= 0 && parent(index) >= 0 && heap[parent(index)].getClientID() > heap[index].getClientID())
    {
        HeapNode temp = heap[index];
        heap[index] = heap[parent(index)];
        heap[parent(index)] = temp;
	
        minheapify(parent(index));
    }
}




void Heap::heapifydown(int index)
{
  int child = left(index);
  int child1 = right(index);
  
  if (child >= 0 && child1 >= 0 && heap[child].getClientID() > heap[child1].getClientID())
  {
    child = child1;
  }
  
  
  if (child > 0 && heap[index].getClientID() > heap[child].getClientID())
  {
    HeapNode temp = heap[index];
    heap[index] = heap[child];
    heap[child] = temp;
    heapifydown(child);
  }
  
}


string Heap::displayHeap()
{
  if (heap.size() == 0) 
  {    
    return ("\nHeap is empty\n\n");
  }//end if
  
  
  string str = "";
  
  vector <HeapNode >::iterator pos = heap.begin();

  while (pos != heap.end())
  {
	
	string child;
	
	//Append data for display
        stringstream numStr;
	stringstream leftChild;	
	stringstream rightChild;
	
	
        numStr << pos->getClientID();
        str.append(numStr.str());
    
        str.append("\t");
        str.append(strip(pos->getName()));    
        str.append("\t");
        str.append(strip(pos->getSurname()));
        str.append("\t");
        str.append(strip(pos->getCountry()));
        str.append("\t");
        str.append(strip(pos->getSeason()));
        str.append("\t");
        str.append(strip(pos->getTrip()));
        str.append("\t");
       
	
	if (pos->getLeftPtr() != NULL && pos->getRightPtr() != NULL) //No ptr's are NULL
	{
	  child.append("[ ");
	  leftChild << pos->getLeftPtr()->getClientID();
	  child.append(leftChild.str());
	  child.append(" , ");
	  
	  rightChild << pos->getRightPtr()->getClientID();
	  child.append(rightChild.str());
	  child.append(" ]");
	  
	  //Add left & right ptr IDs to str
	  str.append(child);
	  str.append("\n");
	}

	if (pos->getLeftPtr() != NULL && pos->getRightPtr() == NULL) //right ptr is NULL
	{
	  child.append("[ ");
	  leftChild << pos->getLeftPtr()->getClientID();
	  child.append(leftChild.str());
	  child.append(" , ");
	  child.append("NULL ]");
	  
	  //Add left & right ptr IDs to str
	  str.append(child);
	  str.append("\n");
	}
	
	if (pos->getLeftPtr() == NULL && pos->getRightPtr() != NULL) //left ptr is NULL
	{
	  child.append("[ NULL");
	  child.append(" , ");
	  rightChild << pos->getRightPtr()->getClientID();
	  child.append(rightChild.str());
	  child.append(" ]");
	  
	  //Add left & right ptr IDs to str
	  str.append(child);
	  str.append("\n");
	  
	}
	
	if (pos->getLeftPtr() == NULL && pos->getRightPtr() == NULL) //both left & right are NULL
	{
	  str.append("[ NULL , NULL ]");
	  str.append("\n");
	}
	
    pos++;
  }//end while
  
  return str;
}



string Heap::strip(string str)
   {
      for (unsigned int x = 0; x < str.size(); x++)
      if ( (!isalpha(str[x]) ) && (str[x] != '-') && (str[x] != ' ') )
      str[x] = ' ';

      return str; 
   }





string Heap::HeapSort()
{
  
  if(heap.size() == 0)
  {
    return "\nHeap is empty\n\n";
  }
  
  
  vector<HeapNode> temp = heap;
  
  int originalSize = heap.size();
  vector<HeapNode>::iterator tempIterate = temp.begin();
  int iterateCount = 0;
  
  
  while(tempIterate != temp.end())
  {
    tempIterate->setClientID(heap[0].getClientID());
    tempIterate->setName(heap[0].getName());
    tempIterate->setSurname(heap[0].getSurname());
    tempIterate->setCountry(heap[0].getCountry());
    tempIterate->setSeason(heap[0].getSeason());
    tempIterate->setTrip(heap[0].getTrip());
    
    swap(heap[0], heap[originalSize - 1 - iterateCount]);
    heap.pop_back();
    
    heapifydown(0);
    iterateCount++;
    tempIterate++;
  }
  
  heap = temp;
  
  temp.resize(0);
  
  vector <HeapNode >::iterator pos = heap.begin();
  pos = heap.begin();
  int count = 0;
  while (pos != heap.end())
  {
    
    if(heap.size() > 2 * count + 1)
    {
      (*pos).setLeftPtr( heap[2*count+1] );
    }
    
    
    if(heap.size() > 2 * count + 2)
    {
      (*pos).setRightPtr(heap[2*count+2]);
    }
    
    count++;
    pos++;
  }//end while 
  
  
  string str = "The Heap has been sorted:\n\n";
  str.append(displayHeap());
  
  return str;
}


int Heap::left(int parent)
{
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}


int Heap::right(int parent)
{
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}



int Heap::parent(int child)
{
    int p = (child - 1)/2;
    if (child == 0)
        return -1;
    else
        return p;
}//parent

#endif
