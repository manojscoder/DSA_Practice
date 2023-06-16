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
       tail=addatbegin(data,tail);
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
void print(struct node* tail)
{
    struct node* ptr=tail->link;
    printf("%d ",ptr->data);
    ptr=ptr->link;
    while(ptr!=tail->link)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
struct node* createalist(struct node* tail)
{
    int n;
    printf("How many elements: ");
    scanf("%d",&n);
    if(n==0)
    return 0;
    else
    {
        int data;
        printf("\nEnter %d elements: ",n);
        scanf("%d",&data);
        tail=addtoempty(data);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&data);
            tail=addatend(data,tail);
        }
        return tail;
    }
}
int main()
{
    struct node* tail=NULL;
    tail=createalist(tail);
    if(tail!=0)
    print(tail);
    else
    printf("Empty");
    return 0;
}