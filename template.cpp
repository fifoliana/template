#include <bits/stdc++.h>

#ifdef LOCAL
# include "template/debug.hpp"
#else
# define debug(...)
# define debugArr(...)
#endif

using namespace std;

typedef long long ll;
#define endl "\n"

template <typename T>
void	print(T cont, ostream & os)
{
	bool	w = false;
	for (typename T::iterator it = cont.begin(); it != cont.end(); ++it)
	{
		if (w)
			os << " ";
		else
			w = true;
		os << *it;
	}
	os << endl;
}

ll pow(ll a, ll b)
{
	return ((ll) round(std::pow(a, b)));
}

ll sqrt(ll a)
{
	ll res = sqrtl(a);

	while (res * res < a) ++res;
	while (res * res > a) --res;

	return (res);
}

void solve()
{
}

int main(void)
{
	bool solved = false; 
	(void) solved;
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;

	t = 1;
	cin >> t;
	for (int o = 0; o < t; ++o)
	{
		solve();
	}
	return 0;
}
