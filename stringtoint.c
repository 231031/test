#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    char str[50];
    char *str2;
    char temp;
    int num[20];
    int i = 0;
    int j = 0;
    fgets(str, 50, stdin);
    while (str[j] != 'E')
    {
        if (str[j] == ' ') // number
        {
            i++;
        }
        j++;
    }
    printf("blank space: %d\n", i);
    
    str2 = str;
    j = 0;
    while (j < i)
    {
        sscanf(str2, "%d %c", &num[j], &temp);
        str2++;
        str2++;
        printf("%d ", num[j]);
        j++;
    }
    /*
    while (j < i)
    {
        printf("%d ", num[j]);
        j++;
    }

    i = 0;
    while (str[i] != 'E')
    {
        if (str[i] != 'q')
        {
            num[j] = atoi(str[i]);
            printf("%d ", num[j]);
            j++;
            i++;
        }
        else
        {
            i++;
        }
    }*/
    
    
    return 0;
}


    /*
    while (node->next != NULL)
    {
        if (prePreptr->data == preptr->data)
        {
            // free(prePreptr);
            // free(preptr);
            prePreptr = preptr;
            preptr = ptr;
            ptr = ptr->next;
        }
        else if (prePreptr->data == preptr->data)
        {

            preptr = ptr;
        }
        else
        {
            ptr = ptr->next;
            node = node->next;
        }*/

        /*
        if (prePreptr->data == preptr->data && preptr->data == ptr->data)
        {
            prePreptr->next = ptr->next;
            printf("%d ", prePreptr->data);
        }
        else if (prePreptr->data == preptr->data && preptr->data != ptr->data)
        {
            prePreptr->next = preptr->next;
        }
        else if (preptr->data == ptr->data)
        {
            prePreptr->next = ptr->next;
            printf("%d", prePreptr->data);
        }
        else
        {
            prePreptr = prePreptr->next;
        }
        preptr = prePreptr->next;
        ptr = preptr->next;
        // ptr = ptr->next->next;
    }*/




        /*
    node = *start;
    preptr = (*start)->next;
    if (preptr == NULL)
    {
        return 0;
    }
    midptr = preptr->next;
    ptr = midptr->next;
    while (ptr != NULL && midptr != NULL) 
    {
        num = preptr->data;
        if (midptr->data == preptr->data && midptr->data != ptr->data)
        {
            node->next = ptr;
            if (preptr->next->next != NULL)
            {
                break;
            }
            preptr = preptr->next;
            midptr = preptr->next;
            ptr->next = ptr->next;
        }
        else if (midptr->data == preptr->data && midptr->data == ptr->data && ptr->next->data != num)
        {
            num = preptr->data;
            node->next = ptr->next;
            preptr = node->next;
            midptr = preptr->next;
            ptr = midptr->next;
        }
        else if (midptr->data == preptr->data && midptr->data == ptr->data && ptr->next->data == num)
        {
            node->next = ptr->next->next;
            preptr = node->next;
            midptr = preptr->next;
            ptr = midptr->next;
        }
        else
        {
            node = node->next;
            preptr = preptr->next;
            midptr = preptr->next;
            ptr = ptr->next;
        }
    }
    */