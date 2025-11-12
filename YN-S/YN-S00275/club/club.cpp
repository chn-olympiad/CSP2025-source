#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005], X, Y, Z, xans, yans, zans, xmin = 10000005, ymin = 1000005, zmin = 1000005;

struct node {
	int x, y, z, k;
} b[100005];
map<int, int, int>m;

bool xmp(node i, node j) {
	return i.x > j.x;
}

bool ymp(node i, node j) {
	return i.y > j.y;
}

bool zmp(node i, node j) {
	return i.z > j.z;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int ans = 0;
		X = 0, Y = 0, Z = 0, xans = 0, yans = 0, zans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> b[i].x >> b[i].y >> b[i].z;
		if (n == 2) {
			ans = max(ans, b[1].x + b[2].y);
			ans = max(ans, b[1].y + b[2].z);
			ans = max(ans, b[1].x + b[2].z);
			ans = max(ans, b[1].z + b[2].x);
			ans = max(ans, b[1].z + b[2].y);
			ans = max(ans, b[1].y + b[2].x);
			cout << ans;
			continue;
		}
		sort(b + 1, b + n + 1, xmp);
		for (int i = n; i >= n / 2; i--)
			xans += b[i].x;
		sort(b + 1, b + n + 1, ymp);
		for (int i = n; i >= n / 2; i--)
			yans += b[i].y;
		sort(b + 1, b + n + 1, zmp);
		for (int i = n; i >= n / 2; i--)
			zans += b[i].z;
		for (int i = 1; i <= n / 2; i++) {
			int minn = min(b[i].x, min(b[i].y, b[i].z));
			if (minn == b[i].x)
				xans -= b[i].x;//, yans -= b[i].y, zans -= b[i].z;
			else if (minn == b[i].y)
				yans -= b[i].y;//, xans -= b[i].x, zans -= b[i].z;
			else if (minn == b[i].z)
				zans -= b[i].z;//, xans -= b[i].x, yans -= b[i].y;
		}
		cout << xans + yans + zans << endl;
	}
	return 0;
}