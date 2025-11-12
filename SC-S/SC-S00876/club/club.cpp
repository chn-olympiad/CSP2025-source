#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 50;
ll T, n;
bool A = true;
struct Node{
	ll a, b, c;
	ll cnt, idx;
	ll Max, Min;
}num[N];
bool cmpa(Node LL, Node RR) {
	return LL.a > RR.a;
}
bool cmp(Node LL, Node RR) {
	if (LL.Min != RR.Min) return LL.Min < RR.Min;
	return LL.Max < RR.Max;
}
void init(int x) {
	// 初定 谁最大 
	num[x].cnt = num[x].a;   num[x].idx = 1;
	if (num[x].b > num[x].cnt) {
		num[x].cnt = num[x].b;
		num[x].idx = 2;
	}
	if (num[x].c > num[x].cnt) {
		num[x].cnt = num[x].c;
		num[x].idx = 3;
	}
	return ;
}
ll op[4];
void solve() {
	memset(op, 0, sizeof(op));
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &num[i].a, &num[i].b, &num[i].c);
		if (num[i].b != 0 || num[i].c != 0) A = false;
	}
	for (int i = 1; i <= n; i++) init(i);
	if (A == true) {
		sort(num + 1, num + n + 1, cmpa);
		ll ans = 0;
		for (int i = 1; i <= (n >> 1); i++) {
			ans += num[i].a;
		}
		cout << ans << "\n";
	}
	else {
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += num[i].cnt;
			op[num[i].idx]++;
		}
		ll Re = 0;
		// 排 b 和 c 
		if (op[1] > (n >> 1)) {
			Re = 1;
			for (int i = 1; i <= n; i++) {
				num[i].Max = max(num[i].cnt - num[i].b, num[i].cnt - num[i].c);
				num[i].Min = min(num[i].cnt - num[i].b, num[i].cnt - num[i].c);
			}
		}
		// 排 a 和 c
		else if (op[2] > (n >> 1)) {
			Re = 2;
			for (int i = 1; i <= n; i++) {
				num[i].Max = max(num[i].cnt - num[i].a, num[i].cnt - num[i].c);
				num[i].Min = min(num[i].cnt - num[i].a, num[i].cnt - num[i].c);
			}
		}
		// 排 a 和 b 
		else if (op[3] > (n >> 1)) {
			Re = 3;
			for (int i = 1; i <= n; i++) {
				num[i].Max = max(num[i].cnt - num[i].b, num[i].cnt - num[i].a);
				num[i].Min = min(num[i].cnt - num[i].b, num[i].cnt - num[i].a);
			}
		}
		
		sort(num + 1, num + n + 1, cmp);
		
		if (Re != 0) {
			for (int i = 1; i <= n; i++) {
				if (Re == num[i].idx) {
					ans -= num[i].Min;
					op[Re]--;
				}
				if (op[Re] <= (n >> 1)) break;
			}
		}
		
		cout << ans << "\n";
	}
	
	return ;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	
	while (T--) solve();

	return 0;
}