#include<bits/stdc++.h>
#define MOD 998244353 
using namespace std;
int n,a[100001],maxn,cnt;
void dfs(int pos,int maxn,int num)
{
	if(pos==n+1)
	{
		if(num>2*maxn)cnt=(cnt+1)%MOD;
		return;
	}
	dfs(pos+1,max(maxn,a[pos]),num+a[pos]);
	dfs(pos+1,maxn,num); 
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
	if(maxn==1)
	{
		int now=(n*(n-1)*(n-2))%MOD;
		int ans=now;
		for(int i=n-3;i>=1;i--)
		{
			now=(now*i)%MOD;
			ans=(ans+now)%MOD;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}
//This is my second time doing CSP-J2
//But last year I hace J1S2.
//I can't join S this year!!!!!!
//My point is 60(or 61),but you need to have 60.5(or 61.5)
//I hate ¢¢£!!!
//But this tern I hope I can have 364 points.
//But!!!!!!!!!!!!!!!!Why can't I join CSP-S2!!!!!!!!!!!!!!!!
//CCF!I f(x) your home!!!!!!!!!
//All in all,RP=RP_MAX.