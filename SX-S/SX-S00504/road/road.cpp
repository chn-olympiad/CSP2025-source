#include <bits/stdc++.h>
using namespace std;
//

//int fa[N],son[N];
//int find(int x){
//	if(x==fa[x])return fa[x];
//	return fa[x]=find[fa[x]];
//}

template <class T>

inline void read(T &res) {
	char c;
	bool f = 0;
	while (!isdigit(c = getchar()))
		if (c == '-')
			f = 1;
	res = (c ^ 48);
	while (isdigit(c = getchar()))
		res = (res << 1) + (res << 3) + (c ^ 48);
	if (f)
		res = ~res + 1;
}

const int N = 1e4+5, M = 1e6+5;

int T, n, m, k, top = 0;
int c[15], p[15][2 * N];
int fl[2 * N];

struct Eg {
	int u, v, wt;
	bool operator <(const Eg &x)const {
		return wt < x.wt;
	}
} tmp[4 * M];

void scan() {
	read(n);
	read(m);
	read(k);
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		read(u);
		read(v);
		read(w);
//		add(u,v,w);add(v,u,w);
		tmp[++top] = {u, v, w};
		tmp[++top] = {v, u, w};
	}
	sort(tmp + 1, tmp + top + 1);
//	for (int i = 1; i <= top; i++) {
//		printf("%d %d %d\n", tmp[i].u, tmp[i].v, tmp[i].wt);
//	}
	for (int i = 1; i <= k; i++) {
		read(c[i]);
		for (int j = 1; j <= n; j++) {
			read(p[i][j]);
			if (p[i][j] == 0) {
				for (int ii = 1; ii <= n; ii++) {
					tmp[++top] = {i, ii, c[i]};
					tmp[++top] = {ii, i, c[i]};
				}
			}

		}
	}
}

int fa[N];

int find(int x) {
	if (x == fa[x]) {
		return fa[x];
	} else {
		return fa[x] = find(fa[x]);
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 1; i <= N; i++)
		fa[i] = i;
	scan();
	int id = 0;
	long long ans = 0LL;
	for (int i = 1; i <= top; i++) {
		if ((fl[tmp[i].u] > 1 && fl[tmp[i].v] > 1) || ((fl[tmp[i].u] > 0 && fl[tmp[i].v] > 0
		        && find(tmp[i].u) == find(tmp[i].v))))
			continue;
		fl[tmp[i].u] ++;
		fl[tmp[i].v] ++;
		fa[find(tmp[i].u)] = find(tmp[i].v);
		ans += tmp[i].wt;
		id = i;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += fl[i];
	}
	if (sum != 2 * n - 2)
		ans -= tmp[id].wt;
	printf("%lld", ans);
	return 0;
}
//5 6 0
//1 2 1
//2 3 3
//3 4 2
//4 5 4
//3 5 5
//1 4 7
