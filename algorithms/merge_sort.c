#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);
void printArray(int arr[], int size);


int main(){
  int arr[] = {6,5,7,3,4,2,1,9,8};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Given array: \n");
  printArray(arr, size);

  merge_sort(arr, 0, size-1);

  printf("\nSorted array: \n");
  printArray(arr, size);
}



void merge_sort(int *arr, int left, int right){
  if(left<right){
    int mid = left + (right-left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}


void merge(int *arr, int left, int mid, int right){
  int n1 = mid - left +1;
  int n2 = right - mid;
  int *L = (int *) malloc(n1 * sizeof(int));
  int *R = (int *) malloc(n2 * sizeof(int));

  for(int i=0; i<n1; i++)
    L[i] = arr[left+i];
  for(int i=0; i<n2; i++)
    R[i] = arr[mid+1+i];

  int i=0, j=0, k=left;
  while(i<n1 && j<n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    arr[k] = L[i];
    i++;
    k++;
  }
  while(j<n2){
    arr[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}


void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
