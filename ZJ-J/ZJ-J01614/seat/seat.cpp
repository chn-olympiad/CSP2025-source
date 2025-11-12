#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	xr=a[1];
	sort(a+1,a+1+n*m);
	c=r=1;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==xr)
		{
			cout<<c<<' '<<r;
			return 0;
		}
		if(c%2==1)
		{
			if(r!=n)r++;
			else c++;
		}
		else
		{
			if(r!=1)r--;
			else c++;
		}
	}
	return 0;
}
//designant.
//ÎÒÒªÉè¼ÆÂìÒÏ£¡
//ÂìÂìÂìÂì ÂìÂìÂìÂìÂì ÒÏÒÏÒÏÒÏ ÒÏÒÏÒÏÒÏÒÏ
