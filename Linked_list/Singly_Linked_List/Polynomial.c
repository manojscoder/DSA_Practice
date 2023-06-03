#include<stdio.h>
#include<stdlib.h>
struct node{
    float co;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head,int co,int expo)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->co=co;
    temp->expo=expo;
    temp->link=NULL;
    if(head==NULL || head->expo<expo)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
        struct node* temp1=head;
        while(temp1->link!=NULL && temp1->link->expo>=expo)
        {
            temp1=temp1->link;
        }
        temp->link=temp1->link;
        temp1->link=temp;
    }
    return head;
}
struct node* create(struct node* head)
{
    int n,expo;
    float co;
    
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the coefficient of term %d: ",i+1);
        scanf("%f",&co);
        printf("\nEnter the exponent of term %d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,co,expo);
    }
    return head;
}
int main()
{
    struct node* head=NULL;
    head=create(head);
    int i=1;
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("(%.1fx^%d)",ptr->co,ptr->expo);
        if(ptr->link!=NULL)
        {
            printf("+");
        }
        ptr=ptr->link;
    }
}
