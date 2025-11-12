#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], b[105], c[105];
// b表示行，c表示列 
bool cmp(int a, int b){return a > b;}
int main() { 
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int ans = a[1];
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n * m; i++){
		if (i % n == 0){
			if ((i / n) % 2 == 1){
				c[a[i]] = i / n;
				b[a[i]] = n;
			} else {
				c[a[i]] = i / n;
				b[a[i]] = 1;
			}
		} else {
			if ((i/n) % 2 == 0){
				c[a[i]] = i / n + 1;
				b[a[i]] = i % n;
			} else {
				c[a[i]] = i / n + 1;
				b[a[i]] = i % n + n - 1;
			}
		}
	}
	cout << c[ans] << ' ' << b[ans];
	return 0;
}
