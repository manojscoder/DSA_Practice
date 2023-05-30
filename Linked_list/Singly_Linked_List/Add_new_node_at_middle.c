#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void add_middle(int pos,struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    struct node* ptr=head;
    for(int i=0;i<pos-2;i++)
    {
        ptr=ptr->link;
    }
    /*pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }*/
    temp->data=data;
    temp->link=ptr->link;
    ptr->link=temp;
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
    current->data=18;
    current->link=NULL;
    head->link->link=current;
    //New node to be inserted at middle
    int pos=3,data=16;
    
    add_middle(pos,head,data);
    
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
