#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* delete_front(struct node* head)
{
    if(head==NULL)
    printf("List is empty");
    else{
    struct node* temp=head;
    head=temp->link;
    free(temp);
    }
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
    
    head=delete_front(head);
    
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
