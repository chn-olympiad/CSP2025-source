#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int Max = 1e5+5;
int n, mid, ans;
int A[Max];

struct node {
	int x, y, z;
} a[Max];

bool cmp(int qw, int er) {
	return qw > er;
}

bool cmp1(node aa, node bb) {
	if (aa.x != bb.x) {
		return aa.x > bb.x;
	} else if (aa.y != bb.y) {
		return aa.y < bb.y;
	} else {
		return aa.z < bb.z;
	}
}

bool cmp2(node aa, node bb) {
	if (aa.y != bb.y) {
		return aa.y > bb.y;
	} else if (aa.x != bb.x) {
		return aa.x < bb.x;
	} else {
		return aa.z < bb.z;
	}
}

bool cmp3(node aa, node bb) {
	if (aa.z != bb.z) {
		return aa.z > bb.z;
	} else if (aa.y != bb.y) {
		return aa.y < bb.y;
	} else {
		return aa.x < bb.x;
	}
}

void solve(int flg) {
	sort(a + 1, a + n + 1, cmp1);
	for (int i = 1; i <= mid; i++) {
		if (flg == 1)
			ans += a[i].x;
		if (flg == 2)
			ans += a[i].y;
		if (flg == 3)
			ans += a[i].z;
		a[i].x = 0;
		a[i].y = 0;
		a[i].z = 0;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		mid = n / 2;
		ans = 0;
		int Acnt = 0;
		int suma = 0, sumb = 0, sumc = 0;
		for (int i = 1; i <= n; i++) {
			a[i].x = 0;
			a[i].y = 0;
			a[i].z = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			suma += a[i].x;
			sumb += a[i].y;
			sumc += a[i].z;
			if (a[i].y == 0 && a[i].z == 0) {
				Acnt++;
				A[i] = a[i].x;
			}
		}
		if (Acnt == n) {
			sort(A + 1, A + 1 + n, cmp);
			for (int i = 1; i <= mid; i++) {
				ans += A[i];
			}
			cout << ans << '\n';
			continue;
		}
		if (suma >= sumb && suma >= sumc && sumb >= sumc) {
			solve(1);
			solve(2);
			solve(3);
		} else if (suma >= sumb && suma >= sumc && sumb <= sumc) {
			solve(1);
			solve(3);
			solve(1);
		} else if (sumb >= suma && sumb >= sumc && suma >= sumc) {
			solve(2);
			solve(1);
			solve(3);
		} else if (sumb >= suma && sumb >= sumc && sumc >= suma) {
			solve(2);
			solve(3);
			solve(1);
		} else if (sumc >= suma && sumc >= sumb && suma >= sumb) {
			solve(3);
			solve(1);
			solve(2);
		} else if (sumc >= suma && sumc >= sumb && sumb >= suma) {
			solve(3);
			solve(2);
			solve(1);
		}
		cout << ans << '\n';
	}
	return 0;
}
