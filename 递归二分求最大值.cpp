#include<iostream>

using namespace std;

int process(int arr[], int L, int R)
{
	if (L == R)
	{
		return arr[L];
	}
	int mid = L + ((R - L) >> 1);//求取中间值

	int leftMax = process(arr, L, mid);
	int rightMax = process(arr, mid + 1, R);
	return max(leftMax, rightMax);
}

int main()
{
	int arr[] = { 1,2,4,56,7,8 };
	cout << process(arr, 0, 6);

	return 0;
}