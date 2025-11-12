#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;
const int mod = 998244353;

bool ps[maxn];
int c[maxn];

void solve1(int n, int m)
{
	long long ans = 1;
	for(int i = 1; i <= n; i++)
		(ans *= i) %= mod;
	cout << ans << endl;
}

void solve2(int n, int m)
{
	int ans = 0;
	int a[20];
	for(int i = 1; i <= n; i++)
		a[i] = i;
	do
	{
		int g = 0, s = 0;
		for(int i = 1; i <= n; i++)
			if(g >= c[a[i]])
				g++;
			else
				if(ps[i]) s++;
				else g++;
		ans += s >= m;
	}while(next_permutation(a + 1, a + n + 1));
	cout << ans << endl;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	bool A = true;
	for(int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		A &= ps[i] = c == '1';
		cnt += ps[i];
	}
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	if(n == m)
	{
		if(A)
			solve1(n, m);
		else
			cout << 0 << endl;
	}
	else if(A)
		solve1(n, m);
	else if(n <= 10)
		solve2(n, m);
	else if(m > cnt)
		cout << 0 << endl;
	return 0;
}

/*

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
