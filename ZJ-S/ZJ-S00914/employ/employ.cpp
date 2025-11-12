#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
char a[N];
int c[N],p[N];
int n,m,ans;
void dfs(int x,int it,int s,int l,int r,int res)
{
	if(x==n+1)
	{
		if(s>n-m)
		{
			ans=(ans+res)%mod;
		}
		return;
	}
	if(a[x]=='0')
	{
		dfs(x+1,it,s+1,l,r-1,res*(r-it));
	}
	else
	{
		dfs(x+1,it,s,l,r,res);
		while(c[it]<=s)
		{
			it++;
		}
		it--;
		if(it>=l)
		{
			dfs(x+1,it,s+1,l+1,r,res*(it-l+1));
		}
		
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10)
	{
		for(int i=1;i<=n;i++)
		{
			p[i]=i;
		}
		ans=0;
		do
		{
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]=='1'&&cnt<c[p[i]])
				{
					sum++;
				}
				else
				{
					cnt++;
				}
			}
			ans+=(sum>=m);
		}while(next_permutation(p+1,p+1+n));
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='1'||c[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='1')
			{
				p[++cnt]=i;
			}
		}
		int res=1;
		for(int i=1;i<=cnt;i++)
		{
			int s=0;
			for(int j=1;j<=n;j++)
			{
				if(c[j]<p[i])
				{
					s++;
				}
			}
			res=res*(s-i+1)%mod;
		}
		for(int i=1;i<=n-cnt;i++)
		{
			res=res*i%mod;
		}
		cout<<(ans-res+mod)%mod;
		return 0;
	}
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		sum=sum*i%mod;
	}
	sort(c+1,c+1+n);
	dfs(1,0,0,1,n,1);
	cout<<(sum-ans+mod)%mod<<endl;
	return 0;
}

