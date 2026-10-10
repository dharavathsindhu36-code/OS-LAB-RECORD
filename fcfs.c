#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, totalSeek = 0;
    int request[100];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Seek Sequence: %d", head);

    for (int i = 0; i < n; i++) {
        totalSeek += abs(head - request[i]);
        head = request[i];

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);

    return 0;
}
