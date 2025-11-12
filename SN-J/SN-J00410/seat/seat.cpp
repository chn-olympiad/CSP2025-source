#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll n, m, fd, s, x, y;
ll a[105];
bool cmp(ll a, ll b)
{
	return a>b;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	fd=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==fd) s=i;
	}
	x=((s-(s%n))/n)+(s%n==0?0:1);
	y=s%n;
	if (y==0) y=n;
	if (x%2==0) y=n-y+1;
	cout << x << " " << y;
} 
