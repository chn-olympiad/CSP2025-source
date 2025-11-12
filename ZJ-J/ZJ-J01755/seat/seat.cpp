#include <bits/stdc++.h>

#define F freopen("seat.in", "r", stdin);freopen("seat.out", "w", stdout)


using namespace std;

int n, m;

int a[100005];

int main (void) {
	
	F;
	
	cin >> n >> m;
	
	int k = n * m;
	
	for(int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	
	int R = a[1];
	
	sort(a + 1, a + 1 + k, greater <int> () );
	
	int s = 0;
	
	for(int i = 1; i <= k; i++) {
		if(a[i] == R) {
			s = i;
			break;
		}
	}
	
	int cnt = 0;
	
	for(int i = 1; i <= m; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= n; j++) {
				cnt++;
				if(cnt == s) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for(int j = n; j >= 1; j--) {
				cnt++;
				if(cnt == s) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
