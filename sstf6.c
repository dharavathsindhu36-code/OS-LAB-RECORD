#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, totalSeek = 0;
    int request[100], visited[100] = {0};

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSSTF Seek Sequence: %d", head);

    for (int count = 0; count < n; count++) {
        int minDistance = 9999;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                int distance = abs(head - request[i]);

                if (distance < minDistance) {
                    minDistance = distance;
                    index = i;
                }
            }
        }

        visited[index] = 1;
        totalSeek += minDistance;
        head = request[index];

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);

    return 0;
}
