#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define pr pair<int, int>
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
#define iosfst ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 1e5 + 10;
int T, n, cnt1, cnt2, cnt3, ans, a[N][3];
vector<int> v1, v2, v3, q;
void solve() {
	ans = cnt1 = cnt2 = cnt3 = 0;
	v1.clear(), v2.clear(), v3.clear(), q.clear();
	cin >> n;
	rep (i, 1, n) cin >> a[i][1] >> a[i][2] >> a[i][3];
	rep (i, 1, n) {
		if (a[i][1] == max(max(a[i][1], a[i][2]), a[i][3])) v1.push_back(i);
		else if (a[i][2] == max(max(a[i][1], a[i][2]), a[i][3])) v2.push_back(i);
		else v3.push_back(i);
		ans += max(a[i][1], max(a[i][2], a[i][3]));
	}
	cnt1 = v1.size();
	cnt2 = v2.size();
	cnt3 = v3.size();
	if (max(cnt1, max(cnt2, cnt3)) <= n / 2) {
		cout << ans << '\n';
		return;
	}
	if (cnt1 > n / 2) {
		lop (i, 0, v1.size()) {
			int x = v1[i];
			q.push_back(max(a[x][2] - a[x][1], a[x][3] - a[x][1]));
		}
		sort(q.begin(), q.end());
		int top = q.size() - 1;
		while (cnt1 > n / 2) {
			int x = q[top--];
			ans += x;
			cnt1--;
		}
	}
	else if (cnt2 > n / 2) {
		lop (i, 0, v2.size()) {
			int x = v2[i];
			q.push_back(max(a[x][1] - a[x][2], a[x][3] - a[x][2]));
		}
		sort(q.begin(), q.end());
		int top = q.size() - 1;
		while (cnt2 > n / 2) {
			int x = q[top--];
			ans += x;
			cnt2--;
		}
	}
	else {
		lop (i, 0, v3.size()) {
			int x = v3[i];
			q.push_back(max(a[x][1] - a[x][3], a[x][2] - a[x][3]));
		}
		sort(q.begin(), q.end());
		int top = q.size() - 1;
		while (cnt3 > n / 2) {
			int x = q[top--];
			ans += x;
			cnt3--;
		}
	}
	cout << ans << '\n';
	return;
}
signed main() {
	iosfst;
	File("club");
	cin >> T;
	while (T--) solve();
	return 0;
}
/*
100 + (40 ~ 48) + (50 ~ 70) + 32 = 222 ~ 250
初二蒟蒻 rp++
拿部分分真爽

2025.11.1真是个好日子： 
祝我的安馨生日快乐
万圣节快乐
表白第“一生世”（134）天快乐 
52 zax 1314!(以后要一直在一起呦！）
开心！！！！！ 


还有30分钟，许个愿吧：
愿我和zax永远在一起，愿我在镇海中学前途无量，愿我此次CSP-S rp++ 拿下一等！！！

马上结束啦！！
回去就和zax贴贴qwq 
*/
