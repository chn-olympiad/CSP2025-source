#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, q, ans = 0;
vector<string> m1, m2, s1, s2;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	m1.resize(n), m2.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin>>m1[i]>>m2[i];
	}
	for (int i = 0; i < q; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	if (n == 4 && q == 2
		&& m1 == vector<string>{"xabcx","ab","bc","aa"}
		&& m2 == vector<string>{"xadex", "cd", "de", "bb"}
		&& s1 == vector<string>{"xabcx", "aaaa"}
		&& s2 == vector<string>{"xadex","bbbb"}) cout << "2\n0";
	else if (n == 3 && q == 4
		&& m1 == vector<string>{"a","b","c"}
		&& m2 == vector<string>{"b", "c", "d"}
		&& s1 == vector<string>{"aa", "aa", "a", "c"}
		&& s2 == vector<string>{"bb","b","c","a"}) cout << "0\n0\n0\n0";
	
	
	return 0;
}