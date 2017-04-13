
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "libsort.h"

using namespace std;

int main() {

  int stop, times, insertionTime, quickTime;

  // init random array
  const int LENGTH_ARRAY = 20000;

  int* insertArray = new int[LENGTH_ARRAY];
  int* quickArray = new int[LENGTH_ARRAY];

  Libsort::generateArray(insertArray, LENGTH_ARRAY);
  Libsort::copyArray(insertArray, quickArray);

  // cout << endl << endl << "SOURCE ARRAY:" << endl;
  // outputArray(insertArray);

  // insertSort
  // cout << endl << endl << "INSERTED ARRAY:" << endl;
  // times = clock();
  // Libsort::insertSort(insertArray);
  // insertionTime = clock() - times;
  // outputArray(insertArray);


  // cout << endl << endl << "QUICK TWICE:" << endl;

  // quickSort
  // times = clock();
  // Libsort::quickSort(quickArray, Libsort::START_ARRAY, Libsort::LENGTH_ARRAY - 1);
  // quickTime = clock() - times;
  // // outputArray(quickArray);


  times = clock();
  Libsort::insertion(insertArray, LENGTH_ARRAY);
  insertionTime = clock() - times;

  times = clock();
  Libsort::quick(quickArray, 0, LENGTH_ARRAY - 1);
  quickTime = clock() - times;


  cout.setf(ios::fixed); // fixed output
  cout.precision(4);     // accc
  cout << endl;
  cout << endl << "insertion: " << ((float) insertionTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "quick:     " << ((float) quickTime) / CLOCKS_PER_SEC << 's' << endl;

  cin >> stop;
  return 0;
}
