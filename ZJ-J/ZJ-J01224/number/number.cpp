// rp++
// orz cyh sto

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n, a[20];
char s[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> (s + 1);
	n = strlen(s + 1);
	for (int i = 1;i <= n;i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[s[i]-'0']++;
	for (int i = 9;i >= 0;i--)
		while (a[i]--)
			cout << i;

	return 0;
}