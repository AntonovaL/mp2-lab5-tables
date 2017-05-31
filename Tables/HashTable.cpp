#include "HashTabel.h";

using namespace std;


int HashTable::HashFunc(string s)
{
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		result = result + s[i];
	}
	return (result % 1000);
}

HashTable::HashTable()
{
	for (int i = 0; i < 1000; i++)
	{
		HTable[i] = new HashNode;
		HTable[i]->Status = 0;
		HTable[i]->pNext = NULL;
	}
}

Word HashTable:: Search(string s)
{
	int index = this->HashFunc(s);
	HashNode* tmp = HTable[index];
	if (tmp->word.GetWord() == s)
		return tmp->word;
	tmp = tmp->pNext;
	while (tmp != NULL)
	{
		if (tmp->word.GetWord() == s)
			return tmp->word;
		tmp = tmp->pNext;
	}
	Word Error;
	Error.SetWord("error");
	return Error;
}

void HashTable::Insert(Word w)
{
	int key = this->HashFunc(w.GetWord());
	if (HTable[key]->Status == 0)
	{
		HTable[key] = new HashNode;
		HTable[key]->word = w;
		HTable[key]->pNext = NULL;
		HTable[key]->Status = 1;
		return;
	}
	HashNode* tmp = HTable[key];
	if (HTable[key]->Status == 1 && tmp->word == w) { tmp->word++; return; }

	while (tmp->pNext != NULL)
	{
		tmp = tmp->pNext;
		if (tmp->word == w)
		{
			tmp->word++;
			return;
		}
	}
		tmp->pNext = new HashNode;
		tmp = tmp->pNext;
		tmp->word = w;
		tmp->Status = 1;
		tmp->pNext = NULL;
}

void HashTable:: Delete(string s)
{
	int key = this->HashFunc(s);
	if (HTable[key]->Status == 0)
		return;
	HashNode* tmp = HTable[key];
	if ((HTable[key]->word.GetWord() == s) && (HTable[key]->pNext == NULL))
	{
		delete tmp;
		HTable[key] = new HashNode;
		HTable[key]->Status = 0;
		HTable[key]->pNext = NULL;
		return;
	}
	if ((HTable[key]->word.GetWord() == s) && (HTable[key]->pNext != NULL))
	{
		HTable[key] = tmp->pNext;
		delete tmp;
		return;
	}
	HashNode* preTmp = tmp;
	tmp = tmp->pNext;
	while (tmp != NULL)
	{
		if (tmp->word.GetWord() == s)
		{
			preTmp->pNext = tmp->pNext;
			delete tmp;
			return;
		}
		preTmp = tmp;
		tmp = tmp->pNext;
	}
}


void HashTable:: ShowTable()
{
	HashNode* tmp;
	cout << "        Hash Table" << endl;
	for (int i = 0; i < 1000; i++)
	{
		if (HTable[i]->Status == 1)
		{
			cout << " [ " << i << " ] " << HTable[i]->word << endl;
		}
		else
			continue;
		tmp = HTable[i];
		while (tmp->pNext != NULL)
		{
			tmp = tmp->pNext;
			cout << tmp->word << endl;
		}
	}
}

void HashTable::FindMaxAmount( List& l)
{
	HashNode* tmp;
	for (int i = 0; i < 1000; i++)
	{
		if (HTable[i]->Status == 1)
		{
			l.SortInsert(HTable[i]->word);
		}
		else
			continue;
		tmp = HTable[i];
		while (tmp->pNext != NULL)
		{
			tmp = tmp->pNext;
			l.SortInsert(tmp->word);
		}
	}


}
