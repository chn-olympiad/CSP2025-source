#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, ans, num, d[210][210][210];
struct node{
	int x, y, z;
}a[N];
bool cmp1(node x, node y){return x.x > y.x;}
bool cmp2(node x, node y){return x.y > y.y;}
bool cmp3(node x, node y){return x.z > y.z;}

int check(int n){
	int flag1 = 1, flag2 = 1;
	for (int i = 1; i <= n; i ++){
		if (a[i].z != 0) flag2 = 0;
		if (a[i].y != 0) flag1 = 0;
		if (flag1 + flag2 == 0) return 0;
	}
	return flag1 + flag2;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> m;
	while (m --){
		cin >> n, ans = 0;
		for (int i = 1; i <= n; i ++) cin >> a[i].x >> a[i].y >> a[i].z;
		memset(d, 0, sizeof d);
		int cc = check(n);
		if (n <= 200){
			d[1][1][0] = a[1].x;
			d[1][0][1] = a[1].y;
			d[1][0][0] = a[1].z;
			for (int i = 2; i <= n; i ++){
				for (int x = 0; x <= min(n / 2, i); x ++){
					for (int y = 0; x + y <= i && y <= n / 2; y ++){
						if (i - x - y > n / 2) continue;
						if (x) d[i][x][y] = max(d[i][x][y], d[i - 1][x - 1][y] + a[i].x);
						if (y) d[i][x][y] = max(d[i][x][y], d[i - 1][x][y - 1] + a[i].y);
						if (n - x - y > 0) d[i][x][y] = max(d[i][x][y], d[i - 1][x][y] + a[i].z);
					}
				}
			}
			for (int x = 0; x <= n / 2; x ++){
				for (int y = n / 2 - x; y <= n / 2; y ++){
					ans = max(ans, d[n][x][y]);
				}
			}
			cout << ans << '\n';
		}
		else if (cc == 2){
			sort(a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i ++){
				ans += a[i].x;
			}
			cout << ans << '\n';
		}
		else if (cc == 1){
			num = 0;
			sort(a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i ++) ans += a[i].x;
			for (int i = n / 2 + 1; i <= n; i ++) ans += a[i].y;
			sort(a + 1, a + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i ++) num += a[i].y;
			for (int i = n / 2 + 1; i <= n; i ++) num += a[i].x;
			cout << max(ans, num) << '\n';
		}
		else {
			num = 0;
			sort(a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i ++) num += a[i].x;
			for (int i = n / 2 + 1; i <= n; i ++) num += max(a[i].y, a[i].z);
			ans = max(ans, num), num = 0;
			sort(a + 1, a + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i ++) num += a[i].y;
			for (int i = n / 2 + 1; i <= n; i ++) num += max(a[i].x, a[i].z);
			ans = max(ans, num), num = 0;
			sort(a + 1, a + n + 1, cmp3);
			for (int i = 1; i <= n / 2; i ++) num += a[i].z;
			for (int i = n / 2 + 1; i <= n; i ++) num += max(a[i].x, a[i].y);
			ans = max(ans, num);
			cout << ans << '\n';
		}
	}
	return 0;
}