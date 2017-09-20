// 数据结构-链表.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node {
	int data;
	node *next;
}linkNode;
int n;
linkNode* createLinkNode() {
	linkNode* head;
	linkNode* p1 = NULL;
	linkNode* p2 = NULL;

	n = 0;
	p1 = (linkNode*)malloc(sizeof(linkNode));
	p2 = p1;
	if (p1 == NULL) {
		return NULL;
	}
	else {
		head = NULL;
		scanf("%d", &p1->data);
	}
	while (p1->data != 0) {
		n += 1;
		if (n == 1) {
			head = p1;
			p2->next = NULL;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = (linkNode*)malloc(sizeof(linkNode));
		scanf("%d", &p1->data);
	}
	p2->next = NULL;
	free(p1);
	p1 = NULL;
	return head;
}

void printLinkNode(linkNode* head) {
	linkNode* p;
	p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

int len;
int length(linkNode* head) {
	linkNode* p;
	p = head;
	while (p!=NULL) {
		len += 1;
		p = p->next;
	}
	return len;
}

void reverseLinkNode(linkNode* head) {
	linkNode* p;
	p = head;
	int len = length(p);
	vector<int> vecLinkNode;
	while (p != NULL) {
		vecLinkNode.push_back(p->data);
		p = p->next;
	}
	vector<int> ans;
	int max = vecLinkNode.size();
	for (int i = 1; i <= max; i++) {
		ans.push_back(vecLinkNode[max - i]);
		cout << vecLinkNode[max - i ] << " ";
	}
}
int main() {
	node* nodeP;
	nodeP = (node*)malloc(sizeof(node));
	nodeP = createLinkNode();
	len = 0;
	cout << "lenght= " << length(nodeP) << endl;

	printLinkNode(nodeP);

	reverseLinkNode(nodeP);

    return 0;
}

