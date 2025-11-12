#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn=1e6+2;
struct edge{
	int u,v,w,nxt;
	bool operator <(const edge &a) const{
		return w<a.w;
	}
}e[mxn*3];
int head[mxn],len;
inline void Insert(int u,int v,int w){
	e[++len]={u,v,w,head[u]},head[u]=len;
}
int n,m,k,u,v,w,prt[mxn];
int c[13],a[13][10003];
int Find(int u){
	return u==prt[u]?u:prt[u]=Find(prt[u]);
}
void kruskal(){
	ll res=0,cnt=0;
	for(int i=1;i<=len;i++){
		if(cnt==n-1){
			printf("%lld",res);
			exit(0);
		}
		int u=e[i].u,v=e[i].v,r_u=Find(u),r_v=Find(v);
		if(r_u==r_v) continue;
		prt[r_u]=r_v;
		res+=e[i].w,cnt++;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		Insert(u,v,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++) prt[i]=i;
	sort(e+1,e+1+len);
	kruskal();
}