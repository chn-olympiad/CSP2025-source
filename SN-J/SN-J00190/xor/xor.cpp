#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 5e5 + 10;
ll n, k, a[N], sum[N], cnt, f[N], ans;
pair<ll, ll> t[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w", stdout);
	cin >> n >> k;
	for(ll i = 1; i <= n; i ++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(ll i = 1; i <= n; i ++)
	{
		for(ll j = 1; j <= i; j ++)
		{
			ll now = sum[i] ^ sum[j - 1];
			if(now == k)
			{
				t[++ cnt].first = j;
				t[cnt].second = i;
			}
		}
	}
	sort(t + 1, t + cnt + 1);
	for(ll i = 1; i <= cnt; i ++)
	{
		for(ll j = 0; j < t[i].first; j ++)
		{
			f[t[i].second] = max(f[j] + 1, f[t[i].second]);
		}
	}
	for(ll i = 1; i <= n; i ++) ans = max(ans, f[i]);
	cout << ans << endl;
	return 0;
}
