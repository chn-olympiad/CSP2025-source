#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pll pair<ll,ll>

const int N = 1e5+10;

int T;
int n, pos, a[3][N], b[3][N], num[3];
int n0, n1, n2, d0, d1, d2;
ll ans;

void clean() {
	ans = 0;
	num[0] = num[1] = num[2] = 0;
	return ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		n0 = n1 = n2 = n / 2;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			pos = 0;
			for (int j = 0; j < 3; j++) {
				scanf("%d", &a[j][i]); //cin>>a[j][i];
				if (a[j][i] > a[pos][i])
					pos = j; //find max
			}
			num[pos]++;
			ans += a[pos][i];
			for (int j = 0; j < 3; j++)
				b[j][i] =  a[j][i] - a[pos][i] ; //make b
			b[pos][i] = -1e9;
//			cout << "###" << pos << " " << i << endl;
		}
//		cout << num[0] << " " << num[1] << " " << num[2];
		while (num[0] > n0 || num[1] > n1 || num[2] > n2) {
			int mx = -1e9-1, p1, p2;
			while (num[0] > n0) {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j < 3; j++) {
						if (b[j][i] > mx) {
							mx = b[j][i];
							p1 = j, p2 = i;
						}
					}
				}
				ans += mx;
				n0++;
				b[p1][p2] = -1e9;
				if (p1 == 1) {
					n1--;
					if (b[2][p2] > -1e9)
						b[2][p2] -= mx;
				} else {
					n2--;
					if (b[1][p2] > -1e9)
						b[1][p2] -= mx;
				}
				mx = -1e9-1;
//				cout << 0 << "@@@" << n0 << " " << ans << " " << p1 << " " << p2 << endl;
			}
			while (num[1] > n1) {
				for (int i = 1; i <= n; i++) {
					for (int j = 0; j < 3 && j != 1; j++) {
						if (b[j][i] > mx) {
							mx = b[j][i];
							p1 = j, p2 = i;
						}
					}
				}
//				cout << "!!!" << mx << endl;
				ans += mx;
				n1++;
				b[p1][p2] = -1e9;
				if (p1 == 0) {
					n0--;
					if (b[0][p2] > -1e9)
						b[2][p2] -= mx;
				} else {
					n2--;
					if (b[0][p2] > -1e9)
						b[0][p2] -= mx;
				}
				mx = -1e9-1;
//				cout << 1 << "@@@" << n0 << " " << ans << " " << p1 << " " << p2 << endl;

			}
			while (num[2] > n2) {
				for (int i = 1; i <= n; i++) {
					for (int j = 0; j < 2; j++) {
						if (b[j][i] > mx) {
							mx = b[j][i];
							p1 = j, p2 = i;
						}
					}
				}
				ans += mx;
				n2++;
				b[p1][p2] = -1e9;
				if (p1 == 0) {
					n0--;
					if (b[1][p2] > -1e9)
						b[1][p2] -= mx;
				} else {
					n1--;
					if (b[0][p2] > -1e9)
						b[0][p2] -= mx;
				}
				mx = -1e9-1;
			}
		}
		printf("%lld\n", ans);
		clean();
	}
	return 0;
}