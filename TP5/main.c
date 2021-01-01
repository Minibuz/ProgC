#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** 
 * Allocate memory for an array which can contain `size`
 * integers. The returned C array has memory for an extra last
 * integer labelling the end of the array. 
 * 
 * @param size int - Size of the array desired
 * @return int* - Array of the given size
 */
int* allocate_integer_array(int size){
  int* new_tab;

  if(size <= 0) {
    fprintf(stderr, "Size of an array shouldn't be negative or empty.\n");
    return NULL;
  }

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

/**
 * Free an integer array
 * 
 * @param tab_to_free int*
 */
void free_integer_array(int* tab_to_free){
  free(tab_to_free);
}

/**
 * Return the lenght of the array
 * 
 * @param array_to_size int*
 * @return int - The size of the given array
 */
int array_size(int* array_to_size) {
  int size;
  size = 0;
  if(array_to_size == NULL) {
    fprintf(stderr, "Cannot get the size of an empty array\n");
    return 0;
  }
  while(array_to_size[size]!=-1){
    size++;
  }
  return size;
}

/**
 * Display the elements of the array
 * 
 * @param array_to_display int*
 */
void print_array(int* array_to_display) {
  size_t size = array_size(array_to_display);
  int i;
  for(i=0; i<size; i++){
    printf("%i ",array_to_display[i]);
  }
  putchar('\n');
}

/**
 * Assert equality of the given array
 * 
 * @param first_array 
 * @param second_array
 * @return 1 if equals, 0 otherwise
 */
int assert_array_equals(int* first_array, int* second_array) {
  int i;
  size_t first_size = array_size(first_array);
  size_t second_size = array_size(second_array);
  if(first_size == second_size){
    for(i=0; i<first_size; i++) {
      if(first_array[i]!=second_array[i]) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

/* Copy an array into a NEW array */
int * copy_array(int * array) {
  int i;
  int *new_array;

  size_t size = array_size(array);
  new_array = allocate_integer_array(size);

  for(i = 0; i<=size; i++) {
    new_array[i] = array[i];
  }

  return new_array;
}

/* */
int* fill_array(void) {
  int size; int i;
  int* result_array;

  printf("Entrez une longueur pour le tableau : ");
  scanf("%d",&size);

  result_array = allocate_integer_array(size);

  for(i=0; i<size; i++) {
    printf("Entrez un entier a rentrez dans le tableau : ");
    scanf("%d",&result_array[i]);
  }
  result_array[size] = -1;

  return result_array;
}

int* random_array(int size, int max_entry) {
  int i;
  int* result_array;
  result_array = allocate_integer_array(size);

  srand(time(NULL));

  for(i=0; i<size; i++){
    result_array[i] = rand() % (max_entry+1);
  }
  result_array[size] = -1;

  return result_array;
}

/**
 * Concat array
 */
int* concat_array(int* first_array, int* second_array) {
  int* result_array;
  int size_first; int size_second; int i; int j;

  size_first = array_size(first_array);
  size_second = array_size(second_array);
  
  result_array = allocate_integer_array(size_first + size_second);

  for(i = 0; i<size_first; i++) {
    result_array[i] = first_array[i];
  }
  for(j = 0; j<size_second; j++) {
    result_array[i+j] = second_array[j];
  }
  result_array[size_first + size_second] = -1;

  return result_array;
}

/**
 * Tri fusion verbeux : merge sorted array
 */
int* merge_sorted_arrays(int* first_array, int* second_array) {
  int first_array_lenght; int second_array_lenght; int i; int j; int k;
  int* result_array;

  printf("\nMerge the two following arrays :\n");
  print_array(first_array);
  print_array(second_array);

  j = k = 0;
  first_array_lenght = array_size(first_array);
  second_array_lenght = array_size(second_array);

  result_array = allocate_integer_array(first_array_lenght + second_array_lenght);

  for(i = 0; i < first_array_lenght + second_array_lenght;) {
    if(j < first_array_lenght && k < second_array_lenght) {
      if(first_array[j] < second_array[k]) {
        result_array[i] = first_array[j];
        j++;
      }
      else { /*first_array[j] > second_array[k]*/
        result_array[i] = second_array[k];
        k++;
      }
      i++;
    }
    else if(j == first_array_lenght) {
      for(; i < first_array_lenght + second_array_lenght;) {
        result_array[i] = second_array[k];
        i++; k++;
      }
    }
    else { /*k == second_array_lenght*/
      result_array[i] = first_array[j];
      i++; j++;
    }
  }
  result_array[first_array_lenght + second_array_lenght] = -1;

  return result_array;
}

/**
 * Tri fusion verbeux : split array
 */
void split_array(int* array, int** first_result_array, int** second_result_array) {
  int array_lenght; int first_result_array_lenght; int second_result_array_lenght;
  int index_array; int index_sub_array;

  printf("\nSplit array in two parts :\n");
  print_array(array);

  array_lenght = array_size(array);
  first_result_array_lenght = array_lenght / 2;
  second_result_array_lenght = array_lenght - first_result_array_lenght;

  *first_result_array = allocate_integer_array(first_result_array_lenght);
  *second_result_array = allocate_integer_array(second_result_array_lenght);

  for(index_sub_array = 0, index_array = 0; index_sub_array < first_result_array_lenght; index_sub_array++, index_array++) {
    *(*first_result_array + index_sub_array) = array[index_array];
  }
  *(*first_result_array + first_result_array_lenght ) = -1;

  for(index_sub_array = 0; index_sub_array < second_result_array_lenght; index_sub_array++, index_array++) {
    *(*second_result_array + index_sub_array) = array[index_array];
  }
  *(*second_result_array + second_result_array_lenght) = -1;

  print_array(*first_result_array);
  print_array(*second_result_array);
}

/**
 * Tri fusion verbeux : merge sort
 */
int* merge_sort(int* array) {
  int* first_array; int *second_array;

  if(array_size(array) <= 1) {
    return array;
  }

  split_array(array,&first_array,&second_array);

  return merge_sorted_arrays(merge_sort(first_array),merge_sort(second_array));
}

/**
 * Main to test all of the functions, with multiples test for each of them.
 */
int main(int argc, char* argv[]){
  int *tab_1 = NULL, *tab_2 = NULL, *tab_3 = NULL, *tab_4 = NULL, *tab_5 = NULL, *tab_6 = NULL, *tab_7 = NULL;
  tab_1 = allocate_integer_array(2);
  tab_1[0] = 1;
  tab_1[1] = 1;
  tab_1[2] = -1;

  tab_2 = copy_array(tab_1);

  printf("Tab_1 :\n");
  print_array(tab_1);
  printf("\nTab_2 :\n");
  print_array(tab_2);

  if(assert_array_equals(tab_1,tab_2)) {
    printf("\nArrays are equals\n");
  }

  tab_3 = fill_array();

  printf("Tab_3 :\n");
  print_array(tab_3);

  tab_4 = random_array(10,20);

  printf("Tab_4 :\n");
  print_array(tab_4);

  tab_5 = concat_array(tab_1,tab_2);
  printf("Tab_5 :\n");
  print_array(tab_5);

  tab_6 = allocate_integer_array(2);
  tab_6[0] = 1;
  tab_6[1] = 3;
  tab_6[2] = -1;
  tab_7 = allocate_integer_array(2);
  tab_7[0] = 2;
  tab_7[1] = 4;
  tab_7[2] = -1;

  int* tab_8 = merge_sorted_arrays(tab_6,tab_7);
  printf("Tab_8 :\n");
  print_array(tab_8);

  free_integer_array(tab_1);
  free_integer_array(tab_2);
  free_integer_array(tab_3);
  free_integer_array(tab_4);
  free_integer_array(tab_5);
  free_integer_array(tab_6);
  free_integer_array(tab_7);
  free_integer_array(tab_8);

  int* tab_9 = NULL, *tab_10 = NULL, *tab_11 = NULL;
  tab_9 = random_array(10,10);
  printf("Tab_9 :\n");
  print_array(tab_9);
  split_array(tab_9,&tab_10,&tab_11);
  printf("Tab_10 :\n");
  print_array(tab_10);
  printf("Tab_11 :\n");
  print_array(tab_11);

  int* array = NULL;

  array = random_array(20,100);
  print_array(array);
  printf("Size of the array : %d\n",array_size(array));

  array = merge_sort(array);

  printf("\n\n");
  print_array(array);
  printf("Size of the array : %d\n",array_size(array));
  return 0;
}
