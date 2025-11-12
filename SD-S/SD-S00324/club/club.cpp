#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define F(i, l, r) for(int i = l; i <= r; i++)
const int N = 100005;
int biggest(int);
int sebig(int);
int judge(int);
int sejudge(int);

int T, n;
ll ans = 0;

struct node {
	int a, b, c;
}st[N];
struct club {
	int id, love;
	club(int id, int love): id(id), love(love) {}
	bool operator < (const club &t) const {
		return biggest(id) - sebig(id) > biggest(t.id) - sebig(t.id);
	}
};
priority_queue<club> lk[3];

int judge(int i) {
	if(st[i].a > st[i].b && st[i].a > st[i].c)
		return 0;
	if(st[i].b > st[i].a && st[i].b > st[i].c)
		return 1;
	return 2;
}
int sejudge(int i) {
	if(st[i].a > st[i].b && st[i].a > st[i].c) {
		if(st[i].b > st[i].c)
			return 1;
		return 2;
	}
	if(st[i].b > st[i].c && st[i].b > st[i].a) {
		cout << "here";
		if(st[i].a > st[i].c) {
			return 0;
		}
		return 1000;
	}
	if(st[i].a > st[i].b)
		return 0;
	return 1;
}
int sebig(int i) {
	int t[3] = {st[i].a, st[i].b, st[i].c};
	sort(t, t + 3);
	return t[1];
}
int biggest(int i) {
	return max(max(st[i].a, st[i].b), st[i].c);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++)
			cin >> st[i].a >> st[i].b >> st[i].c;
		for(int i = 1; i <= n; i++) {
			int flag = judge(i);
			int maxx = biggest(i);
			lk[flag].push(club(i, maxx));
			if(lk[flag].size() > (unsigned)n/2) {
				club tmp = lk[flag].top();
				lk[flag].pop();
				int maxx2 = sebig(tmp.id);
				ans += maxx2;
			}
		}
		for(int i = 0; i < 3; i++) {
			while(!lk[i].empty()) {
				ans += lk[i].top().love;
				lk[i].pop();
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
