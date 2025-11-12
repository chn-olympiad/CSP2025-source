#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t,a[100005][4],b[100005],da,x[100005],h,aa,bb,cc;
bool tsa=1;
bool cmp(ll x,ll y){return x>y;}
void sol_a()
{
	for(ll i=1;i<=n;i++) b[i]=a[i][1];
	sort(b+1,b+n+1,cmp);
	for(ll i=1;i<=n/2;i++) da+=b[i];
	cout<<da<<endl;
}
void dfs(ll jss,ll bh)
{
	if(bh==1) aa++;
	if(bh==2) bb++;
	if(bh==3) cc++;
	if(jss==n+1)
	{
		h=0;
		for(ll i=1;i<=n;i++)
		{
			h+=a[i][x[i]];
		}
		if(h>da)
		{
			da=h;
		}
		if(bh==1) aa--;
		if(bh==2) bb--;
		if(bh==3) cc--;
		return;
	}
	x[jss]=bh;
	if(aa+1<=n/2||jss==n) dfs(jss+1,1);
	if(bb+1<=n/2||jss==n) dfs(jss+1,2);
	if(cc+1<=n/2||jss==n) dfs(jss+1,3);
	if(bh==1) aa--;
	if(bh==2) bb--;
	if(bh==3) cc--;
}
void sol_10()
{
	da=-1999999999999999999;
	dfs(1,1);
	dfs(1,2);
	dfs(1,3);
	cout<<da<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		da=0,tsa=1;
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][2]!=0||a[i][3]!=0) tsa=0;
			}
		}
		if(tsa) sol_a();
		else sol_10();
	}
	return 0;
}
