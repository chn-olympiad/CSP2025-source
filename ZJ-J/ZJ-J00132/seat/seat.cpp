#include<bits/stdc++.h>
#define N 139
using namespace std;
int n, m, ans;
int lie (int s) {
	int a = s / n;
	if (s % n == 0) return a;
	else return (a + 1); 
}
int hang (int s) {
	if (lie (s) % 2 == 0) return ((n - s % n) + 1);
	else if (s % n == 0) return n;
	else return s % n;
}
bool num[139];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int t = n * m;
	int q, r;
	cin >> q;
	r = q;	
	num[q] = 1;
	for (int i = 2; i <= t; i++) {
		cin >> q;
		num[q] = 1;
	}
	for (int i = 100; i >= r; i--) {
		if (num[i] == 1) ans++;
	}
	cout << lie(ans) << " " << hang(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}