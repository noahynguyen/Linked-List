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
	class1->Peek(c2, temp);
	if (temp.name() != string("PradnyaAgarwal"))
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}	
	if (temp.age() != 8)
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	class1->Peek(c1, temp);
	if (temp.name() != string("AnnKang"))
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	if (temp.age() != 7)
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	class1->Peek(c3, temp);
	if (temp.name() != string("BillVollmann"))
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	if (temp.age() != 13)
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	else
	{
		cout << "SCORE: " << to_string(score) << endl;
		return 4;
	}
}

