#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* add_front(struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=head;
    return temp;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    struct node* head=malloc(sizeof(struct node));
    scanf("%d",&m);
    head->data=m;
    head->link=NULL;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&m);
        head=add_front(head,m);
    }
    
    struct node* ptr=head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
