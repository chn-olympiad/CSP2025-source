#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, ans = 0;
	cin >> n >> m;
	int h[109], w = n * m;
	for (int i = 1; i <= w; i++) {
    	cin >> h[i];
	}
	int g = h[1];
	for (int i = 1; i <= w; i++) {
		int a = 0;
    	if (h[i] < h[i + 1]) {
    		a = h[i];
    		h[i] = h[i + 1];
    		h [i + 1] = a;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			ans++;
			if (h[ans] == g) {
				cout << i << ' ' << j;
			}
			
		}
	}
	return 0;
}
