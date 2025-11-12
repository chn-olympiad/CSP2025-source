#include <bits/stdc++.h>

using namespace std;

inline int rd() {
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-')	
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar(); 
	}
	return x * w;
}

int t, n;

using ll = long long;

#define maxn 100005

int a[maxn][5];

struct node {
	int id, val, cid;
	bool operator <(const node &x) const {
		return val < x.val;
	}
};

struct COP {
	priority_queue<node> que;
	int cnt;
} cop[5];

ll ans = 0;

void add(int u, int c) {
	++cop[c].cnt;
	ans += a[u][c];
	int res = -1, id = 0;
	for (int i = 1; i <= 3; ++i)
		if (i != c && res < a[u][i])	
			res = a[u][i], id = i;	
	cop[c].que.emplace((node){u, res - a[u][c], id});
	return;
}

void sol() {
	n = rd();
	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= 3; ++j)
			a[i][j] = rd();
	for (int i = 1; i <= 3; ++i) {
		while (cop[i].que.size())
			cop[i].que.pop();
		cop[i].cnt = 0;
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i][1] == max({a[i][1], a[i][2], a[i][3]})) {
//			cout<<1<<endl;
			if (cop[1].cnt < n / 2)	
				add(i, 1);
			else {
				if (ans + max(a[i][2], a[i][3]) >= ans + cop[1].que.top().val + a[i][1]) {
					if (a[i][2] >= a[i][3])	
						add(i, 2);
					else
						add(i, 3);
				}
				else {
					add(cop[1].que.top().id, cop[1].que.top().cid);
					ans -= a[cop[1].que.top().id][1];
					cop[1].que.pop();
					add(i, 1);
				}
			}
		}
		else if (a[i][2] == max({a[i][1], a[i][2], a[i][3]})) {
//			cout<<2<<endl;
			if (cop[2].cnt < n / 2)	
				add(i, 2);
			else {
				if (ans + max(a[i][1], a[i][3]) >= ans + cop[2].que.top().val + a[i][2]) {
					if (a[i][1] >= a[i][3])	
						add(i, 1);
					else
						add(i, 3);
				}
				else {
					add(cop[2].que.top().id, cop[2].que.top().cid);
					ans -= a[cop[2].que.top().id][2];
					cop[2].que.pop();
					add(i, 2);
				}
			}
		}
		else {
//			cout<<3<<endl;
			if (cop[3].cnt < n / 2)	
				add(i, 3);
			else {
				if (ans + max(a[i][2], a[i][1]) >= ans + cop[3].que.top().val + a[i][3]) {
					if (a[i][2] >= a[i][1])	
						add(i, 2);
					else
						add(i, 1);
				}
				else {
					add(cop[3].que.top().id, cop[3].que.top().cid);
					ans -= a[cop[3].que.top().id][3];
					cop[3].que.pop();
					add(i, 3);
				}
			}
		}
//		cout<<ans<<endl;
	}
	printf("%lld\n", ans);
//	puts("");
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = rd();
	while (t--)
		sol();	
	return 0;
}

