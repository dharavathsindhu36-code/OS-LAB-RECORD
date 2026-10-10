#include <stdio.h>
#include <stdlib.h>

int main()
{
    int request[100], n;
    int head, direction;
    int i, j, temp;
    int totalSeek = 0;
    int current;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request queue:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &direction);


    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    current = head;

    printf("\nC-SCAN Seek Sequence: %d", current);

    if (direction == 1)
    {

        for (i = 0; i < n; i++)
        {
            if (request[i] >= head)
            {
                totalSeek += abs(current - request[i]);
                current = request[i];
                printf(" -> %d", current);
            }
        }


        for (i = 0; i < n; i++)
        {
            if (request[i] < head)
            {
                totalSeek += abs(current - request[i]);
                current = request[i];
                printf(" -> %d", current);
            }
        }
    }
    else
    {

        for (i = n - 1; i >= 0; i--)
        {
            if (request[i] <= head)
            {
                totalSeek += abs(current - request[i]);
                current = request[i];
                printf(" -> %d", current);
            }
        }


        for (i = n - 1; i >= 0; i--)
        {
            if (request[i] > head)
            {
                totalSeek += abs(current - request[i]);
                current = request[i];
                printf(" -> %d", current);
            }
        }
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);

    return 0;
}

