
/**
 *  libsort: library containts basic sorting algorithms, works with arrays.
 *
 *  Available now:
 *  1. insertion sort
 *  2. insertion sort with upgrade to binary search
 *  3. selection sort
 *  4. bubble sort
 *  5. shaker sort (bubble sort to both sides)
 *  6. shells sort (bubble sort with custom distantion between items)
 *  7. quick sort by recursive functions
 *  8. quick sort by iterable algorithm.
 *
 *  Author: pavbox.
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "libsort.h"

namespace Libsort {

  /**
   * Generate array on _size_ items.
   * Will filled random values.
   *
   * @param {int*} array - input array
   * @param {int}  size  - size of array
   * @return {void}
   */
  void generateArray(int* array, int size) {
    srand(time(0));
    for (int idx_i = 0; idx_i < size; idx_i++) {
      array[idx_i] = rand() % 100000 + 1; // 1..100
    }
  }


  /**
   * Copies original array.
   *
   * @param {int*} original - source array, will be cloned;
   * @param {int*} clone    - clonned array;
   * @return {void}
   */
  void copyArray(int* original, int* clone) {
    for (int idx_i = 1; idx_i < 20000; idx_i++) {
      clone[idx_i] = original[idx_i]; // copy array
    }
  }


  /**
   * Pretty output extra large arrays.
   *
   * @param {int*} original - input array, will be printed;
   * @return {void}
   */
  void outputArray(int* array) {
    for (int idx_i = 1; idx_i < 20000; idx_i++) {
      std::cout << array[idx_i] << ' ';
      if (idx_i % 15 == 0) {
        // cout << endl;
      }
    }
  }



  /**
   * Insertion sort.
   * We find best place in sorted part of array for every item from unsorted part.
   * Best place finding by linear search.
   * With O(n^2) time.
   *
   * @param {int*} array - source array, will be sorted;
   * @param {int}  size  - size of array;
   * @return {void}
   */
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


  /**
   * Insertion sort. Modified with Binary search.
   * We find best place in sorted part of array for every item from unsorted part.
   * Best place finding by Binary search.
   * With O(n^2) time. TODO: ??
   *
   * @param {int*} array - source array, will be sorted;
   * @param {int}  size  - size of array;
   * @return {void}
   */
  void insertionBisection(int* array, int size) {
    int idx_i = 0;
    int idx_j = 0;
    int idx_mid = 0;
    int idx_left = 0;
    int idx_right = 0;

    int target = 0;
    double value;

    for (idx_i = 2; idx_i < size; idx_i++) {
      value = array[idx_i];
      idx_left = 1;
      idx_right = idx_i;

      while (idx_left < idx_right) {
        idx_mid = (idx_left + idx_right) / 2;
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


  /**
   * Selection sort.
   * We find max/min item in unsorted part of array and move this item to right/left.
   * With O(n^2) time.
   *
   * @param {int*} array - source array, will be sorted;
   * @param {int}  size  - size of array;
   * @return {void}
   */
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


  /**
   * Bubble sort.
   * We compare nearby items and move max item by value to the right
   * With O(n^2) time.
   *
   * @param {int*} array - source array, will be sorted;
   * @param {int}  size  - size of array;
   * @return {void}
   */
  void bubble(int* array, int size) {
    double value;

    for (int idx_i = 2; idx_i < size; idx_i++) {
      for (int idx_j = size; idx_j > idx_i; idx_j--) {
        std::swap(array[idx_j], array[idx_j - 1]);
      }
    }
  }



  /**
   * Shaker sort.
   * It's Bubble sort, but in both sides.
   * With O(n^2) time.
   *
   * @param {int*} array - source array, will be sorted;
   * @param {int}  size  - size of array;
   * @return {void}
   */
  void shaker(int* array, int size) {
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


  /**
   * Shell's sort.
   * Work as bubble sort, but compares items on large distantion.
   * With from O(n^2) to O(nlogn) time.
   *
   * @param {int*} array - source array, will be sorted;
   * @param {unsigned int} size  - size of array;
   * @return {void}
   */
  void shells(int* array, unsigned int size) {
    unsigned int idx_i;
    unsigned int idx_j;
    unsigned int idx_key;
    double value;

    for(idx_key = size/2; idx_key > 0; idx_key /= 2) {
      for(idx_i = idx_key; idx_i < size; idx_i++) {
        value = array[idx_i];

        for(idx_j = idx_i; idx_j >= idx_key; idx_j -= idx_key) {
          if(value < array[idx_j - idx_key]) {
            array[idx_j] = array[idx_j - idx_key];
          } else {
            break;
          }
        }
        array[idx_j] = value;
      }
    }
  }



  /**
   * Quick recursive sort.
   * Using Partition method for reducing array to parts,
   * until length of parts become equal 1.
   *
   * Then sorting started.
   * It's looks like a sorting array by parts.
   * With O(nlogn) time.
   *
   * @param {int*} array - source array, will be sorted;
   * @param {int} first  - left barier of new array part;
   * @param {int} last   - right barier of new array part;
   * @return {void}
   */
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



  /**
   * Quick iterable sort.
   * Works as Recursive Quick sort.
   * But More securable, because not using additional memory and can't stack overflow error.
   * With O(nlogn) time.
   *
   * @param {int*} array - source array, will be sorted;
   * @param {int} first  - left barier of new array part;
   * @param {int} last   - right barier of new array part;
   * @return {void}
   */
  void quickIterable(int* arr, int size) {
    const int STACK_DEPTH = 2048;
    int* deepDown = new int[STACK_DEPTH];
    int* deepUp = new int[STACK_DEPTH];

    int idx_i, idx_j, idx_left, idx_right, sizeCount;
    int value, buffer;

    sizeCount = 1;
    deepDown[sizeCount] =  0;
    deepUp[sizeCount] =  size - 1;

    do {
      idx_left = deepDown[sizeCount];
      idx_right = deepUp[sizeCount];
      sizeCount--;
      do {
        idx_i = idx_left;
        idx_j = idx_right;
    	  value  =  arr[(idx_left + idx_right) / 2];

        /**
         *  Divides the array in parts.
         *  After, parts will be sort.
         */
        do {
          while (arr[idx_i] < value) idx_i++;
          while (value < arr[idx_j]) idx_j--;

          if (idx_i <= idx_j) {
            buffer  =  arr[idx_i];
            arr[idx_i]  =  arr[idx_j];
            arr[idx_j]  =  buffer;
            idx_i++; idx_j--;
          }
        } while(idx_i < idx_j);

        if (idx_i < idx_right) {
          sizeCount++;
          deepDown[sizeCount] =  idx_i;
          deepUp[sizeCount] =  idx_right;
        }

        idx_right = idx_j;
      } while (idx_left < idx_right);
    } while (sizeCount > 0);
  }
}
