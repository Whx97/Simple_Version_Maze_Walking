#include<iostream>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

int df(int *a1){
	int t = 3;
	// *a1 = t;
	a1 = &t;
	cout <<"1 "<< *a1 << endl;
	return 9;
}

void dfv(int *a1){
	int t = 3;
	*a1 = t;
}

void exchange(int *x, int *y)
{
int *p=x;
*x = *y;
*y = *p;
}

int main()
{	int a = 5;
	int *b = &a;
	cout << *b << endl;

	// int d = df(b);
	df(b);
	// dfv(b);
	cout << *b << endl;
	// cout << d << endl;

	

	return 0;
}
