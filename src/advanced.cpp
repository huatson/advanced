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

bool solveDFS()
{
	cout << "init stuff\n";
	CustomDFS *dfs = new CustomDFS();
	if (!dfs)
	{
		cerr << "Error, creating instance\n";
		return false;
	}
	const char *fpath = "CustomDFS/input.txt";
	TreeNode *node = dfs->createTreeNode(fpath);
	if (!node)
	{
		cerr << "Error, creating node\n";
		delete dfs;
		return false;
	}
	vector<vector<int>> order = dfs->levelOrder(node);
	if (order.empty())
		return false;
	return true;
	delete dfs;
}

bool compareLists()
{
	int a[] = {1, 8, 9, 20};
	int b[] = {5, 8, 20, 1};
	std::vector<int> out;
	// contador de lista a
	int countera[21] = {0};
	// contador de lista b
	int counterb[21] = {0};
	for (unsigned int i = 0; i < 4; i++)
	{
		countera[a[i]]++;
		counterb[b[i]]++;
	}

	for (unsigned int j = 0; j < 21; j++)
	{
		//	excluir coincidencias o no existentes
		if ((countera[j] == 1 && counterb[j] == 1) || (countera[j] == 0 && counterb[j] == 0))
		{
			continue;
		}
		out.push_back(j);
	}
	return true;
}

/**
 * target = 8
 * 
 * a=[1,2,3,9]
 * 
 * nCr --> n = 4, r = 2
 * [1+2] --> combinacion
 * 1+2 == 8 --> false
 * 1+3 == 8 --> false
 * 1+9 == 8 --> false
 * 
 * 2+3 == 8 --> false
 * 2+9 == 8 --> false
 * 
 * 3+9 == 8 --> false
 * 
 * b=[1,2,4,4]
 * 
 * 1+2 == 8 --> false
 * 1+4 == 8 --> false
 * 1+4 == 8 --> false
 * 
 * 2+4 == 8 --> false
 * 2+4 == 8 --> false
 * 
 * 4+4 == 8 --> true
 * 
 * example:
 * vector<int> listA = {1,2,3,9};
 * vector<int> listB = {1,2,4,4};
**/
#define TARGET 8
vector<int> c;
bool result = false;
int counter = 0;
bool testSum(vector<int> &c)
{
	int sum = 0;
	for (int k = 0; k < c.size(); ++k)
	{
		sum += c[k];
	}
	if (sum == TARGET)
	{
		return true;
	}
	return false;
}
void comparesum(vector<int> &list, int stride, int r)
{
	// nCr: Si n = #total de elementos en una lista (n=4),
	// y r = #elementos de la lista n, que tiene que contener cada k-combinacion (r=2)
	// Entonces: Si solo cada combinacion va contener r elementos, entonces,
	// N-1 es la cantidad de combinaciones que pueden existir.
	// stride: cual es el valor que tengo que agregar a la combinacion actual, comenzando desde
	// el primer elemento de la lista.
	if (r == 0)
	{
		// temp log
		cout << "#" << counter << " " << c[0] << ", " << c[1] << endl;
		counter++;
		// r=0: no hay mas elementos pendientes por entrar a la combinacion, comparar valores
		// si la suma de 'ambos' elementos en la combinacion es igual al TARGET, return true
		if (testSum(c))
		{
			result = true;
		}
		return;
	}
	for (int i = stride; i <= list.size() - 1; ++i)
	{
		c.push_back(list[i]);
		comparesum(list, i + 1, r - 1);
		c.pop_back();
	}
}
void exec_comparesum()
{
	vector<int> c;
	vector<int> list = {1, 2, 3, 9};
	comparesum(list, 0, 2);
	if (result)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
	counter = 0;
	list.clear();
	c.clear();
	list = {1, 2, 4, 4};
	comparesum(list, 0, 2);
	if (result)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
}

bool comparetwonumbers_itr(vector<int> &list, int target, int results[2])
{
	for (int i = 0; i < list.size(); ++i)
	{
		for (int j = i + 1; j < list.size(); ++j)
		{
			const int a = list[i];
			const int b = list[j];
			const int sum = a + b;
			if (sum == target)
			{
				results[0] = a;
				results[1] = b;
				return true;
			}
		}
	}
	return false;
}
void exec_comparetwonumbers()
{
	vector<int> list = {1, 2, 3, 9};
	int results[] = {0, 0};
	bool founded = comparetwonumbers_itr(list, 8, results);
	if (founded)
	{
		cout << "founded in " << results[0] << ", " << results[1] << endl;
	}
	else
	{
		cout << "not founded!" << endl;
	}
}

void exec_printfrequencies()
{
	/**
	 * given a string of words, find frequencies of individual words.
	 * */
	const string str = "repeat after repeat word and another word";
	stringstream ss(str);
	unordered_map<string, int> mapWords;
	string aWord;
	while (ss >> aWord)
	{
		mapWords[aWord]++;
	}
	for (unordered_map<string, int>::iterator wordItr = mapWords.begin(); wordItr != mapWords.end(); ++wordItr)
	{
		cout << wordItr->first << " " << wordItr->second << endl;
	}
}
void unorderedMapExamples()
{
	/**
	 * declaring map of type <string, int>
	 * */
	unordered_map<string, int> str2IntMap;
	// insert values
	str2IntMap["valueoften"] = 10;
	str2IntMap["valueoftwenty"] = 20;
	str2IntMap["valueofthirteen"] = 30;
	// traversing the map
	for (auto x : str2IntMap)
	{
		cout << x.first << " " << x.second << endl;
	}
	/**
	 * declaring map of type <string, float>
	 * */
	unordered_map<string, float> str2FloatMap;
	// insert values
	str2FloatMap["PI"] = 3.1416f;
	str2FloatMap["root2"] = 1.414f;
	str2FloatMap["root3"] = 1.732f;
	str2FloatMap["log10"] = 2.302f;
	str2FloatMap["logE"] = 1.0f;
	//other insert method
	str2FloatMap.insert(make_pair("e", 2.718f));
	// test strings
	string keyPI = "PI";
	string keyLambda = "lambda";
	// if key not found in map iterator to end is return
	if (str2FloatMap.find(keyPI) == str2FloatMap.end())
	{
		cout << "\nNot founded: " << keyPI << endl;
	}
	else
	{
		cout << "\nFounded: " << keyPI << endl;
	}
	if (str2FloatMap.find(keyLambda) == str2FloatMap.end())
	{
		cout << "\nNot founded: " << keyLambda << endl;
	}
	else
	{
		cout << "\nFounded: " << keyLambda << endl;
	}
	// iterate over all map
	cout << "All Elements:\n";
	for (unordered_map<string, float>::iterator itrMap = str2FloatMap.begin(); itrMap != str2FloatMap.end(); ++itrMap)
	{
		cout << itrMap->first << " " << itrMap->second << endl;
	}
}

bool exec_comparetwonummap(vector<int> &list, const int target)
{
	unordered_map<int, int> mapList;
	for (int i = 0; i < list.size(); ++i)
	{
		int valueKey = (list[i] - target) * -1;
		if (mapList.find(valueKey) == mapList.end())
		{
			//mapList.insert(list[i],list[i]-target);
			mapList[list[i]] = valueKey;
		}
		else
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int target = 8;
	vector<int> list = {1, 2, 4, 4};
	const bool founded = exec_comparetwonummap(list, target);
	return EXIT_SUCCESS;
}
