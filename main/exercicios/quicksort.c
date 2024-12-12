
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      i++;
      
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}


int main(){
    
    int v[400000];
    clock_t t;     

    srand(time(NULL));

    for( int i=0; i<399999; i++){
        v[i]=rand();
    }
    t = clock(); 
    quickSort(v,0, 399999);
    t = clock() - t;
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    return 0;

}
