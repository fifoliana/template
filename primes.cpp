#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl "\n";

void generate_primes(void)
{
	vector<bool> p(200005, true);

	p[0] = false;
	p[1] = false;
	for (int i = 2; i * i <= 200005; ++i)
	{
		if (p[i])
		{
			for (int j = i * i; j < 200005; j += i)
			{
				p[j] = false;
			}
		}
	}

	vector<ll> primes;

	primes.push_back(2);

	for (int i = 3; i < 200005; i+=2)
	{
		if (p[i])
		{
			primes.push_back(i);
		}
	}
}

