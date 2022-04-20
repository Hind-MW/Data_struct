#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int L,int mid,int R)
{
	//int* help = new int[R - L + 1]; //辅助空间
	vector<int> help;
	int i= 0;
	int p1 = L;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <=R)
	{
		if (arr[p1] <= arr[p2])
		{
			help.push_back(arr[p1]);
			p1++;
		}
		else
		{
			help.push_back(arr[p2]);
			p2++;
		}
	}
	while (p1<=mid)
	{
		help.push_back(arr[p1]);
		p1++;
	}
	while (p2 <= R)
	{
		help.push_back(arr[p2]);
		p2++;
	}
	for (int j = 0; j < help.size(); j++)
	{
		arr[L + j] = help[j];
	}
}
int process(int arr[], int L, int R)
{
	if (L == R)
	{
		return arr[L];
	}
	int mid = L + ((R - L) >> 1);//求取中间值
	int leftMax = process(arr, L, mid);
	int rightMax = process(arr, mid + 1, R);
	merge(arr, L, mid, R);
}

int main()
{
	int arr[] = {1,2,4,56,7,8};
	process(arr, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}