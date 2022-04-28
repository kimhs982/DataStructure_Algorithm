#include "HuffmanTree.h"

int main()
{
	priority_queue<nodetype*, vector<nodetype*>, cmp> pq;
	pq.push(new nodetype("FISH", 27));
	pq.push(new nodetype("ABC", 12));
	pq.push(new nodetype("ABCC", 7));
	pq.push(new nodetype("AB", 19));
	pq.push(new nodetype("A", 35));
	pq.push(new nodetype("B", 40));
	pq.push(new nodetype("BABA", 15));

	nodetype* resultTree = HuffmanTree(pq);

	vector<int> temp;
	printHuffmanTree(resultTree, temp);

	return 0;
}