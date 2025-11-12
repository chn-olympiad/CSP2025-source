#include<bits/stdc++.h>
using namespace std;

const int M=510,mod=998244353;
int n,m,s[M],ans;
int c[M];
int p[M];
bool sg[M],fl;

void work()
{
	int tot=0,fail=0;
//	fl=0;
	for(int i=1;i<=n;i++)
	{
		if(fail>=c[p[i]]) fail++;
		else
		{
			if(s[i]==0) fail++;
			else tot++;
		}
	}
	
	if(tot>=m) ans++;
	
	return;
}

void dfs(int u)
{
	if(u==n+1)
	{
		work();
		return;
	}
	for(int i=1;i<=n;i++)
		if(!sg[i])
		{
			p[u]=i;
			sg[i]=1;
			dfs(u+1);
			sg[i]=0;
		}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch=='1') s[i]=1;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	
	dfs(1);
	
	cout<<ans;
	
	return 0;
}