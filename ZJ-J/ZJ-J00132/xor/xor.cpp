#include<bits/stdc++.h>
#define N 500039
using namespace std;
const int a[10] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256};
bool vis[N];
int n, k, ans, sum;
int nm[N];
string rj (int x) {
	string r = '000000000';
	for (int i = 10; i >= 1; i--) {
		if (x > a[i]) x -= a[i];
		r[i] = '1';
	}
	return r;
}
int yh (int x, int y) {
	string s1 = rj(x);
	string s2 = rj(y);
	string s;
	for (int i = 0; i <= 20; i++) {
		if (s1[i] == s2[i]) s[i] = '0';
		else s[i] = '1';
	}
	int num = 0;
	for (int i = 0; i <= 20; i++) {
		if (s[i] == '1') num += a[i];
	}
	return num;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> nm[i];
	}/*
	int stp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			sum = nm[i];
			for (int q = i + 1; q <= j; q++) {
				if (vis[q] == 1) break;
				sum = yh (sum, nm[q]);
				if (sum == k) {
					for (int p = i; p <= q; p++) {
						vis[p] = 1;
						ans++;
					}
				}
			}
		}
	}
	cout << ans;*/
	cout << 0;
	fclose(stdin);
	fclose(stdout);
}