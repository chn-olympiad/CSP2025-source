#include<bits/stdc++.h>
using namespace std;
const int Mod1=998244353;
int n;
int stick[5010];
long long ans=0;
inline void dfs(int start,int maxn,int he,int cnt)
{
	if((cnt>2)&&maxn*2<he) ans=(ans+1)%Mod1;
	for(int i=start;i<=n;i++)
	{
		dfs(i+1,max(maxn,stick[i]),he+stick[i],cnt+1);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>stick[i];
	}
	dfs(1,0,0,0);
	cout<<ans<<"\n";
	return 0; 
}
