#include <stdio.h>
void insertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
/* Move elements of arr[0..i-1], that are greater than key, to one
position ahead of their current position */
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void quicksort(int number[25], int first, int last)
{
int i, j, pivot, temp;
if (first < last)
{
pivot = first;
i = first;
j = last;
while (i < j)
{
while (number[i] <= number[pivot] && i < last)
i++;
while (number[j] > number[pivot])
j--;
if (i < j)
{


temp = number[i];
number[i] = number[j];
number[j] = temp;
}
}
temp = number[pivot];
number[pivot] = number[j];
number[j] = temp;
quicksort(number, first, j - 1);
quicksort(number, j + 1, last);
}
}
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
void selectionSort(int array[], int size)
{
for (int step = 0; step < size - 1; step++)
{
int min_idx = step;
for (int i = step + 1; i < size; i++)
{
// To sort in descending order, change > to < in this line.
// Select the minimum element in each loop.
if (array[i] < array[min_idx])
min_idx = i;
}
// put min at the correct position swap(&array[min_idx], &array[step]);
}
}
// Driver program
int main() {
int arr[] = {6, 5, 12, 10, 9, 1};
int size = sizeof(arr) / sizeof(arr[0]);
printf("Before Sorted array: \n");
printArray(arr, size);


mergeSort(arr, 0, size - 1);
printf("After Sorted array: \n");
printArray(arr, size);
printf("\n\n");
int arr2[] = {27, 6, 10, 16, 34};
printf("Before Quick Sorted : \n");
printArray(arr2, 5);
quicksort(arr2, 0, 4);
printf("After Quick Sorted : \n");
printArray(arr2, 5);
printf("\n\n");
int data[] = {20, 22, 20, 25, 2};
printf("Before selection Sorted : \n");
printArray(data, 5);
selectionSort(data, 5);
printf("After selection Sorted : \n");
printArray(data, 5);
printf("\n\n");
printf("Before insertion Sorted : \n");
int arr4[] = {12, 11, 13, 51, 16};
int n = sizeof(arr) / sizeof(arr[0]);
printArray(arr4, n);
printf("After insertion Sorted : \n");
insertionSort(arr4, n);
printArray(arr4, n);
}

