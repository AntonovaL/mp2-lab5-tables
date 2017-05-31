#include "Word.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "List.h"
#include "HashTabel.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"


using namespace std;

int main()
{
	HashTable HTable;
	BinarySearchTree BSTree;
	AVLTree AVLTr;

	ifstream fin;
	int i = 0;
	double hashtime = 0, bstime=0, avltime=0;
	double start, finish;
	string buff;
	Word w;
	fin.open("text.txt");
	if (!fin)
	{
		cout << "Can't open the file" << endl;
		return 0;
	}
	else cout << "File open" << endl;
	while (!fin.eof())
	{
		fin>>buff;
		
		w.SetWord(buff);
		w.SetAmount(1);
		//что то происходит
		start = clock();
		HTable.Insert(w);
		finish = clock();
		hashtime += finish - start;
		start = clock();
		BSTree.Insert(BSTree.GetRoot(),w);
		finish = clock();
		bstime += finish - start;
		start = clock();
		AVLTr.Insert(AVLTr.GetRoot(),w);
		finish = clock();
		avltime += finish - start;


	}
	cout << "Reading is complete" << endl;
	int n;
	cout << "How many words do you want to receive?  ";
	cin >> n;
	List resultForHash(n);
    List resultForBin(n);
	List resultForAVL(n);
	//HTable.ShowTable();
	
	start = clock();
	HTable.FindMaxAmount(resultForHash);
	finish = clock();
	hashtime += finish - start;
	
	//cout << resultForHash;
	
	start = clock();
	BSTree.FindMaxAmount(BSTree.GetRoot(),resultForBin);
	finish = clock();
	bstime += finish - start;

	//cout << resultForBin;

	start = clock();
	AVLTr.FindMaxAmount(AVLTr.GetRoot(), resultForAVL);
	finish = clock();
	avltime += finish - start;

	cout << resultForAVL;
	
	//AVLTr.InOrderShow(AVLTr.GetRoot());
	cout <<"Time for hash table   "<< hashtime/CLOCKS_PER_SEC <<"s"<< endl;
	//BSTree.InOrderShow(BSTree.GetRoot());
	cout << "Time for binary search tree  "<<bstime/CLOCKS_PER_SEC<<"s" << endl;
	//AVLTr.PostOrderShow(AVLTr.GetRoot());
	cout << "Time for AVL tree  "<<avltime/CLOCKS_PER_SEC<<"s" << endl;
	//RBTr.InOrderShow(RBTr.GetRoot());


	return 0;
}