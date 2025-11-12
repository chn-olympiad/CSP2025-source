#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
int T;
int n;
int a[N], b[N], c[N];
ll ans = 0;
int f[N][3];
int g[N][3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		int std;
		ans = 0;
		cin >> n;
		std = n/2;
		for(int i=1; i<=n; ++i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		f[1][0] = a[1];
		f[1][1] = b[1];
		f[1][2] = c[1];
		g[1][0] = g[1][1] = g[1][2] = 1;
		for(int i=2; i<=n; ++i) {
			int rs1 = (g[i-1][0]<std) ? a[i]+f[i-1][0]:-1;
			int rs2 = (g[i-1][0]<std) ? a[i]+f[i-1][1]:-1;
			int rs3 = (g[i-1][0]<std) ? a[i]+f[i-1][2]:-1;
			int mx = max(max(rs1, rs2), rs3);
			if(rs1 == mx) {
				g[i][0] = g[i-1][0] + 1;
				f[i][0] = f[i-1][0] + a[i];
			}
			else if(rs2 == mx) {
				g[i][0] = g[i-1][0] + 1;
				f[i][0] = f[i-1][1] + a[i];
			}
			else if(rs3 == mx) {
				g[i][0] = g[i-1][0] + 1;
				f[i][0] = f[i-1][2] + a[i];
			}
			rs1 = (g[i-1][1]<std) ? b[i]+f[i-1][0]:-1;
			rs2 = (g[i-1][1]<std) ? b[i]+f[i-1][1]:-1;
			rs3 = (g[i-1][1]<std) ? b[i]+f[i-1][2]:-1;
			mx = max(max(rs1, rs2), rs3);
			if(rs1 == mx) {
				g[i][1] = g[i-1][1] + 1;
				f[i][1] = f[i-1][0] + b[i];
			}
			else if(rs2 == mx) {
				g[i][1] = g[i-1][1] + 1;
				f[i][1] = f[i-1][1] + b[i];
			}
			else if(rs3 == mx) {
				g[i][1] = g[i-1][1] + 1;
				f[i][1] = f[i-1][2] + b[i];
			}
			rs1 = (g[i-1][2]<std) ? c[i]+f[i-1][0]:-1;
			rs2 = (g[i-1][2]<std) ? c[i]+f[i-1][1]:-1;
			rs3 = (g[i-1][2]<std) ? c[i]+f[i-1][2]:-1;
			mx = max(max(rs1, rs2), rs3);
			if(rs1 == mx) {
				g[i][2] = g[i-1][2] + 1;
				f[i][2] = f[i-1][0] + c[i];
			}
			else if(rs2 == mx) {
				g[i][2] = g[i-1][2] + 1;
				f[i][2] = f[i-1][1] + c[i];
			}
			else if(rs3 == mx) {
				g[i][2] = g[i-1][2] + 1;
				f[i][2] = f[i-1][2] + c[i];
			}
		} 
		cout << max(max(f[n][0], f[n][1]), f[n][2]) << endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5% 
