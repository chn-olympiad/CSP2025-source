#include<bits/stdc++.h>
using namespace std;
int t,n,v[210][5];
long long Max;
void dfs(int k,int a,int b,int c,long long S)
{
	if(a>n/2||b>n/2||c>n/2) return;
	if(k>n)
	{
		Max=max(Max,S);
		return;
	}
	dfs(k+1,a+1,b,c,S+v[k][1]);
	dfs(k+1,a,b+1,c,S+v[k][2]);
	dfs(k+1,a,b,c+1,S+v[k][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		Max=0;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=3;j++) scanf("%d",&v[i][j]);
		dfs(1,0,0,0,0);
		printf("%lld\n",Max);
	}
	return 0;
}