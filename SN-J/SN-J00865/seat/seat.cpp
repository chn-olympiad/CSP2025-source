//SN-J00865 程越萱 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;
int n, m, s[200], s1[100], num, t, c, r;
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> s[i];
	}
	sort (s+2, s+1+n*m);
	for (int i = n*m; i > 1; i--) {
		s1[n*m-i+1] = s[i];
	}
	t = s[1];
	for (int i = 1; i <= n*m; i++) {
		if (i == 1 && t > s1[i]) {
			num = 1;
			break;
		}
		else if (i == n*m && t < s1[i-1]) {
			num = n*m;
			break;
		}
		else if (s1[i-1] > t && t > s1[i]) {
			num = i;
			break;
		}
		else continue;
	}
	if (!(num%m)) {
		c = num/m;
		if (c%2) r = m;
		else r = 1;
	}
	else {
		c = num/m+1;
		if (c%2) r = num%m;
		else r = m-num%m+1;
	}
	cout << c << ' ' << r;
	return 0;
} 
