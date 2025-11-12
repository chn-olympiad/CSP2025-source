#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;
struct Node {
	int p;
	ll num;
	Node(): p(0), num(0) {}
	Node(int p, ll num): p(p), num(num) {}
};
struct Compare1 {
	bool operator()(const Node& a, const Node& b) {
		return a.num < b.num;
	}
};
priority_queue<Node, vector<Node>, Compare1> club1;
priority_queue<Node, vector<Node>, Compare1> club2;
priority_queue<Node, vector<Node>, Compare1> club3;
int n;
vector<vector<ll>> nums;
vector<vector<vector<ll>>> memo;
vector<vector<vector<vector<ll>>>> memo2;
bool speA = true;
bool speB = true;
void solve1() {
	ll ans = 0;
	for (int i = 1; i <= n / 2; i++) {
		ans += club1.top().num;
		club1.pop();
	}
	cout << ans << endl;
	return;
}
ll backtrack(int i, int c1, int c2) {
	if (i == n + 1) {
		return 0;
	}
	if (memo[i][c1][c2] != -1) {
		return memo[i][c1][c2];
	}
	ll ans = 0;
	if (c1 < n / 2) {
		ans = max(ans, backtrack(i + 1, c1 + 1, c2) + nums[i][0]);
	}
	if (c2 < n / 2) {
		ans = max(ans, backtrack(i + 1, c1, c2 + 1) + nums[i][1]);
	}
	memo[i][c1][c2] = ans;
	return ans;
}
ll backtrack2(int i, int c1, int c2, int c3) {
	if (i == n + 1) {
		return 0;
	}
	if (memo2[i][c1][c2][c3] != -1) {
		return memo2[i][c1][c2][c3];
	}
	ll ans = 0;
	if (c1 < n / 2) {
		ans = max(ans, backtrack2(i + 1, c1 + 1, c2, c3) + nums[i][0]);
	}
	if (c2 < n / 2) {
		ans = max(ans, backtrack2(i + 1, c1, c2 + 1, c3) + nums[i][1]);
	}
	if (c3 < n / 2) {
		ans = max(ans, backtrack2(i + 1, c1, c2, c3 + 1) + nums[i][2]);
	}
	memo2[i][c1][c2][c3] = ans;
	return ans;
}
void solve2() {
	cout << backtrack(1, 0, 0) << endl;
	return;
}
void solve3() {
	memo2.assign(n + 1, vector<vector<vector<ll>>>(n / 2 + 1, vector<vector<ll>>(n / 2 + 1, vector<ll>(n / 2 + 1, -1))));
	cout << backtrack2(1, 0, 0, 0) << endl;
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		//cout << t << endl;
		speA = true;
		speB = true;
		nums.assign(n + 1, vector<ll>(3, 0));
		memo.assign(n + 1, vector<vector<ll>>(n / 2 + 1, vector<ll>(n / 2 + 1, -1)));
		while (!club1.empty()) club1.pop();
		while (!club2.empty()) club2.pop();
		while (!club3.empty()) club3.pop();
		for (int i = 1; i <= n; i++) {
			cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
			club1.push(Node(i, nums[i][0]));
			club2.push(Node(i, nums[i][1]));
			club3.push(Node(i, nums[i][2]));
			if (nums[i][1] != 0 || nums[i][2] != 0) {
				speA = false;
			}
			if (nums[i][2] != 0) {
				speB = false;
			}
		}
		//cout << speA << endl;
		if (speA) {
			solve1();
		}
		else if (speB) {
			solve2();
		}
		else {
			solve3();
		}
	}
	return 0;
}
