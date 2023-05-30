#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void add_front(struct node **head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=*head;
    *head=temp;
}
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=12;
    head->link=NULL;
    
    int new=21;
    add_front(&head,new);
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
