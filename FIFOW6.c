#include <stdio.h>

int main()
{
    int pages[100], frames[20];
    int n, frameCount;
    int i, j;
    int pointer = 0;
    int pageFaults = 0, pageHits = 0;
    int found;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);

    // Initially all frames are empty
    for (i = 0; i < frameCount; i++)
    {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\tStatus\n");

    for (i = 0; i < n; i++)
    {
        found = 0;

        // Check whether page is already present
        for (j = 0; j < frameCount; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            pageHits++;
            printf("%d\t", pages[i]);

            for (j = 0; j < frameCount; j++)
            {
                if (frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }

            printf("\tHit\n");
        }
        else
        {
            pageFaults++;

            // Replace page using FIFO
            frames[pointer] = pages[i];

            pointer = (pointer + 1) % frameCount;

            printf("%d\t", pages[i]);

            for (j = 0; j < frameCount; j++)
            {
                if (frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }

            printf("\tPage Fault\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    printf("Total Page Hits   = %d\n", pageHits);

    return 0;
}
