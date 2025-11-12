#include <bits/stdc++.h>
using namespace std;
int a, s[5005], ans;
//
//void bag(int f,  int zhi, int maxx, int xuan) {
//	if (f == a) {
//		if (xuan < 3)
//			return;
//		if (2 * maxx < zhi)
//			ans++;
//		cout << zhi << "  " << maxx << endl;
//		return;
//	}
//
//	bag(f + 1,  zhi += s[f + 1], s[f + 1], xuan + 1);
//	bag(f + 1,  zhi, maxx, xuan);
//}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a>>b>>c>>d;
	if(b+c+d>d*2)
	cout<<1;
	else cout<<0;
//	for (int i = 1; i <= a; i++) {
//		cin >> s[i];
//	}
	
//	bag(1, s[1], s[1], 0);
//	bag(1, 0, 0, 0);
//	cout << ans % 998244353;
	return 0;
}
