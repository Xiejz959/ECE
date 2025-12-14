#include <iostream>
#include <iomanip>
using namespace std;
void sort(double*, int);  
double average(double*, int); 
int main()
{
    double *ScorePtr = nullptr;
	int Scores = 0;			
	double Average = 0;			
	cout << "How many test scores will you enter? "<< endl;
	cin >> Scores;
	while (Scores < 0)
	{
		cout << "The number cannot be negative."<< endl;
		cin >> Scores;
	}
	ScorePtr = new double[Scores];
	for (int i = 0; i < Scores; i++)
	{
		cout << "Enter test score "<< (i + 1) << ": ";
		cin >> *(ScorePtr+i);
		while (*(ScorePtr+i) < 0)  
		{
			cout << "Negative scores are not allowed."<< endl;
			cin >> *(ScorePtr+i);
		}
	}
	sort(ScorePtr, Scores);
	Average = average(ScorePtr, Scores);
	cout << "\nThe test scores in ascending "<< "order, and their average, are:"<< endl;
	for (int j = 0; j < Scores; j++)
	{
		cout << fixed << setprecision(2) << setw(6) << *(ScorePtr+j) << endl;
	}
	cout << "Average score:  " << setprecision(2) << fixed << Average << endl << endl;
	delete [] ScorePtr;
	ScorePtr = nullptr;
	return 0;
}
void sort(double* score, int size)
{
	int start, minIndex; 
	double minValue;
    // sorting in ascending order
	for (start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = *(score+start);

		for(int index = start + 1; index < size; index++)
		{
			if (*(score+index) < minValue)
			{
				minValue = *(score+index);
				minIndex = index;
			}
		}

		*(score+minIndex) = *(score+start);
		*(score+start) = minValue;
	}
}
double average(double* score, int numScores)
{
	double total = 0;
	for (int k = 0; k < numScores; k++)
		total += *(score+k);
   
	// Return the average score.
	return (total / numScores);
}