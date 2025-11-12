#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, c[1005], m, ans, p[1005];
char s[1005];
const int M = 998244353;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s+1;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		sum += s[i]-'0';
		p[i] = i;
	}
	if(sum < m)
	{
		cout << 0;
		return 0;
	}
	do
	{
		int cnt = 0; 
		for(int i = 1; i <= n; i++)
			if(cnt >= c[p[i]] || s[i] == '0') 
				cnt++;
		if(n-cnt >= m) ans++; 
	} while(next_permutation(p+1, p+n+1));
	cout << ans%M;
	return 0;
}
