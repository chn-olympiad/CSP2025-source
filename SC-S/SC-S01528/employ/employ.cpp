#include<bits/stdc++.h>
using namespace std;
int n, m, fs, c[501];
char st[501];
bool p[501];
void dfs(int t, int lq, int fq) {
	if (t > n) {
		if (lq >= m) {
//			cout<<lq<<' '<<m<<'\n';
			++fs;
			if (fs == 998244353)fs = 0;
		}
//		cout<<"\n_____\n";
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!p[i]) {
//			cout<<t<<' '<<i<<' '<<st[t]<<' '<<c[i]<<' '<<lq<<' '<<fq<<' '<<fs<<'\n';
			if (st[t]=='1') {
				if (c[i] > fq) {
					p[i]=true;
					dfs(t + 1, lq + 1, fq);
					p[i]=false;
				} else {
					p[i]=true;
					dfs(t + 1, lq, fq + 1);
					p[i]=false;
				}
			} else {
				p[i]=true;
				dfs(t + 1, lq, fq + 1);
				p[i]=false;
			}
		}
	}
}
int main() {
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> st[i];
	for (int i = 1; i <= n; ++i)cin >> c[i];
	sort(c + 1, c + 1 + n);
	dfs(1, 0, 0);
	return cout << fs, 0;
}