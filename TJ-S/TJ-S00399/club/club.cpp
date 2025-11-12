#include "bits/stdc++.h"

#define ll long long

using namespace std;

ll T, n, ans, cnta, cntb, cntc, p[100005];
struct stu
{
	ll v1, v2, v3, vm; 
}a[100005];

ll max2(ll x, ll y)
{
	if(x > y) return x;
	return y;
}

ll max3(ll x, ll y, ll z)
{
	return max2(max2(x, y), z);
}

int cmp(ll x, ll y)
{
	return x < y;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	while(T --)
	{
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));
		ans = 0, cnta = 0, cntb = 0, cntc = 0;
		
		cin >> n;
		ll m = n/2, l = 1;
		
		for(ll i = 1;i <= n;i ++)
		{
			cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
			
			if(a[i].v1 == max3(a[i].v1, a[i].v2, a[i].v3)) a[i].vm = 1, cnta ++, ans += a[i].v1;
			else if(a[i].v2 == max3(a[i].v1, a[i].v2, a[i].v3)) a[i].vm = 2, cntb ++, ans += a[i].v2;
			else a[i].vm = 3, cntc ++, ans += a[i].v3;
		}
		
		if(cnta > m)
		{
			for(ll i = 1;i <= n;i ++)
			{
				if(a[i].vm == 1) p[l ++] = a[i].v1 - max2(a[i].v2, a[i].v3);
			}
			sort(p+1,p+l,cmp);
			for(ll i = 1;i <= cnta-m;i ++) ans -= p[i];
		}
		else if(cntb > m)
		{
			for(ll i = 1;i <= n;i ++)
			{
				if(a[i].vm == 2) p[l ++] = a[i].v2 - max2(a[i].v1, a[i].v3);
			}
			sort(p+1,p+l,cmp);
			for(ll i = 1;i <= cntb-m;i ++) ans -= p[i];
		}
		else
		{
			for(ll i = 1;i <= n;i ++)
			{
				if(a[i].vm == 3) p[l ++] = a[i].v3 - max2(a[i].v2, a[i].v1);
			}
			sort(p+1,p+l,cmp);
			for(ll i = 1;i <= cntc-m;i ++) ans -= p[i];
		}
		
		
		cout << ans << endl;
	}
	
	return 0;	
}
