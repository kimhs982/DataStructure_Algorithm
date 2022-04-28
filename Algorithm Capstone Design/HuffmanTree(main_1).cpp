#include "HuffmanTree.h"

int main()
{
	priority_queue<nodetype*, vector<nodetype*>, cmp> pq;
	pq.push(new nodetype("H", 27));
	pq.push(new nodetype("A", 15));
	pq.push(new nodetype("B", 12));
	pq.push(new nodetype("C", 9));
	pq.push(new nodetype("D", 5));
	pq.push(new nodetype("E", 10));
	pq.push(new nodetype("F", 11));

	nodetype* resultTree = HuffmanTree(pq);

	vector<int> temp;
	printHuffmanTree(resultTree, temp);

	return 0;
}