#include <iostream>
#include "advancedConfig.h"

#include <vector>

#ifdef USE_DFS
#include "CustomDFS.h"
#endif

#ifdef USE_COMBINATORY
#include "Combinatory.h"
#endif

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
	for(int k=0;k<c.size();++k)
	{
		sum+=c[k];
	}
	if(sum == TARGET)
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
		if(testSum(c))
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

int main()
{
	vector<int> c;
	vector<int> list = {1, 2, 3, 9};
	comparesum(list, 0, 2);
	if (result)
	{
		cout << "TRUE" << endl;
		
	}else
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
		
	}else
	{
		cout << "FALSE" << endl;
	}
	return EXIT_SUCCESS;
}
