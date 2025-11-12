#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 8;
int t, n, A, B, C;
long long ans;
struct node{
	int a, b, c, cur;
	int dif;
}nodes[MAXN];
bool cmp1(node x, node y) {
	if (x.dif > y.dif) return true;
	else if (x.dif == y.dif) return x.c > y.c;
	return false;
}
bool cmp2(node x, node y) {
	return x.dif > y.dif;
}
priority_queue<int> AA, BB;
int main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &t);
	while (t--) {
		ans = 0, A = 0, B = 0, C = 0;
		scanf ("%d", &n);
		int N = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf ("%d%d%d", &nodes[i].a, &nodes[i].b, &nodes[i].c);
			nodes[i].dif = abs(nodes[i].a - nodes[i].b);
		}
		sort(nodes + 1, nodes + n + 1, cmp1);
		for (int i = 1; i <= n; i++) {
			if (nodes[i].a > nodes[i].b) {
				if (A + 1 <= N) {
					A++;
					nodes[i].cur = nodes[i].a;
				}else {
					B++;
					nodes[i].cur = nodes[i].b;
					if (nodes[i].c - nodes[i].b <= nodes[i].dif)AA.push(nodes[i].dif);
				}
			}else if (nodes[i].a < nodes[i].b) {
				if (B + 1 <= N) {
					B++;
					nodes[i].cur = nodes[i].b;
				}else {
					A++;
					nodes[i].cur = nodes[i].a;
					if (nodes[i].c - nodes[i].a < nodes[i].dif)BB.push(nodes[i].dif);
				}
			}else if (nodes[i].a == nodes[i].b) {
				if (A < B) {
					A++;
					nodes[i].cur = nodes[i].a;
				}else {
					B++;
					nodes[i].cur = nodes[i].b;
				}
			}
			nodes[i].dif = nodes[i].c - nodes[i].cur;
		//	cout << "   " << A << " " << B << " " << nodes[i].cur << endl;
		}
		sort (nodes + 1, nodes +n + 1, cmp2);
		for (int i = 1; i <= n; i++) {
			if (nodes[i].dif > 0 && C + 1 <= N) {
				C++;
				if (nodes[i].cur == nodes[i].a && !AA.empty()) {
					ans += AA.top();
					AA.pop();
				}
				if (nodes[i].cur == nodes[i].b && !BB.empty()) {
					ans += BB.top();
					BB.pop();
				}
				nodes[i].cur = nodes[i].c;
			}
		}
		for (int i = 1; i <= n; i++) {
			ans += nodes[i].cur;
			//	cerr << "         " << i << " " << nodes[i].cur << endl;
		}
		cout << ans << endl;
	}
	return 0;
}