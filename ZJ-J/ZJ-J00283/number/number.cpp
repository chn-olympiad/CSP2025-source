#include <bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for (auto i : s)
		if (i >= '0' && i <= '9')
			a[i - '0']++;
	for (int i = 9; i >= 0; i--)
		while (a[i]--)
			cout << i;
	return 0;
}
