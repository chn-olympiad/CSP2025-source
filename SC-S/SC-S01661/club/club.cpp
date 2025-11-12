#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int now[N], cc1, cc2, cc3;
struct Node {
	int x, y, z;
	bool operator<(Node b) {
		return x > b.x;
	}
}a[N];
long long ans;
priority_queue<pair<int, int>, vector<pair<int, int> > >  q1, q2, q3, q4, q5, q6;
/*
q1 - 1-3
q2 - 1-2
q3 - 2-1
q4 - 3-1
q5 - 3-2
q6 - 2-3
*/
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		while(q1.size())q1.pop();
		while(q2.size())q2.pop();
		while(q3.size())q3.pop();
		while(q4.size())q4.pop();
		while(q5.size())q5.pop();
		while(q6.size())q6.pop();
		ans = 0ll;
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n / 2; i++) {
			ans += a[i].x;
//			cout << a[i].x << '\n';
			now[i] = 1;
			q1.push({a[i].z - a[i].x, i});
			q2.push({a[i].y - a[i].x, i});
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			now[i] = 2;
//			cout << a[i].y << '\n';
			q6.push({a[i].z - a[i].y, i});
			q3.push({a[i].x - a[i].y, i});
			ans += a[i].y;
		}
//		cout << ans << '\n';
		cc1 = cc2 = n / 2;
		cc3 = 0;
		while(q1.size() || q2.size() || q3.size() || q5.size() || q6.size()) {
			while(q1.size() && now[q1.top().second] != 1)q1.pop();
			while(q2.size() && now[q2.top().second] != 1)q2.pop();
			while(q3.size() && now[q3.top().second] != 2)q3.pop();
			while(q4.size() && now[q4.top().second] != 3)q4.pop();
			while(q5.size() && now[q5.top().second] != 3)q5.pop();
			while(q6.size() && now[q6.top().second] != 2)q6.pop();
			int u = q1.size() ? q1.top().first : -1;
			int v = q2.size() ? q2.top().first : -1;
			int w = q3.size() ? q3.top().first : -1;
			int u1 = q4.size() ? q4.top().first : -1;
			int v1 = q5.size() ? q5.top().first : -1;
			int w1 = q6.size() ? q6.top().first : -1;
//			cout << u << ' ' << v << ' ' << w << ' ' << u1 << ' ' << v1 << ' ' << w1 << '\n';
//			cout << cc1 << ' ' << cc2 << ' ' << cc3 << '\n';
//			if(max(u, max(v, w)) <= 0)break;
			if(u > 0 && cc3 < n / 2) {
				int k = q1.top().second;
				q1.pop();
				now[k] = 3;
				ans += u;
				cc1 --;
				cc3 ++;
				q4.push({a[k].x - a[k].z, k});
				q5.push({a[k].y - a[k].z, k});
//				cout << "1 to 3 " << u << '\n';
//				puts("1t3\n");
			}else if(w1 > 0 && cc3 < n / 2) {
				int k = q6.top().second;
				ans += q6.top().first;
				q6.pop();
				now[k] = 3;
				cc2 --;
				cc3 ++;
				q4.push({a[k].x - a[k].z, k});
				q5.push({a[k].y - a[k].z, k});
//				cout << "2 to 3 " << w1 << '\n';
//				puts("2t3\n");
			}else if(v > 0 && cc2 < n / 2) {
				int k = q2.top().second;
				ans += q2.top().first;
				q2.pop();
				now[k] = 2;
				cc1 --;
				cc2 ++;
				q3.push({a[k].x - a[k].y, k});
				q6.push({a[k].z - a[k].y, k});
//				puts("1t2\n");
			}else if(v1 > 0 && cc2 < n / 2) {
				int k = q5.top().second;
				ans += q5.top().first;
				q5.pop();
				now[k] = 2;
				cc3 --;
				cc2 ++;
				q3.push({a[k].x - a[k].y, k});
				q6.push({a[k].z - a[k].y, k});
//				puts("3t2\n");
			}else if(w > 0 && cc1 < n / 2) {
				int k = q3.top().second;
				ans += q3.top().first;
				q3.pop();
				now[k] = 1;
				cc1 ++;
				cc2 --;
				q1.push({a[k].z - a[k].x, k});
				q2.push({a[k].y - a[k].x, k});
//				puts("2t1\n");
			}else if(u1 > 0 && cc1 < n / 2) {
				int k = q4.top().second;
				ans += q4.top().first;
				q4.pop();
				now[k] = 1;
				cc1 ++;
				cc3 --;
				q1.push({a[k].z - a[k].x, k});
				q2.push({a[k].y - a[k].x, k});
//				puts("3t1\n");
			}else{
				if(q2.size() && q3.size() && v + w > 0) {
					int k1 = q2.top().second;
					int k2 = q3.top().second;
					ans += v + w;
					q2.pop();
					q3.pop();
					now[k1] = 2;
					now[k2] = 1;
					q1.push({a[k2].z - a[k2].x, k2});
					q2.push({a[k2].y - a[k2].x, k2});
					q3.push({a[k1].x - a[k1].y, k1});
					q6.push({a[k1].z - a[k1].y, k1});
//					puts("sw12\n");
				}else if(q1.size() && q4.size() && u + u1 > 0) {
					int k1 = q1.top().second;
					int k2 = q4.top().second;
					ans += u + u1;
					q1.pop();
					q4.pop();
					now[k1] = 3;
					now[k2] = 1;
					q1.push({a[k2].z - a[k2].x, k2});
					q2.push({a[k2].y - a[k2].x, k2});
					q4.push({a[k1].x - a[k1].z, k1});
					q5.push({a[k1].y - a[k1].z, k1});
//					puts("sw13");
				}else if(q6.size() && q5.size() && v1 + w1 > 0) {
					int k1 = q6.top().second;
					int k2 = q5.top().second;
					ans += v1 + w1;
					q6.pop();
					q5.pop();
					now[k1] = 3;
					now[k2] = 2;
					q3.push({a[k2].x - a[k2].y, k2});
					q6.push({a[k2].z - a[k2].y, k2});
					q4.push({a[k1].x - a[k1].z, k1});
					q5.push({a[k1].y - a[k1].z, k1});
//					puts("sw23");
				}else {
					/*
					q1 - 1-3
					q2 - 1-2
					q3 - 2-1
					q4 - 3-1
					q5 - 3-2
					q6 - 2-3
					*/
					if(q2.size() && q6.size() && cc3 < n / 2 && v + w1 > 0) {
						int k1 = q6.top().second;
						int k2 = q2.top().second;
						ans += v + w1;
						q2.pop();
						q6.pop();
						cc1 --;
						cc3 ++;
						q3.push({a[k2].x - a[k2].y, k2});
						q6.push({a[k2].z - a[k2].y, k2});
						q4.push({a[k1].x - a[k1].z, k1});
						q5.push({a[k1].y - a[k1].z, k1});
					}else if(q1.size() && q5.size() && cc2 < n / 2 && u + v1 > 0) {
						int k1 = q1.top().second;
						int k2 = q5.top().second;
						ans += u + v1;
						q1.pop();
						q5.pop();
						cc1 --;
						cc2 ++;
						q3.push({a[k2].x - a[k2].y, k2});
						q6.push({a[k2].z - a[k2].y, k2});
						q4.push({a[k1].x - a[k1].z, k1});
						q5.push({a[k1].y - a[k1].z, k1});
					}else if(q3.size() && q1.size() && cc3 < n / 2 && u + w > 0) {
						int k1 = q3.top().second;
						int k2 = q1.top().second;
						ans += u + w;
						q1.pop();
						q3.pop();
						cc2 --;
						cc3 ++;
						q4.push({a[k2].x - a[k2].z, k2});
						q5.push({a[k2].y - a[k2].z, k2});
						q1.push({a[k1].z - a[k1].x, k1});
						q2.push({a[k1].y - a[k1].x, k1});
					}else if(q6.size() && q4.size() && cc1 < n / 2 && u1 + w1 > 0) {
						int k1 = q6.top().second;
						int k2 = q4.top().second;
						ans += u1 + w1;
						q6.pop();
						q4.pop();
						cc2 --;
						cc1 ++;
						q4.push({a[k2].x - a[k2].z, k2});
						q5.push({a[k2].y - a[k2].z, k2});
						q1.push({a[k1].z - a[k1].x, k1});
						q2.push({a[k1].y - a[k1].x, k1});
					}else {
						/*
						q1 - 1-3
						q2 - 1-2
						q3 - 2-1
						q4 - 3-1
						q5 - 3-2
						q6 - 2-3
						*/
						if(q4.size() && q2.size() && cc2 < n / 2 && v + u1 > 0) {
							int k1 = q4.top().second;
							int k2 = q2.top().second;
							ans += v + u1;
							q4.pop();
							q2.pop();
							cc3 --;
							cc2 ++;
							q3.push({a[k2].x - a[k2].y, k2});
							q6.push({a[k2].z - a[k2].y, k2});
							q1.push({a[k1].z - a[k1].x, k1});
							q2.push({a[k1].y - a[k1].x, k1});
						}else if(q5.size() && q3.size() && cc1 < n / 2 && w + v1 > 0) {
							int k1 = q5.top().second;
							int k2 = q3.top().second;
							ans += w + v1;
							q5.pop();
							q3.pop();
							cc3 --;
							cc1 ++;
							q3.push({a[k2].x - a[k2].y, k2});
							q6.push({a[k2].z - a[k2].y, k2});
							q1.push({a[k1].z - a[k1].x, k1});
							q2.push({a[k1].y - a[k1].x, k1});
						}else break;
					}
				}
			}
		}
//		for (int i = 1; i <= n; i++)cout << now[i] << ' ';
		printf("%lld\n", ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/