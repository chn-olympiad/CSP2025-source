#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	cin >> n >> m;
	int a[n * m + 3] = {};
	int b[n + 3][m + 3] = {};
	int c[n * m + 3] = {};
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + n *m + 1);


//	for (int i = 1; i <= n * m; i++) {
//		cout << a[i] << " ";
//	}

//	cout << endl;

	int j = n * m;
//	int k=n*m/2;
	for (int i = 1; i <= n * m; i++) {
		c[j] = a[i];
		j--;
//		s++;
//		if(s==m){
//			d[k]=a[i];
//			k--;
//			s1++;
//			if(s1==m) break;
//		}
	}


//	for (int i = 1; i <= n * m; i++) {
//		cout << c[i] << " ";
//	}
//	cout << endl;
	int s = 1;
	for (int i = 1; i <= m ; i += 2) {
		int j;
		for ( j = 1; j <= n; j++) {
			b[j][i] = c[s];
			s++;
		}
		for (int k = n; k >= 1; k--) {
			b[k][i + 1] = c[s];
			s++;
		}
	}

//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << b[i][j] << " ";
//		}
//		cout << endl;
//	}

//	cout << endl << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[j][i] == r) {
				cout << i << " " << j;
			}
		}
	}
	return 0;
}
