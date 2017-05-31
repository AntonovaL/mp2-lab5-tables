#include "Word.h"


Word::Word()
{
word = "hello";
amount = -1;
}

Word::Word(const Word &w)
{
	word = w.word;
	amount = w.amount;
}

void Word::SetWord( string s)
{
	word = TransformWord(s);
}

void Word::SetAmount(const int &val)
{
	amount = val;
}

string Word:: GetWord()
{
	return word;
}

int Word::GetAmount()
{
	return amount;
}

string Word:: TransformWord(string s)
{
	char c=s[0];
	char* word=new char[30];
	int i = 0, j=0;
	while (s[i] != '\0' && isalpha(s[i]))
	{
		word[i] = tolower(s[i]);
		i++;
	}
	word[i] = '\0';
	return word;
}


Word Word::operator++(int)
{
	this->amount++;
	return *this;
}

Word& Word:: operator =(const Word& w)
{
	word = w.word;
	amount = w.amount;
	return *this;
}

bool Word:: operator==(const Word& w)
{
	if (this->word == w.word) return true;
	else return false;
}
