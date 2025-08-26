#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
void	print(T cont)
{
	bool	w = false;
	for (typename T::iterator it = cont.begin(); it != cont.end(); ++it)
	{
		if (w)
			cout << " ";
		else
			w = true;
		cout << *it;
	}
	cout << endl;
}

void solve()
{
	
}


int main(void)
{
	int t;

	cin >> t;
	for (int o = 0; o < t; ++o)
	{
		solve();	
	}
	return 0;
}
