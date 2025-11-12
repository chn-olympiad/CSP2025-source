#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int calc[505];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
long long ans=0;
int m,n;
string s;
int c[505];
int st[505];
bool vis[505];
void dfs(int step)
{
	if(step==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0'||cnt>=c[st[i]])cnt++;
		}
		if(n-cnt>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			st[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(vis,0,sizeof(vis));
	calc[0]=calc[1]=1;
	for(int i=2;i<=n;i++)calc[i]=(calc[i-1]*i)%mod;
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;i++)c[i]=read();
	dfs(1);
	cout<<ans;
	return 0;
}

