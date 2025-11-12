/*by bsjsaikou10 memoria*/ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6 + 20;
int n,m,k;
int fa[MAXN];
typedef struct Edge{
	int u,v,w;
}Edge;
typedef struct NN{
	int id,x;
}NN;
NN nnd[14];
bool cp(NN ndd,NN ndd2){
	return ndd.x < ndd2.x;
}
bool cmp(Edge e1,Edge e2){
	return e1.w < e2.w;
}
typedef struct City{
	int a[MAXN],c;
}City;
Edge edge[MAXN];
City ct[14];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
typedef struct Node{
	int ww,x,pos;
	bool operator < (const Node &nd) const{
		return nd.ww > ww;
	}
}Node;
priority_queue<Node> q;
Node node[MAXN];
int kurskal(int f){
	int ans = 0;
	sort(edge + 1,edge + 1 + m,cmp);
	for(int i = 1; i <= m; i++){
		int u = edge[i].u,v = edge[i].v,w = edge[i].w;
		if(find(u) != find(v)){
			//cout << "A: " << u << " " << v << endl;
			fa[find(v)] = find(u);
			//edge2[u].push_back({u,v,w});
			//edge2[v].push_back({v,u,w});
			ans += w; 
		}
	}
	if(f){
		cout << ans << endl;
		return ans;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		edge[i].u = u,edge[i].v = v,edge[i].w = w;
	}
	int ff = 1;
	for(int i = 1; i <= k; i++){
		cin >> ct[i].c;
		if(ct[i].c != 0){
			ff = 0;
		}
		for(int j = 1; j <= n; j++){
			cin >> ct[i].a[j];
		}
	}
	if(k == 0){
		for(int i = 1; i <= n; i++){
			fa[i] = i;
		}
		kurskal(1);
		return 0;
	}
	if(ff){
		for(int i = 1; i <= n; i++){
			fa[i] = i;
		}
		int aaa = kurskal(0);
		int ct3 = 0;
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				ct3++;
				edge[m + ct3].u = n + i,edge[m + ct3].v = j,edge[m + ct3].w = ct[i].a[j];
			}
		}
		n += k,m += ct3;
		for(int i = 1; i <= n; i++){
			fa[i] = i;
		}
		cout << min(aaa,kurskal(0)) << endl;
		return 0;
	}
	if(k <= 5){
		int as = 1e18;
		int nn = n,mm = m;
		for(int i = 0; i < (1 << k); i++){
			int ct1 = 0,ct2 = 0,sum = 0;
			n = nn,m = mm;
			for(int j = 0; j < 10; j++){
				if(i & (1 << j)){
					sum += ct[j + 1].c;
					ct1++;
					for(int ka = 1; ka <= n; ka++){
						ct2++;
						edge[m + ct2].u = n + ct1,edge[m + ct2].v = ka,edge[m + ct2].w = ct[j + 1].a[ka];
					}
				}
			}
			n += ct1,m += ct2;
			for(int j = 1; j <= n; j++){
				fa[j] = j;
			}
			as = min(as,kurskal(0) + sum);
			for(int j = 1; j <= ct2; j++){
				edge[m + j].u = edge[m + j].v = edge[m + j].w = 0;
			}
		}
		cout << as << endl;
		return 0;
	}
	int dd = 0;
	int asnn = n,asmm = m;
	for(int i = 1; i <= k; i++){
		n = asnn,m = asmm;
		dd = 0;
		for(int j = 1; j <= n; j++){
			dd++;
			edge[m + dd].u = n + 1,edge[m + dd].v = j,edge[m + dd].w = ct[i].a[j];
		}
		n++,m += dd;
		for(int j = 1; j <= n; j++){
			fa[j] = j;
		}
		nnd[i].id = i,nnd[i].x = kurskal(0) + ct[i].c;
	}
	n = asnn,m = asmm;
	sort(nnd + 1,nnd + 1 + k,cp);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	int kasn = kurskal(0);
	int dddd = 0,sd = 0;
	dd = 0;
	for(int i = 1; i <= k; i++){
		n = asnn,m = asmm;
		dddd++;
		sd += ct[nnd[i].id].c;
		for(int j = 1; j <= n; j++){
			dd++;
			edge[m + dd].u = n + dddd,edge[m + dd].v = j,edge[m + dd].w = ct[nnd[i].id].a[j];
		}
		n += dddd,m += dd;
		for(int j = 1; j <= n; j++){
			fa[j] = j;
		}
		kasn = min(kasn,kurskal(0) + sd);
	}
	cout << kasn << endl;
	return 0;
} 