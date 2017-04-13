
/**

 1. !insertion sort (+bisection)
 2. !selection sort
 3. !bubble sort
 4. !shaker sort
 5. !shells sort
 6. !quick sort (+non-recursive)
*/

/**
 *  prototypes
 */

namespace Libsort {
  void print();
  void generateArray(int* array, int size);
  void copyArray(int* original, int* clone);
  void outputArray(int* array);

  void insertion(int* array, int size);
  void insertionBisection(int* array, int size);
  void selection(int* array, int size);
  void quick(int* array, int first, int last);
  void quickIterable(int* arr, int size);

  void bubble(int* array, int size);
  void shaker(int* array, int size);
  void shells(int* array, unsigned int size);
  // heap
  // tree
}
