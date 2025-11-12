#include<bits/stdc++.h>
using namespace std;
const int N=10020;
const int M=2000010;
int a[20][N];
struct node{
	int u,v,w;
}e1[M],e[N],ee[N*20];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e1[i].u,&e1[i].v,&e1[i].w);
	}
	sort(e1+1,e1+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	long long ans=0;
	int m1=0;
	for(int i=1;i<=m;i++){
		int u=e1[i].u,v=e1[i].v,w=e1[i].w;
		int ta=find(u),tb=find(v);
		if(ta!=tb){
			ans+=w;
			fa[ta]=tb;
			e[++m1]={u,v,w};
		}
	}
//	printf("%lld\n",ans);
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int S=1;S<(1<<k);S++){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m1;i++){
			ee[i]=e[i];
		}
		int m2=m1;
		long long sum=0;
		for(int i=0;i<k;i++)if((1<<i)&S){
			sum+=a[i][0];
			for(int j=1;j<=n;j++){
				ee[++m2]={n+i+1,j,a[i][j]};
			}
			if(sum>=ans){
				break;
			}
		}
		if(sum<ans){
			sort(ee+1,ee+m2+1,cmp);
			for(int i=1;i<=m2;i++){
				int u=ee[i].u,v=ee[i].v,w=ee[i].w;
				int tu=find(u),tv=find(v);
				if(tu!=tv){
					sum+=w;
					fa[tu]=tv;
					if(sum>ans){
						break;
					}
				}
			}
		}
//		printf("%d %lld\n",S,sum);
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
