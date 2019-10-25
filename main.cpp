#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <time.h>
#include <chrono>
using namespace std;
int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low){
        return (item > a[low])?  (low + 1): low;
    }
    int mid = (low + high)/2;

    if(item == a[mid]){
        return mid+1;
    }

    if(item > a[mid]){
    return binarySearch(a, item, mid+1, high);
    }
    else{
        return binarySearch(a, item, low, mid-1);
    }
}
void binary_insertionSort(int a[], int n)
{
    int loc, j, k, selected;

    for (int i = 1; i < n; ++i)
    {
        cout<<"1"<<endl;
        j = i - 1;
        selected = a[i];
        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);
        //cout<<loc<<endl;
        // Move all elements after location to create space
        while (j >= loc)
        {
            cout<<"2"<<endl;
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}
void linear_insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
          cout<<"3"<<endl;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            cout<<"4"<<endl;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int a[] = {37, 23, 0, 17, 12, 72, 31,46, 100, 88, 54};
    int n = sizeof(a)/sizeof(a[0]);
    clock_t tStart1 = clock();
    binary_insertionSort(a, n);
    double t_comparisons1=(double)(clock() - tStart1)/CLOCKS_PER_SEC;
    cout<<t_comparisons1<<endl;
    clock_t tStart2 = clock();
    linear_insertionSort(a,n);
    double t_comparisons2=(double)(clock() - tStart2)/CLOCKS_PER_SEC;
    fstream f;
    f.open("compare.csv",ios::app|ios::out);
    f<<n<<","<<t_comparisons1;
    f<<endl;
    f<<n<<","<<t_comparisons2;
    f<<endl;
    f.close();
    return 0;
}
