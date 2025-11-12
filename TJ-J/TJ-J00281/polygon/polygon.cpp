#include <bits/stdc++.h>
using namespace std;
int a[5002], max_length=0, n;
bool c[5002];
int d[5002];
bool f(int i, int index, int stick) {
	if (c[index] == true) {
		//f(i+1,index,stick);
		return false;
	}
	d[index] = a[i];
	c[index] = false;
	if (index == stick) {
		int cnt = 0;
		for (int i = 1;i <= n;i++) {
			cnt += d[i];
		}
		int maxw = 0;
		for (int i = 1;i <= stick;i++) {
			maxw = max(maxw,d[i]);
		}
		//sort(d+1, d+n, greater<int>());
		if (cnt >= 2 * maxw) {
			max_length++;
			//c[index] = false;
			return true;
		}
		else {
			//c[index] = false;
			return false;
		}
	}
	//if (n-index >= stick - index) f(i+2, index+1,stick);
	f(i+1, index+1,stick);
	c[index] = false;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n-2;i++) {
		for (int j = 3;j <= n - i + 1;j++) {
			
			f(i, 1, j);
		}
	}
	cout << max_length;
	return 0;
}
