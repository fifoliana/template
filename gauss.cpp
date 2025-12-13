#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// used to solve sytem of linear equation
// vector a is the augmented matrix, return : 0 if no solution, 1 if unique solution and 2 if INF solutions, if not 0 the vector ans is filled by a default solution
// see : https://cp-algorithms.com/linear_algebra/linear-system-gauss.html


const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

// fast and default solutions, solutions can be decimals
int gauss (vector < vector<double> > a, vector<double> & ans, int level) 
{
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;

	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col)
	{
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;

		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}

	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}

	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}

const int MAX_TRY = 256;
// minimal sum of the solutions and integer solutions (slower)
int min_int_gauss (vector < vector<double> > a, vector<double> & ans, int level) 
{
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;

	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col)
	{
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;

		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}

	///////////////////

	for (int i = 0; i < m; ++i)
	{
		if (where[i] == -1)
		{
			ll mi = (ll)INT_MAX;
			for (int k = 0; k <= MAX_TRY; ++k)
			{
				vector <vector<double>> a_cpy = a;
				for (int j = 0; j < (int) a.size(); ++j)
				{
					a_cpy[j][a[j].size() - 1] -= a_cpy[j][i] * (double)k;
					a_cpy[j].erase(a_cpy[j].begin() + i);
				}
				vector<double> ans2;
				if (gauss(a_cpy, ans2, level + 1) && ans2.size() > 0)
				{
					ans2.insert(ans2.begin() + i, (double) k);
				}
				ll s = 0;
				bool valid = (ans2.size() > 0) ? true : false;
				for (int j = 0; j < (int) ans2.size(); ++j)
				{
					if (round(ans2[j]) < 0 || abs(round(ans2[j]) - ans2[j]) > EPS)
					{
						valid = false;
						break;
					}
					s += (ll) round(ans2[j]);
				}
				if (valid)
				{
					if (mi >= s)
					{
						mi = s;
						ans = ans2;
					}
				}
			}
			return 1;
		}
	}

	///////////////////

	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}

	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}