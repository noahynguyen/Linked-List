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
	Child c1("Ann", "Kang", 7), c2("Pradnya", "Agarwal", 8), c4("Cesar", "Ruiz", 6);
	Child c5("Piqi", "Tang", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
	Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
	List342<Child> class1, class2, soccer, chess, rockstars, family, santasList;
	Child temp;
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1 = class1;

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

