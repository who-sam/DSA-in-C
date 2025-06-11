#include <stdio.h>
#include <stdlib.h>


void isertion_sort(int arr[], int n);
void swap(int *a, int *b);
void printArray(int arr[], int size);


int main(){
  int arr[] = {6,5,7,3,4,2,1,9,8};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Given array: \n");
  printArray(arr, size);

  isertion_sort(arr, size);

  printf("\nSorted array: \n");
  printArray(arr, size);
}


void isertion_sort(int arr[], int n){
  int i,j;
  for(i=1; i<n; i++){
    j=i;
    while(j>0 && arr[j]<arr[j-1]){
      swap(&arr[j], &arr[j-1]);
      j--;
    }
  }
}


void swap(int *a, int *b){
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *b ^ *a;
}


void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
