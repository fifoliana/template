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

int main(int argc, char const *argv[])
{
	(void) argc;

	int t;

	t = atoi(argv[1]);
	return 0;
}
