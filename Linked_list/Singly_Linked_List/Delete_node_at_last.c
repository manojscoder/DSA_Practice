#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void delete_last(struct node* head)
{
    if(head==NULL)
    printf("List is empty");
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node* temp=head;
        struct node* temp1=head;
        while(temp->link!=NULL)
        {
            temp1=temp;
            temp=temp->link;
        }
        temp1->link=NULL;
        free(temp);
        temp=NULL;
    }
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
    
    delete_last(head);
    
    struct node* ptr=head;
    
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
