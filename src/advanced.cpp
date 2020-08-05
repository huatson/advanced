#include <iostream>
#include "advancedConfig.h"

#include <bits/stdc++.h>
#include <vector>

#ifdef USE_DFS
#include "CustomDFS.h"
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
	int a[]={ 1, 8, 9, 20 };
	int b[]={ 5, 8, 20, 1 };
	std::vector<int> out;
	// contador de lista a
	int countera[21]={ 0 };
	// contador de lista b
	int counterb[21]={ 0 };
	for (unsigned int i=0;i<4;i++)
	{
		countera[a[i]]++;
		counterb[b[i]]++;
	}

	for (unsigned int j=0;j<21;j++)
	{
		//	excluir coincidencias o no existentes
		if ((countera[j] == 1 && counterb[j] == 1) || (countera[j] == 0 && counterb[j] == 0))
		{
			continue;
		}
		out.push_back(j);
		/**
		else
		{

			// solo existe A o B solamente
			if (countera[j] == 1 && counterb[j] == 0
				|| countera[j] == 0 && counterb[j] == 1)
			{
				out.push_back(j);
			}
			**/
	}
	return true;
}

int main()
{
	if (!compareLists())
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}
