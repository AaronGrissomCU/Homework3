//====================================
// Assignment 3
// Author: Matt Bubernak
// Date: 1/29/2015
// Modified : Fall 2016 E.S.Boese
//            Fall 2017 W. Temple
//            10/3/17 Aaron Grissom
// Discription: Linked List fun
//====================================

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <string>

using namespace std;

//DO NOT MODIFY THIS STRUCT
struct city
{
	string name;        // name of city
	city* next;         // pointer to the next city
	int numberMessages; // How many messages passed through this city
	string message;     // message we are sending accross
};

/* Function Prototypes */

city* addCity (city* head, city* previous, string cityName);
city* deleteCity (city* head, string cityName);
city* deleteEntireNetwork(city* head);
city* searchNetwork(city* Head, string cityName);
city* loadDefaultSetup (city* Head);

void transmitMsg(city* head, string reciver, string filename);
void printPath(city* head);
void displayMenu();

city* handleUserInput (city* head);

/* Do NOT modify main function */
int main(int argc, char* argv[])
{
	//pointer to the head of our network of cities
	city* head = NULL;
	head = handleUserInput(head);
	printPath(head);
	head = deleteEntireNetwork(head);
	
	if (head == NULL)
		cout << "Path cleaned" << endl;
	else
		printPath(head);
	
	cout << "Goodbye!" << endl;
	return 0;
}

/* Funtion: handleUserInput DO NOT MODIFY THIS FUNCTION
 * Purpose: handle the interaction with the user
 * @param head - the start of the linked lsit
 * @return - the start of the linked list
 *
 * DO NOT MODIFY THIS FUNCTION
 */
 
 city* handleUserInput(city* head)
 {
	 bool quit = false;
	 string s_input;
	 int input;
	 
	 //loop until the user quits
	 while (!quit)
	 {
		 displayMenu();
		 
		 //read in input, assuming a number comes in
		 getline(cin, s_input);
		 input = stoi(s_input);
		 
		 switch (input)
		 {
			 //print all nodes
			 case 1:	//rebuild network
				head = loadDefaultSetup(head);
				printPath(head);
				break;
				
			case 2:	// print path
				printPath(head);
				break;
			
			case 3:	// message is read from file
				{
					string cityReciver;
					cout << "Enter name of the city to receive the message: " << endl;
					getline(cin, cityReciver);
				
					cout << "Enter the message to send: " << endl;
					string message;
					getline(cin,message);
				
					transmitMsg(head, cityReciver, message);
				}
				break;
				
			case 4:	// add city
				{
					string newCityName;
					string prevCityName;
					
					cout << "Enter a new city name: " << endl;
					getline(cin, newCityName);
					
					cout << "Enter the previous city name (or First): " << endl;
					getline(cin, prevCityName);
					
					// find the node containing prevCity
					city* tmp = NULL;
					if (prevCityName != "First")
						tmp = searchNetwork(head, newCityName);
					
					//add the new node
					head = addCity(head, tmp, newCityName);
					printPath(head);
				}
				break;
				
			case 5:	//delete city
				{
					string city;
					cout << "Enter a city name: " << endl;
					getline(cin, city);
					head = deleteCity(head, city);
					printPath(head);
				}
				break;
				
			case 6: // delete Network
				head = deleteEntireNetwork(head);
				break;
				
			case 7:	//quit
				quit = true;
				cout << "Quitting... cleaning up path: " << endl;
				break;
				
			default:	//Invalid input
				cout << "Invalid Input" << endl;
				break;	
		}
	 }
	 
	 return head;
 }
 
 /* Function: addCity Completed
  * Purpose: Adda new City to the network between the city* previous and the
  * 		 city that follows it in the network
  * Prints: 'prev: <city name> new: <city name>' when a city is added,
  *         '' if the city is being added to the first position in the list
  * @param head - pointer to start of lsit
  * @param previous - name of city that comes before new city
  * @param cityName - name of the new city
  * @return - pointer to first node in lsit
  */
 city* addCity(city* head, city* previous, string cityName)
{
	city* newCity = new city;
	newCity->name = cityName;
	newCity->numberMessages = 0;
	
	if (previous == NULL)
	{
	    newCity->next = head;
	    head = newCity;
	    return head;
	}
	else
	{
	    cout << "prev: " << previous->name << "  new: " << cityName << endl;
		newCity->next = previous->next;
		previous->next = newCity;
	}
    
	return head;
}
 
 /* Function: searchNetwork Completed
  * Purpose: Search the network for the specified city and return a pointer to that node
  * @param ptr - head of the list
  * @param cityName - name of the city to look for in network
  * return pointer to node of cityName, or NULL if not found
  * @see addCity, deleteCity
  */
city *searchNetwork(city *ptr, string cityName)
{
    do
    {
        if (ptr->name == cityName)
        {
            return ptr;
        }
        else
        {
            ptr = ptr->next;
        }
    }while (ptr != NULL);
    
    return ptr;
        
}

/* Function deleteEntireNetwork Completed
 * Purpose: deletes all cities in the netword starting at the head city.
 * @param ptr - head of list
 @ return NULL as the list is empty
 */
city* deleteEntireNetwork(city *ptr)
{
    city* del;
	
	if (ptr == NULL)
	{
		return ptr;
	}
    
    while (ptr != NULL)
    {
        cout << "deleting: " << ptr->name << endl;
        del = ptr;
        ptr = ptr->next;
        delete del;
    }
    cout << "Deleted network" << endl;
    return ptr;
}

/* Funtion: transmitMsg Completed
 * Purpose: transmit a message from a city to a city
 * @param head - pointer to head of the list
 * @param reciever - the name of the city to recieve the message
 * @param message - the message to transmit
 */
 
void transmitMsg (city* head, string reciever, string message)
{
	if (head == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	else
	{
	    city* sender = head;
	    
	    while (sender->name != reciever && sender != NULL)
	    {
	        sender->message = message;
	        sender->numberMessages++;
	        
	        cout << sender->name << " [# messages passed: " << sender->numberMessages 
	             << "] received: " << sender-> message << endl;
	        
	        sender = sender->next;
	        
	    }
	    
	   sender->message = message;
	   sender->numberMessages++; 
	   cout << sender->name << " [# messages passed: " << sender->numberMessages 
	        << "] received: " << sender-> message << endl;
	}
 }
 
 /* Function: deleteCity Completed
  * Purpose: delete the city in the network with the specified name.
  * @param head - first node in the list
  * @param cityName - name of the city to delete in the network
  * @return - head node of list
  */
city* deleteCity(city *head, string cityName)
{
    city* del = head;
    city* prev = head;
    
    while (del->name != cityName && del != NULL)
    {
        del = del->next;
    }
    
    if (del == NULL)
    {
        cout << "City does not exist." << endl;
        return head;
    }
    else
    {
        if (del != head)
        {
            while (prev->next != del)
            {
                prev = prev->next;
            }
        
            prev->next = del->next;
        
            delete del;
        
            return head;
        }
        else
        {
            head = del->next;
            delete del;
            return head;
        }
    }
}
 
 /* Function: printPath
  * Purpose: prints the current list nicely
  * @param ptr - head of list
  */
 void printPath(city* ptr)
 {
	 cout << "== CURRENT PATH ==" << endl;
	 // If the head is NULL
	 if (ptr == NULL)
		 cout << "nothing in path" << endl;
	 else
	 {
		 while(ptr != NULL)
		 {
			 cout << ptr->name;
			 cout << " -> ";
			 ptr = ptr->next;
		 }
		 cout << " NULL" << endl;
	 }
	 
	 cout << "===" << endl;
 }
 
 /* Function: loadDefaultSetup Completed
  * Purpose: populates the network with the predetermined cities
  * @param head - start of list
  * @return - head of list
  */
city* loadDefaultSetup(city *head)
{
    city* prev;
    
    head = addCity(head,NULL,"Los Angeles");
    
    prev = searchNetwork(head, "Los Angeles");
    head = addCity(head,prev,"Phoenix");
    
    prev = searchNetwork(head, "Phoenix");
    head = addCity(head,prev,"Denver");
    
    prev = searchNetwork(head, "Denver");
    head = addCity(head,prev,"Dallas");
    
    prev = searchNetwork(head, "Dallas");
    head = addCity(head,prev,"Atlanta");
    
    prev = searchNetwork(head, "Atlanta");
    head = addCity(head,prev,"New York");
	
	return head;
}
  
/* Function: displayMenu DO NOT MODIFY THIS FUNCTION
 * Purpose: displays a menu with options 
 * DO NOT MODIFY THIS FUNCTION
 */
 void displayMenu()
 {
	 cout << "Select a numerical option:" << endl;
	 cout << "======Main Menu=====" << endl;
	 cout << "1. Build Network" << endl;
	 cout << "2. Print Network Path" << endl;
	 cout << "3. Transmit Message" << endl;
	 cout << "4. Add City" << endl;
	 cout << "5. Delete City" << endl;
	 cout << "6. Clear Network" << endl;
	 cout << "7. Quit" << endl;
 }
