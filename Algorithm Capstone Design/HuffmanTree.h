#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct nodetype {
	string symbol;
	int frequency;
	nodetype* left;
	nodetype* right;

	nodetype(string s = "", int f = 0) : symbol(s), frequency(f), left(NULL), right(NULL) {}
	nodetype(nodetype* left, nodetype* right) : symbol(""), frequency(left->frequency + right->frequency), left(left), right(right) {}
};

struct cmp
{
	bool operator()(const nodetype* a, const nodetype* b)
	{
		return a->frequency > b->frequency;
	}
};

nodetype* HuffmanTree(priority_queue<nodetype*, vector<nodetype*>, cmp>& pq)
{
	while (pq.size() > 1)
	{
		nodetype* p = pq.top();
		pq.pop();
		nodetype* q = pq.top();
		pq.pop();
		nodetype* r = new nodetype(p, q);
		r->frequency = p->frequency + q->frequency;
		pq.push(r);
	}

	nodetype* endTree = pq.top();
	pq.pop();

	return endTree;
}

void printHuffmanTree(nodetype* T, vector<int> temp)
{
	if (T->left != NULL) {
		temp.push_back(0);
		printHuffmanTree(T->left, temp);
	}

	if (T->symbol != "") {
		cout << T->symbol << ' ';
		for (int i = 0; i<int(temp.size()); i++)
			cout << temp[i];
	}
	cout << '\n';
	temp.pop_back();

	if (T->right != NULL) {
		temp.push_back(1);
		printHuffmanTree(T->right, temp);
	}
}

#endif