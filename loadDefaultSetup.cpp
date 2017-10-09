city* loadDefaultSetup(city *head)
{
		city* LosAngeles = new city;
		city* Phoenix = new city;
		city* Denver = new city;
		city* Dallas = new city;
		city* Atlanta = new city;
		city* NewYork = new city;
		
		LosAngeles->name = "Los Angeles";
		Phoenix->name = "Phoenix";
		Denver->name = "Denver";
		Dallas->name = "Dallas";	
		Atlanta->name = "Atlanta";
		NewYork->name = "New York";
		
		head = LosAngeles;
		LosAngeles->next = Phoenix;
		Phoenix->next = Denver;
		Denver->next = Dallas;
		Dallas->next = Atlanta;
		Atlanta->next = NewYork;
		NewYork->next = NULL;
		
		LosAngeles->numberMessages = 0;
		Phoenix->numberMessages = 0;
		Denver->numberMessages = 0;
		Dallas->numberMessages = 0;	
		Atlanta->numberMessages = 0;
		NewYork->numberMessages = 0;
		
		return head;
}
