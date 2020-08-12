#include "Combinatory.h"

using namespace std;

Combinatory::Combinatory()
{
    localCounter = 0;
    target = 8;
}

Combinatory::~Combinatory()
{
}

void Combinatory::create(int N, int r)
{
    for (int i = 0; i < N; ++i)
    {
        list.push_back(i + 1);
    }
}

bool Combinatory::testSum(const vector<int> &combinatory)
{
    return ((combinatory[0] + combinatory[1]) == target);
}

void Combinatory::recursive(vector<int> &rndList, int stride, int r)
{
    if (r == 0)
    {
        logIteration(combinatoryList);
        if(testSum(combinatoryList))
        {
            cout << "founded pair/target " << combinatoryList[0] << " + " << combinatoryList[1] << " = " << target << endl;
        }
        return;
    }
    for (int i = stride; i <= rndList.size() - r; i++)
    {
        combinatoryList.push_back(rndList[i]);
        recursive(rndList, i + 1, r - 1);
        combinatoryList.pop_back();
    }
}

void Combinatory::logIteration(const vector<int> &combinatory)
{
    cout << "Combine Iteration #" << (++localCounter) << ": [";
    for (int i = 0; i < combinatory.size(); ++i)
    {
        cout << combinatory[i] << " ";
    }
    cout << "] " << endl;
}

void Combinatory::runExample()
{
    vector<int> pair = {0, 0};
    vector<int> rndList = {1, 2, 3, 9};
    recursive(rndList, 0, 2);
    rndList.clear();
    cout << "new list.." << endl;
    localCounter=0;
    rndList = {1, 2, 4, 4};
    recursive(rndList, 0, 2);
    return;
}