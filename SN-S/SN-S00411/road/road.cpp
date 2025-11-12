#include <bits/stdc++.h>
using namespace std;

void node{
	int u,v,w;
}a[1000005];

int f[1000005];

void init(int n){
	for(int i = 1;i<=n;++i){
		f[i]=i;
	}
}

int fa(int x){
	return (f[x]==x)?(x):(f[x]=fa(f[x]));
}

int main(){
	#ifndef NeiKos496
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	int n,m,k;
	cin >> n >> m >> k;
	init(n);
	//if(k!=0)return 0;
	for(int i=1;i<=m;++i){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a+1,a+1+n,[](node a,node b){
		return a.w < b.w;
	})
	int ans = 0;
	int x = 0;
	for(int i=1;i<=m;++i){
		int faa=fa(a[i].u);
		int fb=fa(a[i].v);
		if(faa==fb)continue;
		else{
			fa[faa]=fb;
			sum+=a[i].w;
			++x;
			if(x == n-1){
				break;
			}
		}
	}
	cout << ans;
} 

