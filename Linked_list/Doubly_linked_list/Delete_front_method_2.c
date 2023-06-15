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
    head=DelAtFirst(head);
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
