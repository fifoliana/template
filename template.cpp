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

bool isnotspace(int c)
{
	return (!isspace(c));
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), isnotspace)
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), isnotspace).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str, string del = " ") {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(del, start)) != string::npos) {

		string res = str.substr(start, end - start);
		// if (res != "")
        tokens.push_back(res);

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

string stoupper(string const & s)
{
	string u = s;

	for (char & c : u)
		c = toupper(c);
	return (u);
}

string stolower(string const & s)
{
	string u = s;

	for (char & c : u)
		c = tolower(c);
	return (u);
}

void solve()
{
	
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;

	cin >> t;
	for (int o = 0; o < t; ++o)
	{
		solve();
	}
	return 0;
}
