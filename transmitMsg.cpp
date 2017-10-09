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
