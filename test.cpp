

/**
 *  test.cpp: file for testing sorts algorithms.
 *  Just creates eight identical arrays and sort with different algorithms.
 *
 *  Created by pavbox.
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "libsort.h"

using namespace std;

int main() {

  int stop, times;
  int insertionTime;
  int insertionBinaryTime;
  int selectionTime;
  int quickTime;
  int quickIterableTime;
  int bubbleTime;
  int shakerTime;
  int shellsTime;

  // init random array
  const int LENGTH_ARRAY = 20000;

  int* insertionArray = new int[LENGTH_ARRAY];
  int* insertionBinaryArray = new int[LENGTH_ARRAY];
  int* selectionArray = new int[LENGTH_ARRAY];
  int* quickArray = new int[LENGTH_ARRAY];
  int* quickIterableArray = new int[LENGTH_ARRAY];
  int* bubbleArray = new int[LENGTH_ARRAY];
  int* shakerArray = new int[LENGTH_ARRAY];
  int* shellsArray = new int[LENGTH_ARRAY];

  Libsort::generateArray(insertionArray, LENGTH_ARRAY);

  Libsort::copyArray(insertionArray, insertionBinaryArray, LENGTH_ARRAY);
  Libsort::copyArray(insertionArray, selectionArray,       LENGTH_ARRAY);
  Libsort::copyArray(insertionArray, quickArray,           LENGTH_ARRAY);
  Libsort::copyArray(insertionArray, quickIterableArray,   LENGTH_ARRAY);
  Libsort::copyArray(insertionArray, bubbleArray,          LENGTH_ARRAY);
  Libsort::copyArray(insertionArray, shakerArray,          LENGTH_ARRAY);
  Libsort::copyArray(insertionArray, shellsArray,          LENGTH_ARRAY);

  times = clock();
  Libsort::insertion(insertionArray, LENGTH_ARRAY);
  insertionTime = clock() - times;

  times = clock();
  Libsort::insertionBisection(insertionBinaryArray, LENGTH_ARRAY);
  insertionBinaryTime = clock() - times;

  times = clock();
  Libsort::selection(selectionArray, LENGTH_ARRAY);
  selectionTime = clock() - times;

  times = clock();
  //Libsort::quick(quickArray, LENGTH_ARRAY);
  Libsort::quick(quickArray, 0, LENGTH_ARRAY - 1);
  quickTime = clock() - times;

  times = clock();
  Libsort::quickIterable(quickIterableArray, LENGTH_ARRAY);
  quickIterableTime = clock() - times;

  times = clock();
  Libsort::bubble(bubbleArray, LENGTH_ARRAY);
  bubbleTime = clock() - times;

  times = clock();
  Libsort::shaker(shakerArray, LENGTH_ARRAY);
  shakerTime = clock() - times;

  times = clock();
  // unsigned int LEN_A = LENGTH_ARRAY;
  Libsort::shells(shellsArray, LENGTH_ARRAY);
  shellsTime = clock() - times;


  cout.setf(ios::fixed); // fixed output
  cout.precision(4);     // accc
  cout << endl;
  cout << endl << "insertion time:         " << ((float) insertionTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "insertionBinary time:   " << ((float) insertionBinaryTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "selection time:         " << ((float) selectionTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "quick time:             " << ((float) quickTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "quickIterable time:     " << ((float) quickIterableTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "bubble time:            " << ((float) bubbleTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "shaker time:            " << ((float) shakerTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "shells time:            " << ((float) shellsTime) / CLOCKS_PER_SEC << 's' << endl;

  cin >> stop;
  return 0;
}
