#ifndef CHILD_H_
#define CHILD_H_
#include <string>
#include <iostream>
using namespace std;

class Child
{

friend ostream& operator<<(ostream &, const Child &child); 
friend istream& operator>>(istream &, Child &child);  

public:
	Child();
	Child(string first_name, string last_name, int age);
	Child(string first_name, string last_name);
	~Child();

	string name() const;
	int age() const;
	void set_first(const string &name);
	void set_last(const string &name);

	bool operator<(const Child &child) const;
	bool operator<=(const Child &child) const;
	bool operator>=(const Child &child) const;
	bool operator>(const Child &child) const;
	bool operator==(const Child &child) const;
	bool operator!=(const Child& child) const;

private:
	string first_name_;
	string last_name_;
	int age_;
};
#endif

