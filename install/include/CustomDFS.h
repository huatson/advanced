/**
*	from: <https://leetcode.com/problems/binary-tree-level-order-traversal/>
*	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*	For example:
*	Given binary tree [3,9,20,null,null,15,7],
*		3
*	   / \
*	  9  20
*		/  \
*	   15   7
*	return its level order traversal as:
*	[
*	  [3],
*	  [9,20],
*	  [15,7]
*	]
**/

#ifndef __CUSTOMDFS_H__
#define __CUSTOMDFS_H__

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

/**
* Definition for a binary tree node.
**/
struct TreeNode
{
public:
	TreeNode()
		: val(0)
		, left(nullptr)
		, right(nullptr)
	{
		//
	}
	TreeNode(int x) 
		: val(x)
		, left(nullptr)
		, right(nullptr)
	{
		//
	}
	TreeNode(int x, TreeNode *l, TreeNode *r)
		: val(x)
		, left(l)
		, right(r)
	{
		//
	}

	int val;
	TreeNode *left;
	TreeNode *right;

};
 

class CustomDFS
{
public:
	CustomDFS();
	~CustomDFS();

	void removeBrackets(string &inputData);
	string getInputData(const char *filepath);
	TreeNode *createTreeNode(const char *filepath);

	vector<vector<int>> levelOrder(TreeNode* root);

};

#endif  //__CUSTOMDFS_H__