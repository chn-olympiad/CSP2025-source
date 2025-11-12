#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1010];
bool cmp(int a,int b)
{
	return a>b;
}
ll n,m,s;
void dfs(ll x,ll y,ll k,ll p)
{
	if(a[p]==s)
	{
		cout<<y<<" "<<x;
		return;
	}
	if(x+k>n||x+k<1)
	{
		dfs(x,y+1,-k,p+1);
	}
	else
	{
		dfs(x+k,y,k,p+1);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1,1);
	return 0;
}