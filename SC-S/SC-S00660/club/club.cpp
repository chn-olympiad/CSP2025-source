#include<bits/stdc++.h>
using namespace std;
#define int long long
struct P{
	int x, y, id, id1, id2, sam1, sam2;
}a[100010];
int st[100010];
int cnt[5];
int t;
bool cmp(P n, P m) {
	return abs(n.x - n.y) > abs(m.x - m.y);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while(t --) {
		int len = 0;
		int n, ans1 = 0, ans2 = 0;
		cin >> n;
		memset(cnt, 0, sizeof cnt);
		for(int i = 1; i <= n; ++ i) {
			int x, y, z; 
			cin >> x >> y >> z;
			if(x <= y && x <= z) a[i].x = y, a[i].y = z, a[i].id1 = 2, a[i].id2 = 3;
			else if(y <= x && y <= z) a[i].x = x, a[i].y = z, a[i].id1 = 1, a[i].id2 = 3;
			else a[i].x = x, a[i].y = y, a[i].id1 = 1, a[i].id2 = 2;
			if(x == z && x != y && x != 0) {
				st[i] = 1;
			}else if(y == z && y != x && y != 0) {
				st[i] = 2;
			}else if(x == y && x != z && x != 0) st[i] = 3;
			a[i].id = i;
//			cout << a[i].x << " " << a[i].y << endl;
		}sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; ++ i) {
//			cout << a[i].x << " " << a[i].y << endl;
			if(a[i].x > a[i].y) {
				if(cnt[a[i].id1] < n / 2) {
					cnt[a[i].id1] ++;
					ans1 += a[i].x;
				}else {
					if(st[a[i].id] == 1) {
						swap(a[i].x, a[i].y);
						if(a[i].id1 == 1) a[i].id2 = 3, a[i].id1 = 2;
						else if(a[i].id1 == 2) a[i].id1 = 1, a[i].id2 = 2;
						i --;
						continue;
					}else if(st[a[i].id] == 2) {
						if(a[i].id2 == 2) a[i].id2 = 3;
						else if(a[i].id2 == 3) a[i].id2 = 2;
						i --;
						continue;
					}else if(st[a[i].id] == 3) {
						if(a[i].id2 == 2) a[i].id2 = 1;
						else if(a[i].id2 == 1) a[i].id2 = 2;
						i --;
						continue;
					}
					ans1 += a[i].y;
					cnt[a[i].id2] ++;
				}
			}else {
				if(cnt[a[i].id2] < n / 2) {
					cnt[a[i].id2] ++;
					ans1 += a[i].y;
				}else {
					if(st[a[i].id] == 1) {
						swap(a[i].x, a[i].y);
						if(a[i].id1 == 1) a[i].id2 = 3, a[i].id1 = 2;
						else if(a[i].id1 == 2) a[i].id1 = 1, a[i].id2 = 2;
						i --;
						continue;
					}else if(st[a[i].id] == 2) {
						if(a[i].id2 == 2) a[i].id2 = 3;
						else if(a[i].id2 == 3) a[i].id2 = 2;
						i --;
						continue;
					}else if(st[a[i].id] == 3) {
						if(a[i].id2 == 2) a[i].id2 = 1;
						else if(a[i].id2 == 1) a[i].id2 = 2;
						i --;
						continue;
					}
					ans1 += a[i].x;
					cnt[a[i].id1] ++;
				}
			}
		}cout << ans1 << endl;
	}
} 
/*
完辣，本场考试 AC 0道题 
卧槽这个空格好难按 ，果然平时细糠吃多了 
我们神奇的发现其实最小的那个价值是无用的 ，然后忘了 
可以拿数据结构维护。吗？
退役了QWQ 
Goodbye, OI.
I'm a loser.
对不起，下辈子我还要学 OI。  
半个小时，能逆风翻盘吗 
*/