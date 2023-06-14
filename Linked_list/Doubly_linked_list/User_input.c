#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* AddToEmpty(struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* AddAtBeg(struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
void AddAtEnd(struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    struct node* temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
    temp->prev=temp1;
    temp->data=data;
    temp->next=NULL;
}
int main()
{
    struct node* head=NULL;
    int n,m;
    printf("How many elements: ");
    scanf("%d",&n);
    printf("\nEnter %d elements: ",n);
    for(int i=0;i<n;i++)
    {
    if(i==0){
    scanf("%d",&m);
    head=AddToEmpty(head,m);}
    else
    {
    //head=AddAtBeg(head,23);
    scanf("%d",&m);
    AddAtEnd(head,m);
    }
    }
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}
