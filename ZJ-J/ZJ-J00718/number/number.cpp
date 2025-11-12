#include <bits/stdc++.h>
using namespace std;
string s, s1;
bool cmp(char l, char r)
{
	return l > r;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for (size_t i = 0; i < s.size(); ++i)
		if ('0' <= s[i] && s[i] <= '9')
			s1.push_back(s[i]);
	sort(s1.begin(), s1.end(), cmp);
	cout << s1 << '\n';
	return 0;
}
