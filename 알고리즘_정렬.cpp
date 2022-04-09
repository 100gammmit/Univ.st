#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}
//선택정렬
void selectionSort(int A[], int n, int &c)
{
    c = 0;
    for (int i = 0; i < n - 1; i++) {        
        int least = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[least]) least = j;
            c++;
        }
        swap(A[i], A[least]);
    }
}
//버블정렬
void BubbleSort(int A[], int n, int &c)
{
    c = 0;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                c++;
            }
        }
    }
}
//삽입정렬
void insertionSort(int A[], int n, int &c)
{
    c = 0;
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j;
        for (j = i - 1; j >= 0 && A[j] > key; j--)
            A[j + 1] = A[j];
        A[j + 1] = key;
        c++;
    }
}


static void printArray(int arr[], int n, const char* str = "Array")
{
    printf("%s = ", str);
    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}
//배열 초기화
void arrinit(int a[5], int b[5], int c[5]) {
    int arr1[5] = { 2, 4, 7, 9, 11 };
    for (int i = 0; i < 5; i++) swap(a[i], arr1[i]);
    int arr2[5] = { 11, 9, 7, 4, 2 };
    for (int i = 0; i < 5; i++) swap(b[i], arr2[i]);
    int arr3[5] = { 7, 11, 2, 9, 4 };
    for (int i = 0; i < 5; i++) swap(c[i], arr3[i]);
}

int main() {
    int arr1[5], arr2[5], arr3[5];
    int n = 5;
    int c1, c2, c3 = 0;
    arrinit(arr1, arr2, arr3);

    printf("1. 입력의 형태\n");
    printArray(arr1, n, "가");
    printArray(arr2, n, "나");
    printArray(arr3, n, "다");
    
    printf("2. 선택정렬\n");
    selectionSort(arr1, n, c1);
    printArray(arr1, n, "가");
    selectionSort(arr2, n, c2);
    printArray(arr2, n, "나");
    selectionSort(arr3, n, c3);
    printArray(arr3, n, "다");
    
    printf("3. 비교횟수\n");
    printf("가. %d\n나. %d\n다. %d\n", c1, c2, c3);
    arrinit(arr1, arr2, arr3);

    printf("4. 버블정렬\n");
    BubbleSort(arr1, n, c1);
    printArray(arr1, n, "가");
    BubbleSort(arr2, n, c2);
    printArray(arr2, n, "나");
    BubbleSort(arr3, n, c3);
    printArray(arr3, n, "다");

    printf("5. 비교횟수\n");
    printf("가. %d\n나. %d\n다. %d\n", c1, c2, c3);
    arrinit(arr1, arr2, arr3);

    printf("6. 삽입정렬\n");
    insertionSort(arr1, n, c1);
    printArray(arr1, n, "가");
    insertionSort(arr2, n, c2);
    printArray(arr2, n, "나");
    insertionSort(arr3, n, c3);
    printArray(arr3, n, "다");

    printf("7. 비교횟수\n");
    printf("가. %d\n나. %d\n다. %d\n", c1, c2, c3);
}