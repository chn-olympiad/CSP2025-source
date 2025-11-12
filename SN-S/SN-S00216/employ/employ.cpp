#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int a[505],b[505],f[505];
int n,m,flg=1,ans=0;
void dfs(int x,int sum,int num)
{
	if(n-x+1<m-sum) return;
	if(x>n)
	{
		if(sum>=m) ans=ans+1%p;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			if(a[i]==0 or num>=b[i])
			{
				dfs(x+1,sum,num+1);
			}
			else
			{
				dfs(x+1,sum+1,num);
			}
			f[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char t;
		cin>>t;
		a[i]=t-'0';
		if(a[i]==0) flg=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(flg==1)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%p;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 

/*
10 5
2 1101111011
3 6 0 4 2 1 2 5 4 3 3
*/
