#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500;
const int MOD = 998244353;
int S[N + 9];
int C[N + 9];
int P[N + 9];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool f = true;
	for (int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		S[i] = ch - '0';
		f &= S[i];
	}
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 1; i <= n; i++) P[i] = i;
	if (f)
	{
		int res = 1;
		for (int i = 1; i <= n; i++) res = 1ll * res * i % MOD;
		int sum = 0;
		for (int i = 1; i <= n; i++) sum += (C[i] == 0);
		cout << (n - sum >= m ? res : 0);
	}
	else
	{
		int rej = 0;
		int ans = 0;
		do
		{
			rej = 0;
			for (int i = 1; i <= n; i++)
				if (!S[i] || rej >= C[P[i]]) rej++;
			ans += (n - rej >= m);
		} while (next_permutation(P + 1, P + n + 1));
		cout << ans;
	}
	return 0;
}
