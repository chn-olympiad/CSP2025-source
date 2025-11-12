#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005,M=1000005;
int n,m,k,f[N],nm,a[15][N],c[N],ct,ctt;
struct node{int u,v,w;}e[M],ne[N],nee[M];
LL rs,mn=1e18;
int find(int u){return u==f[u]?u:f[u]=find(f[u]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(e+1,e+1+m,[&](node x,node y){return x.w<y.w;});
	for(int i=1,fu,fv;i<=m;i++){
		fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;
		f[fu]=fv,ne[++nm]=e[i],rs+=e[i].w;
		if(nm==n-1)break;
	}
	for(int S=0;S<(1<<k);S++){
		nm=n-1,rs=ct=ctt=0;
		for(int i=1;i<n;i++)nee[i]=ne[i];
		for(int i=0;i<k;i++)if(S>>i&1){
			rs+=c[i+1],ctt++;
			for(int j=1;j<=n;j++)nee[++nm]={n+ctt,j,a[i+1][j]};
		}
		for(int i=1;i<=n+ctt;i++)f[i]=i;
		sort(nee+1,nee+1+nm,[&](node x,node y){return x.w<y.w;});
		for(int i=1,fu,fv;i<=nm;i++){
			fu=find(nee[i].u),fv=find(nee[i].v);
			if(fu==fv)continue;
			f[fu]=fv,rs+=nee[i].w,ct++;
			if(ct==n+ctt-1)break;
		}
		mn=min(mn,rs);
	}
	cout<<mn<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
