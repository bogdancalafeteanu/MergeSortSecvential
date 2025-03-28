#include <iostream>
#include <chrono>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}

	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = {12,11,13,5,6,7,25,12,60,24,116,-43,63,62,-6,0,35,64363,232,6116,3235,4467,33,227,9,3,22,885,67444,225};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Array before sorting: ";
	printArray(arr, size);

	auto start = chrono::high_resolution_clock::now();
	mergeSort(arr, 0, size - 1);
	auto stop = chrono::high_resolution_clock::now();

	cout << "Array after sorting: ";
	printArray(arr, size);

	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Run time: " << duration.count() << " microseconds" << endl;


	return 0;
};