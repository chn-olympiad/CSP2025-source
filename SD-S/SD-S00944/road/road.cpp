#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;

const int N=2e4+10, M=2e6+10;
struct Edge{int u,v,w;}e[M];
int a[15][N], fa[N], b[N], c[N];
int n, m, k, ans;

void FAST(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int cmp(Edge x,Edge y){return x.w<y.w;}
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}

void kru(){
	int fx,fy; int cnt=0;
	for(int i=1; i<=m; i++){
		fx=Find(e[i].u); fy=Find(e[i].v);
		if(fx!=fy){
			ans+=e[i].w; cnt++;
			fa[fx]=fy;
			if(cnt==n-1)break;
		}
	}
}

void Init(){
	for(int i=0; i<N; i++) fa[i]=i;
	for(int i=1; i<=n; i++)
		b[i]=1e9;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	FAST();
	cin>>n>>m>>k;
	Init();
	int u,v,w;
	for(int i=1; i<=m; i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
		}
	}
	if(!k){
		stable_sort(e+1, e+m+1, cmp);
		kru();
		cout<<ans; return 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			for(int p=1; p<=k; p++){
				e[++m]={i,j,c[p]+a[p][i]+a[p][j]};
			}
		}
	}
	stable_sort(e+1, e+m+1, cmp);
	kru();
	cout<<ans;
	return 0;
}
