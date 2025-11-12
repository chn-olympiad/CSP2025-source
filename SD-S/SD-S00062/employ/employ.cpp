#include <bits/stdc++.h>
using namespace std;

const int N=510, P=998244353;

int fac[N];

void Init()
{
	fac[0] = 1;
	for(int i=1; i<N; i++)
		fac[i] = fac[i-1] * i % P;
}

int n, m, ans;
int s[N], c[N], a[N];
bool fA=1;

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Init();
	cin >> n >> m;
	char ch;
	for(int i=1; i<=n; i++)
	{
		cin >> ch; s[i] = (ch=='0') ? 0 : 1;
		fA &= (s[i]==1);
	}
	for(int i=1; i<=n; i++)
		cin >> c[i];
	if(fA) return cout << fac[n] << '\n', 0;
	for(int i=1; i<=n; i++)
		a[i] = i;
	for(int i=1; i<=fac[n]; i++)
	{
		int cnt = 0, res = 0;
		for(int j=1; j<=n; j++)
		{
			if(s[j]==0 || cnt>=c[a[j]]) cnt ++;
			else res ++;
		}
		if(res >= m) ans ++;
		next_permutation(a+1, a+n+1);
	}
	cout << ans;
    return 0;
}

