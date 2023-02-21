    // 3 2 3 2 3 3 1 END
    // case 7 8 8 7 8
    ptrEnd = *start;
    checkNew = 0;
    while (ptrStart->data != ptrEnd->data || endIndexNew <= endIndex / 2)
    {
        ptrEnd = ptrEnd->next;
        endIndexNew++;
        if (endIndexNew > endIndex) // checkNew it can end loop by itself
        {
            checkNew++;
            break;
        }
    }