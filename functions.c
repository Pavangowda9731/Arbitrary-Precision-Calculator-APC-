#include "header_file.h"
Status insert_arguments(Dlist **head1,Dlist** tail1,Dlist** head2,Dlist** tail2,char* argv1,char* argv2)
{
	insert_at_last(head1,tail1,argv1);
	insert_at_last(head2,tail2,argv2);

}

Status insert_at_last(Dlist** head,Dlist** tail,char* argv)
{
	for(int i=0;i<strlen(argv);i++)
	{
		Dlist* new = malloc(sizeof(Dlist));
		if(new == NULL)
		{
			printf("Memory allocation failed\n");
			return failure;
		}
		if(argv[i] != '-' && argv[i] != '+')
		{
			new->data = argv[i] - 48;
			if(new->data >= 0 && new->data <= 9)
			{
				new->prev = NULL;
				new->next = NULL;
				if(*head == NULL)
				{
					*head = new;
					*tail = new;
				}
				else
				{
					new->prev = *tail;
					(*tail)->next = new;
					*tail = new;
				}
			}
		}
	}
	return success;
}

Status free_all(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** head3,Dlist** tail3)
{
	free_node(head1,tail1);
	free_node(head2,tail2);
	free_node(head3,tail3);
}

void free_node(Dlist** head,Dlist** tail)
{
	Dlist* temp = (*head);
	Dlist* back_up = NULL;
	while(temp != NULL)
	{
		back_up = temp->next;
		free(temp);
		temp = back_up;
	}
	*head = NULL;
	*tail = NULL;
}

int find_bigger(Dlist** head1,Dlist** head2)
{
	Dlist* temp = *head1;
	Dlist* temp2 = *head2;
	while(temp && temp2)
	{
		if(temp->data > temp2->data)
			return 1;
		else if(temp2->data > temp->data)
			return 3;
		temp = temp->next;
		temp2 = temp2->next;

	}
	return 0;
}

void print_result(Dlist** head,Dlist** tail)
{
	printf("Result is ");
	Dlist* temp = *head;
	while(temp != NULL)
	{
		if(temp->data == '-')
		{
			printf("%c",'-');
		}
		else
		{
			printf("%d",temp->data);
		}
		temp = temp->next;
	}
	printf("\n");
}

int find_length(char* argv)
{
	int i = 0,count = 0;
	while(argv[i] != '\0')
	{
		if(argv[i] == '-' || argv[i] == '+')
		{
			i++;
			continue;
		}
		else
		{
			count++;
			i++;
		}
	}
	return count;
}


int is_zero(Dlist *head)
{
    while(head)
    {
        if(head->data != 0)
            return 0;
        head = head->next;
    }
    return 1;
}