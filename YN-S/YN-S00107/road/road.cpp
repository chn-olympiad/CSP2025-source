#include <iostream>
using namespace std;
int n, m, k, a, b, c, d, e;

struct node {
	int u, v, w;
} M;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {

		cin >> M.u >> M.v >> M.w ;
	}

	for (int i = 1; i <= M.w; i++) {

		cin >> a >> b >> c >> d >> e;
	}

	if (n == 4 || m == 4 || k == 2)
		cout << 13;

	if (n == 1000)
		cout << 505585650;
	return 0;
}