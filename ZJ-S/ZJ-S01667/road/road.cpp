#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5, M = 1e4 + 100, K = 15;
struct A{
	int u, v, w;
	bool operator<(const A &p)const{
		return w < p.w;
	}
}a[N], b[N], zt[K][M];
int n, m, k, ljd, c[K], f[K][M], fa[M];
vector<int> ans[K];
inline int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9')	c = getchar();
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
int query(int x){
	if(x == fa[x])	return x;
	return fa[x] = query(fa[x]);
}
int U(int u, int v){
	u = query(u);
	v = query(v);
	if(u != v)	fa[u] = v;
}
signed main(){
//	set<A> s;
//	s.insert(A{4, 1, 1});
//	s.insert(A{4, 2, 1});
//	cout << s.size();
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for(int i = 1; i <= m; ++i){
		a[i].u = read();
		a[i].v = read();
		a[i].w = read();
	}
	sort(a + 1, a + 1 + m);
	for(int i = 1; i <= n; ++i)	fa[i] = i;
	int cntt = 0;
	for(int i = 1; i <= m; ++i){
		if(cntt == n - 1)	break;
		if(query(a[i].u) == query(a[i].v))	continue;
		cntt++;
		U(a[i].u, a[i].v);
		ljd += a[i].w;
	}
	for(int i = 1; i <= k; ++i){
		c[i] = read();
		for(int j = 1; j <= m; ++j)	b[j] = a[j];
		for(int j = 1; j <= n; ++j){
			f[i][j] = read();
			b[m + j] = A{n + 1, j, f[i][j]};
		}
		sort(b + 1, b + 1 + m + n);
		for(int j = 1; j <= n + 1; ++j)	fa[j] = j;
		int cnt = 0;
		for(int j = 1; j <= n + m; ++j){
			if(cnt == n)	break;
			if(query(b[j].u) == query(b[j].v))	continue;
			cnt++;
			zt[i][cnt] = A{b[j].u, b[j].v, b[j].w};
			if(b[j].u == n + 1)	zt[i][cnt].u = n + i;
			U(b[j].u, b[j].v);
		}
	}
//	for(int i = 1; i <= n; i++)	cout << zt[1][i].u << ' ' << zt[1][i].v << ' ' << zt[1][i].w << endl;
	for(int s = 1; s < (1 << k); ++s){
		set<pair<int, pair<int, int> > > st;
		int lzt = 0, cnt = 0, gs = 0, hah = 0;
		for(int j = 1; j <= k; ++j){
			if((1 << (j - 1)) & s){
				lzt += c[j];
				++gs;
				for(int i = 1; i <= n; ++i)	st.insert(make_pair(zt[j][i].u, make_pair(zt[j][i].v, zt[j][i].w)));
			}
		}
//		cout << endl;
//		cout << s << endl;
//		for(auto now : st){
//			cout << now.u << ' ' << now.v << ' ' << now.w << endl;
//		}
//		if(s == 3){
//			for(auto now : st)	cout << now.first << ' ' << now.second.first << ' ' << now.second.second << endl;
//		}
		for(auto now : st)	b[++cnt] = A{now.first, now.second.first, now.second.second};
		sort(b + 1, b + 1 + cnt);
//		cout << cnt << endl;
		for(int i = 1; i <= n + 20; ++i)	fa[i] = i;
		for(int i = 1; i <= cnt; ++i){
			if(hah == gs + n - 1)	break;
			if(query(b[i].u) == query(b[i].v))	continue;
			++hah;
			U(b[i].u, b[i].v);
			lzt += b[i].w;
		}
//		if(lzt == 2)	cout << s << endl;
		ljd = min(ljd, lzt);
	}
	printf("%lld", ljd);
	return 0;
}
/*
3 3 2
1 2 100
1 3 100
2 3 100
1 1 1 1000
1 1000 1 1*/
