
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
    for (int idx_i = 1; idx_i < 20000; idx_i++) {
      array[idx_i] = rand() % 100000 + 1; // 1..100
    }
  }

  void copyArray(int* original, int* clone) {
    for (int idx_i = 1; idx_i < 20000; idx_i++) {
      clone[idx_i] = original[idx_i]; // copy array
    }
  }

  void outputArray(int* array) {
    for (int idx_i = 1; idx_i < 20000; idx_i++) {
      std::cout << array[idx_i] << ' '; // copy array
      if (idx_i % 15 == 0) {
        // cout << endl;
      }
    }
  }



  void insertion(int* array, int size) {
    int idx_finder = 0;
    double value;

    for (int idx_i = 2; idx_i < size; idx_i++) {
      value = array[idx_i];
      array[0] = value; // barier
      idx_finder = idx_i;

      while (value < array[idx_finder - 1]) {
        array[idx_finder] = array[idx_finder - 1];
        idx_finder--;
      }
      array[idx_finder] = value;
    }
  }



  void insertionBisection(int* array, int size) {
    int idx_i = 0;
    int idx_j = 0;
    int idx_mid = 0;
    int idx_left = 0;
    int idx_right = 0;

    int target = 0;
    double value;

    for (idx_i = 2; idx_i < size; idx_i++) {
      value = array[i];
      idx_left = 1;
      idx_right = i;

      while (idx_left < idx_right) {
        idx_mid = (first + last) / 2;
        target = array[idx_mid];

        if (target < value) {
          idx_left = idx_mid + 1;
        } else {
          idx_right = idx_mid;
        }
      }

      for (idx_j = (idx_right + 1); idx_j > idx_i; idx_j--) {
        array[idx_j] = array[idx_j - 1];
      }

      array[idx_right] = value;
    }
  }




  void selection(int* array, int size) {
      for (int idx_i = 0; idx_i < size - 1; idx_i++) {
          int idx_min = idx_i;
          for (int j = idx_i + 1; j < size; j++) {
              if (array[j] < array[idx_min]){
                  idx_min = j;
              }
          }

          if (idx_min != idx_i){
              std::swap(array[idx_i], array[idx_min]);
          }
      }
  }



  void bubble(int* array, int size) {
    double value;

    for (int idx_i = 2; idx_i < size; idx_i++) {
      for (int idx_j = size; idx_j > idx_i; idx_j--) {
        std::swap(array[idx_j], array[idx_j - 1]);
      }
    }
  }




  void shacker(int* array, int size) {
    double value;
    int idx_j;
    int idx_left = 2;
    int idx_right = size;
    int idx_key = size;

    do {
      for (idx_j = idx_right; idx_j > idx_left; idx_j--) {
        if (array[idx_j - 1] > array[idx_j]) {
          std::swap(array[idx_j], array[idx_j - 1]);
          idx_key = idx_j;
        }
      }

      idx_left = idx_key + 1;

      for (idx_j = idx_left; idx_j < idx_right; idx_j++) {
        if (array[idx_j - 1] > array[idx_j]) {
          std::swap(array[idx_j], array[idx_j - 1]);
          idx_key = idx_j;
        }
      }

      idx_right = idx_key - 1;

    } while (idx_left < idx_right);

  }





  void quick(int* array, int first, int last) {
      int idx_i = first, idx_j = last, value = array[(first + last) / 2];

      do {
          while (array[idx_i] < value) idx_i++;
          while (array[idx_j] > value) idx_j--;

          if (idx_i <= idx_j) {
              if (array[idx_i] > array[idx_j]) std::swap(array[idx_i], array[idx_j]);
              idx_i++; idx_j--;
          }
      } while (idx_i <= idx_j);

      if (last  > idx_i) quick(array, idx_i, last);
      if (first < idx_j) quick(array, first, idx_j);
  }




}
