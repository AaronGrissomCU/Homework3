city* loadDefaultSetup(city *head)
{
    city* temp = NULL;
	city* prev = NULL;
	int counter = 0;
	
	do
	{
		temp = new city;
		switch (counter)
		{
			case 0:
				temp->name = "Los Angeles";
				break;
			case 1:
				temp->name = "Phoenix";
				break;
			case 2:
				temp->name = "Denver";
				break;
			case 3:
				temp->name = "Dallas";
				break;
			case 4:
				temp->name = "Atlanta";
				break;
			case 5:
				temp->name = "New York";
				break;
		}
		temp->next = NULL;
		temp->numberMessages = 0;
		temp->message;
		
		if (counter == 1)
		{
			head = temp;
			prev = temp;
		}
		else
		{
			prev->next = temp;
			prev = temp;
		}
	} while (counter < 5);
}
