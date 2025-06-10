#include <stdio.h>

void sort(int *, int);
void swap(int *, int *);

int main (){
  int nums[] = {6,5,4,3,2,1};

  for(int i=0; i<6; i++){
    printf("%d ,", nums[i]);
  }
  printf("\n");

  sort(nums, 6);

  for(int i=0; i<6; i++){
    printf("%d ,", nums[i]);
  }
  printf("\n");

}

void swap(int *a, int *b){
  // a=1 , b=0
  // a=1 , b=1
  // a=0
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *b ^ *a;
}

void sort(int *num, int n){
  short swapping = 1;
  int end = n;

  while(swapping){
    swapping = 0;
    for(int i=1; i<end; i++){
      if(num[i-1] > num[i]){
        swap(&num[i-1],&num[i]);
        swapping = 1;
      }
    }
    end --;
  }
}

