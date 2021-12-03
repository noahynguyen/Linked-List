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
	int p(1);
	int r(-1);
	int q(13);
	int pos;
	numbers->BuildList("ints.txt");
	if ((numbers->Peek(r, pos)) &&
	    (numbers->Peek(p, pos)) &&
	    (numbers->Peek(q, pos)))
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

