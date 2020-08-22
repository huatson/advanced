
#include "advancedConfig.h"

#ifdef USE_DFS
#include "CustomDFS.h"
#endif

#ifdef USE_COMBINATORY
#include "Combinatory.h"
#endif

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/**
 * matrix N  X N
 * N = 5
 * a b i j n
 * e n z h n 
 * i m p o q
 * h w a n m
 * o n b i h
 * buscando 
 * izpmi -> true
 * enmwo -> false
 * hibno -> true
 * 
 * iterative
 * izpmi = 5 
 * i == a --> false
 * i == b --> false
 * i == i --> true
 * */
static const int N = 5;
static char EMPTY = '-';
bool findWords(char wordMap[N][N], const char *word)
{
	if (strlen(word) > (N * N))
	{
		return false;
	}
	int idx = 0;
	bool letterFounded = false;
	int counterFounded = 0;
	while (idx < strlen(word))
	{
		letterFounded = false;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cout << word[idx] << " " << wordMap[i][j] << endl;
				if ((wordMap[i][j] != EMPTY) && (wordMap[i][j] == word[idx]))
				{
					counterFounded++;
					wordMap[i][j] = EMPTY;
					letterFounded = true;
					break;
				}
			}
			if (letterFounded)
			{
				break;
			}
		}
		idx++;
	}
	cout << "founded: " << counterFounded << " of " << strlen(word) << endl;
	if(counterFounded == strlen(word))
	{
		return true;
	}
	return false;
}

int main()
{
	FILE *f = freopen("src/input.txt", "r", stdin);
	if (!f)
		return EXIT_FAILURE;
	char data[N][N] = {'a'};
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> data[i][j];
	bool founded = findWords(data, "izcxi");
	return EXIT_SUCCESS;
}
