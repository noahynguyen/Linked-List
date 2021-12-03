#include "child.h"
#include "animal.h"
#include "bird.h"
#include "list342.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int score = 3;
	List342<int>* numbers = new List342<int>();

	int a = 4, b = -6, c = -7;
	numbers->BuildList("ints.txt");
	int temp, temp1;
	numbers->Insert(&a);
	numbers->Insert(&b);
	numbers->Insert(&c);
	if ( (! numbers->Peek(a, temp)) ||
	     (! numbers->Peek(b, temp)) ||
	     (! numbers->Peek(c, temp)))
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	numbers->Remove(a, temp);
	if (numbers->Peek(a, temp1))
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	numbers->Remove(c, temp);
	if (numbers->Peek(c, temp1))
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	ostringstream stream;
	stream << *numbers;
	if ((std::string)"-6-1113" == stream.str())
	{
		cout << "SCORE: " << to_string(score) << endl;
		return score;
	}
	else
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
}

