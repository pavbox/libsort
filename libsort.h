
/**


*/

/**
 *  prototypes
 */

namespace Libsort {
  static const int LENGTH_ARRAY = 20000;
  static const int START_ARRAY = 1; // from 1 to 150k

  void print();
  void generateArray(int* array);
  void copyArray(int* original, int* clone);

  void outputArray(int* array);
  void insertSort(int* array);
  void quickSort(int* array, int first, int last);
}
