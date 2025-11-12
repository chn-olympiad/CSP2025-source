#include<bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int n, m;
int a[1001], seat_i, seat_j;
int c, r, R;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	R = a[1];
	int len = 0;
	sort (a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				if (a[++len] == R){
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else {
			for (int j = 1; j <= n; j++) {
				if (a[++len] == R) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
}

