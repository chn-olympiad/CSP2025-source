#include<bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
int a[100005];
int b[6005][6005];
int n;
int p;
int c[100005],vis[100005];
int cnt=0;
void print()
{
	int sum=0;
	int maxn=0;
	for(int i=1;i<=p;i++)
	{
		sum+=a[c[i]];
		maxn=max(maxn,a[c[i]]);
	}
	if(sum-maxn>maxn)
	{
		cnt++;
		cnt%=MOD;
	}
}
void dfs(int x,int last)
{
	if(x>p)
	{
		print();
		return;
	}
	if(last+p-x>n)return;
	for(int i=last+1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			c[x]=i;
			dfs(x+1,i);
			vis[i]=0;
		}
	}
}
void solve1()
{
	int i,j;
	for(i=1;i<=5005;i++)
	{
		b[i][1]=1;
	}
	for(i=1;i<=5005;i++)
	{
		for(j=2;j<=i;j++)
		{
			b[i][j]=b[i-1][j-1]+b[i-1][j];
			b[i][j]%=MOD;
		}
	}
	int sum=0;
	for(i=3;i<=n;i++)
	{
		sum+=b[n+1][i+1];
		sum%=MOD;
	}
	cout<<sum;
}
void solve2()
{
	sort(a+1,a+1+n);
	for(p=3;p<=n;p++)
	{
		dfs(1,0);
	}
	cout<<cnt;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int all1=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			all1=0;
		}
	}
	if(all1==1)
	{
		solve1();
	}
	else
	{
		solve2();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

