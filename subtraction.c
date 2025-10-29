/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/


#include "header_file.h"

Status do_subt(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    int sub = 0;
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;
    Dlist *temp3;

    while (temp1 != NULL || temp2 != NULL)
    {
        int d1 = (temp1) ? temp1->data : 0;
        int d2 = (temp2) ? temp2->data : 0;

        if (d1 >= d2)
        {
            sub = d1 - d2;
        }
        else
        {
            temp3 = (temp1) ? temp1->prev : NULL;

            while (temp3 != NULL)
            {
                if (temp3->data > 0)
                {
                    (temp3->data)--;
                    break;
                }
                else
                {
                    temp3->data = 9;
                }
                temp3 = temp3->prev;
            }

            sub = (d1 + 10) - d2;
        }

        add_result(headR, tailR, sub);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    return SUCCESS;
}
