#include <bits/stdc++.h>
using namespace std;
string a[200002], b[200002];
string c[200002], d[200002];
int m, n;
int f(int i) {
	int l = c[i].length(),cnt = 0;
	for (int p = 0;p < a[i].length();p++) {
		for(int j = 1;j <= m;j++){
			if (a[i][p] == c[j][1]) {
				bool flag = true;
				for (int k = 1;k < c[j].length();k++) {
					if (a[i][k+p-1] != c[j][k]) {
						//cout << i << ' ' << k+p << ' ' << j << ' ' << k;
						//cout << a[i][k+p-1] << ' ' << c[j][k] << endl;
						flag = false;
						break;
					}
				}
				if (flag) {
					string cache = a[i];
					int df = 0;
					for (int k = 0;k < d[j].length();k++) {
						cache[k+p-1] = d[j][k];
						df = k;
					}
					/*if (d[j].length() > c[j].length()) {
						string cache2;
						int now = 0;
						for (int lll = 0;lll < df+p;lll++){
							cache2[lll] = cache[lll];
							now = lll;
						}
						int gh = 0;
						for (int k = 0;k < d[i].length();k++) {
							cache2[df+p+k] = d[i][k];
							gh = df+k;
						}
						for (int lll = gh;lll < a[i].length() - (d[j].length() - c[j].length());lll++){
							cache2[lll] = cache[now];
							now++;
						}
					}*/
					if (cache == b[i]) {
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> m >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1;i <= m;i++) {
		cin >> c[i] >> d[i];
	}
	for (int i = 1;i <= n;i++) {
		cout << f(i) << endl;
	}
	return 0;
}
