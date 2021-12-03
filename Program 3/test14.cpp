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
	Bird b1("swan", 10), b2("parrot", 5), b3("pigeon", 4), b4("duck", 2), temp;

	List342<Bird>thebirds, bird;
	thebirds.Insert(&b1);
	thebirds.Insert(&b2);
	thebirds.Insert(&b3);
	bird.Insert(&b4);
	thebirds += bird;
	if (thebirds.Peek(b4, temp))
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

