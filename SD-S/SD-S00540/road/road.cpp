#include <bits/stdc++.h>
using namespace std;
long long fa[1000100],n,m,k,ent,u1,v1,w1,rp,tot,ans;
struct edge{
	long long u,v,w;
}e[3000001];
bool cmp(edge ax,edge bx){
	return ax.w<bx.w;
}
void eadd(int ua,int va,int wa){
	ent++;
	e[ent].u = ua;
	e[ent].v = va;
	e[ent].w = wa;
}
long long find(long long ax){
	if(fa[ax] == ax)return ax;
	else return fa[ax] = find(fa[ax]);
}
void hb(long long ax,long long bx){
	long long aa=find(ax);
	long long bb = find(bx);
	fa[aa] = bb;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld",&u1);
		scanf("%lld",&v1);
		scanf("%lld",&w1);
		eadd(u1,v1,w1);
	} //cout<<1;
	for(int i=1;i<=n+k;i++){
		fa[i] = i;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&rp);
		for(int j=1;j<=n;j++){
		    scanf("%lld",&w1);
			eadd(n+i,j,w1);
		}
	}
	sort(e+1,e+ent+1,cmp);
	for(int i=1;i<=ent;i++){
		if(find(e[i].u) != find(e[i].v)){
			hb(e[i].u,e[i].v);
			tot++;
			ans+=e[i].w;
		}
	}
	rp++;
	cout<<ans;
	
	return 0;
}
