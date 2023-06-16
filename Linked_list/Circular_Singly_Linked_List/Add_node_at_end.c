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
int main()
{
    struct node* tail=NULL;
    tail=addtoempty(23);
    tail=addatbegin(34,tail);
    tail=addatend(25,tail);
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
