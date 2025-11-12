#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f
#define N 201000
using namespace std;

int T, n, a2[N], a1[N], a3[N], ans, club[N], tans, cnt;
bool flag[N];
struct node {
	int val, pepnum, clubnum;
	friend bool operator < (node a, node b) {
		return a.val < b.val;
	}
};
priority_queue<node> st;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out","w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--) {
		tans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		for (int j = 0; j <= n * 3; j++) {
			memset(flag, false, sizeof(flag));
			memset(club, 0, sizeof(club));
			ans = cnt = 0;
			for (int i = 1; i <= n; i++) {
				st.push({a1[i], i, 1});
				st.push({a2[i], i, 2});
				st.push({a3[i], i, 3});
			}
			for (int i = 0; i < j; i++) st.pop();
			while (!st.empty()) {
				node tmp = st.top();
				st.pop();
				if (flag[tmp.pepnum] || club[tmp.clubnum] >= n / 2) continue;
				ans += tmp.val;
	//			cout << tmp.val << ' ';
				flag[tmp.pepnum] = true;
				club[tmp.clubnum]++;
				if (club[tmp.clubnum] >= n / 2) cnt++;
			}
			tans = max(tans, ans);
		}
		cout << tans << endl;
	}
	
	return 0;
}
