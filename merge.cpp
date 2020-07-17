#include <iostream>
using namespace std;

void print(int* a, int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void sortArr(int* a, int size)
{
    int i, j , key;
    for (int i = 1; i < size; i++) {
        key = a[i];
        j = i -1;
        while (j > -1 && key < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int* a, int as, int* b, int bs, int* ar, int s) {
    sortArr(a, as);
    sortArr(b, bs);

    int i = 0,  j = 0, k = 0;
    for (; i < as && j < bs; k++) {
        if(a[i] < b[j])
            ar[k] = a[i++];
        else
            ar[k] = b[j++];
    }

    for(; i < as; i++)
        ar[k++] = a[i];

    for(; j < bs; j++)
        ar[k++] = b[j];
}

int main()
{ 
    int* arr1 = NULL, 
       * arr2 = NULL,
       * ans = NULL;

    int arr1Size, arr2Size, ansSize;

    cout << "Enter Array 1 Size: ";
    cin >> arr1Size;
    cout << "Enter Array 2 Size: ";
    cin >> arr2Size;

    ansSize = arr1Size + arr2Size;

    arr1 = new int[arr1Size];
    arr2 = new int[arr2Size];
    ans = new int[ansSize];

    cout << "\nEnter space separated values of Array 1: ";
    for(int i = 0; i < arr1Size; i++)
        cin >> arr1[i];

    cout << "Enter space separated values of Array 2: ";
    for (int i = 0; i < arr2Size; i++)
        cin >> arr2[i];

    merge(arr1, arr1Size, arr2, arr2Size, ans, ansSize);
    cout << "\nThe sorted merge array is: ";
    print(ans, ansSize);

    delete[] arr1;
    delete[] arr2;
    delete[] ans;

    arr1 = NULL;
    arr2 = NULL;
    ans = NULL;

    return 0;
}
