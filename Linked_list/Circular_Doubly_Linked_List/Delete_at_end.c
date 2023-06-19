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
    tail->next->prev=temp;
    return tail;
    }
}
struct node* addatend(struct node* tail,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=tail;
    temp->data=data;
    temp->next=tail->next;
    tail->next->prev=temp;
    tail->next=temp;
    tail=temp;
    return tail;
}
struct node* addatpos(struct node* tail,int pos,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    if(pos==1)
    {
        temp->prev=tail;
        temp->data=data;
        temp->next=tail->next;
        tail->next->prev=temp;
        tail->next=temp;
        return tail;
    }
    else{
        struct node* temp1=tail->next;
        pos--;
        while(pos!=1)
        {
            temp1=temp1->next;
            pos--;
        }
        temp->prev=temp1;
        temp->data=data;
        temp->next=temp1->next;
        temp1->next->prev=temp;
        temp1->next=temp;
        if(temp->prev==tail)
        {
            return tail->next;
        }
        else
        return tail;
    }
}
struct node* delatfront(struct node* tail)
{
    struct node* temp=tail->next;
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    temp=NULL;
    return tail;
}
struct node* delatend(struct node* tail)
{
    struct node* temp=tail;
    tail=tail->prev;
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    temp=NULL;
    return tail;
    
}
int main()
{
    struct node* tail=NULL;
    tail=addtoempty(45);
    tail=addatbegin(tail,34);
    tail=addatend(tail,56);
    tail=addatpos(tail,3,23);
    tail=delatfront(tail);
    tail=delatend(tail);
    struct node* ptr=tail->next;
    printf("%d ",ptr->data);
    ptr=ptr->next;
    while(ptr!=tail->next)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
}
