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
	Child t;

	Child c1("Ann", "Kang", 7), c2("Pradnya", "Agarwal", 8), c3("Bill", "Vollmann", 13), c11;
	List342<Child>* class1 = new List342<Child>();
	List342<Child>* class2 = new List342<Child>();
	Child temp;
	class1->Insert(&c1);
	class1->Insert(&c2);
	class1->Insert(&c3);
	class1->Remove(c1, c11);
	class2->Insert(&c11);
	ostringstream stream;
	stream << *class2;
	if (((std::string)"AnnKang7" == stream.str()) &&
	    (! class1->Peek(c1, temp)))
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

