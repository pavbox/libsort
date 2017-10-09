# Алгоритмы и структуры данных: Библиотека для работы с сортировками массивов libsort.

Status.
OSX: [![Build Status](https://travis-ci.org/pavbox/libsort.svg?branch=master)](https://travis-ci.org/pavbox/libsort)

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


# API и способ вызова.

Для примера решим задачу: измерить время выполнения сортировки Хоара (рекурсивной).

- Зададим переменные для хранения времени, данных, константы для генерации массива.

```cpp
int times, quickTime;
const int LENGTH_ARRAY = 20000;
int* quickArray = new int[LENGTH_ARRAY];
```

- Генерируем массив заданной длины, состоящий из случайных элементов.

```cpp
Libsort::generateArray(quickArray, LENGTH_ARRAY);
```

- Получаем системы время до начала сортировки, сортируем и считаем разницу между текущим и начальным временем системы.

```cpp
times = clock();
// Сортируем quickArray от нулевого элемента до последнего.
// Интервал нужно указывать, так как функция рекурсивная.
Libsort::quick(quickArray, 0, LENGTH_ARRAY - 1);
quickTime = clock() - times;
```

- Настроим фиксированный удобный вывод для чисел и преобразуем тики процессора в секунды.

```cpp
cout.setf(ios::fixed); // fixed output
cout.precision(4);     // accc
cout << std::endl << "quick time: " << ((float) quickTime) / CLOCKS_PER_SEC << 's' << endl;
```


PS: [test.cpp с реализацией всех сортировок](https://github.com/pavbox/libsort/blob/master/test.cpp)
