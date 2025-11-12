#include<iostream>
#include<cstdio>
#include<vector> 
#include<algorithm>
#define int long long
using namespace std;
int n,m,k;
int fa[10010];
inline int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int v,w;
};
struct nod{
	int u,v,w;
}a[1001000];
bool cmp(nod x,nod y){
	return x.w<y.w;
}
vector<node>e[10010];
int ans;
struct nde{
	int c;
	int a[10010];
}s[20];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		e[x].push_back({y,z});
		e[y].push_back({x,z});  
		a[i].u=x;
		a[i].v=y;
		a[i].w=z;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int v=find(a[i].v),u=find(a[i].u);
		if(u!=v){
			fa[u]=v;
			ans+=a[i].w;
		}
	}
	if(k==0){
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&s[i].c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&s[i].a[j]);
		}
	}
	for(int i=1;i<1<<k;i++){
		
	}
	return 0;
}
