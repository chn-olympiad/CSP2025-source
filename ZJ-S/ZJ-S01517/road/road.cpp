#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=1e4+10+15;
const int MAXM=1e6+10+10*MAXN;
const int MAXK=15;

struct edge{
	int u,v,w;
	operator <(edge y){
		return w<y.w;
	}
	operator >(edge y){
		return w>y.w;
	}
} e[MAXM];
int el=0;
// 1<=i<=n !!!
int n,m,k;
int u,v,w;
int c[MAXK],a[MAXK][MAXN];
//vector<vector<int> >p(MAXN);
//vector<vector<int> >pw(MAXN);
int du[MAXN];

int f[MAXN]; // аз╫с╠М 
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int link(int x,int y){
	f[find(x)]=find(y);
}

int ans=0;

void build(int u,int v,int w){
	e[el].u=u;
	e[el].v=v;
	e[el].w=w;
	el++;
//	p[u].push_back(v);
//	p[v].push_back(u);
//	pw[u].push_back(w);
//	pw[v].push_back(w);
}

void solve(){
	int cnt=1; // cnt for linked nodes
	sort(e,e+el);
	for (int i=0;i<el && cnt<n;i++){
		u=e[i].u;
		v=e[i].v;
		w=e[i].w;
		if (find(u)!=find(v)){
			if (u<v) swap(u,v);
			link(u,v);
			du[u]++;
			du[v]++;
			if ((u<=n)||(du[u]>1)){
				cnt++;
			}
			ans+=w;
		}
	}
}

int main(){
//	freopen("road3.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for (int i=0;i<MAXN;i++){
		f[i]=i; // init
	}
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		build(u,v,w);
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		int zero;
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if (a[i][j]==0){
				zero=j;
			}
		}
		for (int j=1;j<=n;j++){
			if (zero!=j) build(zero,j,a[i][j]);
		}
	}
	
	solve();
	cout << ans;
	
	return 0;
}
