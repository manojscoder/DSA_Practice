#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addtoempty(struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* addatend(struct node* head,int data)
{
    struct node* temp1=head;
    struct node* temp=malloc(sizeof(struct node));
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp->prev=temp1;
    temp->data=data;
    temp->next=NULL;
    temp1->next=temp;
    return head;
}
struct node* DelAtFirst(struct node* head)
{
    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}
struct node* DelAtPos(struct node* head,int pos)
{
    struct node* temp=head;
    if(pos==1)
    return DelAtFirst(head);
    else
    {
    
        while(pos!=1)
        {
            temp=temp->next;
            pos--;
        }
        if(temp->next==NULL)
        {
            DelAtLast(head);
        }
        else{
        temp->prev->next=temp->next;
        temp->next=temp->prev;
        free(temp);
        temp=NULL;
        }
    }
    return head;
}
void DelAtLast(struct node* head)
{
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    temp=NULL;
}
int main()
{
    struct node* head=NULL;
    int data,n,i;
    printf("Enter how many elements:");
    scanf("%d",&n);
    if(n==0)
    printf("empty");
    else
    {
        printf("\nEnter %d elements: ",n);
        scanf("%d",&data);
        head=addtoempty(head,data);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&data);
            head=addatend(head,data);
        }
    }
    //head=DelAtFirst(head);
    int pos=5;
    head=DelAtPos(head,pos);
    //DelAtLast(head);
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addtoempty(struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* addatend(struct node* head,int data)
{
    struct node* temp1=head;
    struct node* temp=malloc(sizeof(struct node));
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp->prev=temp1;
    temp->data=data;
    temp->next=NULL;
    temp1->next=temp;
    return head;
}
struct node* DelAtFirst(struct node* head)
{
    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}
struct node* DelAtPos(struct node* head,int pos)
{
    struct node* temp=head;
    if(pos==1)
    return DelAtFirst(head);
    else
    {
    
        while(pos!=1)
        {
            temp=temp->next;
            pos--;
        }
        temp->prev->next=temp->next;
        temp->next=temp->prev;
        free(temp);
        temp=NULL;
    }
    return head;
}
int main()
{
    struct node* head=NULL;
    int data,n,i;
    printf("Enter how many elements:");
    scanf("%d",&n);
    if(n==0)
    printf("empty");
    else
    {
        printf("\nEnter %d elements: ",n);
        scanf("%d",&data);
        head=addtoempty(head,data);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&data);
            head=addatend(head,data);
        }
    }
    //head=DelAtFirst(head);
    int pos=3;
    head=DelAtPos(head,pos);
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
