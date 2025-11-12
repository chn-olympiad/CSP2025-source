#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int a[220];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int d = 0;
	for(int i = 1;i <= n * m;i ++) {
		cin >> a[i];
	}
	d = a[1];
	sort(a + 1,a + 1 + n * m);
	int x = 0,y = 1;
	bool flag = 0;
	for(int i = n * m;i >= 1;i --) {
		if(x == n) {
			flag ^= 1;
			y ++;
			x = 0;
		}
		x ++;
		if(a[i] == d) {
			if(flag == 0) cout << y << ' ' << x << endl;
			else cout << y << ' ' << n - x + 1 << endl;
			return 0;
		}
	}
	return 0;
}
