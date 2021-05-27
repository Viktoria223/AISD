#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

void quickSort(int *numbers, int left, int right) {
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    numbers[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}

int main() {
    int n, *arr;
    for (int j = 0; j <= 51; j++) {
        clock_t start;
        double duration;
        start = clock();
        ifstream fin("C://Users/huawei/Desktop/Java/Homeworks/Tests2/ttest" + to_string(j + 1) + ".txt");
        fin >> n;
        arr = new int[n];
        cout << "test #" << j+1 << endl;
        cout << "n: " << n << endl;
        for (int i = 1; i < n; ++i) {
            fin >> arr[i];
        }
        quickSort(arr, 0, n - 1);
        duration = (clock() - start)/(double)CLOCKS_PER_SEC;
        cout << "time1:" << duration << endl;
    }
}

//Задача
/*
 Дан массив баллов студентов универитета в произвольном порядке.
 Необходимо отсортировать их, чтобы позже узнать какое количество человек получат зачет.
 */