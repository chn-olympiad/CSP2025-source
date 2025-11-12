#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MAXN 100005
#define MAXM 5
#define pii pair<int, int>
#define mod 1000000007

int t;
int n;
int club1;
int club2;
int club3;
int res = 0;
bool rA = true;
bool rB = true;
struct member{
	int a[MAXM];
	int max1;
	int max2;
	int max3;
	void init() {
		cin >> a[1] >> a[2] >> a[3];
		if (a[1] >= a[2]) {
			max1 = 1;
			max2 = 2;
		} else {
			max1 = 2;
			max2 = 1;
		}
		if (a[3] >= a[max1]) {
			max3 = max2;
			max2 = max1;
			max1 = 3;
		} else if (a[max1] > a[3] && a[3] >= a[max2]) {
			max3 = max2;
			max2 = 3;
		} else {
			max3 = 3;
		}
		if (a[2] != 0 || a[3] != 0)
			rA = false;
		if (a[3] != 0)
			rB = false;
	}
} mem[MAXN];

void dfs(int i, int ans) {
	if (i > n) {
		res = max(res, ans);
		return ;
	}
	if (club1 < n / 2) {
		++club1;
		dfs(i + 1, ans + mem[i].a[1]);
		--club1;
	}
	if (club2 < n / 2) {
		++club2;
		dfs(i + 1, ans + mem[i].a[2]);
		--club2;
	}
	if (club3 < n / 2) {
		++club3;
		dfs(i + 1, ans + mem[i].a[3]);
		--club3;
	}
}

bool cmp1(member x, member y) {
	return x.a[1] > y.a[1];
}
bool cmp2(member x, member y) {
	return x.a[1] - x.a[2] > y.a[1] - y.a[2];
}
bool cmp3(member x, member y) {
	return x.a[x.max1] - x.a[x.max2] > y.a[x.max1] - y.a[x.max2];
}
bool cmp4(member x, member y) {
	return x.a[x.max2] - x.a[x.max3] > y.a[x.max2] - y.a[x.max3];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		cin >> n;
		res = 0;
		for (int i = 1; i <= n; ++i) {
			mem[i].init();
		}
		if (n <= 10) {
			dfs(1, 0);
			cout << res << endl;
			continue;
		}
		if (rA) {
			sort(mem + 1, mem + 1 + n, cmp1);
			for (int i = 1; i <= n / 2; ++i) 
				res += mem[i].a[1];
			cout << res << endl;
			continue;
		}
		if (rB) {
			sort(mem + 1, mem + 1 + n, cmp2);
			int i;
			for (i = 1; i <= n / 2 && mem[i].a[1] - mem[i].a[2] >= 0; ++i) 
				res += mem[i].a[1];
			int ti = i;
			for (; i <= ti + n / 2 - 1; ++i)
				res += mem[i].a[2];
			cout << res << endl;
			continue;
		}
		int v[3] = {0, 0, 0};
		vector<member> nemem;
		for (int i = 1; i <= n; ++i) {
			member curr = mem[i];
			if (v[curr.max1] < n / 2) {
				res += curr.a[curr.max1];
				++v[curr.max1];
			} else {
				nemem.push_back(curr);
			}
		}
		sort(nemem.begin(), nemem.end(), cmp4);
		vector<member> ne2mem;
		for (int i = 0; i < nemem.size(); ++i) {
			member curr = nemem[i];
			if (v[curr.max2] < n / 2) {
				res += curr.a[curr.max2];
				++v[curr.max2];
			} else {
				ne2mem.push_back(curr);
			}
		}
		for (int i = 0; i < ne2mem.size(); ++i) {
			res += ne2mem[i].a[ne2mem[i].max3];
		}
		cout << res << endl;
	}
	return 0;
}