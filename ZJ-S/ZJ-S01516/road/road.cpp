#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 10, M = 1e6 + 10;
long long n, m, k, u[M], v[M], w[M], c[N], a[15][N], fa[N], ans, U[M], V[M], W[M], cnt, bc[N];
tuple<int, int, int> b[1100][22000], dd[M];

long long find(long long x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(long long x, long long y){
	fa[find(x)] = find(y);
	return ;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for(long long i = 1; i <= m; i++){
		long long u, v, w;
		cin >> u >> v >> w;
		dd[i] = make_tuple(w, u, v);
	}
	sort(dd + 1, dd + 1 + m);

	for(long long i = 1; i <= n; i++) fa[i] = i;
	for(long long i = 1; i <= m; i++){
		long long u = find(get<1>(dd[i])), v = find(get<2>(dd[i]));
		if(u == v) continue;
		merge(u, v);
		U[++cnt] = get<1>(dd[i]);
		V[cnt] = get<2>(dd[i]);
		W[cnt] = get<0>(dd[i]);
		ans += W[cnt];
	}

	for(long long j = 1; j <= k; j++){
		cin >> c[j];
		for(long long l = 1; l <= n; l++){
			cin >> a[j][l];
		}
	}

	for(long long S = 1; S < (1 << k); S++){
		long long res = 0;
		for(long long j = 1; j <= k; j++) if((S >> (j - 1)) & 1)
			res = res + c[j];
		for(long long i = 1; i <= n + k; i++) fa[i] = i;

		if((S & -S) == S){
			for(long long j = 1; j <= k; j++) if((S >> (j - 1)) & 1){
				for(long long i = 1; i <= n; i++){
					b[S][++bc[S]] = make_tuple(a[j][i], n + j, i);
				}
			}
			sort(b[S] + 1, b[S] + 1 + bc[S]);
		}
		else{
			long long T = S ^ (S & -S), L = (S & -S);
			long long i = 1, j = 1;
			while(i <= bc[T] && j <= bc[L]){
				++bc[S];
				if(get<0>(b[T][i]) <= get<0>(b[L][j]))
					b[S][bc[S]] = b[T][i], i++;
				else
					b[S][bc[S]] = b[L][j], j++;
			}
			while(i <= bc[T]){
				++bc[S];
				b[S][bc[S]] = b[T][i], i++;
			}
			while(j <= bc[L]){
				++bc[S];
				b[S][bc[S]] = b[L][j], j++;
			}
		}

		long long j = 1, tmp = 0;
		for(long long i = 1; i <= bc[S]; i++){
			long long u = get<1>(b[S][i]), v = get<2>(b[S][i]), w = get<0>(b[S][i]);
			while(j <= cnt && W[j] <= w){
				if(find(U[j]) == find(V[j])){
					j++;
					continue;
				}
				merge(U[j], V[j]);
				res += W[j];
				j++;
			}
			if(find(u) == find(v)) continue;
			merge(u, v);
			res += w;

			++tmp;
			b[S][tmp] = b[S][i];
		}
		bc[S] = tmp;

		while(j <= cnt){
			if(find(U[j]) == find(V[j])){
				j++;
				continue;
			}
			merge(U[j], V[j]);
			res += W[j];
			j++;
		}
		ans = min(ans, res);
	}

	cout << ans << "\n";
	return 0;
}