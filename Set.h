
#ifndef SET_H
#define SET_H

#include <vector>
#include <iterator>
#include <string>

class SetNode
{
  private:
            int     guestID;
            string  name;
            string  surname;
            string  country;
            string  season;
            string  trip;
		   
  public:
	    SetNode *left;    // pointer to left subtree
	    SetNode *right;   // pointer to right subtree

	    //Constructor Functions
	    SetNode(){left = NULL; right = NULL;}
	    SetNode(int, string, string, string, string, string);

	    //Accessor functions
            int     getID()         { return guestID; }
            string  getName()       { return name; }
            string  getSurname()    { return surname; }
            string  getCountry()    { return country; }
            string  getSeason()     { return season; }
            string  getTrip()       { return trip; }
	    SetNode *getLeftPtr()   { return left;}
	    SetNode *getRightPtr()  { return right;}

	    //Mutator functions
            void setID(int num)              { guestID = num; }
            void setName(string str)         { name = str; }
            void setSurname(string str)      { surname = str; }
            void setCountry(string str)      { country = str; }
            void setSeason(string str)       { season = str; }
            void setTrip(string str)         { trip = str; }
	    void setLeftPtr(SetNode* ptr)   { left = ptr;}
	    void setRightPtr(SetNode* ptr)  { right = ptr;}
		   
};



//SetNode Constructor Function
SetNode::SetNode(int clientID, string firstName, string lastName, string destination, string period, string booking)
{
        guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
	left        = NULL;
	right       = NULL;
}



 
class Set
{
  
 private:
	   vector <SetNode> elements;     

 public:
	   Set (void){elements.resize(0);} 	
	   Set (int n){elements.resize(n);}	

	   int getNumElements   (){return elements.size();}
	   SetNode getElements  (int ) ;
	   bool find            (int idNo) ;
	   void addElements     (int, string, string, string, string, string);
	   void remove       (SetNode & );
	   string strip      (string);
	   
	   string displaySet ();
	   void intersection ( Set*,   Set*);
	   void unionOfSets  ( Set*,  Set*);
	   
};


string Set::strip(string str)
{
      for (unsigned int x = 0; x < str.size(); x++)
      if ( (!isalpha(str[x]) ) && (str[x] != '-') && (str[x] != ' ') )
	  str[x] = ' ';

      return str; 
}


SetNode Set::getElements(int index)  
{
	if (index < elements.size ( ) )
		{
		   return elements[index];
		}
		
	else
		{
			cout << "Set index out of range." << endl;
			exit (1);
		}	
}



bool Set::find(int clientID)  
{
	for (int count = 0;  count < elements.size( );  count++)
	{
		   if (elements[count].getID() == clientID)   // found item
		{
			return true; 
		}
	}
			 
	return false; // not found
}


void Set::addElements (int clientID, string firstName, string lastName, string destination, string period, string booking)
{
	SetNode item(clientID, firstName, lastName, destination, period, booking);
		 
	if (find(clientID))
	{
	    return;
	}
	
	else 
	{
	    elements.push_back (item); //add element
	}
	
	return;
}



string Set::displaySet()
{
	if (elements.size() == 0)
	{    
	  return ("\nSet is empty\n\n");
	}
	stringstream numStr;
	string str = "";
	
	vector <SetNode>::iterator pos = elements.begin();
			
	while (pos != elements.end())
	{ 
			
	numStr << pos->getID();
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
			
			pos++;
	}
		 
	str.append("\nEnd\n\n");
		 
	return str;
}



void Set::intersection( Set *A, Set *B)
{	
	 
	elements.resize(0);
	
	for(int count = 0; count < A->elements.size(); count++)
	{
		if(strcmp(A->elements[count].getTrip().c_str() , "Online") == 0)
		{
		    elements.push_back(A->elements[count]);
		}
	}
			
	for(int count2 = 0; count2 < B->elements.size(); count2++)
	{
		if (strcmp(B->elements[count2].getTrip().c_str() , "Other Booking") == 0)
		{
			elements.push_back(B->elements[count2]);
		}
	}

	return;
}


void Set::unionOfSets( Set *A,   Set *B)
{
	  int x;
	  
	  elements.resize(0);
	  elements = A->elements;     //Copy setA
	  x = A->getNumElements();

	  for (int count = 0;  count < B->getNumElements();  count++)
	  {
		if ( A->find( B->elements[count].getID()) == false )
		{
		      elements.push_back(B->elements[count]);
		}
	  }
	  return;
}

#endif
