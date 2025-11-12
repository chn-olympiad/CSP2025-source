//#include <bits/stdc++.h>

//using namespace std;
//int a[500005], b[500005], c[500005];
//
//int main() {
////	freopen("club.in", "r", stdin);
////	freopen("club.out", "w", stdout);
//	int t;
//	cin >> t;
//	for (int j = 1; j <= t; j++) {
//		int n;
//		cin >> n;
//		int cnta = 0, cntb = 0, cntc = 0, cnt = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i] >> b[i] >> c[i];
//		}
//		for (int i = 1; i <= n; i++) {
//			if (a[i] > b[i] && a[i] > c[i] && cnta <= n / 2) {
//				cnta++;
//				cnt += a[i];
//			} else if (b[i] > a[i] && b[i] > c[i] && cntb <= n / 2) {
//				cntb++;
//				cnt += b[i];
//			} else if (c[i] > b[i] && c[i] > a[i] && cntc <= n / 2) {
//				cnt += c[i];
//				cntc++;
//			} else if (a[i] == b[i] && a[i] >= c[i] && cnta <= n / 2) {
//				cnta++;
//				cnt += a[i];
//			} else if (c[i] == b[i] && c[i] >= a[i] && cntc <= n / 2) {
//				cntc++;
//				cnt += c[i];
//			} else if (b[i] == c[i] && b[i] >= a[i] && cntb <= n / 2) {
//				cntb++;
//				cnt += b[i];
//			} else if (a[i] == c[i] && a[i] >= b[i] && cnta <= n / 2) {
//				cnta++;
//				cnt += a[i];
//			} else if (c[i] == a[i] && c[i] >= b[i] && cntc <= n / 2) {
//				cntc++;
//				cnt += c[i];
//			} else if (b[i] == a[i] && a[i] >= c[i] && cntb <= n / 2) {
//				cntb++;
//				cnt += b[i];
//			} else if (b[i] < a[i] && b[i] > c[i] && cntb <= n / 2) {
//				cntb++;
//				cnt += b[i];
//			} else if (c[i] < a[i] && c[i] > b[i] && cntb <= n / 2) {
//				cntc++;
//				cnt + c[i];
//			} else if (a[i] < b[i] && a[i] > c[i] && cntb <= n / 2) {
//				cnta++;
//				cnt += a[i];
//			} else if (b[i] < c[i] && b[i] > a[i] && cntb <= n / 2) {
//				cntb++;
//				cnt += b[i];
//			} else if (c[i] < b[i] && c[i] > a[i] && cntb <= n / 2) {
//				cntc++;
//				cnt + c[i];
//			} else if (a[i] < c[i] && a[i] > b[i] && cntb <= n / 2) {
//				cnta++;
//				cnt += a[i];
//			}
//		}
//		cout << cnt << "\n";
//	}
//	return 0;
//}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
#include <bits/stdc++.h>
using namespace std;
int a[500005], b[500005], c[500005], n, s;
int cnta, cntb, cntc;

void dfs(int dep, int sum, int n) {
	if (dep > n) {
		s = max(sum, s);
	} else {
		if (cnta < n / 2) {
			cnta++;
			dfs(dep + 1, sum + a[dep], n);
			cnta--;
		}
		if (cntb < n / 2) {
			cntb++;
			dfs(dep + 1, sum + b[dep], n);
			cntb--;
		}
		if (cntc < n / 2) {
			cntc++;
			dfs(dep + 1, sum + c[dep], n);
			cntc--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int j = 1; j <= t; j++) {
		int n;
		s = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
//			cout << a[i] << " " << b[i] << " " << c[i] << endl;
		}
		dfs(1, 0, n);
		cout << s << "\n";
	}
	return 0;
}
