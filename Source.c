/*---------------------------------------------------
			Name: Sara Mohamed Taha

						Task 3

-----------------------------------------------------*/




#include <stdio.h>
#pragma warning(disable : 4996)


int isSorted(int arr[], int n) 
{
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] < arr[i + 1]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

int binarySearch(int arr[], int x, int low, int high) 
{
	if (high >= low) {
		int mid = low + (high - low) / 2;

		// If found at mid, then return mid
		if (arr[mid] == x)
			return mid;

		// Go left
		if (arr[mid] > x)
			return binarySearch(arr, x, low, mid - 1);

		// Else go right
		return binarySearch(arr, x, mid + 1, high);
	}

	return -1;		//not found
}

void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
}

void read(int arr[], int size)
{
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
}


int main()
{
	int arr[5], x = 0, choice;

	do
	{
		printf("Enter array: ");

		read(arr, 5);

		int n = sizeof(arr) / sizeof(arr[0]);

		if (isSorted(arr, n) == 0)
		{
			BubbleSort(arr, n);
			printf("Sorted array using Bubble Sort: \n");
			Print(arr, n);
		}
		else
			printf("Already Sorted!\n");

		
		printf("\nEnter number to be found using Binary Search: ");
		scanf("%d", &x);

		int result = binarySearch(arr, x, 0, n - 1);

		if (result == -1)
			printf("Element is not present in array\n");
		else
			printf("Element is at index %d\n", result);

		printf("Try Again? 1.yes    2.no	  : ");

		scanf("%d", &choice);
	} while (choice == 1);

	printf("Thank you :)");
}
