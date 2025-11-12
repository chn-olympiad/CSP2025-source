#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
int n,m,s[505],sum=0,cnt,c[505],res=0,ch[505],vis[505];
void dfs(int x)
{
	if(x>n)
	{
		sum=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(sum>=c[ch[i]]) {sum++;continue;}
			if(s[i]==1) cnt++;
			else sum++;
		}
		if(cnt>=m)
		{
			res++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			ch[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char a;cin>>a;
		s[i]=a-'0';
	}
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	if(n<=18) {dfs(1);cout<<res;}
	else
	{
		for(int i=1;i<=n;i++) sum+=s[i];
		if(sum==n)
		{
			res=1;
			for(int i=1;i<=n;i++)
				res=res*i%p;
			cout<<res;
		}
	}
	return 0;
}
