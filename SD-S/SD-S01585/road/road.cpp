#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1000005,K=7;
struct Edge{
	long long u,v,w;
}e[M+N*K];
long long n,m,k,c[K],a[K][N],fa[N+K],ans=1000000000000005,ens;
int cntt;
bool flag[K];
long long find(long long x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
void solve(){
	ens=0;
	cntt=m;
	for(int i=1;i<=k;i++){
		if(flag[i]){
			ens+=c[i];
			for(int j=1;j<=n;j++){
				e[++cntt].u=n+i;
				e[cntt].v=j;
				e[cntt].w=a[i][j];
			}
		}
	}
	sort(e+1,e+1+cntt,cmp);
	for(int i=1,x,y,fx,fy;i<=cntt;i++){
		x=e[i].u;
		y=e[i].v;
		fx=find(x);
		fy=find(y);
		if(fx!=fy){
			ens+=e[i].w;
			fa[fy]=fx;
		}
	}
	ans=min(ans,ens);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int stt=0,sct;stt<(1<<k);stt++){
		sct=stt;
		memset(flag,0,sizeof(flag));
		cntt=0;
		while(sct){
			cntt++;
			if(sct&1){
				flag[cntt]=1;
			}
			sct>>=1;
		}
		for(int i=1;i<n+k;i++){
			fa[i]=i;
		}
		solve();
	}
	cout<<ans;
	return 0;
}

