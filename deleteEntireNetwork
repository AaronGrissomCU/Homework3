city* deleteEntireNetwork(city *ptr)
{
    city* del;
    
    while (ptr != NULL)
    {
        cout << "deleting: " << ptr->name << endl;
        del = ptr;
        ptr = ptr->next;
        delete del;
    }
    cout << "Deleted network" << endl;
    return ptr;
}
