#include <bits/stdc++.h>
using namespace std;
int satis[100009][4];
#define int long long

/*
FUCK U CCF
*/
struct per {
	int satis;
	int ind;
	int minis;
	per(int s, int i, int m) {
		satis = s;
		ind = i;
		minis = m;
	}
};

struct per2 {
	int satis;
	int ind;
	int minis;
	per2(int s, int i, int m) {
		satis = s;
		ind = i;
		minis = m;
	}
};
int n;
int maximum = n / 2, sum = 0;

auto lambda = [](per a, per b) {
	return a.satis < b.satis;
};

auto rule = [](per2 a, per2 b) {
	return a.satis > b.satis;
};
int amount[4];
int people[100009];
priority_queue<per, vector<per>, decltype(lambda)> q(lambda);
priority_queue<per2, vector<per2>, decltype(rule)> rest(rule);

inline bool check() {
	return amount[1] > maximum || amount[2] > maximum || amount[3] > maximum;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		memset(people, -1, sizeof(people));
		memset(amount, 0, sizeof(amount));
		sum = 0;
		cin >> n;
		maximum = n / 2;
		for (int x = 0; x < n; x++) {
			for (int y = 1; y <= 3; y++) {
				cin >> satis[x][y];
				q.push(per(satis[x][y], x, y));
			}
		}
		while (!q.empty()) {
			auto tmp = q.top();
			if (people[tmp.ind] == -1) {
				people[tmp.ind] = tmp.minis;
				amount[tmp.minis]++;
				sum += tmp.satis;
				//	cout << "pick " << tmp.minis << " of " << tmp.ind << '\n';
			} else {
				rest.push(per2(satis[tmp.ind][people[tmp.ind]] - tmp.satis, tmp.ind, tmp.minis));
			}
			q.pop();
		}
		//	cout << rest.size() << '\n';
		while (check()) {
			//	cout << "cycle\n";
			auto tmp = rest.top();
			if (people[tmp.ind] != 0) {
				sum -= tmp.satis;
				amount[people[tmp.ind]]--;
				people[tmp.ind] = 0;
			}
			rest.pop();
		}
		while (rest.empty() != 1) {
			rest.pop();
		}
		cout << sum << '\n';
	}
	return 0;
}
