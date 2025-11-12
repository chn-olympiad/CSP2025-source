#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t;

struct obj {
	int a, b, c;
	int Max1, Max2, Max3;
	char M1 = '0', M2 = '0', M3 = '0';
} s[N];

bool cmp(obj a, obj b) {
	if (a.Max1 == b.Max1) {
		if (a.Max2 == b.Max2) {
			return a.Max3 > b.Max3;
		}
		return a.Max2 > b.Max2;
	}
	return a.Max1 > b.Max1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n;
		int A = 0, B = 0, C = 0;
		int sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int MAX1 = -100;
			int MIN1 = INT_MAX;
			int MID = 0;
			cin >> s[i].a >> s[i].b >> s[i].c;
			MAX1 = max(MAX1, max(s[i].a, max(s[i].b, s[i].c)));
			MIN1 = min(MIN1, min(s[i].a, min(s[i].b, s[i].c)));
			if (MAX1 != s[i].a && MIN1 != s[i].a)
				MID = s[i].a;
			if (MAX1 != s[i].b && MIN1 != s[i].b)
				MID = s[i].b;
			if (MAX1 != s[i].c && MIN1 != s[i].c)
				MID = s[i].c;
			//找最大次大最小
			bool aa = 0, bb = 0, cc = 0;
			if (s[i].a == MAX1 && s[i].M1 == '0' && aa == 0) {
				s[i].M1 = 'a';
				aa = 1;
			}
			if (s[i].a == MID && s[i].M2 == '0' && aa == 0) {
				s[i].M2 = 'a';
				aa = 1;
			}
			if (s[i].a == MIN1 && s[i].M3 == '0' && aa == 0) {
				s[i].M3 = 'a';
				aa = 1;
			}

			if (s[i].b == MAX1 && s[i].M1 == '0' && bb == 0) {
				s[i].M1 = 'b';
				bb = 1;
			}
			if (s[i].b == MID && s[i].M2 == '0' && bb == 0) {
				s[i].M2 = 'b';
				bb = 1;
			}
			if (s[i].b == MIN1 && s[i].M3 == '0' && bb == 0) {
				s[i].M3 = 'b';
				bb = 1;
			}

			if (s[i].c == MAX1 && s[i].M1 == '0' && cc == 0) {
				s[i].M1 = 'c';
				cc = 1;
			}
			if (s[i].c == MID && s[i].M2 == '0' && cc == 0) {
				s[i].M2 = 'c';
				cc = 1;
			}
			if (s[i].c == MIN1 && s[i].M3 == '0' && cc == 0) {
				s[i].M3 = 'c';
				cc = 1;
			}
			s[i].Max1 = MAX1;
			s[i].Max2 = MID;
			s[i].Max3 = MIN1;
		}
		sort(s + 1, s + 1 + n, cmp);
		for (int i = n; i >= 1; i--) {
			if (s[i].M1 == 'a') {
				if (A < n / 2) {
					sum += s[i].Max1;
					A++;
					continue;
				}
			}
			if (s[i].M1 == 'b') {
				if (B < n / 2) {
					sum += s[i].Max1;
					B++;
					continue;
				}
			}
			if (s[i].M1 == 'c') {
				if (C < n / 2) {
					sum += s[i].Max1;
					C++;
					continue;
				}
			}

			if (s[i].M2 == 'a') {
				if (A < n / 2) {
					sum += s[i].Max2;
					A++;
					continue;
				}
			}
			if (s[i].M2 == 'b') {
				if (B < n / 2) {
					sum += s[i].Max2;
					B++;
					continue;
				}
			}
			if (s[i].M2 == 'c') {
				if (C < n / 2) {
					sum += s[i].Max2;
					C++;
					continue;
				}
			}

			if (s[i].M3 == 'a') {
				if (A < n / 2) {
					sum += s[i].Max3;
					A++;
					continue;
				}
			}
			if (s[i].M3 == 'b') {
				if (B < n / 2) {
					sum += s[i].Max3;
					B++;
					continue;
				}
			}
			if (s[i].M3 == 'c') {
				if (C < n / 2) {
					sum += s[i].Max3;
					C++;
					continue;
				}
			}
		}
//		cout << "\n";
//		for (int i = 1; i <= n; i++) {
//			cout << s[i].a << " " << s[i].b << " " << s[i].c << "\n";
//			cout << s[i].Max1 << " " << s[i].Max2 << " " << s[i].Max3 << "\n";
//			cout << s[i].M1 << " " << s[i].M2 << " " << s[i].M3 << "\n";
//			cout << '\n' << "\n";
//		}
		cout << sum << endl;
		for (int i = 1; i <= n; i++) {
			s[i].Max1 = 0;
			s[i].Max2 = 0;
			s[i].Max3 = 0;
			s[i].a = 0;
			s[i].b = 0;
			s[i].c = 0;
			s[i].M1 = '0';
			s[i].M2 = '0';
			s[i].M3 = '0';
		}
	}
	return 0;
}