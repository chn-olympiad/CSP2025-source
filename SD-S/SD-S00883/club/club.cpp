#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int A[MAXN][5], sum[MAXN], n;
bool vis[MAXN];
struct Node {
	int cha, op, id;
} Diff[MAXN];

bool cmp(const Node &x, const Node &y) {
	return x.cha == y.cha ? x.id < y.id : x.cha > y.cha; 
}

void Solve() {
	int ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= 3; j ++) cin >> A[i][j];
	sum[1] = sum[2] = sum[3] = 0;
	for(int i = 1; i <= n; i ++) {
		int a = A[i][1], b = A[i][2], c = A[i][3];
		int maxx = 0, mexx = 0, op = 0;
		if(a > b) {
			if(a > c) maxx = a, mexx = max(b, c);
			else maxx = c, mexx = a;
		}
		else if(a > c) {
			if(a > b) maxx = a, mexx = max(b, c);
			else maxx = b, mexx = a;
		}
		else if(b > c) {
			if(c > a) maxx = b, mexx = c;
			else maxx = b, mexx = a;
		}
		else {
			maxx = c, mexx = b;
		}
		int cha = maxx - mexx;
		if(maxx == a) op = 1;
		else if(maxx == b) op = 2;
		else op = 3;
		Diff[i] = {cha, op, i};
	}
	sort(Diff + 1, Diff + n + 1, cmp);
	for(int i = 1; i <= n; i ++) {
		int cha = Diff[i].cha, op = Diff[i].op, id = Diff[i].id;
		if(sum[op] >= n / 2) {
			if(op == 1) ans += max(A[id][2], A[id][3]);
			if(op == 2) ans += max(A[id][1], A[id][3]);
			if(op == 3) ans += max(A[id][1], A[id][2]);
		}
		else {
			sum[op] ++;
			ans += A[id][op];
		}
	}
	cout << ans << "\n";
	return ;
		
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T;
	while(T --) Solve();
	
	return 0;
	
}

