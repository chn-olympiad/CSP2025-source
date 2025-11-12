//刘泽辰 SN-J00133 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
int a[N], n, cnt;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int len = 3; len <= n; len++) {
		for (int l = 1; l+len-1 <= n; l++) {
			int r = l+len-1, maxx=-1, sum=0;
			for (int i = l; i <= r; i++) {
				maxx = max(maxx, a[i]);
				sum += a[i];
			}
			if (sum > 2*maxx) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
