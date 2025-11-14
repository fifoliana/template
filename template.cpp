#include <bits/stdc++.h>

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;

typedef long long ll;

#define endl "\n"

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}

	size_t operator()(pair<uint64_t,uint64_t> x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
	}
};

// unordered_map<int, pair<int,int>, custom_hash>

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
