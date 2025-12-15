//ascending order
#include <iostream>
using namespace std;
void arrSelectSort(int *, int);
void showArray(int [], int);
int main()
{
	int *donations = nullptr;		// Points to a sorted array of donations
	int *origin = nullptr;	// Points to an unsorted array of donations
	int numDonations = 0;			// To hold the number of donations
	cout << "How many donations would you like to enter? ";
	cin >> numDonations;
	while (numDonations <= 0)  // more than 0.
	{
        cout << endl;
		cout << "Please enter a positive number: ";
		cin >> numDonations;
	} 
	donations = new int[numDonations];
	origin = new int[numDonations];
	for (int k = 0; k < numDonations; k++)
	{
		cout << "Enter a donation: ";
		cin >> donations[k];
		while (donations[k] <= 0)
		{
			cout << "Donations must be greater than 0." << endl;
			cout << "Enter a donation: ";
			cin >> donations[k];
		}
		origin[k] = donations[k];  
	}
	arrSelectSort(donations, numDonations);
	cout << "The donations, sorted in ascending order are:"<< endl;
	showArray(donations, numDonations);
	cout << "The donations, in their original order are: " << endl;
	showArray(origin, numDonations);
	delete [] donations;
	delete [] origin;
	donations = nullptr;
	origin = nullptr;
	return 0;
}
void arrSelectSort(int *values, int elems)//in ascending order
{
	int startScan, minIndex, minElem;
	for (startScan = 0; startScan < (elems - 1); startScan++)
	{
		minIndex = startScan;
		minElem = values[startScan];
		for(int index = startScan + 1; index < elems; index++)
		{
			if (values[index] < minElem)
			{
				minElem = values[index];
				minIndex = index;
			}
		}
		values[minIndex] = values[startScan];
		values[startScan] = minElem;
	}
}
void showArray(int array[], int size)
{
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;
}