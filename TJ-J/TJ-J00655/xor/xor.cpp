#include "bits/stdc++.h"

#define ll long long 

using namespace std;

ll n, k, a[500005], ans; 

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> k;
	for(ll i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	
	if(k == 0)
	{
		ll cnt = 0;
		for(ll i = 1;i <= n;i ++)
		{
			if(a[i] == 0) ans ++, ans += cnt/2, cnt = 0;
			if(a[i] == 1) cnt ++;
		}
	}
	if(k == 1)
	{
		for(ll i = 1;i <= n;i ++)
		{
			if(a[i] == 1) ans ++;
		}
	}
	
		
	cout << ans;
		
	return 0;
}
