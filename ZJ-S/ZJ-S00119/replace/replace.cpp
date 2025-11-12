#include <bits/stdc++.h>
using namespace std;

const int M = 2e5 + 10;
int n, m;
string a[M][4];
string b, c;
int k = 0, l;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string d, e, f;
		cin >> a[i][0] >> a[i][1];
		while(true) {
			if(a[i][0] != a[i][1]) break;
			d += a[i][0];
			k++;
		}
		for(int j = d.size(); j >= 0; j--) {
			a[i][2] += d[j];
		}
		while(true) {
			if(a[i][0] == a[i][1]) break;
			e += a[i][0];
			f += a[i][1];
			k++;
		}
		while(k <= n) {
			a[i][3] += a[i][0];
			k++;
		}
		a[i][0] = e;
		a[i][1] = f;
	}
	for(int j = 0; j < m; j++) {
		k = 0;
		cin >> b >> c;
		string x, z, y1, y2, x1;
		while(true) {
			if(b[k] != c[k]) break;
			x1 += b[k];
			k++;
		}
		for(int i = x1.size(); i >= 0; i--) {
			x += x1[j];
		}
		while(true) {
			if(b[k] == c[k]) break;
			y1 += b[k];
			y2 += c[k];
			k++;
		}
		while(k <= n) {
			z += b[k];
			k++;
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(a[i][0] == y1 && a[i][1] == y2) {
				int flag = 0;
				for(int p = 0; p < a[i][2].size(); p++) {
					if(a[i][2][p] != x[p]) flag = 1;
					break;
				}
				for(int p = 0; p < a[i][3].size(); p++) {
					if(a[i][3][p] != z[p]) flag = 1;
					break;
				}
				if(flag == 0) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
