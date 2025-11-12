#include <bits/stdc++.h>
using namespace std;
//
const int N = 1e4 + 100;
const int mod = 998244353;
int n, m, k;
int ans = 0;
int c[30];
bool vis[N];

struct E {
	int u;
	int v;
	int w;
	bool z;
	bool operator <(const E &other)const {
		return w < other.w;
	}
	bool operator >(const E &other)const {
		return w > other.w;
	}
};
priority_queue<E, vector<E>, greater<E>> q;
int f[N];

int find(int i) {
	if (f[i] == i) {
		return f[i];
	}



	f[i] = find(f[i]);
	return f[i];
}

void add(int x, int y) {


	if (find(x) < find(y)) {
		f[find(y)] = find(x);
	} else {
		f[find(x)] = find(y);
	}
}

bool ch(int x, int y) {

	return (find(x) == find(y));
}

struct DD {
	int v;
	int w;

};
vector<DD>S[N];
int siz[N];

void dfs_cut(int i) {
	vis[i] = 1;


	for (int j = 0; j < S[i].size(); j++) {

		if (vis[j]) {
			continue;
		}

		if (S[i][j].v > n && siz[S[i][j].v] == 2 ) {
			if ((siz[S[S[i][j].v][0].v] == 2 || siz[S[S[i][j].v][1].v] == 2 )) {
				ans -= S[i][j].w;
				ans -= S[S[i][j].v][j].w;
			}
		} else {
			dfs_cut(j);
		}
	}

//	for (DD j : S[i]) {
//		if (j.v > n && S[j.v].size() == 2) {
//			ans -= j.w;
//			ans -= S[j.v].w;
//		}
//	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {

		f[i] = i;
	}

	for (int i = 1; i <= m; i++) {

		E a;
		cin >> a.w >> a.v >> a.w;
		a.z = 0;
		q.push(a);
	}



	for (int i = 1; i <= k; i++) {

		int sss;
		cin >> sss;

		for (int j = 1; j <= n; j++) {

			int aa;
			cin >> aa;
			E ne;
			ne.z = 1;
			ne.u = n + i;
			ne.v = j;
			ne.w = aa;
			q.push(ne);
		}
	}



	while (!q.empty()) {

		E i = q.top();
		q.pop();

		if (ch(i.u, i.v)) {
			continue;
		}

		add(i.u, i.v);
		ans += i.w;
		bool flag = 1;

		for (int i = 2; i <= n; i++) {

			if (!ch(i, 1)) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			cout << ans << endl;
			return 0;
		}
	}

	cout << ans;

	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
