#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int MAXN = 2e5+10;


bool cmp(ll x,ll y)
{
	return x > y;
}

ll n,m,a[MAXN],sei[MAXN],xfg = -1;


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i=1;i<=n * m;i++)
	{
		cin >> a[i];
	}
	ll mepo = a[1],x = 1,y = 1;
	sort(a+1,a+1+n * m,cmp);
	for(ll i=1;i<=n * m;i++)
	{
		if(a[i] == mepo)
		{
			cout << y << ' ' << x;
			return 0;
		}
		if(xfg == -1 && x < n)
		{
			x++;
		}
		else if(xfg == 1 && x > 1)
		{
			x--;
		}
		else
		{
			y++;
			xfg = -xfg;
		}
	}
	return 0;
}
