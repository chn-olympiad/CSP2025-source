#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n;
unsigned long long ans=0;
long long a[50005];
void dfs(int step,int all,int last,int sum)
{
	if(step==all)
	{
		int p=lower_bound(a+1,a+n+1,sum)-a;
		if(a[p]>=sum || p>=n) p--;
		ans=(ans+(p-last)%Mod)%Mod;
		return ;
	}
	for(int i=last+1;i<=n;i++)
	{
		dfs(step+1,all,i,sum+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) dfs(1,3,0,0);
	cout<<ans;
	return 0;
}
