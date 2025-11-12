#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct node{
	int u,v,w;
}a[1000000+5];

int kc[10+5][10000+5];

bool cmp(node aa,node bb)
{
	return aa.w<bb.w;
}
int fa[10000+5];
int ft(int p){
	if(fa[p]==p){
		return p;
	}
	fa[p]=ft(fa[p]);
	return fa[p];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",kc[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&kc[i][j]);
		}
	}
	sort(a+1,a+m+1,cmp);
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int fafi=ft(a[i].u),fase=ft(a[i].v);
		if(fafi!=fase){
			fa[fase]=fafi;
			cnt++;
			ans+=a[i].w;
			if(cnt>=n-1){
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
