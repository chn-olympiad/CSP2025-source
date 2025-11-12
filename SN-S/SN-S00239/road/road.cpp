#include "bits/stdc++.h"
using namespace std;
const int N = 1e6+5;

int n, m, k;
long long ans = INT_MAX, c[20];
int f[N];
bool flag = 0;
vector<int> d[N];

struct Node{
	long long u, v, w;
}g[N];

bool cmp(Node x, Node y){
	return x.w <= y.w;
}

int find(int a){
	if(a == f[a]) return a;
	return f[a] = find(f[a]);
}

void add(int a, int b){
	f[find(a)] = find(b);
	return ;
}

int main(){
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i) f[i] = i;
		for(int i=1;i<=m;++i){
		cin >> g[i].u >> g[i].v >> g[i].w;
		
	}
	for(int i=1;i<=k;++i){
		cin >> c[i];
		for(int j=1;j<=n;++j){
			int a;
			cin >> a;
			d[c[i]].push_back(a);
		}
	}
	
	for(int i=1;i<=k;++i){
		for(int j : d[c[i]]){
			if(j != 0) flag = 1;
		}
		if(!flag) {
			ans = min(ans, c[i]);
		}
	} 
	
	sort(g+1, g+1+m, cmp);
	long long cnt = 0;
	for(int i=1;i<n;++i) {
		cnt += g[i].w;
		add(g[i].u, g[i].v);
	}
	for(int i=n-1;i<=m;++i){
		if(find(g[i].u)!=find(g[i].v)){
			cnt += g[i].w;
			add(g[i].u, g[i].v);
		}
	}
	
	cout<<min(ans, cnt);
	
	
	return 0;
}
