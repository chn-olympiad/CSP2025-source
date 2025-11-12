#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;
const int N = 10105,M = 998244353;
int n,m,p[N],ans,c[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> s;
	s = ' '+s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++)
		p[i] = i;
	if (n <= 18)
	{
		do
		{
			int sum = 0;
			for (int i = 1; i <= n; i++)
			{
				if (i-1-sum >= c[p[i]]) continue;
				if (s[i] == '1') sum++;
			}
			if (sum >= m)
			{
				ans++;
			//	for (int i = 1; i <= n; i++) cout << p[i] << ' ';
			//	cout << '\n';
			}
		} while (next_permutation(p+1,p+n+1));
		cout << ans;
		return 0;
	}
	ll ans = 1,cnt = 0;
	for (int i = 1; i <= n; i++)
		ans = ans*i%M;
	cout << ans;
	return 0;
}
