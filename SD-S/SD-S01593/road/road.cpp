//Author:ZhuHua14(luogu)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e4 + 5;
const int MAXM = 2e6 + 5;
const int MAXK = 15;

struct Edge{
	int u,v,w;
};
Edge edge[MAXM];
bool cmp(Edge x,Edge y){
	return x.w < y.w;
}

struct Node{
	int pay1,pay[MAXN];
};
Node node[MAXK];

int n,m,k;

//k == 0 20pts at14:50左右 
int fa[MAXN],cnt;

int find(int x){
	return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

bool merge(int a,int b){
	int faa = find(a),fab = find(b);
	if(faa != fab){
		fa[faa] = fab;
		return 1;
	}
	else return 0;
}

void init(){
	for(int i = 1; i <= n + 2 * k; i++){
		fa[i] = i;
	}
}

//trick1: 乡村是乡村，城市是城市，相当于用c_j的代价开了一个中继点（只有10个） 而且中继点与中继点之间是不连通的 
//trick2: 只要用到中继点 中继点必然也在最小生成树上 
//给整个图加上链接中继点的边是行不通的
//好像可以把村子拆成俩点处理，这俩点之间的边权是c_j
//如果连这个点的边只有一条，证明这个点用不着，删了这条边的边权和这个点的点权就好了,会多1e5条边和20个点。 
//单开一个函数写这个。
//18:12 这个做法假了，留着看看能不能骗点分（ ，反正是分开写的（ 
 
void solve1(){
	sort(edge + 1,edge + 1 + n,cmp);
	ll ans = 0;
	init();
	for(int i = 1; i <= m; i++){
		if(merge(edge[i].u,edge[i].v)){
//			 << edge[i].u << ' ' << edge[i].v;
			ans += edge[i].w;
			cnt++;
		}
		if(cnt == n) break;
	}
	cout << ans << '\n';
}

//fake 
int ind[MAXK],lstp[MAXK];
void init2(){
	//(n + i，n + k + i)对应第i个村 
	for(int i = 1; i <= k; i++){
		edge[++m] = {n + i,n + i + k,node[i].pay1};
		for(int j = 1; j <= n; j++){
			edge[++m] = {j,n + i + 1,node[i].pay[j]};
		} 
	} 
	sort(edge + 1,edge + 1 + m,cmp);
	ll ans = 0;
	init();
	for(int i = 1; i <= m; i++){
		if(merge(edge[i].u,edge[i].v)){
			//cerr << edge[i].u << ' ' << edge[i].v << '\n';
			if(edge[i].v > n && edge[i].u <= n){
				ind[edge[i].v]++;
				lstp[edge[i].v] = edge[i].u;
			}
			ans += edge[i].w;
			cnt++;
		}
		if(cnt == n + 2 * k) break;
	}
	for(int i = 1; i <= k; i++){
		if(ind[i] == 1){
			ans -= node[i].pay[lstp[i]];
			ans -= node[i].pay1;
		}
	}
	cout << ans << '\n';
} 

void solve2(){
	init2();
} 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road1.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for(int i = 1; i <= k; i++){
		cin >> node[i].pay1;
		for(int j = 1; j <= n; j++){
			cin >> node[i].pay[j];
		}
	}
	if(k == 0) solve1();
	else solve2();
	return 0;
}

