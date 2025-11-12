#include<bits/stdc++.h>
//#include<windows.h>
#define LL long long
using namespace std;
int m,n,t1,t2,k,t3,ans=INT_MAX,sum;
int a[1010][1010];
void dfs(int x)
{
	if(x>=n)
	{
		ans=min(ans,sum);
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[x][i]!=0)
		{
			sum+=a[x][i];
			dfs(i);
			sum-=a[x][i];
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		cin>>t1>>t2>>t3;
		a[t1][t2]=t3,a[t2][t1]=t3;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
