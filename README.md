# libsort
Library contains basic sorts algorithms. Compiled with g++ as shared library (for mac/linux).

# Алгоритмы и структуры данных: Библиотека для работы с сортировками массивов.

Функции:

```cpp
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
```
