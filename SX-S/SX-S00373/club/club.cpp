#include <bits/stdc++.h>
//反悔贪心（不过感觉正解不是这个，上位绿~中位蓝（毕竟板子是绿的）
using namespace std;//真确性可能有问题
typedef long long ll;
#define PII pair<int,int>
#define val first
#define id second


int n, a[3][100005];
priority_queue<PII, vector<PII>, greater<PII> > q0, q1, q2; //存差最小的
int cnt1, cnt2, cnt0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out",  "w", stdout);
	int _ = 1;
	cin >> _;
	while (_--) {
		cin >> n;
		cnt1 = cnt2 = cnt0 = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[0][i] >> a[1][i] >> a[2][i];
		for (int i = 1; i <= n; i++) {
			int x = a[0][i], y = a[1][i], z = a[2][i];
			if (x == max(x, max(y, z))) {
				if (cnt0++ < n / 2) {
					q0.push({min(x - y, x - z), i});
				} else {//如果名额满了
					if (q0.top().val < min(x - y, x - z)) {//如果弹出最优
						q0.push({min(x - y, x - z), i});
						int j = q0.top().id;//处理被弹出那个的情况
						if (a[0][j] == max(a[1][j], max( a[0][j], a[2][j]))) { //不是被二次弹出（感觉这个是一定的，保险起见
							if (a[1][j] > a[2][j]) {
								q1.push({a[1][j] - a[2][j], j});
								++cnt1;
							}//一次弹出
							else {
								q2.push({a[2][j] - a[1][j], j});
								++cnt2;
							}
						} else if (a[1][j] > a[0][j]) {
							q2.push({-1, j});
							++cnt2;
						} else {
							q1.push({-1, j});
							++cnt1;
						}
						q0.pop();
					} else if (y > z) { //一次弹出
						++cnt1;
						q1.push({y - z, i});
					} else {
						q2.push({z - y, i});
						++cnt2;
					}
				}
			}

			else if (y == max(x, max(y, z))) {
				if (cnt1++ < n / 2) {
					q1.push({min(y - z, y - x), i});
				} else {//如果名额满了
					if (q1.top().val < min(y - z, y - x)) {//如果弹出最优
						q1.push({min(y - z, y - x), i});
						int j = q1.top().id;//处理被弹出那个的情况
						if (a[1][j] == max(a[1][j], max( a[0][j], a[2][j]))) { //不是被二次弹出（感觉这个是一定的，保险起见
							if (a[0][j] > a[2][j]) {
								q0.push({a[1][j] - a[2][j], j});
								++cnt0;
							} else {
								q2.push({a[2][j] - a[1][j], j});
								++cnt2;
							}
						} else if (a[0][j] > a[1][j]) {
							q2.push({-1, j});
							++cnt2;
						} else {
							q0.push({-1, j});
							++cnt0;
						}
						q1.pop();
					} else if (x > z) {
						q0.push({x - z, i});
						++cnt0;
					} else {
						q2.push({z - x, i});
						++cnt2;
					}
				}
			}

			else {
				if (cnt2++ < n / 2) {
					q2.push({min(z - y, z - x), i});
				} else {//如果名额满了
					if (q2.top().val < min(z - y, z - x)) {//如果弹出最优
						q2.push({min(z - y, z - x), i});
						int j = q2.top().id;//处理被弹出那个的情况
						if (a[2][j] == max(a[1][j], max( a[0][j], a[2][j]))) { //不是被二次弹出（感觉这个是一定的，保险起见
							if (a[1][j] > a[0][j]) {
								q1.push({a[1][j] - a[0][j], j});
								++cnt1;
							} else {
								q0.push({a[0][j] - a[1][j], j});
								++cnt0;
							}
						} else if (a[1][j] > a[2][j]) {
							q1.push({-1, j});
							++cnt1;
						} else {
							q0.push({-1, j});
							++cnt0;
						}
						q2.pop();
					} else if (y > x) {
						q1.push({y - z, i});
						++cnt1;
					} else {
						q0.push({z - y, i});
						++cnt0;
					}
				}
			}
			//做三遍
		}
		ll ans = 0;
		while (!q1.empty()) {
			ans += a[1][q1.top().id];
			q1.pop();
		}
		while (!q2.empty()) {
			ans += a[2][q2.top().id];
			q2.pop();
		}
		while (!q0.empty()) {
			ans += a[0][q0.top().id];
			q0.pop();
		}
		cout << ans << "\n";
	}
}/*
建议迷惑行为大赏看看谁多测不清空

快结束了，还是说两句吧
感觉这次难多了
不好评价
哎，死去的7勾，不知道能不能搞上
怎么办啊
怎么办啊
啊啊啊啊啊
哎，算了，就这样吧
AFO是必然的（吗）
不管了
死去吧
——————on 18：16时写作

//freopen("
//freopen("
//freopen("
//freopen("
//freopen("
//freopen("
引起注意.gif
*/
