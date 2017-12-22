#pragma once
#define uint unsigned int
#include <vector>
using namespace std;


class d_aryHeap
{
	vector<double> data;

	unsigned int d;

	void siftUp(uint i);
	void siftDown(uint i);
	int kthChild(uint i, uint k);
	int maxChild(uint i);
	int parent(uint i);

public:

	double extractMax();
	void insert(double x);
	double extract(uint index);
	void increaseKey(uint index, double key);
	//void decreaseKey(int index, double key);
	void clear();
	void print();
	void demo();
	d_aryHeap(uint _d) : d(_d) {};
};

void test();