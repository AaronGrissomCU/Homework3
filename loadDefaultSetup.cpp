city* loadDefaultSetup(city *head)
{
    city* prev;
    
    head = deleteEntireNetwork(head);
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
