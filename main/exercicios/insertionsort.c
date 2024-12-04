#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (j >=0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main(){
    
    int v[400000];
    clock_t t;     

    srand(time(NULL));

    for( int i=0; i<400000; i++){
        v[i]=rand();
    }
    t = clock(); 
    insertionSort(v,400000);
    t = clock() - t;
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    return 0;

}
