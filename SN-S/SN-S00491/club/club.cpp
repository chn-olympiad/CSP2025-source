#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace wsq {
	const int N = 1e6;
	int n;
	struct Node {
		int a[4], b[4], c[4];
		void init(int x, int y, int z) {
			if(x <= y && y <= z) {
				a[1] = x, a[2] = y, a[3] = z;
				b[1] = 1, b[2] = 2, b[3] = 3;
				c[1] = 1, c[2] = 2, c[3] = 3;
			}
			if(x <= z && z <= y) {
				a[1] = x, a[2] = z, a[3] = y;
				b[1] = 1, b[2] = 3, b[3] = 2;
				c[1] = 1, c[3] = 2, c[2] = 3;
			}
			if(y <= x && x <= z) {
				a[1] = y, a[2] = x, a[3] = z;
				b[1] = 2, b[2] = 1, b[3] = 3;
				c[2] = 1, c[1] = 2, c[3] = 3;
			}
			if(y <= z && z <= x) {
				a[1] = y, a[2] = z, a[3] = x;
				b[1] = 2, b[2] = 3, b[3] = 1;
				c[2] = 1, c[3] = 2, c[1] = 3;
			}
			if(z <= x && x <= y) {
				a[1] = z, a[2] = x, a[3] = y;
				b[1] = 3, b[2] = 1, b[3] = 2;
				c[3] = 1, c[1] = 2, c[2] = 3;
			}
			if(z <= y && y <= x) {
				a[1] = z, a[2] = y, a[3] = x;
				b[1] = 3, b[2] = 2, b[3] = 1;
				c[3] = 1, c[2] = 2, c[1] = 3;
			}
			/*
			cout << a[1] << a[2] << a[3] <<  " ";
			cout << b[1] << b[2] << b[3] <<  " ";
			cout << c[1] << c[2] << c[3] <<  " ";
			cout << endl;
			*/
		}
		bool operator<(Node x) {
			if(a[3] - a[2] != x.a[3] - x.a[2])
				return a[3] - a[2] > x.a[3] - x.a[2];
			if(a[3] - a[1] != x.a[3] - x.a[1])
				return a[3] - a[1] > x.a[3] - x.a[1];
			return 0;
		}
	};
	Node a[N];
	void main() {
		cin >> n;
		for(int i = 1, x, y, z; i <= n; i++) {
			cin >> x >> y >> z;
			a[i].init(x, y, z);
		}
		sort(a + 1, a + n + 1);	
		queue<int> v[4];
		for(int i = 1; i <= n; i++) {
			Node t = a[i];
			if(v[t.b[3]].size() < n / 2)
				v[t.b[3]].push(i);
			else if(v[t.b[2]].size() < n / 2)
				v[t.b[2]].push(i);
			else if(v[t.b[1]].size() < n / 2)
				v[t.b[1]].push(i);
		}
		int ans = 0;
		for(int i = 1; i <= 3; i++) {
			while(v[i].size()) {
				int t = v[i].front();
				ans += a[t].a[a[t].c[i]];
				v[i].pop();
			}
		}
		cout << ans << endl;
	}
};

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = 1;
	cin >> T;
	while(T--)
		wsq::main();
	return 0;
}

