#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10005
#define M 1000005
ll n,m,k,val[N],now[N],num_edge,fa[N],c[15],vis[15];
struct node{
	ll u,dis;
};
struct edge{
	ll u,v,w,cz;
};
edge a[M*2];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll find(ll x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
ll uni(ll x,ll y)
{
	fa[find(x)]=find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	num_edge=m;
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		a[i].cz=0;
	}
	for(int i=1;i<=k;i++){
		ll bj,zhi=INT_MAX;
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> now[j];
			if(now[j]<zhi){
				bj=j;
				zhi=now[j];
			}
		}
		for(int j=1;j<=n;j++){
			a[++num_edge].u=j;
			a[num_edge].v=bj;
			a[num_edge].w=now[j]+zhi;
			a[num_edge].cz=i;
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	ll ans=0,num=0;
	sort(a+1,a+num_edge+1,cmp);
	for(int i=1;i<=num_edge;i++){
		if(find(a[i].u)!=find(a[i].v)){
			uni(a[i].u,a[i].v);
			ans+=a[i].w;
			num++;
			vis[a[i].cz]++;
			if(num==n-1){
				break;
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(vis[i]>0){
			ans+=c[i];
		}
	}
	cout << ans;
	return 0;
} 
