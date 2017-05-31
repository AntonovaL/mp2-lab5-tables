#ifndef  _WORD_H_
#define _WORD_H_

#include<string>
#include<iostream>

using namespace std;

class Word
{
	string word;
	int amount;
public:
	Word();
	Word(const Word &w);
   
	void SetWord(string s);

	void SetAmount(const int &val);

	string GetWord();
	
	int GetAmount();

	string TransformWord(string s);

	Word& operator =(const Word& w);

	bool operator==(const Word& w);

	Word operator++(int);


    friend ostream& operator << (ostream &os, Word &w)
	{
		os << w.word;
		cout<<" : " << w.amount;
		return os;
	}

};


#endif