#pragma once
#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_
#include <string>
#include "Word.h"
#include "List.h"

using namespace std;

struct HashNode
{
	HashNode* pNext;
	int Status;
	Word word;
};

class HashTable
{
private:
	HashNode* HTable[1000];
	int HashFunc(string s);
public:
	HashTable();
	
	Word Search(string s);
	
	void Insert(Word w);

	void Delete(string s);

	void ShowTable();

	void FindMaxAmount(List& l);
};
#endif;