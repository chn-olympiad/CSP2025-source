#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,fa[10005],sum,xx,kk[22][10005];
struct node{
	ll edge1;
	ll edge2;
	ll quan;
}f[10005];
bool cmp(node X,node Y){
	return X.quan<Y.quan;
}
int find1(ll x){
	if(fa[x]!=x) return find1(fa[x]);
	return fa[x];
}
void kruskal(){
	for(int i=1;i<=m;i++){
		ll u=f[i].edge1,v=f[i].edge2;
		if(find1(u)!=find1(v)){
			fa[find1(u)]=v;
			sum+=f[i].quan;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		f[i].edge1=x;
		f[i].edge2=y;
		f[i].quan=z;
	}
	if(k==0){
		sort(f+1,f+1+m,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		kruskal();
		printf("%lld",sum);
		return 0;
	}
	else{
		for(int i=1;i<=k;i++){
			scanf("%lld",&xx);
			for(int j=1;j<=n;j++){
				scanf("%lld",&kk[i][j]);
				f[m+(i-1)*n+j].edge1=n+i;
				f[m+(i-1)*n+j].edge2=j;
				f[m+(i-1)*n+j].quan=kk[i][j];
			}	
		}
		m=m+k*n;
		sort(f+1,f+1+m,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		kruskal();
		printf("%lld",sum);
	}
	return 0;
}
