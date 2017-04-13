
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "libsort.h"

using namespace std;

int main() {

  int stop, times, insertionTime, quickTime;

  // init random array
  int* insertArray = new int[Libsort::LENGTH_ARRAY];
  int* quickArray = new int[Libsort::LENGTH_ARRAY];

  Libsort::generateArray(insertArray);
  Libsort::copyArray(insertArray, quickArray);

  // cout << endl << endl << "SOURCE ARRAY:" << endl;
  // outputArray(insertArray);

  // insertSort
  // cout << endl << endl << "INSERTED ARRAY:" << endl;
  times = clock();
  Libsort::insertSort(insertArray);
  insertionTime = clock() - times;
  // outputArray(insertArray);


  // cout << endl << endl << "QUICK TWICE:" << endl;

  // quickSort
  times = clock();
  Libsort::quickSort(quickArray, Libsort::START_ARRAY, Libsort::LENGTH_ARRAY - 1);
  quickTime = clock() - times;
  // outputArray(quickArray);


  cout.setf(ios::fixed); // fixed output
  cout.precision(4);     // accc
  cout << endl;
  cout << endl << "insertion: " << ((float) insertionTime) / CLOCKS_PER_SEC << 's' << endl;
  cout << endl << "quick:     " << ((float) quickTime) / CLOCKS_PER_SEC << 's' << endl;

  cin >> stop;
  return 0;
}
