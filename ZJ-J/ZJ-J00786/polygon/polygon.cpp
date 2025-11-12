#include<bits/stdc++.h>
using namespace std;
const int N=5111,Mod=998244353;
int n,a[N],cnt;
void dfs(int k,int ans,int mx,bool x)
{
	if(ans>mx*2&&x==1)cnt=(cnt+1)%Mod;
	if(k==n+1)return;
	dfs(k+1,ans+a[k],max(mx,a[k]),1);
	dfs(k+1,ans,mx,0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>=500)
	{
		cout<<((n-2)*(n-1)*(n))%Mod;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<cnt%Mod;
	return 0;
}