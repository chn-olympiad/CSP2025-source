#include<bits/stdc++.h>
#define LL long long
using namespace std;
//_______________________________________________________________________________________________________
#define PLI pair<LL, int>
#define PIL pair<int, LL>
const int N = 2009, M = 2000009;
int n, m, k;
vector<pair<int, LL> >g[N];
int p[N];
int find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

struct AC{
	int u, v;
	LL w;
}e[M], ee[M];
int rp = 0;
int lst[15];
bool cmp(AC a, AC b){
	return a.w < b.w;
}

LL cnt, ans[N];

void calc(){
	for(int i = 1; i < N; i++) p[i] = i;
	cnt = 0;
	sort(e + 1, e + rp + 1, cmp);
	for(int i = 1; i <= rp; i++){
		int u = e[i].u, v = e[i].v;
		LL w = e[i].w;
		int pu = find(u), pv = find(v);
		if(pu == pv) continue;
		cnt += w;
		p[pu] = pv; 
	}
}
LL c[15];



int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int u, v; LL w;
		scanf("%d%d%lld", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		e[++rp] = {u, v, w};
	}
	
	bool flag1 = true;
	for(int i = n + 1; i <= n + k; i++){
		bool flag2 = false;
		LL a;
		scanf("%lld", &c[i - n]);
		if(c[i - n] != 0) flag1 = false;
		for(int j = 1; j <= n; j++){
			scanf("%lld", &a);
			g[i].push_back({j, a});
			g[j].push_back({i, a});
			if(a == 0) flag2 = true;
		}
		if(!flag2) flag1 = false;
	}
	
	if(flag1){
		for(int i = n + 1; i <= n + k; i++){
			int u = i;
			for(PIL x : g[u]){
				int v = x.first;
				LL w = x.second;
				e[++rp] = {u, v, w};
			}
		}
		calc();
		printf("%lld\n", cnt);
	}
	else{
		calc();
		LL ans = cnt, sum = 0;
		for(int i = 1; i <= k; i++){
			int u = n + i;
			int rrp = rp;
			for(PIL x : g[u]){
				int v = x.first;
				LL w = x.second;
				e[++rp] = {u, v, w};
			}
			memcpy(ee, e, sizeof(e));
			calc();
			memcpy(e, ee, sizeof(e));
			if(ans >= cnt + c[i] + sum){
				ans = cnt + c[i] + sum;
				sum += c[i];
			}
			else{
				rp = rrp;
			}
//			printf("%lld\n", ans);
		}
		printf("%lld\n", ans);
	}
	

	return 0;
}

