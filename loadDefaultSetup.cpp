city* loadDefaultSetup(city *head)
{
	city* prev= NULL;
	
	for (int c = 0; c < 6; c++)
	{
		city* newCity = new city;
		switch(c)
		{
			case 0:
				newCity->name = "Los Angeles";
				break;
			case 1:
				newCity->name = "Phoenix";
				break;
			case 2:
				newCity->name = "Denver";
				break;
			case 3:
				newCity->name = "Dallas";
				break;
			case 4:
				newCity->name = "Atlanta";
				break;
			case 5:
				newCity->name = "New York";
				break;
		}
		newCity->next = NULL;
		newCity->numberMessages = 0;
		
		if (c == 0)
		{
			head = newCity;
		}
		else
		{
			prev = newCity;
		}
		
		if (prev != NULL)
		{
			prev->next = newCity;
		}
	}
}
