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

	List342<Bird>bird;

	bird.Insert(&b4);
	bird.Merge(bird);

	ostringstream stream;
	stream << bird;

	if ((std::string)"duck2" == stream.str())
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

