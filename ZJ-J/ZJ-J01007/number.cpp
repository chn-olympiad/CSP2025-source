#include <bits/stdc++.h>
using namespace std;

int t[15];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s; cin >> s;
	for (int i = 0; i != int(s.size()); i++)
		if (s[i] <= '9' && s[i] >= '0') t[s[i] - '0']++;
	string s1 = "";
	for (int i = 9; i >= 0; i--)
		while (t[i]--) s1 += char(i + '0');
	if (s1[0] == '0') s1 = "0";
	cout << s1 << endl;
	return 0;
}
