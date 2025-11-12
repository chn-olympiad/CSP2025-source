//Luogu 743373-Vitamin_B:)
//ZJ-S01668
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

struct edge {

	int x, y, z;

	bool operator < (const edge& a) {
		return z < a.z;
	}

} input[1000005], a[2000005], tmp[2000005];

int f[10015], n, m, k, c[15], v[15][10005], b[15];

ll minx = 1e18;

int find (const int& x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}

//void init () {
//
//	for (int i = 1; i <= n; ++ i)
//		f[i] = i;
//
//	sort (input, input + m);
//
//	for (int i = 1, tot = 0; i < m; ++ i)
//		if (find (input[i].x) != find (input[i].y))
//			f[f[input[i].x]] = f[input[i].y], tmp[++ tot] = input[i], minx += input[i].z;
//
//	return ;
//}

void calc (int len) {

	int tot = m;

	ll sum = 0;

	for (int i = 1; i <= m; ++ i)
		a[i] = tmp[i];

	for (int i = 0; i < len; ++ i) {

		sum += c[b[i]];

		for (int j = 1; j <= n; ++ j)
			a[++ tot] = {j, i + n + 1, v[b[i]][j]};

	}
//	cerr << tot << ':';
//	for (int i = 1; i <= tot; ++ i) cerr << a[i].x << "->" << a[i].y << ':' << a[i].z << '\n';
	sort (a + 1, a + tot + 1);

	len += n;

	for (int i = 1; i <= len; ++ i)
		f[i] = i;

	for (int i = 1; i <= tot; ++ i) //{
		if (find (a[i].x) != find (a[i].y)) //cerr << a[i].x << '~' << a[i].y << ':' << a[i].z << '\n',
			f[f[a[i].x]] = f[a[i].y], sum += a[i].z;
//		else cerr << a[i].x << '~' << a[i].y << ':' << find (a[i].x) << ',' << find (a[i].y) << '\n';
//		for (int j = 1; j <= len; ++ j) cerr << j << ':' << find (j) << '\n';
//	}
//	cerr << (len -= n) << ':';
//	for (int i = 0; i < len; ++ i) cerr << b[i] << ' ';
//	cerr << '\n';
//	cerr << "= " << sum << '\n';
//	cerr << "-----------\n";
	minx = min (minx, sum);

	return ;
}

void dfs (const int x, const int c) {

	if (x > k) {

		calc (c);

		return ;
	}

	dfs (x + 1, c);

	b[c] = x;

	dfs (x + 1, c + 1);

	return ;
}

int main () {
//	freopen ("road2.in", "r", stdin);
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m >> k;

	for (int i = 1; i <= m; ++ i)
		cin >> tmp[i].x >> tmp[i].y >> tmp[i].z;

//	init ();

	for (int i = 1; i <= k; ++ i) {

		cin >> c[i];

		for (int j = 1; j <= n; ++ j)
			cin >> v[i][j];

	}

	dfs (1, 0);

	cout << minx;

	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

struct edge {

	int x, y, z;

	bool operator < (const edge& a) {
		return z < a.z;
	}

} input[1000005], a[110015], tmp[10015];

int f[10015], n, m, k, c[15], v[15][10005], b[15];

ll minx;

int find (const int& x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}

void init () {

	for (int i = 1; i <= n; ++ i)
		f[i] = i;

	sort (input, input + m);

	for (int i = 1, tot = 1; tot < n && i < m; ++ i)
		if (find (input[i].x) != find (input[i].y))
			f[f[input[i].x]] = f[input[i].y], tmp[tot ++] = input[i], minx += input[i].z;

	return ;
}

void calc (int len) {

	int tot = n;

	ll sum = 0;

	for (int i = 1; i < n; ++ i)
		a[i] = tmp[i];

	for (int i = 0; i < len; ++ i) {

		sum += c[b[i]];

		for (int j = 1; j <= n; ++ j)
			a[tot ++] = {j, i + n + 1, v[b[i]][j]};

	}

	sort (a + 1, a + tot);
//	cerr << tot << ':';
//	for (int i = 1; i < tot; ++ i) cerr << a[i].x << "->" << a[i].y << ':' << a[i].z << '\n';
	len += n;

	for (int i = 1; i <= len; ++ i)
		f[i] = i;

	for (int i = 1, x = 1; x < len && i < tot; ++ i) //{
		if (find (a[i].x) != find (a[i].y)) //cerr << a[i].x << '~' << a[i].y << ':' << a[i].z << '\n',
			f[f[a[i].x]] = f[a[i].y], sum += a[i].z, ++ x;
//		else cerr << a[i].x << '~' << a[i].y << ':' << find (a[i].x) << ',' << find (a[i].y) << '\n';
//		for (int j = 1; j <= len; ++ j) cerr << j << ':' << find (j) << '\n';
//	}
//	cerr << (len -= n - 1) << ':';
//	for (int i = 0; i < len; ++ i) cerr << b[i] << ' ';
//	cerr << '\n';
//	cerr << "= " << sum << '\n';
//	cerr << "-----------\n";
	minx = min (minx, sum);

	return ;
}

void dfs (const int x, const int c) {

	if (x > k) {

		calc (c);

		return ;
	}

	dfs (x + 1, c);

	b[c] = x;

	dfs (x + 1, c + 1);

	return ;
}

int main () {
//	freopen ("road2.in", "r", stdin);
//	freopen ("road.in", "r", stdin);
//	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; ++ i)
		cin >> input[i].x >> input[i].y >> input[i].z;

	init ();

	for (int i = 1; i <= k; ++ i) {

		cin >> c[i];

		for (int j = 1; j <= n; ++ j)
			cin >> v[i][j];

	}

	dfs (1, 0);

	cout << minx;

	return 0;
}
*/
