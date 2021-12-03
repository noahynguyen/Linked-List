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
	Bird b1("swan", 10), b2("parrot", 5), temp;

	List342<Bird>thebirds;
	thebirds.Insert(&b1);
	thebirds.Insert(&b2);
	List342<Bird>* bird = new List342<Bird>(thebirds);
	if ((bird->Peek(b1, temp)) &&
	    (bird->Peek(b2, temp)))
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

