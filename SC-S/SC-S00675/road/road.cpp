#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int a[1000005]={};
int k1[11],k2[11][10005]={};

bool cmp(int a,int b)
{
	return a<b;
}

signed int main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		a[i]=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&k1[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&k2[i][j]);
	}
	sort(a+1,a+m+1,cmp);
	int ans=0;
	for(int i=1;i<n;i++)
		ans+=a[i];
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 