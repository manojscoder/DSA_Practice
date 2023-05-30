#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void delete_position(struct node **head,int pos)
{
    struct node* temp=*head;
    struct node* temp1=*head;
    if(*head==NULL)
    printf("List is empty");
    else if(pos==1)
    {
        *head=temp->link;
        free(temp);
        temp=NULL;
    }
    else
    {
    int i=0;
    while(i<pos-1)
    {
        temp1=temp;
        temp=temp->link;
        i++;
    }
    temp1->link=temp->link;
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
    int pos=2;
    delete_position(&head,pos);
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
