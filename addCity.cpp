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
	    cout << "prev: " << previous->name << " new: " << cityName << endl;
		newCity->next = previous->next;
		previous->next = newCity;
	}
    
	return head;
}
