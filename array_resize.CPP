#include<iostream>

using namespace std;

void resize_array(int *arr, int arr_size, int new_size)//make sure to pass a dynamic array
{
int *new_array, new_size;

    cout<<"Enter new array size: ";
    cin>>new_size;

    new_array=new int[new_size];

    for(int i=0;i<n;i++)
        new_array[i]=arr[i];

    delete arr;
    arr=new_array;
    new_array=0;
    delete new_array;
}
