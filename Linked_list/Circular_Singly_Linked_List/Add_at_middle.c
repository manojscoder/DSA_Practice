#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* addtoempty(int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=temp;
    return temp;
}
struct node* addatbegin(int data,struct node* tail)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=tail->link;
    tail->link=temp;
    return tail;
}
struct node* addatend(int data,struct node* tail)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=tail->link;
    tail->link=temp;
    tail=temp;
    return tail;
}
struct node* addatbet(int data,struct node* tail,int pos)
{
    struct node* temp=malloc(sizeof(struct node));
    if(pos==1)
    {
        temp->data=data;
        temp->link=tail->link;
        tail->link=temp;
    }
    else
    {
        struct node* temp1=tail->link;
        pos--;
        while(pos!=1)
        {
            temp1=temp1->link;
            pos--;
        }
        if(temp1->link==tail->link)
        {
            tail=addatend(data,tail);
        }
        else{
        temp->data=data;
        temp->link=temp1->link;
        temp1->link=temp;
        }
    }
    return tail;
}
int main()
{
    struct node* tail=NULL;
    tail=addtoempty(45);
    tail=addatbegin(34,tail);
    tail=addatend(6,tail);
    tail=addatend(56,tail);
    tail=addatbet(23,tail,5);
    struct node* ptr=tail->link;
    printf("%d ",ptr->data);
    ptr=ptr->link;
    while(ptr!=tail->link)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
