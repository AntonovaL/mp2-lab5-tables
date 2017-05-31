#include "BinarySearchTree.h"

using namespace std;

BSTNode* BinarySearchTree:: FindWithParent(string s, BSTNode& parent)
{
	BSTNode *current = root;
	while (current != NULL)
	{
		if (s<current->x.GetWord())// ���� ������� �������� ������, ���� ������.
		{

			parent = *current;
			current = current->left;
		}
		else
			if (s < current->x.GetWord())// ���� ������� �������� ������, ���� �������.
			{
				parent = *current;
				current = current->right;
			}
			else break;
	}
	return current;
}

BinarySearchTree::BinarySearchTree() //�����������
{
	root = NULL;
}

BSTNode*BinarySearchTree:: GetRoot()
{
	return root;
}

void BinarySearchTree:: Insert(BSTNode* r, Word w)
{
	if (r == NULL)//���� ������ ������, ������ ������� �������� ����.
	{
		root = new BSTNode(w);
		return;
	}
	if (w.GetWord()<r->x.GetWord())// ����������� �������� ������ �������� ����
	{
		if (r->left == NULL)// ���� ��� ������ ���������, ��������� �������� � ������ �������
		{
			r->left = new BSTNode(w);
		}
		else
		{
			Insert(r->left, w);// � ��������� ������ ��������� ��� ������ ���������
		}
	}
	// ����������� �������� ������ ��� ����� �������� ����.
	else
	{
		if (w.GetWord() == r->x.GetWord()) //���� ����� ����������, �� ����������� ����������
		{
			r->x++;
			return;
		}
		if (r->right == NULL) // ���� ��� ������� ���������, ��������� �������� � ������� �������
		{
			r->right = new BSTNode(w);
		}
		else
		{
			Insert(r->right, w);// � ��������� ������ ��������� ��� ������� ���������.
		}
	}
}

void BinarySearchTree:: Delete(string s)
{
	BSTNode *current, *parent;

	// ������� ��������� ����.
	current = FindWithParent(s, *parent);
	if (current == NULL)
	{
		return;
	}

	if (current->right == NULL)// ���� ��� ����� ������, ����� ������� ������ �� ����� ����������.
	{
		if (parent == NULL)
		{
			root = current->left;
		}
		else
		{
			if (parent->x.GetWord()>current->x.GetWord())
			{
				// ���� �������� �������� ������ ��������,
				// ����� ������� �������� ���� ���������� ����� �������� ��������.
				parent->left = current->left;
			}
			else if (parent->x.GetWord()<current->x.GetWord())
			{ // ���� �������� �������� ������ ��������, ����� ������� �������� ���� ���������� ������ �������� ��������. 
				parent->right = current->left;
			}
		}
	} // ���� � ������� ������� ��� ����� ����� �� �� �������� ����� ���������� ����. 
	else if (current->right->left == NULL)
	{
		current->right->left = current->left;
		if (parent == NULL)
		{
			root = current->right;
		}
		else
		{
			if (parent->x.GetWord()>current->x.GetWord())
			{
				// ���� �������� �������� ������ ��������,������ ������� �������� ���� ���������� ����� �������� ��������.
				parent->left = current->right;
			}
			else
				if (parent->x.GetWord()<current->x.GetWord())
				{ // ���� �������� �������� ������ �������� - ������ ������� �������� ���� ���������� ������ �������� ��������.
					parent->right = current->right;
				}
		}
	} // ���� � ������� ������� ���� ���� �����, ������� ����� ������� �� ������� ��������� �������� ��������� ����. 
	else {
		// ������ ������� ����� ����. 
		BSTNode* leftmost = current->right->left;
		BSTNode* leftmostParent = current->right;
		while (leftmost->left != NULL)
		{
			leftmostParent = leftmost;
			leftmost = leftmost->left;
		} // ����� ��������� �������� ���������� ������ ���������� �������� ������ ����. 
		leftmostParent->left = leftmost->right; // ����� � ������ ������� �������� ���� ���������� ����� � ������ �������� �������� ������.
		leftmost->left = current->left;
		leftmost->right = current->right;
		if (parent == NULL) { root = leftmost; }
		else
		{
			if (parent>current)
			{
				// ���� �������� �������� ������ �������� - ������� ����� ���� ���������� ����� �������� ��������.
				parent->left = leftmost;
			}
			else if (parent<current)
			{
				// ���� �������� �������� ������ ��������,
				// ������� ����� ���� ���������� ������ �������� ��������.
				parent->right = leftmost;
			}
		}
	}
}

Word BinarySearchTree:: Search(BSTNode* r, string s)
{
	BSTNode *current = r;
	while (current != NULL)
	{
		if (s<current->x.GetWord())// ���� ������� �������� ������, ���� ������.
		{

			return Search(current->left, s);
		}
		else
			if (s < current->x.GetWord())// ���� ������� �������� ������, ���� �������.
			{
				return Search(current->right, s);
			}
			else break;

	}
	Word res;
	res.SetWord("error");
	return res;
}

void BinarySearchTree::PreOrderShow(BSTNode* node)
{
	if (node != NULL)
	{
		cout << node->x << endl;
		PreOrderShow(node->left);
		PreOrderShow(node->right);
	}
}

void BinarySearchTree:: PostOrderShow(BSTNode *node)
{
	if (node != NULL)
	{
		PostOrderShow(node->left);
		PostOrderShow(node->right);
		cout << node->x << endl;
	}
}

void BinarySearchTree:: InOrderShow(BSTNode *node)
{
	if (node != NULL)
	{
		InOrderShow(node->left);

		cout << node->x << endl;

		InOrderShow(node->right);
	}
}

void BinarySearchTree::FindMaxAmount(BSTNode * node, List & l)
{
	if (node != NULL)
	{
		FindMaxAmount(node->left,l);

		l.SortInsert(node->x);

		FindMaxAmount(node->right,l);
	}
}


