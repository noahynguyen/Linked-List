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
	List342<Bird>* thebirds = new List342<Bird>();
	Bird p("Eagle", 1);
	Bird r("Warbler", 3);
	Bird q("Tern", 44);
	Bird pos;
	thebirds->BuildList("birds.txt");
	if ((thebirds->Peek(r, pos)) &&
	    (thebirds->Peek(p, pos)) &&
	    (thebirds->Peek(q, pos)))
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

