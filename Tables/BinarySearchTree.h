#ifndef  _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_


#include "List.h";
#include "Word.h";

using namespace std;

struct BSTNode
{
	Word x;
	BSTNode *left, *right;
	
	BSTNode(BSTNode& n)
	{
		x = n.x;
		left = n.left;
		right = n.right;
	}

	BSTNode(Word w)
	{
		x = w;
		left = NULL;
		right = NULL;
	}

	BSTNode& operator=(BSTNode& n)
	{
		x = n.x;
		left = n.left;
		right = n.right;
		return *this;
	}
};


class BinarySearchTree
{
private:
	BSTNode* root;
	BSTNode* FindWithParent(string s, BSTNode& parent);
public:
	BinarySearchTree();

	BSTNode* GetRoot();
	
	void Insert(BSTNode* r, Word w);

	void Delete(string s);

	Word Search(BSTNode* r, string s);

	void PreOrderShow(BSTNode* node);

	void  PostOrderShow(BSTNode *node);

	void InOrderShow(BSTNode *node);
	
	void FindMaxAmount(BSTNode *node,List& l);

};

#endif