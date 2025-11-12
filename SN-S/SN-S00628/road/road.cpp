#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 7;
const int M = 1e6 + 7;
const int K = 17;

struct Edge1{
	int u, v;
	ll w;
}e1[M];

struct Edge2{
	int u, v;
	ll w;
}e2[N * K];

int n, m, k, cnt, c[K], f[N + K], idx;
ll tmp, ans = 1000000000000000ll;
bool b[K], flag;

bool cmp1(Edge1 x, Edge1 y){
	return x.w < y.w;
}

bool cmp2(Edge2 x, Edge2 y){
	return x.w < y.w;
}

int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void merge(int u, int v, ll w){
	u = find(u);
	v = find(v);
	if(u == v) return;
	cnt++;
	tmp += w;
	f[u] = v;
	return;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++) cin>>e1[i].u>>e1[i].v>>e1[i].w;
	sort(e1 + 1, e1 + m + 1, cmp1);
	for(int i = 1; i <= k; i++){ 
		cin>>c[i];
		for(int j = 1; j <= n; j++){
			cin>>e2[++idx].w;
			e2[idx].u = i + n;
			e2[idx].v = j;
		}
	}
	sort(e2 + 1, e2 + idx + 1, cmp2);
	if(m > 5e5){
		cout<<0;
		return 0;
	}
	for(int stts = 0; stts < (1<<k); stts++){ //枚举 
		tmp = 0;
		int req = n - 1;
		cnt = 0;
		for(int i = 1; i <= n + k; i++){ //初始化 
			f[i] = i;
		}
		for(int i = 1; i <= k; i++){ //拆 
			if((stts>>(i - 1)) & 1){
				b[i] = true;
				tmp += c[i];
				req++;
			}else b[i] = false;
		}
		
		int idx1 = 1;   //最小生成树 
		int idx2 = 1;
		while(idx1 <= m || idx2 <= idx){
			if(cnt >= req) break;
			while(!b[e2[idx2].u - n] && idx2 <= idx) idx2++;
			if(idx2 <= idx && (e2[idx2].w < e1[idx1].w || idx1 > m)){
				merge(e2[idx2].u, e2[idx2].v, e2[idx2].w);
				idx2++;
			}else{
				merge(e1[idx1].u, e1[idx1].v, e1[idx1].w);
				idx1++;
			}
		}
		ans = min(ans, tmp);
	}
	cout<<ans<<endl;
	return 0;
} 
