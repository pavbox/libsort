
/**

 1. insertion sort (+bisection)
 2. selection sort
 3. bubble sort
 4. shaker sort
 5. shells sort
 6. quick sort (+non-recursive)


*/

/**
 *  prototypes
 */

namespace Libsort {
  // static const int LENGTH_ARRAY = 20000;
  // static const int START_ARRAY = 1; // from 1 to 20k

  // TODO: CHECK ALL ALGS

  void print();
  void generateArray(int* array);
  void copyArray(int* original, int* clone);
  void outputArray(int* array);

  void insertion(int* array, int size);
  void insertionBisection(int* array, int size);
  void selection(int* array, int size); // need check code
  void quick(int* array, int first, int last);

  void bubble(int* array, int size);
}
