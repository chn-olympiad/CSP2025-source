//刘泽辰 SN-J00133 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std; 
const int N = 110;
int a[N];
int n, m, t, x, pos;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << "1 1\n";
		return 0;
	}
	t = n*m;
	cin >> x;
	a[1] = x;
	for (int i = 2; i <= t; i++) {
		cin >> a[i];
	}
	sort(a+1, a+t+1);
	reverse(a+1, a+t+1);
	for (int i = 1; i <= t; i++) {
		if (a[i] == x) {
			pos = i;
			break;
		}
	}
	int ansx=1, ansy=1;
	for (int i = 1; i <= pos; i++) {
		if (ansy > n || ansy < 1) {
			ansx++;
			if (ansx%2 == 0) ansy = n;
			else ansy = 1;
		}
		if (i == pos) break;
		else {
			if (ansx%2 == 0) ansy--;
			else ansy++;
		}
	}
	cout << ansx << " " << ansy;
	return 0;
}
