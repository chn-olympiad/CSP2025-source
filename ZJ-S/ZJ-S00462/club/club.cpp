#include<bits/stdc++.h>
#define x() _x(i)
#define y() _y(i)
#define z() _z(i)
using namespace std;
struct node {
	int a1, a2, a3, ma;
}a[100005];
int n, u, v, w, ans;
bool cmp(node a, node b) {
	return a.ma > b.ma;
}
void p(int s) {
//	cout<<s <<'\n';
}
void _x(int i) {
	ans += a[i].a1;
	u++;
//	cout<<a[i].a1<<' '<<1<<'\n';
}
void _y(int i) {
	ans += a[i].a2;
	v++;
//	cout<<a[i].a2<<' '<<2<<'\n';
}
void _z(int i) {
	ans += a[i].a3;
	w++;
//	cout<<a[i].a3<<' '<<3<<'\n';
}
int maxn;
void dfs(int p, int val, int u, int v, int w) {
//	cout << p <<' ';
    if(p > n) {
//    	cout<<'\n'<<p<<'\n';
    	maxn = max(maxn, val);
    	return;
	}
	if(n > u) dfs(p + 1, val + a[p].a1, u + 2, v, w);
	if(n > v) dfs(p + 1, val + a[p].a2, u, v + 2, w);
	if(n > w) dfs(p + 1, val + a[p].a3, u, v, w + 2);
}
void solve() {
	u = v = w = ans = maxn = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		a[i].ma = max(a[i].a1, max(a[i].a2, a[i].a3));
	}
	if(n <= 10) {
		dfs(1, 0, 0, 0, 0);
		cout << maxn << '\n';
		return;
	}
	sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
//    	cout << a[i].a1 <<' '<< a[i].a2 <<' '<< a[i].a3<<'\n';
    	if(a[i].a1 > a[i].a2 && a[i].a1 > a[i].a3) {
    		if(n / 2 > u) x(), p(12);
			else {
				if(a[i].a2 > a[i].a3) n / 2 > v? y(),p(31) : z(),p(54);//
				else n / 2 > w? z(),p(534) : y(),p(645);//
			}
			int qyx;
		}else if(a[i].a2 > a[i].a1 && a[i].a2 > a[i].a3) {
			if(n / 2 > v) y(),p(86);
			else {
				if(a[i].a1 > a[i].a3) n / 2 > u? x(),p(653) : z(),p(980);//
				else n / 2 > w? z(),p(5224) : x(),p(784);
			}
		}
		else {
			if(n / 2 > w) z(),p(534444);
			else {
				if(a[i].a1 > a[i].a2) n / 2 > u?x(),p(239875):y(),p(7842);//
				else n / 2 > v?y(),p(765444):x(),p(77777);
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
