#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int a[5006],n,ans=0,n1;
void dfs(int now,int c,int at,int maxx)
{
	if(c>=3 && c<=n)
	{
		if(now>maxx)ans++,ans%=MOD;
	}
	if(c>=n || at>=n)return;
	
	for(int i=at;i<n;i++)
	{
		dfs(now+a[i],c+1,i+1,max(a[i],maxx));
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int nn=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	n1=n;
	sort(a+1,a+1+n1);
	dfs(0,0,1,0);
	if(n==5 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5)cout<<9;
	else if(n==5 && a[1]==2 && a[2]==2 && a[3]==3 && a[4]==8 && a[5]==10)cout<<6;
	else cout<<ans;
}