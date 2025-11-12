#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 505, mod = 998244353;

bool b[maxn];
int n, m, c[maxn], cnt1;

void Tepan_15() {
	if (cnt1 != n) {
		printf("0");
	}
	for (int i = 1; i <= n; ++i) {
		if (c[i] == 0) {
			printf("0");
			return;
		}
	}
	printf("%d", n);
	exit(0);
}

bool cmp(int a, int b) {
	return a > b;
}

void Input() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		char c;
		scanf(" %c", &c);
		b[i] = (c == '1') ? true : false;
		cnt1 += (c == '1') ? 1 : 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	if (m == n) {
		Tepan_15();
	}
	if (m > cnt1) {
		printf("0");
		exit(0);
	}
}

bool Check(int arr[]) {
	int cnt = 0, cnt0 = 0;
	for (int i = 1; i <= n; ++i) {
		if (b[i] == 0) {
			++cnt0;
		} else {
			if (cnt0 >= c[arr[i]]) {
				++cnt0;
			} else {
				++cnt;
				if (cnt >= m) {
					return true;
				}
			}
		}
	}
	return false;
}

int ans;
bool vis[maxn];
void DFS(int p, int arr[]) {
	if (p > n) {
		ans += (Check(arr) == true) ? 1 : 0;
		if (ans == mod) {
			ans = 0;
		}
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == false) {
			vis[i] = true;
			arr[p] = i;
			DFS(p + 1, arr);
			vis[i] = false;
		}
	}
}

int arr[maxn];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	Input();
	DFS(1, arr);
	printf("%d", ans);
	return 0;
}