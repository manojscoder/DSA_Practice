#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=24;
    head->link=head;
    struct node* current=malloc(sizeof(struct node));
    current->data=12;
    current->link=head;
    head->link=current;
    current=malloc(sizeof(struct node));
    current->data=52;
    current->link=head;
    head->link->link=current;
    struct node* ptr=head;
    printf("%d ",ptr->data);
    ptr=ptr->link;
    while(ptr!=head)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
