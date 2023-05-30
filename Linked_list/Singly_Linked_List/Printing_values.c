#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void print(struct node* head)
{
    struct node* ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

int main()
{
    struct node* head=(struct node *)malloc(sizeof(struct node));
    head->data=5;
    head->link=NULL;
    
    struct node* current=malloc(sizeof(struct node));
    current->data=7;
    current->link=NULL;
    head->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=8;
    current->link=NULL;
    head->link->link=current;
    
    print(head);
    return 0;
}
