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
	Bird b1("swan", 10), b2("parrot", 5);

	List342<Bird>thebirds, bird;
	thebirds.Insert(&b1);
	thebirds.Insert(&b2);

	thebirds += thebirds;

	ostringstream stream;
	stream << thebirds;

	if ((std::string)"parrot5swan10" == stream.str())
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

