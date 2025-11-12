#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int MAXN = 1e3+10;


ll n,k,a[MAXN],ss[MAXN];
bool vis[MAXN][MAXN];


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(ll i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(ll l = 1;l<=n;l++)
	{
		for(ll i=1;i<=n - l + 1;i++)
		{
			ll j = i + l - 1;
			ll ans = a[i];
			for(ll q=i+1;q<=j;q++)
			{
				ans ^= a[q];
			}
			if(ans == k)
			{
				vis[i][j] = true;
			}
		}
	}
	ll maxx = 0;
	for(ll st = 1;st <= n;st++)
	{
		ll tans = 0;
		for(ll i = st;i<=n;i++)
		{
			for(ll j=i;j<=n;j++)
			{
				if(vis[i][j] == true)
				{
					//cout << i << ' ' << j << '\n';
					tans ++;
					i = j + 1;
					continue;
				}
			}
		}
		maxx = max(maxx,tans);
	}
	//cout << vis[1][2] << '\n';
	cout << maxx;
	return 0;
}
