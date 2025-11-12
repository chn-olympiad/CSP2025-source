#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    for(; ch < '0' || ch > '9'; w *= ch == '-' ? -1 : 1, ch = getchar());
    for(; ch >= '0' && ch <= '9'; s = s * 10 + ch - '0', ch = getchar());
    return s * w;
}
const int MAXN = 10015;
const int MAXM = 1000005;
const int MAXK = 15;
int N, M, K, a[MAXK][MAXN], w[MAXK], fa[MAXN], cnt, res, tot2;
vector<int> tr;
struct Edge{
	int u, v, w;
	bool operator < (const Edge &rhs) const{
		return w < rhs.w;
	}
} e[MAXM], e2[MAXM];
int get(int x) {return x == fa[x] ? x : (fa[x] = get(fa[x]));}
int work(int n, int m){
	int tmpres = 0;
	sort(e2 + 1, e2 + m + 1);
//	cout << n << "," << m << endl;
	for(int i = 1; i <= n; i++) fa[i] = i;
	cnt = n;
	for(int i = 1; i <= m; i++){
//		cout << e2[i].u << "," << e2[i].v << "," << e2[i].w << endl;
		if(get(e2[i].u) == get(e2[i].v)) continue;
		fa[get(e2[i].v)] = get(e2[i].u);
		tmpres += e2[i].w;
		cnt--;
		if(cnt == 1) break;
	}
	return tmpres;
}
signed main(){
//	freopen("road4.in", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	N = read(), M = read(), K = read();
	for(int i = 1; i <= M; i++){
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	}
	for(int i = 1; i <= K; i++){
		w[i] = read();
		for(int j = 1; j <= N; j++) a[i][j] = read();
	}
	sort(e + 1, e + 1 + M);
	for(int i = 1; i <= N; i++) fa[i] = i;
	cnt = N, res = 0;
	for(int i = 1; i <= M; i++){
		if(get(e[i].u) == get(e[i].v)) continue;
		fa[get(e[i].v)] = get(e[i].u);
		res += e[i].w;
		tr.push_back(i);
		cnt--;
		if(cnt == 1) break;
	}
//	cout << res << endl;
	for(int S = 0, tmpcnt, tmpsum; S < (1 << K); S++){
		for(int i = 0; i < tr.size(); i++) e2[i + 1] = e[tr[i]];
		tot2 = tr.size(); tmpcnt = tmpsum = 0;
		for(int i = 1; i <= K; i++){
			if((S & (1 << (i - 1))) == 0) continue;
			tmpcnt++, tmpsum += w[i];
			for(int j = 1; j <= N; j++){
				e2[++tot2].u = N + tmpcnt, e2[tot2].v = j, e2[tot2].w = a[i][j];
			}
		}
//		cout << S << " " << tmpcnt << " " << tmpsum << " " << work(N + tmpcnt, tot2) << endl;
		res = min(res, work(N + tmpcnt, tot2) + tmpsum);
	}
	cout << res << endl;
	return 0;
}
/*
At 16:35, I seemingly get the solution.
but I'm afraid that the solution is not correct and i will have little time to get partical points.
At 17:21, I compete all the code, but it could't pass the example 3&4...
My answer used to be lower than std. It's strange.
I would have expected it to be higher than std...
At 17:28, I find out the bug and my code pass all the examples!!
The only thing I'm thinking about is that my code won't exceed the time limitation.
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
