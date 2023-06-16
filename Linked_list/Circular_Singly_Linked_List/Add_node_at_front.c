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
int main()
{
    int data=23;
    struct node* tail=NULL;
    tail=addtoempty(data);
    data=34;
    tail=addatbegin(data,tail);
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
