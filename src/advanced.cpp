#include <iostream>
#include "advancedConfig.h"

#include <vector>

#ifdef USE_DFS
#include "CustomDFS.h"
#endif

#ifdef USE_COMBINATORY
#include "Combinatory.h"
#endif

#include <unordered_map>

/**
 *	a=[10,20,30,20,20,50,50,10,70]
 *	output=3
 *	vacio[]
 *	numeros enteros
 *	0<=a[i]<=100
 * 
 *	iterativo:
 *	a[i], a[j] >= 0 && i != j
 *	10 == 20 --> false
 *	10 == 30 --> false
 *		...
 *	10 == 10 --> true
 *	a=[-1,20,30,20,20,50,50,-1,70]
 *	20 == 30 --> false
 *	20 == 20 --> true
 *	a=[-1,-1,30,-1,20,50,50,-1,70]
 *	30 == 20 --> false
 *	30 == 50 --> false
 *	30 == 50 --> false
 *	30 == 70 --> false
 *	20 == 30 --> false
 *		...
 *	50 == 30 --> false
 *	50 == 20 --> false
 *	50 == 50 --> true
 *	a=[-1,-1,30,-1,20,-1,-1,-1,70]
 *	70 == 30 --> false
 *	70 == 20 --> false
 *
 * contador: 
 * crear contador c de a
 * (c >= 2)
 * 0 >= 2 --> false: NEXT
 * 2 >= 2 --> true: 2/2 = 1
 * 3 >= 2 --> true: (3-1)/2 = 1
 * 4 >= 2 --> true: 4/2= 2 
 * ..
 * 
 **/
bool IsValidPair(vector<int> &a, const int i, const int j)
{
	return ((i != j) && (a[i] >= 0 && a[j] >= 0) && (a[i] == a[j]));
}

int PairNumbersItr(vector<int> &a)
{
	if (a.size() <= 1)
	{
		return 0;
	}
	int pares = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 1; j < a.size(); ++j)
		{
			//cout << i << " " << a[i] << " " << j << " " << a[j] << endl;
			if (IsValidPair(a, i, j))
			{
				pares++;
				a[i] = -1;
				a[j] = -1;
				continue;
			}
		}
	}
	return pares;
}

int PairNumbersCounter(vector<int> &a)
{
	if (a.size() <= 1)
	{
		return 0;
	}
	int pares = 0;
	const int MAX_VALUE = 100;
	int counter[MAX_VALUE] = {0};
	for (int k = 0; k < a.size(); ++k)
	{
		counter[a[k]]++;
	}
	for (int i = 0; i <= MAX_VALUE; ++i)
	{
		if (counter[i] >= 2)
		{
			//cout << "Num. " << i << " count: " << counter[i] << endl;
			if ((counter[i] % 2) == 0)
			{
				pares += counter[i] / 2;
			}
			else
			{
				pares += (counter[i] - 1) / 2;
			}
		}
	}
	return pares;
}

int PairNumbersMap(vector<int> &a)
{
	return 0;
}

int main()
{
	//vector<int> a = {10, 20, 30, 20, 20, 50, 50, 10, 70};
	vector<int> a = {10, 10, 10, 10, 10, 10, 10, 20, 20, 70, 70, 70, 70};
	//int pares = PairNumbers(a);
	int pares = PairNumbersCounter(a);
	cout << "pares: " << pares << endl;
	return EXIT_SUCCESS;
}
