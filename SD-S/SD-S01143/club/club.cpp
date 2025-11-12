#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 29;

int n, m;
int d[N];
vector<int> a, b, c;
priority_queue<int, vector<int>, greater<int> > q;

void tbcclear() {
	a.clear();
	b.clear();
	c.clear();
	rep (i, 1, n) d[i] = 0;
	while (q.size()) q.pop();
}

void tbcsolve() {
	cin >> n;
	tbcclear();
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
	rep (i, 1, n) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x >= y && x >= z) {
			cnt1++;
			ans += x;
			a.pb(i);
			if (y > z) d[i] = x - y;
			else d[i] = x - z;
		}
		else if (y >= x && y >= z) {
			cnt2++;
			ans += y;
			b.pb(i);
			if (x > z) d[i] = y - x;
			else d[i] = y - z;
		}
		else {
			cnt3++;
			ans += z;
			c.pb(i);
			if (x > y) d[i] = z - x;
			else d[i] = z - y;
		}
//		cout << abs(x - y) << " " << d[i] << endl;
	}
//	rep (i, 1, n) {
//		cout << d[i] << endl;
//		cout << ans << endl;
//	}
//	cout << cnt1 << " " << cnt2 << " " << cnt3 << endl; 
//———————————————————— 
	int maxn = max({cnt1, cnt2, cnt3});
	if (maxn <= (n >> 1)) {
		cout << ans << '\n';
		return; 
	}
	if (cnt1 == maxn) {
		for (auto i : a) q.push(d[i]);
//		int tmp = 1;
		while (cnt1 > (n >> 1)) {
//			cout << tmp++ << endl;
			ans -= q.top();
			q.pop();
			cnt1--;
		}
	}
	else if (cnt2 == maxn) {
		for (auto i : b) q.push(d[i]);
		while (cnt2 > (n >> 1)) {
//			cout << ans << endl;
			ans -= q.top();
			q.pop();
			cnt2--;
		}
	}
	else {
		for (auto i : c) q.push(d[i]);
		while (cnt3 > (n >> 1)) {
			ans -= q.top();
			q.pop();
			cnt3--;
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int SHEN = 1;
	cin >> SHEN;
	while (SHEN--) {
		tbcsolve();
	}
	return 0;
}

/*
14:41 读完题且有思路 
14:58 写完代码但样例1没过 
15:06 调过样例1，是边界没处理好，样例2又没过……发现可能是清空没清空好 
15:11 我是傻子，我clear函数没调用（ 
15:14 样例3居然单点了一个0？！！破案了又忘记初始化数组大小了 
15:16 样例4的第4组数据没过。。。 
15:26 发现是忽略了两项甚至三项喜爱度同为最大值的情况，更改后通过样例4
15:27 样例5顺利通过（此题真是每个样例都起到了它的作用） 
*/
