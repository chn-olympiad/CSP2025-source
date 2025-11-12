#include<bits/stdc++.h>
using namespace std;
long long n,m,a[550],c[550],q,ans,c2[550];
char cc[550];
bool l[550],f,used[550];

void dfs(int p,int led,int s)
{
	/*if(led>=m)
	{
		int ls=1;
		for(int i=2;i<=s;i++)
		{
			ls*=i;
			ls%=998244353;
			ans+=ls;
			ans%=998244353;
			return;
		}
	}
	*/
	if(s==0)
	{
		if(led>=m)
		{
			ans++;
		}
		return;
	}
	if(c2[p]<c[p])
	{
		used[p]=1;
		for(int i=1;i<=n;i++)
		{
			if(!used[i])
			{
				dfs(i,led+1,s-1);
			}
		}
		used[p]=0;
	}
	else
	{
		used[p]=1;
		for(int i=1;i<=n;i++)
		{
			if(!used[i])
			{
				dfs(i,led,s-1);
			}
		}
		used[p]=0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cc[i];
		if(cc[i]=='1')
		{
			l[i]=1;
			c2[i]=c2[i-1];
		}
		else
		{
			c2[i]=c2[i-1]+1;
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=1)
		{
			f=1;
		}
	}
	if(!f)
	{
		for(int i=1;i<=n;i++)
		{
			if(l[i]==0)
			{
				q=i-1;
				break;
			}
		}
		if(q<m)
		{
			ans=0;
		}
		else
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=998244353;
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			dfs(i,0,n-1);
		}
		cout<<ans;
	}
	

	
	return 0;
}
