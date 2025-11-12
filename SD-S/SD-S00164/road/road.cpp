#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,m,k;
struct node{
	ll x,y,z;
}edge[2*N+20];
int cnt;
void add(ll x,ll y,ll z){
	edge[++cnt].x=x;
	edge[cnt].y=y;
	edge[cnt].z=z;
}
int c[N],fa[N],a[N];
int Find(int x){
	if(x==fa[x]) return x;
	return fa[x]=Find(fa[x]);
}
int Union(int x,int y){
	x=Find(x),y=Find(y);
	fa[x]=y;
}
int cmp(node a,node b){
	return a.z<b.z;
}
ll ans;
int cc;
void f(){
	sort(edge+1,edge+1+cnt,cmp);
	for(int i=1;i<=cnt;++i){
		int x=edge[i].x,y=edge[i].y,z=edge[i].z;
		if(Find(x)!=Find(y)){
			Union(x,y),ans+=z;
			cc++;
		}
		if(cc==n-1) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j){
			scanf("%lld",&a[i]);
		}
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				add(j,k,a[j]+a[k]);
			}
		}
	}
	f();
	printf("%lld",ans);
	return 0;
} 
