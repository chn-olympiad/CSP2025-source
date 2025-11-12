#include<bits/stdc++.h>
#define int long long
using namespace std;
#define Exit(str,val) {cout<<str<<endl;return val;}
#define Ms(shuzu,val) memset(shuzu,val,sizeof(shuzu))
const int N=505;
int a[N],s[N],vis[N];
int n,m,ans=0;string str;
void dfs(int dep)
{
	if(dep==n+1)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i-1]=='0') tot++;
			else if(a[s[i]]<=tot) tot++;
		}
		if(n-tot>=m)
		{
//			for(int i=1;i<=n;i++) cout<<s[i]<<" ";
//			cout<<tot<<endl;
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1,s[dep]=i;
			dfs(dep+1);
			vis[i]=0,s[dep]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;cin>>str;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);cout<<ans%998244353<<endl;
	return 0;
}
//bye,OI.Hello,MO&whk.
//i am ZJ-J00983/ZJ-S01038 czy.
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/