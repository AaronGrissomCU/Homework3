city* deleteCity(city *head, string cityName)
{
    city* del = NULL;
    city* prev = head;
    
    while (prev->next->name != cityName && prev != NULL)
    {
        prev = prev->next;
    }
    
    if (prev == NULL)
    {
        cout << "City does not exist." << endl;
        return head;
    }
    
    else
    {
        del = prev->next;
        prev->next = del->next;
        
        delete del;
    }
}
