#include<bits/stdc++.h>
#define fileio(nam) \
	freopen(nam".in","r",stdin); \
	freopen(nam".out","w",stdout)
#define ct(x) \
	ios::sync_with_stdio(x); \
	cin.tie(x),cout.tie(x)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define fi first
#define se second

const ll inf = 100000000000000000;
const int N = 12345;
const int M = 1234567 ;
struct point {
	int u,v,w;
}e[M];
int n,m,k;
int cost[N];
int fa[N];
int find(int x) {
	if(fa[x]==x) return x;
	return  fa[x] = find(fa[x]);
}

bool lv[N];
bool Cmpval(point aa,point bb) {
	return aa.w<bb.w;
}
// PREBLEM:    road   
int main() {
	fileio("road");
	ct(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>e[i].u>>e[i].v>>e[i].w ;
	}
	
	for(int i=1;i<=k;i++) {
		cin>>cost[i];
		for(int j=1;j<=n;j++) {
			m++;
			cin>>e[m].w;
			e[m].u=j;
			e[m].v=i+n;
		}
	}
	for(int i=1;i<=n;i++) lv[i]=1;
//	cout<<"M "<<m<<'\n';
	sort(e+1,e+1+m,Cmpval);
	ll Answer=inf;
	for(int sta=0;sta<(1<<k);sta++) {
		ll cted=0; // About Money has cost
		int mem=0;
		for(int i=1;i<=k;i++) {
			if(sta&(1<<i-1)) {
				lv[i+n]=1;
				cted+=cost[i];
				mem++;
			} else {
				lv[i+n]=0;
			}
		}
		for(int i=1;i<=n+k;i++) {
			fa[i]=i;
		}
		int Lnked=0;
		int u,v,w;
		for(int i=1;i<=m;i++) {
			u=e[i].u,  v=e[i].v ,w=e[i].w ;
			if(lv[u]&&lv[v]&&find(u)!=find(v)) {
				cted+=w;
				fa[find(u)]=find(v);
				Lnked++;
		//		cout<<"Merge  "<<u<<" "<<v <<"   "<<w<<'\n';
			//	if(mem+n==Lnked+1) break;
			}
		}
	//	cout<<k<<" "<<cted<<'\n';
		Answer=min(Answer,cted);
	}
	cout<<Answer<<'\n';
	return 0;
}
