#include "heap.h"
#include <iostream>
#include <ctime>
using namespace std;

int d_aryHeap::parent(uint pos)
{
	return (pos - 1) / d;
}

int d_aryHeap::kthChild(uint pos, uint k)
{
	return d*pos + k;
}

int d_aryHeap::maxChild(uint pos)
{
	int c = d*pos + 1;
	if (c >= data.size())
		return -1;
	int M = c;
	double Mdata = data[c];
	for (int j = c + 1; j < c + d; ++j)
		if (j >= data.size())
			break;
		else if (data[j] > Mdata)
		{
			Mdata = data[j];
			M = j;
		}
	return M;
}


double d_aryHeap::extractMax()
{
	return extract(0);
}

void d_aryHeap::insert(double x)
{
	data.push_back(x);
	siftUp(data.size() - 1);
}

double d_aryHeap::extract(uint pos)
{
	if (data.size() <= pos)
	{
		cout << "error: heap underflow" << endl;
		return 0;
	}
	double tmp = data[pos];
	data[pos] = data[data.size() - 1];
	data.pop_back();
	siftDown(pos);
	return tmp;
}

void d_aryHeap::increaseKey(uint pos, double key)
{
	if (key < data[pos])
	{
		cout << "error: key is less than existing value" << endl;
		return;
	}
	data[pos] = key;
	siftUp(pos);
}

void d_aryHeap::siftUp(uint pos)
{
	int tmp = data[pos];
	while (pos > 0 && data[pos] > data[parent(pos)])
	{
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = tmp;
}

void d_aryHeap::siftDown(uint pos)
{
	if (pos <= data.size())
		return;
	double tmp = data[pos];
	uint child = maxChild(pos);
	while (child != -1)
	{
		if (data[pos] < data[child])
			data[pos] = data[child];
		else break;
		pos = child;
		child = maxChild(pos);
	}
	data[pos] = tmp;
}

void d_aryHeap::clear()
{
	data.clear();
}

void d_aryHeap::print()
{
	cout << "HEAP - ";
	int p = 0;
	for (int i = 0; i < data.size(); ++i)
	{
		cout << data[i] << " ";
		if (i % d == 0)
			cout << "   |   ";
		if (i == p)
		{
			p = kthChild(p, d);
			cout << endl;
		}
	}
	cout << endl;
}

void test()
{
	srand(clock());
	const int arity = 7;
	d_aryHeap heap(arity);
	//int arr[300];
	int N = 50000;
	time_t t = clock();
	for (int i = 0; i < N; ++i)
	{
		heap.insert(rand());
	}
	for (int i = 0; i < 1000; ++i)
	{
		heap.increaseKey(i, INT_MAX);
		heap.extractMax();
	}
	t = clock() - t;
	cout << "Took " << t << " clocks." << endl;
}

void d_aryHeap::demo()
{
	uint choise;
	cout << "1 - INSERT, 2 - EXTRACT, 3 - EXTRACT MAX, 4 - INCREASE KEY, 6 - CLEAR, 7 - PRINT, 0 - FINISH" << endl;
	do {
		cin >> choise;
		uint pos;
		double key;
		switch (choise)
		{
		case 0:
			//print();
			cout << "---END---" << endl;
			system("pause");
			return;
		case 1:
			cout << "Enter key: ";
			cin >> key;
			insert(key);
			break;
		case 2:
			cout << "Enter index: ";
			cin >> pos;
			cout << extract(pos) << endl;
			break;
		case 3:
			cout << extractMax() << endl;
			break;
		case 4:
			cout << "Enter pos: " << endl;
			cin >> pos;
			cout << "Enter key: " << endl;
			cin >> key;
			increaseKey(pos, key);
			break;
		case 5:
			break;
		case 6:
			clear();
			break;
		case 7:
			print();
			break;
		}
	} while (choise);
}