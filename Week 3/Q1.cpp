#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, vector<int> &shifts, vector<int> &comparisons)
{
	int s=0, c=0;
	int i, key, j;
	int n = arr.size();
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			s++; c++;
		}
		arr[j + 1] = key;
		s++;
	}
	shifts.push_back(s);
	comparisons.push_back(c);
}
void printArray(vector<int> arr, int shifts, int comparisons)
{
	int i;
	cout << "\nSorted array : ";
	for (i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Comparisons : " << comparisons << endl;
	cout << "Shifts : " << shifts << endl;
}
int main() 
{
	int testcases, size, value;
	vector<vector<int>> arr;
	vector<int> shifts;
	vector<int> comparisons;
	cout << "Enter number of test cases : ";
	cin >> testcases;
	vector<int> tmp;
	
	for (int i = 0; i < testcases; i++) 
	{
		cout << "Enter size of array : ";
		cin >> size;

		cout << "Enter elements of array : ";
		tmp.clear();
		for (int j = 0; j < size; j++) 
		{
			cin >> value;
			tmp.push_back(value);
		}
		arr.push_back(tmp);
	}
	for (int i = 0; i < testcases; i++) 
	{
		insertionSort(arr[i], shifts, comparisons);
		printArray(arr[i], shifts[i], comparisons[i]);
	}
}
