#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,m,a[10010];
long long ans;
string s;
bool vis[1010];
void dfs(int x,int cnt)
{
	if(x==n)
	{
		if(cnt>=m) ans=(ans+1)%M;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(a[i]<=x-cnt||s[x]=='0') dfs(x+1,cnt);
			else dfs(x+1,cnt+1);
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("emoploy.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0,0);
	printf("%lld",ans%M);
	return 0;
}
