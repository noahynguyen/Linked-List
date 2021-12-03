#include "child.h"
#include "animal.h"
#include "bird.h"
#include "list342.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int score = 4;
	Child c1("Ann", "Kang", 7), c2("Pradnya", "Agarwal", 8), c3("Pradnya", "Agarwal", 8);
	List342<Child> class1;

	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);

	ostringstream stream;
	stream << class1;
	if ((std::string)"PradnyaAgarwal8AnnKang7" == stream.str())
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

