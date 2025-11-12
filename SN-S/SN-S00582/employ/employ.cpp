#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
char str[505];
int c[505];
bool vis[505];
int res=0;
void dfs(int pos,int ans,int fail)
{
	if(ans>=m)
	{
		res++;
		return;	
	}
	if(pos>n) return;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(c[i]>fail&&str[pos]=='1') dfs(pos+1,ans+1,fail);
			else dfs(pos+1,ans,fail+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(str+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<res<<'\n';
	return 0; 
}
