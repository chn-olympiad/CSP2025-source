#include <bits/stdc++.h>
using namespace std;
#define ll long long
//多测记得清空！！！
int T;
int n;
const int N = 100005;
pair<int, int> a[N], b[N], c[N];
bool vis[N];

struct WS {
	bool a1, b1, c1;
} fvis[N];
int lc;
int cnt1, cnt2, cnt3;
ll ans = 0;

pair<int, int> tg;

bool cmp(pair<int, int> G, pair<int, int> R) {
	return G.first > R.first;
}
bool f1, f2, f3;
ll ans2;

//第二位是编号，第一为是dat
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		f1 = f2 = f3 = 0;
		cin >> n;
		ans = 0;
		cnt1 = cnt2 = cnt3 = 0;
		memset(vis, 0, sizeof vis);
		memset(fvis, 0, sizeof fvis);
		for (int i = 1; i <= n; i++) {
			cin >> a[i].first;
			cin >> b[i].first;
			cin >> c[i].first;
			a[i].second = i;
			b[i].second = i;
			c[i].second = i;
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (cnt1 >= (n >> 1))
				break;
			if (vis[a[i].second])
				continue;
			vis[a[i].second] = 1;
			fvis[a[i].second].a1 = 1;
			cnt1++;
			ans += a[i].first;
		}
		for (int i = 1; i <= n; i++) {
			if (cnt2 >= (n >> 1))
				break;
			if (vis[b[i].second])
				continue;
			vis[b[i].second] = 1;
			fvis[a[i].second].b1 = 1;
			cnt2++;
			ans += b[i].first;
		}
		for (int i = 1; i <= n; i++) {
			if (cnt3 >= (n >> 1))
				break;
			if (vis[c[i].second])
				continue;
			vis[c[i].second] = 1;
			fvis[a[i].second].c1 = 1;
			cnt3++;
			ans += c[i].first;
		}
		//	cout << ans << '\n';
		for (int i = 1; i <= n; i++) {
			f1 = f2 = f3 = 0;
			ans2 = ans;
			if (fvis[a[i].second].a1) {
				f1 = 1;

			} else if (fvis[a[i].second].b1) {
				f2 = 1;
			} else if (fvis[a[i].second].c1) {
				f3 = 1;
			}
			for (int j = 1; j <= n; j++) {
				if (j == i)
					continue;
				if (f1 == 1) {
					if (!fvis[a[j].second].a1) {
						if (fvis[a[j].second].b1 == fvis[a[j].second].c1 && fvis[a[j].second].b1 == 0) {
							if (a[a[j].second].first - a[a[i].second].first > 0) {
								ans += a[a[j].second].first - a[a[i].second].first;
								fvis[a[j].second].a1 = 1;
								fvis[a[i].second].a1 = 0;
							}
						} else if (fvis[a[j].second].b1) {
							if (b[a[i].second].first + a[a[j].second].first - a[a[i].second].first - b[a[j].second].first > 0) {
								ans += b[a[i].second].first + a[a[j].second].first - a[a[i].second].first - b[a[j].second].first;
								fvis[a[j].second].a1 = 1;
								fvis[a[j].second].b1 = 0;
								fvis[a[i].second].b1 = 1;
								fvis[a[i].second].a1 = 0;
							}
						} else if (fvis[a[j].second].c1) {
							if (c[a[i].second].first + a[a[j].second].first - a[a[i].second].first - c[a[j].second].first > 0) {
								ans += c[a[i].second].first + a[a[j].second].first - a[a[i].second].first - c[a[j].second].first;
								fvis[a[j].second].a1 = 1;
								fvis[a[j].second].c1 = 0;
								fvis[a[i].second].c1 = 1;
								fvis[a[i].second].a1 = 0;
							}
						}
					}

				} else if (f2 == 1) {
					if (!fvis[a[j].second].b1) {
						if (fvis[a[j].second].a1 == fvis[a[j].second].c1 && fvis[a[j].second].a1 == 0) {
							if (b[a[j].second].first - b[a[i].second].first > 0) {
								ans += b[a[j].second].first - b[a[i].second].first;
								fvis[a[j].second].b1 = 1;
								fvis[a[i].second].b1 = 0;
							}
						} else if (fvis[a[j].second].a1) {
							if (a[a[i].second].first + b[a[j].second].first - b[a[i].second].first - a[a[j].second].first > 0) {
								ans += a[a[i].second].first + b[a[j].second].first - b[a[i].second].first - a[a[j].second].first;
								fvis[a[j].second].b1 = 1;
								fvis[a[j].second].a1 = 0;
								fvis[a[i].second].a1 = 1;
								fvis[a[i].second].b1 = 0;
							}
						} else if (fvis[a[j].second].c1) {
							if (c[a[i].second].first + b[a[j].second].first - b[a[i].second].first - c[a[j].second].first > 0) {
								ans += c[a[i].second].first + b[a[j].second].first - b[a[i].second].first - c[a[j].second].first;
								fvis[a[j].second].b1 = 1;
								fvis[a[j].second].c1 = 0;
								fvis[a[i].second].c1 = 1;
								fvis[a[i].second].b1 = 0;
							}
						}
					}

				} else if (f3 == 1) {
					if (!fvis[a[j].second].c1) {
						if (fvis[a[j].second].a1 == fvis[a[j].second].b1 && fvis[a[j].second].a1 == 0) {
							if (c[a[j].second].first - c[a[i].second].first > 0) {
								ans += c[a[j].second].first - c[a[i].second].first;
								fvis[a[j].second].c1 = 1;
								fvis[a[i].second].c1 = 0;
							}
						} else if (fvis[a[j].second].a1) {
							if (a[a[i].second].first + c[a[j].second].first - c[a[i].second].first - a[a[j].second].first > 0) {
								ans += a[a[i].second].first + c[a[j].second].first - c[a[i].second].first - a[a[j].second].first;
								fvis[a[j].second].c1 = 1;
								fvis[a[j].second].a1 = 0;
								fvis[a[i].second].a1 = 1;
								fvis[a[i].second].c1 = 0;
							}
						} else if (fvis[a[j].second].b1) {
							if (b[a[i].second].first + c[a[j].second].first - c[a[i].second].first - b[a[j].second].first > 0) {
								ans += b[a[i].second].first + c[a[j].second].first - c[a[i].second].first - b[a[j].second].first;
								fvis[a[j].second].c1 = 1;
								fvis[a[j].second].b1 = 0;
								fvis[a[i].second].b1 = 1;
								fvis[a[i].second].c1 = 0;
							}
						}
					}

				}
			}
		}
		for (int i = 1; i <= n; i++) {
			f1 = f2 = f3 = 0;
			if (fvis[a[i].second].a1) {
				f1 = 1;

			} else if (fvis[a[i].second].b1) {
				f2 = 1;
			} else if (fvis[a[i].second].c1) {
				f3 = 1;
			}
			for (int j = 1; j <= n; j++) {
				if (j == i)
					continue;
				if (f1 == 1) {
					if (!fvis[a[j].second].a1) {
						if (fvis[a[j].second].b1 == fvis[a[j].second].c1 && fvis[a[j].second].b1 == 0) {
							if (a[a[j].second].first - a[a[i].second].first > 0) {
								ans2 += a[a[j].second].first - a[a[i].second].first;
								fvis[a[j].second].a1 = 1;
								fvis[a[i].second].a1 = 0;
							}
						}  else if (fvis[a[j].second].c1) {
							if (c[a[i].second].first + a[a[j].second].first - a[a[i].second].first - c[a[j].second].first > 0) {
								ans2 += c[a[i].second].first + a[a[j].second].first - a[a[i].second].first - c[a[j].second].first;
								fvis[a[j].second].a1 = 1;
								fvis[a[j].second].c1 = 0;
								fvis[a[i].second].c1 = 1;
								fvis[a[i].second].a1 = 0;
							}
						} else if (fvis[a[j].second].b1) {
							if (b[a[i].second].first + a[a[j].second].first - a[a[i].second].first - b[a[j].second].first > 0) {
								ans2 += b[a[i].second].first + a[a[j].second].first - a[a[i].second].first - b[a[j].second].first;
								fvis[a[j].second].a1 = 1;
								fvis[a[j].second].b1 = 0;
								fvis[a[i].second].b1 = 1;
								fvis[a[i].second].a1 = 0;
							}
						}
					}

				} else if (f2 == 1) {
					if (!fvis[a[j].second].b1) {
						if (fvis[a[j].second].a1 == fvis[a[j].second].c1 && fvis[a[j].second].a1 == 0) {
							if (b[a[j].second].first - b[a[i].second].first > 0) {
								ans2 += b[a[j].second].first - b[a[i].second].first;
								fvis[a[j].second].b1 = 1;
								fvis[a[i].second].b1 = 0;
							}
						}  else if (fvis[a[j].second].c1) {
							if (c[a[i].second].first + b[a[j].second].first - b[a[i].second].first - c[a[j].second].first > 0) {
								ans2 += c[a[i].second].first + b[a[j].second].first - b[a[i].second].first - c[a[j].second].first;
								fvis[a[j].second].b1 = 1;
								fvis[a[j].second].c1 = 0;
								fvis[a[i].second].c1 = 1;
								fvis[a[i].second].b1 = 0;
							}
						} else if (fvis[a[j].second].a1) {
							if (a[a[i].second].first + b[a[j].second].first - b[a[i].second].first - a[a[j].second].first > 0) {
								ans += a[a[i].second].first + b[a[j].second].first - b[a[i].second].first - a[a[j].second].first;
								fvis[a[j].second].b1 = 1;
								fvis[a[j].second].a1 = 0;
								fvis[a[i].second].a1 = 1;
								fvis[a[i].second].b1 = 0;
							}
						}
					}

				} else if (f3 == 1) {
					if (!fvis[a[j].second].c1) {
						if (fvis[a[j].second].a1 == fvis[a[j].second].b1 && fvis[a[j].second].a1 == 0) {
							if (c[a[j].second].first - c[a[i].second].first > 0) {
								ans += c[a[j].second].first - c[a[i].second].first;
								fvis[a[j].second].c1 = 1;
								fvis[a[i].second].c1 = 0;
							}
						} else if (fvis[a[j].second].b1) {
							if (b[a[i].second].first + c[a[j].second].first - c[a[i].second].first - b[a[j].second].first > 0) {
								ans += b[a[i].second].first + c[a[j].second].first - c[a[i].second].first - b[a[j].second].first;
								fvis[a[j].second].c1 = 1;
								fvis[a[j].second].b1 = 0;
								fvis[a[i].second].b1 = 1;
								fvis[a[i].second].c1 = 0;
							}
						} else if (fvis[a[j].second].a1) {
							if (a[a[i].second].first + c[a[j].second].first - c[a[i].second].first - a[a[j].second].first > 0) {
								ans += a[a[i].second].first + c[a[j].second].first - c[a[i].second].first - a[a[j].second].first;
								fvis[a[j].second].c1 = 1;
								fvis[a[j].second].a1 = 0;
								fvis[a[i].second].a1 = 1;
								fvis[a[i].second].c1 = 0;
							}
						}
					}

				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}