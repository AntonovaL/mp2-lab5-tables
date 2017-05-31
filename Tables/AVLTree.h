#pragma once
#ifndef  _AVL_TREE_H_
#define _AVL_TREE_H_

#include "Word.h"

#include <math.h>

using namespace std;

struct AVLNode // структура для представления узлов дерева
{
	Word x;
	AVLNode* left;
	AVLNode* right;
	unsigned char height;

	AVLNode(Word w)
	{
		x = w;
		left = NULL;
		right = NULL;
		height = 0;
	}
};


class AVLTree
{
private:
	AVLNode* root;

public:	
	AVLTree() : root(NULL) { }

	AVLNode*GetRoot()
	{ 
		return this->root; 
	}


	unsigned char height(AVLNode* p)
	{
		return p ? p->height : 0;
	}

	int bFactor(AVLNode* p)
	{
		return height(p->right) - height(p->left);
	}

	void fixheight(AVLNode* p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = (hl>hr ? hl : hr) + 1;
	}

	AVLNode* RightRotate(AVLNode* p) // правый поворот вокруг p
	{
		AVLNode* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}

	AVLNode* LeftRotate(AVLNode* q) // левый поворот вокруг q
	{
		AVLNode* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}

	AVLNode* Balance(AVLNode* p) // балансировка узла p
	{
		fixheight(p);
		if (bFactor(p) == 2)
		{
			if (bFactor(p->right) < 0)
				p->right = RightRotate(p->right);
			return LeftRotate(p);
		}
		if (bFactor(p) == -2)
		{
			if (bFactor(p->left) > 0)
				p->left = LeftRotate(p->left);
			return RightRotate(p);
		}
		return p; // балансировка не нужна
	}


AVLNode* Insert(AVLNode* r, Word w)
{
	if (root == NULL)
	{
		root = new AVLNode(w);
		return root;
	}
	if (!r) {
		r = new AVLNode(w);
		return r;
	}
	else if (w.GetWord() < r->x.GetWord()) {
		r->left = Insert(r->left, w);
		r = Balance(r);
	}
	else if (w.GetWord() > r->x.GetWord()) {
		r->right = Insert(r->right, w);
		r = Balance(r);
	}
	else r->x++;

	return r;
}




void InOrderShow(AVLNode *node)
{
	if (!node) {
		return;
	}

	InOrderShow(node->left);
	cout << node->x << endl;
	InOrderShow(node->right);
}

	void PostOrderShow(AVLNode *node)
	{
		
		if (node != NULL)
		{
			PostOrderShow(node->left);
			PostOrderShow(node->right);
			cout << node->x << endl;
		}
	}


	void FindMaxAmount(AVLNode * node, List & l)
	{
		if (node != NULL)
		{
			FindMaxAmount(node->left, l);

			l.SortInsert(node->x);

			FindMaxAmount(node->right, l);
		}
	}



};


#endif // ! _AVL_TREE_H_
