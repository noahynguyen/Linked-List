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
	List342<Animal>* a = new List342<Animal>();
	Animal p("dog", 1);     /////// Similar constructor to Bird
	Animal r("hippo", 3);   /////// Similar calls

	Animal pos;

	if (! a->BuildList("animal.txt"))
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	if ((a->Peek(r, pos)) &&
	    (a->Peek(p, pos)))
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

