#include <stdio.h>
#include <limits.h>
#define MAX_BLOCKS 10
#define MAX_PROCESSES 10
void firstFit(int blockSize[], int m, int processSize[], int n) {
int allocation[MAX_PROCESSES];
for (int i = 0; i < n; i++) {
allocation[i] = -1; // initially no block is assigned
}
for (int i = 0; i < n; i++) { // process each process
for (int j = 0; j < m; j++) { // find first block that fits
if (blockSize[j] >= processSize[i]) {
allocation[i] = j;
blockSize[j] -= processSize[i];
break;
}
}
}
printf("\nFirst Fit Allocation:\n");
printf("Process No.\tProcess Size\tBlock No.\n");
for (int i = 0; i < n; i++) {
printf("%d\t\t%d\t\t", i + 1, processSize[i]);
if (allocation[i] != -1)
printf("%d\n", allocation[i] + 1);
else
printf("Not Allocated\n");
}
}
void bestFit(int blockSize[], int m, int processSize[], int n) {
int allocation[MAX_PROCESSES];
for (int i = 0; i < n; i++) {
allocation[i] = -1; // initially no block is assigned

}
for (int i = 0; i < n; i++) { // process each process
int bestIdx = -1;
for (int j = 0; j < m; j++) { // find best block that fits
if (blockSize[j] >= processSize[i]) {
if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
bestIdx = j;
}
}
}
if (bestIdx != -1) {
allocation[i] = bestIdx;
blockSize[bestIdx] -= processSize[i];
}
}
printf("\nBest Fit Allocation:\n");
printf("Process No.\tProcess Size\tBlock No.\n");
for (int i = 0; i < n; i++) {
printf("%d\t\t%d\t\t", i + 1, processSize[i]);
if (allocation[i] != -1)
printf("%d\n", allocation[i] + 1);
else
printf("Not Allocated\n");
}
}
void worstFit(int blockSize[], int m, int processSize[], int n) {
int allocation[MAX_PROCESSES];
for (int i = 0; i < n; i++) {
allocation[i] = -1; // initially no block is assigned
}
for (int i = 0; i < n; i++) { // process each process
int worstIdx = -1;
for (int j = 0; j < m; j++) { // find worst block that fits
if (blockSize[j] >= processSize[i]) {
if (worstIdx == -1 || blockSize[worstIdx] < blockSize[j]) {
worstIdx = j;

}
}
}
if (worstIdx != -1) {
allocation[i] = worstIdx;
blockSize[worstIdx] -= processSize[i];
}
}
printf("\nWorst Fit Allocation:\n");
printf("Process No.\tProcess Size\tBlock No.\n");
for (int i = 0; i < n; i++) {
printf("%d\t\t%d\t\t", i + 1, processSize[i]);
if (allocation[i] != -1)
printf("%d\n", allocation[i] + 1);
else
printf("Not Allocated\n");
}
}
int main() {
int m, n;
int blockSize[MAX_BLOCKS], processSize[MAX_PROCESSES];
printf("Enter number of blocks: ");
scanf("%d", &m);
printf("Enter size of each block: ");
for (int i = 0; i < m; i++) {
scanf("%d", &blockSize[i]);
}
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter size of each process: ");
for (int i = 0; i < n; i++) {
scanf("%d", &processSize[i]);
}
int blockSize1[MAX_BLOCKS], blockSize2[MAX_BLOCKS], blockSize3[MAX_BLOCKS];

// Copy blockSize array to three different arrays for each fit method
for (int i = 0; i < m; i++) {
blockSize1[i] = blockSize[i];
blockSize2[i] = blockSize[i];
blockSize3[i] = blockSize[i];
}
firstFit(blockSize1, m, processSize, n);
bestFit(blockSize2, m, processSize, n);
worstFit(blockSize3, m, processSize, n);
return 0;
}
