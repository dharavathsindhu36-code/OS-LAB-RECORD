#include <stdio.h>

int main() {
    int pageSize, numPages, numFrames;
    int pageTable[50];
    int logicalAddress, pageNumber, offset;
    int frameNumber, physicalAddress;

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter number of pages: ");
    scanf("%d", &numPages);

    printf("Enter number of frames: ");
    scanf("%d", &numFrames);

    // Check if enough frames are available
    if (numPages > numFrames) {
        printf("\nError: Number of pages cannot be greater than number of frames.\n");
        return 0;
    }

    // Enter page table
    printf("\nEnter the frame number for each page:\n");

    for (int i = 0; i < numPages; i++) {
        printf("Page %d -> Frame ", i);
        scanf("%d", &pageTable[i]);

        // Validate frame number
        if (pageTable[i] < 0 || pageTable[i] >= numFrames) {
            printf("Invalid frame number!\n");
            return 0;
        }
    }

    // Display page table
    printf("\nPage Table:\n");
    printf("Page\tFrame\n");

    for (int i = 0; i < numPages; i++) {
        printf("%d\t%d\n", i, pageTable[i]);
    }

    // Enter logical address
    printf("\nEnter logical address: ");
    scanf("%d", &logicalAddress);

    // Calculate page number and offset
    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    // Check whether page number is valid
    if (pageNumber >= numPages) {
        printf("\nInvalid logical address!\n");
        return 0;
    }

    // Find corresponding frame
    frameNumber = pageTable[pageNumber];

    // Calculate physical address
    physicalAddress = (frameNumber * pageSize) + offset;

    printf("\nLogical Address  : %d", logicalAddress);
    printf("\nPage Number      : %d", pageNumber);
    printf("\nOffset           : %d", offset);
    printf("\nFrame Number     : %d", frameNumber);
    printf("\nPhysical Address : %d\n", physicalAddress);

    return 0;
}

