
/**


*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "libsort.h"

/**
 * Create constants structure.
 */


/**
 *  prototypes
 *  function for works
 */
namespace Libsort {


  void print() {
    std::cout << "/* message */" << '\n';
  }


  void generateArray(int* array) {
    srand(time(0));
    for (int i = START_ARRAY; i < LENGTH_ARRAY; i++) {
      array[i] = rand() % 100000 + 1; // 1..100
    }
  }


  void copyArray(int* original, int* clone) {
    for (int i = START_ARRAY; i < LENGTH_ARRAY; i++) {
      clone[i] = original[i]; // copy array
    }
  }



  void outputArray(int* array) {
    for (int i = START_ARRAY; i < LENGTH_ARRAY; i++) {
      std::cout << array[i] << ' '; // copy array
      if (i % 15 == 0) {
        // cout << endl;
      }
    }
  }


  void insertSort(int* array) {
    int j = 0;
    double value;

    for (int i = START_ARRAY + 1; i < LENGTH_ARRAY; i++) {
      value = array[i];
      array[0] = value; // barier
      j = i;

      while (value < array[j - 1]) {
        array[j] = array[j - 1];
        j--;
      }
      array[j] = value;
    }
  }



  void quickSort(int* array, int first, int last) {
      int i = first, j = last, value = array[(first + last) / 2];

      do {
          while (array[i] < value) i++;
          while (array[j] > value) j--;

          if (i <= j) {
              if (array[i] > array[j]) std::swap(array[i], array[j]);
              i++;
              j--;
          }
      } while (i <= j);

      if (i < last)
          quickSort(array, i, last);
      if (first < j)
          quickSort(array, first, j);
  }
}
