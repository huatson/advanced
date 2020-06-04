#include "CustomDFS.h"

using namespace std;

CustomDFS::CustomDFS()
{
}

CustomDFS::~CustomDFS()
{
}

void CustomDFS::removeBrackets(string &dataStr)
{
	dataStr = dataStr.substr(1, dataStr.length() - 2);
}


string CustomDFS::getInputData(const char *filepath)
{
	string dataStr = "";
	fstream datafile;
	datafile.open(filepath, ios::in);
	if (!datafile.is_open())
	{
		cerr << "Error opening input.txt file\n";
		return dataStr;
	}
	getline(datafile, dataStr);
	removeBrackets(dataStr);
	datafile.close();
	return dataStr;
}


TreeNode *CustomDFS::createTreeNode(const char *filepath)
{
	//	get tree from input.txt
	string dataStr = getInputData(filepath);
	if (dataStr.empty())
	{
		cerr << "Error, empty data, string size " << dataStr.size() << "\n";
		return nullptr;
	}
	//	get the first element of the tree
	string itemList;
	stringstream ss;
	ss.str(dataStr);
	std::getline(ss, itemList, ',');

	//	initialize tree node
	TreeNode *rootNode = new TreeNode(stoi(itemList));
	queue<TreeNode*> queueTreeNodes;
	queueTreeNodes.push(rootNode);

	//	feed-in branches
	while (true)
	{
		TreeNode *dummyNode = queueTreeNodes.front();
		queueTreeNodes.pop();

		//	read next value
		if (!std::getline(ss, itemList, ','))
		{
			break;
		}
		//cout << "left item " << itemList << "\n";

		//	get left branch
		if (itemList != "null")
		{
			dummyNode->left = new TreeNode(stoi(itemList));
			queueTreeNodes.push(dummyNode->left);
		}

		//	read next value
		if (!std::getline(ss, itemList, ','))
		{
			break;
		}
		//cout << "right item " << itemList << "\n";

		//	get left branch
		if (itemList != "null")
		{
			dummyNode->right = new TreeNode(stoi(itemList));
			queueTreeNodes.push(dummyNode->right);
		}
	}
	return rootNode;
}

vector<vector<int>> CustomDFS::levelOrder(TreeNode* root)
{
	vector<vector<int>> levelorder;
	return levelorder;
}

