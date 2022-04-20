#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
int check_number1(int arr[])
{
    //通过异或找出数组中一个出现奇数次数
    int ero = 0;
    for (int i = 0; i < 9; i++) {
        ero ^= arr[i];
    }
    return ero;
}

void check_number2(int arr[],int size)
{
    //通过异或找出数组中两个出现奇数次数
    int ero = 0;
    for (int i = 0; i < size; i++) {
        ero ^= arr[i];
    }
    int rightOne = ero & (~ero + 1);
    int onlyone = 0;
    for (int i = 0; i < size; i++) {
        if((rightOne & arr[i]) == 0 )
            onlyone ^= arr[i];
    }
    cout << onlyone<< "\n" << (ero ^ onlyone) << endl;;
}


int main()
{
    
    int arr[] = {4,2,2,1,3,4,3,4,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    check_number2(arr,size);
    return 0;
}