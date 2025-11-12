//20pts
#include<bits/stdc++.h>
using namespace std;
int ans;
int n;
struct uu {
	int a, b, c;
	int x() {
		return max(a, max(b, c));
	}
	int bm() {
		if (a >= b && a >= c) {
			return 1;
		} else if (b >= a && b >= c) {
			return 2;
		} else return 3;
	}
};
vector<uu> v1;
bool cmp(uu a, uu b) {
	return a.x() > b.x();
}
void os(int x, int a, int b, int c, int num) {
	if (x == n) {
		ans = max(ans, num);
		return;
	}
	if (a + 1 <= (n / 2)) os(x + 1, a + 1, b, c, num + v1[x].a);
	if (b + 1 <= (n / 2)) os(x + 1, a, b + 1, c, num + v1[x].b);
	if (c + 1 <= (n / 2)) os(x + 1, a, b, c + 1, num + v1[x].c);
}
void f() {
	bool fa = 1, fb = 1;
	ans = 0;
	int l[5] = {};
	vector<uu> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({x, y, z});
		if (y != 0) fa = 0;
		if (z != 0) fa = fb = 0;
	}
	if (n <= 10) {
		v1 = v;
		os(0, 0, 0, 0, 0);
		cout << ans << '\n';
		return;
	}
	if (fa) {
		int ans = 0;
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < n / 2; i++) {
			ans += v[i].x();
		}
		cout << ans << '\n';
		return;
	}
	if(fb){
		
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (l[v[i].bm()] < n / 2) {
			ans += v[i].x();
			l[v[i].bm()]++;
//			v.erase(v.begin());
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--) {
		f();
	}
}
//rp++