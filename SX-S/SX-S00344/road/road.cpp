#include <bits/stdc++.h>
using namespace std;
const int M = 1e4+2;
int l[M][M];
int c[M][11];
long long as = -1;
bool j[M];
int n, m, k;

void op(int a, long long ass) {
	bool w = 0;
	j[a] = 1;
	for (int i = 1; i <= n; i++) {
		if (i == a  || j[i] || l[a][i] == -1)
			continue;
		bool d = 1;
		w = 1;
		for (int o = 1; o <= n; o++) {
			if (o == a || o == i)
				continue;
			if (l[i][o] != -1)
				d = 0;
		}
		if (d) {
			ass += l[a][i];
		} else {
			int la = l[a][i];
			l[a][i] = -1;
			l[i][a] = -1;
			op(i, ass + la);
			l[a][i] = la;
			l[i][a] = la;

		}
	}
	j[a] = 0;
	if (w == 0) {
		if (as != -1)
			as = min(as, ass);
		else
			as = ass;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	memset(l, -1, sizeof(l));
	for (int i = 1; i <= m; i++) {
		int lss, lsk;
		cin >> lss >> lsk;
		cin >> l[lss][lsk];
		l[lsk][lss] = l[lss][lsk];
	}
	for (int i = 1; i <= n; i++)
		op(i, 0);
	cout << as << endl;
}
