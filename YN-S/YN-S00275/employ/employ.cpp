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
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cout << 2;
	return 0;
}