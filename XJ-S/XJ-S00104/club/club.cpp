# include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, t, a[N][5], xianzhi, cnt, b[N], d[N];
bool c = true;
// 1 4 4 2 1 3 2 4 5 3 4 3 5 1
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &a[i][j]);
			}
			
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (a[i][3] == 0 && a[i][2] == 0){
					
				}else {
					c = false;
				}
			}
			
		}
		xianzhi = n / 2;
		
		if (n == 2) {
			int mxa = 0, mxb = 0;
			bool flag = true;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++) {
					if (a[i][j] > mxa) {
						mxa = a[i][j];
					}
					if (a[i][j] == mxa) {
						if(a[i][j] == a[i - 1][j]) {
							flag = false;
						}else {
							mxb = mxa;
						}
					}
					
				}
			}
			if (flag) {
				cout << mxa + mxb;
			}else {
				for (int i = 1; i <= 3; i++) {
					b[i] = a[2][i];
				}
				sort(b + 1, b + n + 1);
				cout << mxa + b[2];
				
			}
		}else if(c == true) {
			for (int i = 1; i <= xianzhi; i++) {
				b[i] = a[i][1];
			}
			sort(b + 1, b + n + 1);
			for (int i = n; i >= n - xianzhi; i--) {
				cnt+=b[i];
			} 
			cout << cnt;
		}else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++) {
					d[i] = max(a[i][j], d[i]);
				}
			}
			sort(d + 1, d + n + 1);
			for (int i = n; i >= n - xianzhi; i++) {
				cnt += b[i];
			}
			cout << cnt;
		}
		
		
	}
	
	return 0;
}
