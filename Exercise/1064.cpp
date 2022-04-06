#include<bits/stdc++.h>
using namespace std;
#define MAXN 30
int n;

struct levelNode
{
	int lev;
	char data;
};

struct pcNode
{
	int lev;
	char data;
	pcNode* child[MAXN];
	pcNode* parent;
	pcNode(levelNode a)
	{
		lev = a.lev;
		data = a.data;
		for (int i = 0; i < MAXN; i++)
			child[i] = NULL;
		parent = NULL;
	}
};

levelNode a[MAXN];

void getData()
{
	cin >> n;
	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> a[i].lev >> c >> a[i].data >> c;
		getchar();
	}
}

pcNode* buildTree(levelNode* a, int n)
{
	pcNode* root = new pcNode(a[0]);
	pcNode* p = root;
	for (int i = 1; i < n; i++)
	{
		pcNode* q = new pcNode(a[i]);
		while (p->lev >= q->lev)  // 找到q的parent
		{
			p = p->parent;
		}
		int j = 0;
		while (p->child[j] != NULL) j++;
		p->child[j] = q;
		q->parent = p;
		p = q;
	}
	return root;
}

void postOrderTraverse(pcNode* root)
{
	if (root)
	{
		for (int i = 0; i < MAXN; i++)
		{
			if (root->child[i])
				postOrderTraverse(root->child[i]);
		}
		cout << root->data;
	}
}

int main()
{
	getData();
	pcNode* root = buildTree(a, n);
	postOrderTraverse(root);
	return 0;
}