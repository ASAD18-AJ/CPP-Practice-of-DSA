#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
// void ll(struct Node *head){
//     struct Node *ptr=head;
//     do{
//         printf("Element is %d \n",ptr->data);
//         ptr=ptr->next;
//     }while(ptr!=head);
// }

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 54;
    second->next = third;

    third->data = 34;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = head;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);

    return 0;
}