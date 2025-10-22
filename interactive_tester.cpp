#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

// #define endl "\n";

#define debug(x) cerr << #x << " = " << x << "\n"

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

void	parse_time(string t, int & h, int & m, int & s)
{
	vector<string>	v = split(t, ":");
	h = stoi(v[0]);
	m = stoi(v[1]);
	s = stoi(v[2]);
}

// use cin and cout

void solve()
{
	char *solution_file = "solution";
	int realOUT = dup(1);
	
	int p1[2];
	int p2[2];
	
	pipe(p1);
	pipe(p2);
	
	int proc = fork();
	if (proc == 0)
	{
		dup2(p1[1], STDOUT_FILENO);
		dup2(p2[0], STDIN_FILENO);
		close(p1[1]);
		close(p2[0]);
		
		execl(solution_file, solution_file, NULL);
		exit(1);
	}
	
	dup2(p1[0], STDIN_FILENO);
	dup2(p2[1], STDOUT_FILENO);
	
	close(p1[1]);
	close(p2[0]);
	

	/*
	
		CODE HERE
	
	*/

	close(p1[0]);
	close(p2[1]);
	dup2(realOUT, STDOUT_FILENO);

}

int main(void)
{
	// ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	// cin >> t;
	for (int o = 0; o < t; ++o)
	{
		solve();
	}
	return 0;
}
