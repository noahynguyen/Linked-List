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
	Child c1("Ann", "Kang", 7), c2("Pradnya", "Agarwal", 8), c3("Bill", "Vollmann", 13), c11;
	List342<Child>* class1 = new List342<Child>();
	List342<Child>* class2 = new List342<Child>();
	Child temp;
	class1->Insert(&c2);
	class1->Insert(&c3);
	class1->Insert(&c1);
	class1->Remove(c2, c11);
	class2->Insert(&c11);

	ostringstream stream, stream1;
	stream << *class1;
	stream1 << *class2;
	if (((std::string)"PradnyaAgarwal8" == stream1.str()) &&
	    ((std::string)"AnnKang7BillVollmann13" == stream.str()))
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

