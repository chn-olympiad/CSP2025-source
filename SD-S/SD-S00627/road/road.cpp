#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,t,fa[200001],siz[200001],w[20001];
struct edge{
	signed u,v;
	int w;
} e[12000001];
bool cmp(edge l,edge r){
	return l.w<r.w;
}
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
int cnt=1,c;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&t);
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1;i<=n;i++)	siz[i]=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[cnt].u,&e[cnt].v,&e[cnt].w);
		cnt++;
	}
	for(int i=1;i<=t;i++){
		scanf("%lld",&c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w[j]);
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				e[cnt].u=j;
				e[cnt].v=k;
				e[cnt].w=w[j]+w[k];
				cnt++;
			}
		}
	}
	sort(e+1,e+cnt,cmp);
	c=0;
	for(int i=1;i<cnt;i++){
		int lu=find(e[i].u);
		int lv=find(e[i].v);
		if(lu!=lv){
			c+=e[i].w;
			if(siz[lu]<siz[lv]){
				fa[lu]=lv;
				siz[lv]+=siz[lu];
			}
			else{
				fa[lv]=lu;
				siz[lu]+=siz[lv];
			} 
		}
	}
	printf("%lld",c);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
please remember to
*/
