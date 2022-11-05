#include<iostream>
#include<string>
#include"Foo.h"
using namespace std;
void heapify(int HeapSize, string h1[], string h[], int i)
{
	int left, right;
	string temp;
	string temp1;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < HeapSize) {
		if (stod(h[i]) < stod(h[left])) {
			temp = h[i];
			temp1 = h1[i];
			h[i] = h[left];
			h[left] = temp;
			h1[i] = h1[left];
			h1[left] = temp1;
			heapify(HeapSize, h1, h, left);
		}
	}
}
void addelem(string h[], string h1[], int HeapSize, int HeapSize1, string val, string name)
{
	int i, parent;
	i = HeapSize;
	h[i] = val;
	h1[i] = name;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (stod(h[i]) > stod(h[parent])) {
			string temp = h[i];
			string temp1 = h1[i];
			h[i] = h[parent];
			h[parent] = temp;
			h1[i] = h1[parent];
			h1[parent] = temp1;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
	HeapSize1++;
}