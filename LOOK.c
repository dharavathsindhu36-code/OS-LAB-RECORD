#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int request[100], n;
    int head, direction;
    int i, pos = 0;
    int totalMovement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    sort(request, n);


    for (i = 0; i < n; i++)
    {
        if (request[i] >= head)
        {
            pos = i;
            break;
        }
    }

    printf("\nLOOK Disk Scheduling Order:\n");
    printf("%d", head);

    if (direction == 1)
    {

        for (i = pos; i < n; i++)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", head);
        }


        for (i = pos - 1; i >= 0; i--)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", head);
        }
    }
    else
    {

        for (i = pos - 1; i >= 0; i--)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", head);
        }


        for (i = pos; i < n; i++)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}

