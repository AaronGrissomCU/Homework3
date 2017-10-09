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
