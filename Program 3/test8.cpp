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

	Child temp;
	class1->Insert(&c2);
	class1->Insert(&c3);
	class1->Insert(&c1);
	int count = 1;
	while (count <= 1000)
	{
		class1->Peek(c2, temp);
		if ((temp.name() != string("PradnyaAgarwal")) ||
		    (temp.age() != 8))
		{
			cout << "SCORE: 0" << endl;
			return 0;
		}
		class1->Peek(c1, temp);
		if ((temp.name() != string("AnnKang")) ||
		     (temp.age() != 7))
		{
			cout << "SCORE: 0" << endl;
			return 0;
		}
		count++;
	}

	cout << "SCORE: " << to_string(score) << endl;
	return score;
}

