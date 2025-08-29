#include <bits/stdc++.h>

using namespace std;

// create a vector of size 5
vector<int> v(5);
// create a vector of size 5 with default value 0
vector<int> v(5, 0); // 

bool comp(int a, int b)
{
	return (a < b); // increasing
	// return (a > b); // decreasing
}

void sorting()
{
	sort(v.begin(), v.end(), comp);
}