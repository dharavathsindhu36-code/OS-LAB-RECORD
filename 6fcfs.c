#include <stdio.h>

  int main() {
    int n, m;
    int allocation[10][10], max[10][10], need[10][10];
    int available[10], work[10];
    int finish[10] = {0};
    int safeSequence[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Maximum Matrix
    printf("\nEnter Maximum Requirement Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &available[j]);
        work[j] = available[j];
    }

    // Calculate Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Display Need Matrix
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Find Safe Sequence
    int count = 0;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {

            if (finish[i] == 0) {
                int canExecute = 1;

                // Check if current process can get all required resources
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                // If resources are enough, process can finish
                if (canExecute) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process could execute, system is unsafe
        if (found == 0) {
            printf("\nSystem is NOT in a safe state.\n");
            return 0;
        }
    }

    // System is safe
    printf("\nSystem is in a SAFE state.\n");

    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", safeSequence[i]);

        if (i != n - 1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}


Process P1: 2 0 0
Process P2: 3 0 2
Process P3: 2 1 1
Process P4: 0 0 2

Enter Maximum Requirement Matrix:
Process P0: 7 5 3
Process P1: 3 2 2
Process P2: 9 0 2
Process P3: 2 2 2
Process P4: 4 3 3

Enter Available Resources:
3 3 2

Sample Output
Need Matrix:
P0: 7 4 3
P1: 1 2 2
P2: 6 0 0
P3: 0 1 1
P4: 4 3 1

System is in a SAFE state.
Safe Sequence: P1 -> P3 -> P4 -> P0 -> P2

Short explanation
The program uses three main matrices:

Allocation – resources currently allocated to each process.

Max – maximum resources each process may need.

Need – remaining resources required, calculated as:
Need = Max - Allocation

Available – resources currently available.

Banker’s Algorithm repeatedly checks whether a process's Need ≤ Available. If it is, that process can safely finish, and its allocated resources are returned to the available pool. If all processes can finish, the system is safe and the program prints the safe sequence.



You said:

implementation of paging technique of memory manage ment give code by using c

ChatGPT said:
C Program: Implementation of Paging Technique
Here is a simple, student-friendly C program to implement the paging technique of memory management. It converts a logical address into a physical address using a page table.

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

Sample Input
Enter page size: 100
Enter number of pages: 4
Enter number of frames: 6

Enter the frame number for each page:
Page 0 -> Frame 3
Page 1 -> Frame 0
Page 2 -> Frame 5
Page 3 -> Frame 2

Enter logical address: 250

Sample Output
Page Table:
Page    Frame
0       3
1       0
2       5
3       2

Logical Address  : 250
Page Number      : 2
Offset           : 50
Frame Number     : 5
Physical Address : 550

How it works
The logical address is divided into page number and offset:

Page Number = Logical Address / Page Size
Offset      = Logical Address % Page Size

Then the page table gives the corresponding frame number.

Finally:

Physical Address = (Frame Number × Page Size) + Offset

For the example:

Logical Address = 250
Page Size       = 100

Page Number = 250 / 100 = 2
Offset      = 250 % 100 = 50

Page 2 → Frame 5

Physical Address = (5 × 100) + 50
                 = 550

This version is suitable for an Operating Systems lab record/program and is kept straightforward so you can explain it easily during a viva.



You said:

GIVE ONE more outputt

ChatGPT said:
Sure! Here is one more sample output for the paging program.

Sample Output 2
Enter page size: 128
Enter number of pages: 5
Enter number of frames: 8

Enter the frame number for each page:
Page 0 -> Frame 4
Page 1 -> Frame 7
Page 2 -> Frame 1
Page 3 -> Frame 6
Page 4 -> Frame 2

Page Table:
Page    Frame
0       4
1       7
2       1
3       6
4       2

Enter logical address: 300

Logical Address  : 300
Page Number      : 2
Offset           : 44
Frame Number     : 1
Physical Address : 172

Calculation:

Page Number = 300 / 128 = 2
Offset      = 300 % 128 = 44

Page 2 → Frame 1

Physical Address = (1 × 128) + 44
                 = 172



You said:

. Simulate the following Disk scheduling algorithms.
a. FCFS b) SSTF c) SCAN
GIVE CODE by using c

ChatGPT said:
Sure. Below is a simple, student-friendly C program that simulates all three disk scheduling algorithms:

FCFS – First Come First Serve

SSTF – Shortest Seek Time First

SCAN – Elevator algorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to calculate absolute difference
int difference(int a, int b) {
    return abs(a - b);
}

// FCFS Algorithm
void FCFS(int requests[], int n, int head) {
    int totalSeek = 0;
    int current = head;

    printf("\n--- FCFS Disk Scheduling ---\n");
    printf("Seek Sequence: %d", current);

    for (int i = 0; i < n; i++) {
        totalSeek += difference(current, requests[i]);
        current = requests[i];
        printf(" -> %d", current);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
}

// SSTF Algorithm
void SSTF(int requests[], int n, int head) {
    int visited[MAX] = {0};
    int totalSeek = 0;
    int current = head;

    printf("\n--- SSTF Disk Scheduling ---\n");
    printf("Seek Sequence: %d", current);

    for (int count = 0; count < n; count++) {
        int minDistance = 9999;
        int index = -1;

        // Find the closest unvisited request
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int distance = difference(current, requests[i]);

                if (distance < minDistance) {
                    minDistance = distance;
                    index = i;
                }
            }
        }

        visited[index] = 1;
        totalSeek += minDistance;
        current = requests[index];

        printf(" -> %d", current);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
}

// SCAN Algorithm
void SCAN(int requests[], int n, int head, int diskSize, int direction) {
    int totalSeek = 0;
    int current = head;

    int left[MAX], right[MAX];
    int leftCount = 0, rightCount = 0;

    // Separate requests into left and right of the head
    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[leftCount++] = requests[i];
        else
            right[rightCount++] = requests[i];
    }

    // Add disk boundaries
    left[leftCount++] = 0;
    right[rightCount++] = diskSize - 1;

    // Sort left array
    for (int i = 0; i < leftCount - 1; i++) {
        for (int j = i + 1; j < leftCount; j++) {
            if (left[i] > left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }

    // Sort right array
    for (int i = 0; i < rightCount - 1; i++) {
        for (int j = i + 1; j < rightCount; j++) {
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

    printf("\n--- SCAN Disk Scheduling ---\n");
    printf("Seek Sequence: %d", current);

    // Moving towards higher cylinder numbers
    if (direction == 1) {
        for (int i = 0; i < rightCount; i++) {
            totalSeek += difference(current, right[i]);
            current = right[i];
            printf(" -> %d", current);
        }

        for (int i = leftCount - 2; i >= 0; i--) {
            totalSeek += difference(current, left[i]);
            current = left[i];
            printf(" -> %d", current);
        }
    }

    // Moving towards lower cylinder numbers
    else {
        for (int i = leftCount - 1; i >= 0; i--) {
            totalSeek += difference(current, left[i]);
            current = left[i];
            printf(" -> %d", current);
        }

        for (int i = 1; i < rightCount; i++) {
            totalSeek += difference(current, right[i]);
            current = right[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
}

