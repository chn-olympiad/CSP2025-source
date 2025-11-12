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
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> X >> Y;
	for (int i = 1; i <= Y; i++)
		cout << 0 << endl;
	return 0;
}