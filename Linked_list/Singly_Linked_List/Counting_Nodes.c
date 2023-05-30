#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void count(struct node* head)
{
    int count=0;
    if(head==NULL)
    printf("Linked list is empty.");
    struct node* ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("%d",count);
}
int main()
{
    struct node* head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    
    struct node* current=(struct node *)malloc(sizeof(struct node));
    current->data=23;
    current->link=NULL;
    head->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=7;
    current->link=NULL;
    head->link->link->link=current;
    
    count(head);
    
    return 0;
}
