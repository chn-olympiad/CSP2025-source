/*
#include <bits/stdc++.h>
using namespace std;
int n, t;
int sum[20002][400];
int sum1[20002][400];
int sum2[20002][400];

struct node {
	int sum;
	int at;
};
node a[114514], b[114514], c[114514];

int a, b, c, x, y, z, aa, bb, cc;
int vis[114514];
long long ans;

int main() {
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> c;
			sum[a][++aa] = i, sum1[b][++bb] = i, sum2[c][++cc] = i;
		}
		for (int i = 20000; i >= 0; i--) {
			for (int j = 0; j < 300; j++) {
				if (x < n / 2 && !vis[sum[i][j]]&&sum[i][j]!=0) {
					cout << "j1:" << j << endl;
					ans += j;
					vis[sum[i][j]] = 1;
					x++;
				}
			}
			for (int j = 0; j < 300; j++) {
				if (y < n / 2 && !vis[sum1[i][j]]) {
					cout << "j2:" << j << endl;
					ans += j;
					vis[sum1[i][j]] = 1;
					y++;
				}
			}
			for (int j = 0; j < 300; j++) {
				if (z < n / 2 && !vis[sum2[i][j]]) {
					cout << "j3:" << j << endl;
					ans += j;
					vis[sum2[i][j]] = 1;
					z++;
				}
			}
		}
		cout << ans << endl;
		memset(sum, 0, sizeof(sum));
		memset(sum1, 0, sizeof(sum1));
		memset(sum2, 0, sizeof(sum2));
		ans = 0;
	}

	return 0;
}
*/
//fuck CCF
//CCF毁了我的信竞梦
//CCF have no mother
//#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
int n, a[114514], b, c;
long long ans;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);Never gonna give you up
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b >> c;
	sort(a + 1, a + n + 1);
	for (int i = n; i >= n / 2 + 1; i--)
		ans += a[i];
	cout << ans << endl;

	return 0;
}