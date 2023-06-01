#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* reverse(struct node* head)
{
    struct node* temp=NULL;
    struct node* temp1=NULL;
    while(head!=NULL)
    {
        temp1=head->link;
        head->link=temp;
        temp=head;
        head=temp1;
    }
    head=temp;
    return head;
}
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=12;
    head->link=NULL;
    
    struct node* current=malloc(sizeof(struct node));
    current->data=14;
    current->link=NULL;
    head->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=16;
    current->link=NULL;
    head->link->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=18;
    current->link=NULL;
    head->link->link->link=current;
    
    head=reverse(head);
    
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
