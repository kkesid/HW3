#include <iostream>
using namespace std;

//Реализуйте шаблонные функции для поиска максимума,
//минимума, сортировки массива(любым алгоритмом сортировки), двоичного поиска в массиве, замены элемента
//массива на переданное значение.

template <typename T>
T findMax(T arr[], int size) {
    if (size <= 0) {
        return T();
    }
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
T findMin(T arr[], int size) {
    if (size <= 0) {
        return T();
    }
    T min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int binarySearch(T arr[], int size, T key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void replaceElement(T arr[], int size, int index, T newValue) {
    if (index >= 0 && index < size) {
        arr[index] = newValue;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int intArr[] = { 5, 2, 9, 1, 7 };
    int intArrSize = sizeof(intArr) / sizeof(intArr[0]);

    double doubleArr[] = { 3.14, 1.618, 2.718, 1.414, 0.577 };
    int doubleArrSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

    cout << "Максимум в intArr: " << findMax(intArr, intArrSize) << endl;
    cout << "Минимум в doubleArr: " << findMin(doubleArr, doubleArrSize) << endl;

    bubbleSort(intArr, intArrSize);
    cout << "Отсортированный intArr: ";
    for (int i = 0; i < intArrSize; ++i) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    int key = 7;
    int index = binarySearch(intArr, intArrSize, key);
    if (index != -1) {
        cout << "Элемент " << key << " найден в индексе " << index << endl;
    }
    else {
        cout << "Элемент " << key << " не найден" << endl;
    }

    replaceElement(intArr, intArrSize, 2, 10);
    cout << "intArr после замены: ";
    for (int i = 0; i < intArrSize; ++i) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    return 0;
}
