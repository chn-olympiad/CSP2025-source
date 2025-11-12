#include<bits/stdc++.h>
#define ll long long
#define inf INT_MAX
#define INF LLONG_MAX
#define lf double
#define ld long double

using namespace std;
const int MAXN = 1e6+10;

int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN], tot;
int bel[MAXN];

void Adde(int u, int v, int w) {
	nxt[++tot] = head[u];
	val[tot] = w;
	to[tot] = v;
	head[u] = tot;
	
}

int find(int i) {
	while(i!=bel[i])i = bel[i];
	return i;
}
void inclu(int i, int j) {
	 bel[find(i)] = i;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i < MAXN; i++) bel[i] = i;
	int n, m, k;
	cin >> n >> m >> k;
	for()
	
	return 0;

}

