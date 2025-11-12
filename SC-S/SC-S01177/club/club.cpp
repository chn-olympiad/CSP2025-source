#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int T, n;
long long ans;
struct node {
	int num[3];
};
node a[MAXN];
int b[MAXN];

bool cmp(node x, node y) {
	return x.num[0] > y.num[0];
}

void dfs(int step, long long sum, node m) {//无特殊性质
	if (step > n) {
		bool flag = true;
		for (int i = 0; i < 3; i++) {
			if (m.num[i] > (n / 2)) flag = false;
		}
		if (flag)
			ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 3; i++) {
		m.num[i]++;
		sum += (long long)(a[step].num[i]);
		dfs(step + 1, sum, m);
		sum -= (long long)(a[step].num[i]);
		m.num[i]--;
	}
}

void f_A() { //特殊性质A
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i * 2 <= n; i++) {
		ans += a[i].num[0];
	}
}

void f_B() { //特殊性质B
	for (int i = 1; i <= n; i++) {
		ans += a[i].num[0];
		b[i] = a[i].num[0] - a[i].num[1];
	}
	sort(b + 1, b + 1 + n);
	for (int i = 1; i * 2 <= n; i++) {
		ans -= b[i];
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		bool flagA, flagB;
		flagA = flagB = true;
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].num[0] >> a[i].num[1] >> a[i].num[2];
			if (a[i].num[2] != 0) flagA = flagB = false;
			if (a[i].num[1] != 0) flagA = false;
		}
		if (flagA) { //特殊性质A
			f_A();
		} else if (flagB) { //特殊性质B
			f_B();
		} else { //无特殊性质
			node tmp;
			tmp.num[0] = tmp.num[1] = tmp.num[2] = 0;
			dfs(1, 0, tmp);
		}
		cout << ans << endl;
	}
	return 0;
}