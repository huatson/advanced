#include <iostream>
#include "advancedConfig.h"

#ifdef USE_DFS
#include "CustomDFS.h"
#endif


int main()
{
	cout << "init stuff\n";
	CustomDFS *dfs = new CustomDFS();
	if (!dfs)
	{
		cerr << "Error, creating instance\n";
		return EXIT_FAILURE;
	}
	const char *fpath = "CustomDFS/input.txt";
	TreeNode *node = dfs->createTreeNode(fpath);
	if (!node)
	{
		cerr << "Error, creating node\n";
		delete dfs;
		return EXIT_FAILURE;
	}
	vector<vector<int>> order = dfs->levelOrder(node);

	delete dfs;
	return EXIT_SUCCESS;
}
