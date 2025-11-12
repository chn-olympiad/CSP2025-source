#include<bits/stdc++.h>
using namespace std;
int a[100005][3],m[3],n,ma=-2e9;
void dfs(int x,int s)
{
	if(x==n+1)
	{
		ma=max(ma,s);
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(m[0]<n/2)
			m[0]++,dfs(x+1,s+a[x][0]),m[0]--;
		if(m[1]<n/2)
			m[1]++,dfs(x+1,s+a[x][1]),m[1]--;
		if(m[2]<n/2)
			m[2]++,dfs(x+1,s+a[x][2]),m[2]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ma=-2e9;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		memset(m,0,sizeof(m));
		dfs(1,0);
		printf("%d\n",ma);
	}
	return 0;
}

