#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10105],yf,bl;
long long c[15][10005],ans=0;
struct sid{
	int u,v;
	long long w;
} mp[1000005];
bool cmp(sid x,sid y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}void merge(int a,int b){
	if(find(a)==find(b)){
		return;
	}f[find(a)]=find(b);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin >> mp[i].u >> mp[i].v >> mp[i].w;
	}
	for(int i=1;i<=k;i++){
		cin >> c[i][1];
		for(int j=1;j<=n;j++){
			cin >> c[i][j];
		}
	}
	for(int l=1;l<=k;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				mp[++m].w=c[l][i]+c[l][j];
				mp[m].u=i,mp[m].v=j;
			}
		}
	}
	sort(mp+1,mp+1+m,cmp);
	while(yf<n-1){
		bl++;
		if(find(mp[bl].u)==find(mp[bl].v)) continue;
		merge(mp[bl].u,mp[bl].v);
		ans+=mp[bl].w;
		yf++;
	}cout << ans;
	return 0;
}
