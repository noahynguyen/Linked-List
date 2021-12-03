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
	List342<Child>* rockstars = new List342<Child>();
	Child p("Thomas", "Paine", 17);
	Child r("Joseph", "Smith", 4);
	Child q("George", "Washington", 12);
	Child pos;
	rockstars->BuildList("child.txt");
	if ((rockstars->Peek(r, pos)) &&
	    (rockstars->Peek(p, pos)) &&
	    (rockstars->Peek(q, pos)))
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

