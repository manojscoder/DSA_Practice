#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addtoempty(int data)
{
    struct node* tail=malloc(sizeof(struct node));
    tail->prev=tail;
    tail->data=data;
    tail->next=tail;
    return tail;
}
struct node* addatbegin(struct node* tail,int data)
{
    if(tail->prev==tail)
    {
        struct node* temp=malloc(sizeof(struct node));
        temp->prev=tail;
        temp->data=data;
        temp->next=tail->next;
        tail->next=temp;
        tail->prev=temp;
        return tail;
    }
    else
    {
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=tail;
    temp->data=data;
    temp->next=tail->next;
    tail->next=temp;
    return tail;
    }
}
int main()
{
    struct node* tail=NULL;
    tail=addtoempty(32);
    tail=addatbegin(tail,46);
    tail=addatbegin(tail,67);
    struct node* ptr=tail->next;
    printf("%d ",ptr->data);
    ptr=ptr->next;
    while(ptr!=tail->next)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
}
