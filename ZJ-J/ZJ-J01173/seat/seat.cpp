#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int n, m, a[104], self, cnt = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	cin >> self;
	a[0] = self;
	for (int i = 1; i < n * m; ++i) {
		cin >> a[i];
		if (a[i] > self) {
			++cnt;
		}
	}
	
	int md = cnt % (n << 1), ln = cnt / n;
	if (md >= n) {
		md = (n << 1) - 1 - md;
	}
	++md; ++ln;
	cout << ln << " " << md << "\n";
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

