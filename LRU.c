#include <stdio.h>

int main()
{
    int pages[100], frames[20];
    int recent[20];
    int n, frameCount;
    int i, j;
    int time = 0;
    int pageFaults = 0, pageHits = 0;
    int found;
    int lruIndex;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);
    for (i = 0; i < frameCount; i++)
    {
        frames[i] = -1;
        recent[i] = 0;
    }

    printf("\nPage\tFrames\t\tStatus\n");

    for (i = 0; i < n; i++)
    {
        found = 0;
        time++;
        for (j = 0; j < frameCount; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                recent[j] = time;
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
            lruIndex = -1;

            for (j = 0; j < frameCount; j++)
            {
                if (frames[j] == -1)
                {
                    lruIndex = j;
                    break;
                }
            }
            if (lruIndex == -1)
            {
                lruIndex = 0;

                for (j = 1; j < frameCount; j++)
                {
                    if (recent[j] < recent[lruIndex])
                    {
                        lruIndex = j;
                    }
                }
            }

            frames[lruIndex] = pages[i];
            recent[lruIndex] = time;

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

