#include <bits/stdc++.h>

using namespace std;
int seat[15][15],cnt = 1;
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[109];
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i];
	}
	int ans = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				seat[j][i] = a[cnt];
				cnt++;
				if (seat[j][i] == ans) {
					cout << i << " " << j;
					break;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				seat[j][i] = a[cnt];
				cnt++;
				if (seat[j][i] == ans) {
					cout << i << " " << j;
					break;
				}
			}
		}
	}
	return 0;
}
