
#ifndef __COMBINATORY_H__
#define __COMBINATORY_H__

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


class Combinatory
{
public:
	Combinatory();
	~Combinatory();

	// from nCr expression n combinations of r
	void create(int N, int r);

	void iterate(vector<int> &rndList, int offset, int r);

	void logIteration(const vector<int> &combinatory);

	void runExample();

	vector<int> list;
	vector<int> combinatoryList;

	int localCounter;

};

#endif  //__COMBINATORY_H__