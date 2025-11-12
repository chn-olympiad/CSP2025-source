#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
int n,cnt;
int a[N];
bool vis[N]; 
void dfs(int x)
{
	if(x==n+1)
	{
		int sum=0,maxn=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) sum+=a[i],maxn=max(maxn,a[i]),num++;
		}
		if(num>=3&&sum>maxn*2) cnt++,cnt%=MOD;
		return;
	}
	dfs(x+1);
	vis[x]=true;
	dfs(x+1);
	vis[x]=false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
