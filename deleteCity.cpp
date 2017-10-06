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
        while (prev->next != del)
        {
            prev = prev->next;
        }
        
        prev->next = del->next;
        
        delete del;
        
        return head;
    }
}
