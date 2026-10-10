#include <stdio.h>
int main()
{
    int pages[100], frames[20];
    int n, frameCount;
    int i, j, k;
    int pageFaults = 0, pageHits = 0;
    int found;
    int replaceIndex;
    int farthest;
    int nextUse;

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


            replaceIndex = -1;

            for (j = 0; j < frameCount; j++)
            {
                if (frames[j] == -1)
                {
                    replaceIndex = j;
                    break;
                }
            }
            if (replaceIndex == -1)
            {
                farthest = -1;

                for (j = 0; j < frameCount; j++)
                {
                    nextUse = -1;
                    for (k = i + 1; k < n; k++)
                    {
                        if (pages[k] == frames[j])
                        {
                            nextUse = k;
                            break;
                        }
                    }

                    if (nextUse == -1)
                    {
                        replaceIndex = j;
                        break;
                    }
                    if (nextUse > farthest)
                    {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }
            }
            frames[replaceIndex] = pages[i];

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






