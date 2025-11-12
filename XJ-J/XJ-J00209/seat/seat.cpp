# include <bits/stdc++.h>

using namespace std;

const int N = 250;
int n, m, sum, a[N], b[N][N], bug, idx = 1, x;

int cmp(int a, int b) {
	return a > b;
}


// 2 3 1 2 3 4 5 6
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d%d", &n, &m);
	
	sum = n * m;
	
	for (int i = 1; i <= sum; i++) {
		scanf("%d", &a[i]);
	}
	
	bug = a[1];
	
	sort(a + 1, a + 1 + sum, cmp);	
		
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			b[j][i] = a[idx];
			idx++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == bug) {
				if (j % 2 == 0)
					cout << j << " " << n - i + 1;
				else
					cout << j << " " << i;
			}
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << b[i][j] << " ";
//		}
//		cout << endl;
//	}
	return 0;
}
