#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[500010];

struct edge {
	int x;
	int e;
	int st, en;
};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int m = 0;
	deque<edge>q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m++;
		q.push_back({0, 0, i, -1});
		int num = 0;
		int vis[500010];
//		cout << i << endl;
		for (int j = 1; j <= m; j++) {

			edge w = q.back();
			q.pop_back();
//			cout << w.x << " " << w.e << " " << w.st << " " << w.en << endl;
			for (int s = 1; s <= num; s++) {

				if (w.en >= vis[s]) {
					w.e++;
				}

			}

			if (w.e >= 2) {
				m--;

				continue;

			}
			if (w.x != k) {
				w.x = w.x ^a[i];
				if (w.x == k) {

					w.en = i;
					vis[++num] = w.st;
				}
			}






			q.push_front(w);

		}
	}
	int sum = 0;
//	cout << "&" << endl;
	edge last = {k, 0, 0, 0};
	for (int j = 1; j <= m; j++) {

		edge w = q.front();
		q.pop_front();
//		cout << w.x << " " << w.e << " " << w.st << " " << w.en ;

		if (w.en != -1 && w.x == k && last.en < w.st) {

			sum++;
//			cout << "&";
		}
//		cout << endl;
		q.push_back(w);
		if (w.en != -1 && w.x == k) {
			last = w;
		}

	}
	cout << sum;
	return 0;
}
