#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[11111],vis[11111],s=0,m=0,mxs=0;
long long ans;
void dfs(int x)
{
	if(x>n) return;
	if(m>=3&&s>2*mxs&&vis[x]==1)
	{
		ans++;
		ans%=N;
	}
	s+=a[x+1];
	int xx=mxs;
	mxs=max(xx,a[x+1]);
	m++;
	vis[x+1]=1;
	dfs(x+1);
	s-=a[x+1];
	m--;
	mxs=xx;
	vis[x+1]=0;
	dfs(x+1);
	return;
}
int main()
{
	freopen(polygon.in,"r",stdin);
	freopen(polygon.out,"w",stdout);
	int xx;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1) xx=0;
	}
	if(xx==0) dfs(0);
	else
	{
		for(int i=3;i<=n;i++)
		{
			int q=1,p=1;
			for(int j=2;j<=i;j++)
			{
				q*=j;
				q%=N;
			}
			for(int j=n;j>n-i;j--)
			{
				p*=j;
				p%=N;
			}
			ans=(p%N)/(q%N);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
