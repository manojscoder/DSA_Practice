#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* add_at_last(struct node* ptr,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    
    ptr->link=temp;
    return ptr->link;
}
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=12;
    head->link=NULL;
    
    struct node* ptr=head;
    ptr=add_at_last(ptr,13);
    ptr=add_at_last(ptr,14);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
