#include<bits/stdc++.h>
typedef long long Int;
constexpr Int MAXN = 10000;
constexpr Int MAXM = 1000000;
constexpr Int MAXK = 10;
constexpr Int INF = LLONG_MAX;
Int N, M, K, F[1 + MAXN + MAXK], fix[1 + MAXK], A[1 + MAXK][1 + MAXN], ans = INF;
struct Edge{
	Int u, v, w;
	Edge(){
		u = v = w = 0;
	}
	Edge (Int a, Int b, Int c){
		u = a, v = b, w = c;
	}
} edges[1 + MAXM];
std:: vector<Edge> pre;
Int find(Int X){
	if (F[X] == X) return X;
	return F[X] = find(F[X]);
}
void kruskal(Int pw){
	Int tt = N + __builtin_popcountll(pw), res = 0;
	for (Int i = 1, j = 1 ; i <= K ; i++, j <<= 1){
		if (pw & j){
			for (Int l = 1 ; l <= N ; l++){
				pre.emplace_back(Edge(N + i, l, A[i][l]));
			}
			res += fix[i];
		}
	}
	std:: sort(pre.begin(), pre.end(), [](Edge X, Edge Y){
		return X.w < Y.w;
	});
	memset(F, 0, sizeof F);
	for (Int i = 1 ; i <= N + K ; i++) F[i] = i;
	for (Edge e: pre){
		if (find(e.u) == find(e.v)) continue;
		res += e.w;
		F[find(e.u)] = find(e.v);
		tt--;
		if (tt == 1) break;
	}
	std:: sort(pre.begin(), pre.end(), [](Edge X, Edge Y){
		return X.u < Y.u;
	});
	for (Int i = 1, j = 1 ; i <= K ; i++, j <<= 1){
		if (pw & j){
			for (Int l = 1 ; l <= N ; l++){
				pre.pop_back();
			}
		}
	}
	ans = std:: min(ans, res);
}
void solve(){
	for (Int i = 1 ; i <= M ; i++){
		pre.emplace_back(edges[i]);
	}
	for (Int i = 0 ; i < (1LL << K) ; i++){
		kruskal(i);
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std:: ios:: sync_with_stdio(false);
	std:: cin.tie(nullptr);
	std:: cin >> N >> M >> K;
	for (Int i = 1 ; i <= M ; i++){
		std:: cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	for (Int i = 1 ; i <= K ; i++){
		std:: cin >> fix[i];
		for (Int j = 1 ; j <= N ; j++){
			std:: cin >> A[i][j];
		}
	}
	solve();
	std:: cout << ans << '\n';
	return 0;
}

