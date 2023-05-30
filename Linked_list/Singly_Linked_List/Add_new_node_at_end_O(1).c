#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void add_at_last(struct node* head,int data)
{
    struct node* ptr=head;
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=12;
    head->link=NULL;
    
    struct node* current=malloc(sizeof(struct node));
    current->data=23;
    current->link=NULL;
    
    head->link=current;
    
    add_at_last(head,90);
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
