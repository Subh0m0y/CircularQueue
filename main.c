#include <stdio.h>
#include <stdlib.h>

#define CONTENT 5
#define MAX (CONTENT + 1)

void insert(int queue[], const int *front, int *rear, int x)
{
    *rear = (*rear + 1) % MAX;
    if (*rear == *front)
    {
        printf("Queue is full.\n");
        *rear = *rear == 0 ? MAX - 1 : *rear - 1;
        return;
    }
    queue[*rear] = x;
}

int delete(const int queue[], int *front, const int *rear)
{
    if (*front == *rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    *front = (*front + 1) % MAX;
    return queue[*front];
}

void display(int queue[], const int *front, const int *rear)
{
    if (*front == *rear)
    {
        printf("Queue is empty.\n");
        return;
    }
    int index = *front;
    while (index != *rear)
    {
        index = (index + 1) % MAX;
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main()
{
    int queue[MAX];
    int front = 0, rear = 0;

    while (1)
    {
        printf("\nCircular Queue operations:\n\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice :");
        int choice, x;
        scanf("%d", &choice); // NOLINT
        switch (choice)
        {
            case 1:
                if ((rear + 1) % MAX == front)
                {
                    printf("Queue full.\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &x); // NOLINT
                insert(queue, &front, &rear, x);
                break;
            case 2:
                if (rear == front)
                {
                    printf("Queue empty.\n");
                    break;
                }
                x = delete(queue, &front, &rear);
                printf("Deleted element is: %d\n", x);
                break;
            case 3:
                display(queue, &front, &rear);
                break;
            case 4:
                return EXIT_SUCCESS;
            default:
                printf("Unrecognised choice. Try again.\n");
        }
    }
}