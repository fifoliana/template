#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll rand(ll a, ll b)
{
	return (a + rand() % (b - a + 1));
}

void rand_arr(ll n, ll a, ll b)
{
	for (int i = 0; i < n; ++i)
	{
		cout << rand(a, b) << " "; 
	}
	cout << endl;
}

// for stress test : just one test case per execution but multiple executions using case_test.sh
int main(int argc, char const *argv[])
{
	(void) argc;

	int seed;

	seed = atoi(argv[1]);
	srand(seed);

	//number of test cases
	cout << 1 << endl;

	// code here to generate input

	return 0;
}

// for time test : just one execution but with many test cases in one execution
int main(int argc, char const *argv[])
{
	(void) argc;

	srand(time(0));
	int t = stoi(argv[1]);
	cout << t << endl;

	for (int i = 0; i < t; ++i)
	{
		// code here to generate input
	}
}
