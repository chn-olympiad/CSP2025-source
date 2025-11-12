#include <bits/stdc++.h>

using namespace std;
int a[101][101];
int ch[1001];
int n, m;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int r;
	for(int i = 1; i <= n * m; i++) {
		cin >> ch[i];
	}
	r = ch[1];
	sort(ch + 1, ch + n * m + 1);
	int cnt = n * m;
	for(int j = 1; j <= m; j++) {
		if(j % 2 == 1) {
			for(int i = 1; i <= n; i++) {
				a[i][j] = ch[cnt--];
			}
		}
		else {
			for(int i = n; i >= 1; i--) {
				a[i][j] = ch[cnt--];
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == r) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}



