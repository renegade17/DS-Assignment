#ifndef NODE_H
#define NODE_H

class Node
    {
        private:
            int     guestID;
            string  name;
            string  surname;
            string  country;
            string  season;
            string  trip;
            Node*   nextPtr;
    
        public:
                // Constructor function
            Node(int, string, string, string, string, string);
            
                //Accessor functions
            int     getID()         { return guestID; }
            string  getName()       { return name; }
            string  getSurname()    { return surname; }
            string  getCountry()    { return country; }
            string  getSeason()     { return season; }
            string  getTrip()       { return trip; }
            Node*   getNext()       { return nextPtr; }
            string  getData();
    
                //Mutator functions
            void setID(int num)              { guestID = num; }
            void setName(string str)         { name = str; }
            void setSurname(string str)      { surname = str; }
            void setCountry(string str)      { country = str; }
            void setSeason(string str)       { season = str; }
            void setTrip(string str)        { trip = str; }
            
            
            void setNext(Node* ptr){nextPtr = ptr;}
    };

    // Node constructor function
Node::Node(int clientID, string firstName, string lastName, string destination, string period, string booking)

    {
        guestID    = clientID;
        name       = firstName;
        surname    = lastName;
        country    = destination;
        season     = period;
        trip       = booking;
        nextPtr    = NULL;
    }


string Node::getData()
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
#endif
