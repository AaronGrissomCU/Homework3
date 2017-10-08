city* loadDefaultSetup(city *head)
{
    city* temp = NULL;
	city* prev = NULL;
    for (int c = 0; c < 6; c++)
    {
		temp = new city;
        switch (c)
        {
            case 0:
                temp->name = "Los Angeles"
				head = temp;
                break;
            case 1:
                temp->name = "Phoenix";
				prev->next = temp;
                break;
            case 2:
                temp->name = "Denver";
				prev->next = temp;
                break;
            case 3:
                temp->name = "Dallas";
				prev->next = temp;
                break;
            case 4:
                temp->name = "Atlanta";
				prev->next = temp;
                break;
            case 5:
                temp->name = "New York";
                break;
			default:
				cout << "Error" << endl;
        }
		prev = temp;
		temp->next = NULL;
		temp->numberMessages = 0;
		temp->message;
    }
}
