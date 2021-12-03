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
	int a = 1, b = -1, d = 10000;
	List342<int>numbers;
	numbers.Insert(&a);
	numbers.Insert(&d);
	numbers.Insert(&b);
	ostringstream stream;
	stream << numbers;
	if ((std::string)"-1110000" == stream.str())
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

