#include <iostream>

void count_sort(int* arr, int size) 
{
    const int min = 10, max = 24;
    int count[max - min + 1] = { 0 };
    int* output = new int[size];

    for (int i = 0; i < size; i++) 
    {
        count[arr[i] - min]++;
    }

    for (int i = 1; i < max - min + 1; i++) 
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

void arrPrint(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int arr[]{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int size = 0;
    size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Исходный массив: ";
    arrPrint(arr, size);
    count_sort(arr, size);
    std::cout << "Отсортированный массив: ";
    arrPrint(arr, size);
    return 0;
}