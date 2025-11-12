#include <bits/stdc++.h>
using namespace std;
int T;

int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin >> T;
	while (T--) {
		int n;
		int a[1000] = {0}, b[1000] = {0}, c[1000] = {0};
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		int aa = a[1] + b[2], bb = a[1] + c[2], cc = b[1] + a[2], dd = b[1] + c[2], ee = c[1] + a[2], ff = c[1] + b[2];
		if (aa < bb) {
			aa = bb;
		}
		if (aa < cc) {
			aa = cc;
		}
		if (aa < dd) {
			aa = dd;
		}
		if (aa < ee) {
			aa = ee;
		}
		if (aa < ff) {
			aa = ff;
		}
		cout << aa << endl;
	}
	return 0;
}