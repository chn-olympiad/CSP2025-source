#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, idx, t, a[105], j;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}	
	t = a[1];
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			idx = i, t = 0;
			break;
		}
	}
	for (int i = 1; i <= m; ) { // i: ÁÐ£¬j£ºÐÐ  
		if (i % 2 == 1) {
			while (j != n) {
				j++, t++;
				if (t == idx) {
					cout << i << ' ' << j;
					return 0;
				} 
			//	cout << i << ' ' << j << ' ' << t << endl;
			}
		} else {
			while (j != 1) {
				j--, t++;
				if (t == idx) {
					cout << i << ' ' << j;
					return 0;
				}
			//	cout << i << ' ' << j << ' ' << t << endl;
			}
		}
		i++, t++;
	//	cout << i << ' ' << j << ' ' << t << endl;
		if (t == idx) {
			cout << i << ' ' << j;
			return 0;
		}
	}
	return 0;
}
