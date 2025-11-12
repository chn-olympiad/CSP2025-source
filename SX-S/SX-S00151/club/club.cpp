#include <bits/stdc++.h>
using namespace std;

struct node {
	int a1;
	int a2;
	int a3;
} s[100010];
int ans1[100010];

int b[10] = {0};
int n, st;
int ans = 0;

int xianzhi(int x) {
	if (b[x] < st) {
		return 1;
	} else {
		return 0;
	}
}

int ma(int i) {
	if (s[i].a1 >= s[i].a2 && s[i].a1 >= s[i].a3) {
		if (xianzhi(1)) {
			b[1]++;
			return s[i].a1;
		} else {
			if (s[i].a2 >= s[i].a3) {
				if (xianzhi(2)) {
					b[2]++;
					return s[i].a2;
				} else {
					b[3]++;
					return s[i].a3;
				}
			}
		}
	}
	if (s[i].a2 >= s[i].a1 && s[i].a2 >= s[i].a3) {
		if (xianzhi(2)) {
			b[2]++;
			return s[i].a2;
		} else {
			if (s[i].a1 >= s[i].a3) {
				if (xianzhi(1)) {
					b[1]++;
					return s[i].a1;
				} else {
					b[3]++;
					return s[i].a3;
				}
			}
		}
	}
	if (s[i].a3 >= s[i].a2 && s[i].a3 >= s[i].a1) {
		if (xianzhi(3)) {
			b[3]++;
			return s[i].a3;
		} else {
			if (s[i].a1 >= s[i].a2) {
				if (xianzhi(1)) {
					b[1]++;
					return s[i].a1;
				} else {
					b[2]++;
					return s[i].a2;
				}
			}
		}
	}
}
bool cmp(node x, node y) {
	if (x.a1 == 0 && y.a1 == 0) {
		return x.a2 > y.a2;
	} else {
		return x.a1 < y.a1;
	}
}
int  a() {
	b[1] = {0};
	b[2] = {0};
	b[3] = {0};
	b[4] = {0};
	ans = 0;
	cin >> n;
	st = n / 2;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a1 >> s[i].a2 >> s[i].a3;
	}
	sort(s + 1, s + 1 + n, cmp);
	int x;
	for (int i = 1; i <= n; i++) {
		x = ma(i);
		ans += x;
	}
	return  ans;

}


int main() {
	freopen("club.cpp", "r", stdin);
	freopen("club.cpp", "w", stdout);
	int n1;
	cin >> n1;
	for (int j = 1; j <= n1; j++) {
		ans1[j] = a();
	}
	for (int j = 1; j <= n1; j++) {
		cout << ans1[j] << endl;
	}

	return 0;
}