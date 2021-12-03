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
	List342<Bird>* birdlist = new List342<Bird>();

	Bird b1("bird1", 1);
	Bird b2("bird2", 2);
	birdlist->Insert(&b1);
	birdlist->Insert(&b2);
	if (birdlist->isEmpty())
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	birdlist->DeleteList();
	if (birdlist->isEmpty())
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

