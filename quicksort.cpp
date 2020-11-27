#include <iostream>
using namespace std;
#include "quicksort.h"

int main()
{
    int a[6] = {10,3,5,11,8,14};
    int b[6] = {10,3,5,11,8,14};
    quicksort(a,0,5);
    SortOddEven(b,6);
    cout << "Array a is sorted: ";
    for(int i = 0; i < 6; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
    cout << "Array b is sorted with parity: ";
    for(int i = 0; i < 6; i++)
    {
        cout << " " << b[i];
    }
    cout << endl;
    return 0;
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int* numArr,int first, int last)
{
	int left = first, right = last;
	while(left < right)
	{
		if(numArr[left] < numArr[last])
			left = left + 1;
		else if(numArr[right] > numArr[last])
			right = right - 1;
		else if(left < right)
			swap(numArr[left],numArr[right]);
	}
	swap(numArr[left],numArr[last]);
	return left;
}

void quicksort(int* numArr,int first, int last)
{
	if(last - first + 1  <= 1)
		return;
	else
	{
		int p = partition(numArr,first, last);
		quicksort(numArr,first,p-1);
		quicksort(numArr,p+1,last);
	}
}

void SortOddEven( int* numbers, int count )
{
	int left = 0, right = count - 1, inc = 0;
	int * temp;
	temp = new int[count];

	// Partition the array based on Parity
	for(inc = 0; inc < count;inc++)
	{
		if(numbers[inc]%2 == 1)
		{
            //If odd append to left
			temp[left] = numbers[inc];
			left = left + 1;
		}
		else
		{
            //If even append to right
			temp[right] = numbers[inc];
			right = right - 1;
		}
	}
    
    // DEBUG OUTPUT: cout << "left: " << left << endl;
    for(inc = 0; inc < count; inc++)
    {
        // DEBUG OUTPUT: cout << " " << temp[inc];
        // copy temp to numbers
        numbers[inc] = temp[inc];
    }
	// once left > right, "left" is the position of the first even number
	delete[] temp;
	quicksort(numbers,0,left-1); // sort the odd numbers
	quicksort(numbers,left,count-1); // sort the even numbers
}