#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* left;
    int data;
    struct node* right;
};
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->left=head;
    head->data=24;
    head->right=head;
    struct node* current=malloc(sizeof(struct node));
    current->left=head;
    current->data=43;
    current->right=head;
    head->right=current;
    head->left=current;
    current=malloc(sizeof(struct node));
    current->left=head->right;
    current->data=93;
    current->right=head;
    head->right->right=current;
    head->left=current;
    struct node* ptr=head;
    printf("%d ",ptr->data);
    ptr=ptr->right;
    while(ptr!=head)
    {
        printf("%d ",ptr->data);
        ptr=ptr->right;
    }
    return 0;
}
