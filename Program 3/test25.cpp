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
	List342<Animal>* listAnimal = new List342<Animal>();
	Animal d("dog", 1), c("cat", 2);      //////Again, another instance
	listAnimal->Insert(&d);
	listAnimal->Insert(&c);
	Animal temp;

	if (( !listAnimal->Peek(d, temp)) ||
	    ( !listAnimal->Peek(c, temp)))
	{
		cout << "SCORE: 0" << endl;
		return 0;
	}
	listAnimal->Remove(d, temp);
	if (! listAnimal->Peek(d, temp))
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

