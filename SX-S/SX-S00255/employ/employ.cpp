#include "bits/stdc++.h"
using namespace std;
int n, m, c, xuhao1[505], xuhao2[505], sum, pa[505];
bool p[505], stop;
string s, s1, s2;
long long num;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> pa[i];
		xuhao1[i] = i;
		xuhao2[i] = i;
		s1 += (i + '0');
	}
	for (int day = 1; day <= n; day++) {
		if (s[day]) {
			if (pa[xuhao2[day]] <= 0) {
				for (int j = 1; j <= n; j++) {
					pa[j]--;
				}
			} else
				p[xuhao2[day]] = 1;
		} else {
			for (int j = 1; j <= n; j++)
				pa[j]--;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (p[i] == 1)
			sum++;
		if (sum >= m) {
			num++;
			break;
		}
	}
	sum = 0;
	swap(xuhao2[1], xuhao2[2]);
	int left = 1, right = 2;
	while (s1 != s2) {
		s2 = "";
		for (int day = 1; day <= n; day++) {
			if (s[day]) {
				if (pa[xuhao2[day]] <= 0)
					for (int j = 1; j <= n; j++) {
						pa[j]--;
					} else
					p[xuhao2[day]] = 1;
			} else {
				for (int j = 1; j <= n; j++)
					pa[j]--;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (p[i] == 1)
				sum++;
			cout << sum << endl;
			if (sum >= m) {
				num++;
				break;
			}
		}
		sum = 0;
		left++;
		right++;
		if (left == n) {
			left = 1;
			right = 2;
		}
		swap(xuhao2[left], xuhao2[right]);
		for (int i = 1; i <= n; i++) {
			s2 += (xuhao2[i] + '0');
		}
	}
	cout << num << endl;
}