#include <bits/stdc++.h>
using namespace std;
const int M = 1010;
long long n,m,k,fa[M],c[M],a[11][M];
long long minn[M][M],mink[M][M];
bool vis[100];
int fd(int i){
	if(fa[i] == i) return i;
	else{
		fa[i] = fd(fa[i]);
		return fa[i];
	}
}
struct eg{
	int u,v;long long w;int k;
}e[3000000];
bool operator < (eg a,eg b){
	return a.w < b.w;
}
long long ksk(){
	sort(e,e+m);
	for(int i = 0;i <= n;i ++ ) fa[i] = i;
	long long res = 0;
	for(int i = 0,j = 1;j < n;i ++ ){
		int fu = fd(e[i].u),fv = fd(e[i].v);
		if(fu != fv){
			if(k != -1){
				if(vis[k]) {res -= c[k];}
				else vis[k] = 1;
			}
			res += e[i].w;
			j++;
			fa[fu] = fv;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(minn,0x7f,sizeof minn);
	for(int i = 0;i < m;i ++ ){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i].u = u;
		e[i].v = v;
		e[i].w = w;
		e[i].k = -1;
	}
	bool fl = 1;
	for(int i = 0;i < k;i ++ ){
		scanf("%lld",&c[i]);
		int p = -1;
		for(int j=1;j<=n;j++){scanf("%lld",&a[i][j]);if(!a[i][j])p=j;}
		if(p == -1) fl = 0;
	}
	if(k==0);
	else if(fl){
		for(int i = 0;i < k;i ++ ){
			int p = -1;
			for(int j=1;j<=n;j++) if(!a[i][j])p=j;
			for(int j=1;j<=n;j++){
				if(j != p){
					e[m].u=j;
					e[m].v=p;
					e[m].w=c[i] + a[i][j];
					e[m++].k = i;
				}
			}
		}
	}else if(n <= 1000){
		for(int i = 0;i < k;i ++ ){
			for(int j=1;j<=n;j++){
				for(int kk=j+1;kk<=n;kk++){
					if(c[i] + a[i][j] + a[i][kk] < minn[j][kk])minn[j][kk]=c[i] + a[i][j] + a[i][kk],mink[j][kk] = i;;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int kk=j+1;kk<=n;kk++){
				e[m].u=j;
				e[m].v=kk;
				e[m].w=minn[j][kk];
				e[m++].k = mink[j][kk];
			}
		}
	}
	cout << ksk();
	return 0;
}

