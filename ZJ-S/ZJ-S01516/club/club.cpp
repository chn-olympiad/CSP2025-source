#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;
int n, a[N], b[N], c[N], p[N], q[N], r[N], cntp, cntq, cntr, ans, ansp, ansq, ansr;

bool cmp1(int x, int y){return a[x] > a[y];}
bool cmp2(int x, int y){return b[x] > b[y];}
bool cmp3(int x, int y){return c[x] > c[y];}

void solve(){
	cntp = cntq = cntr = ans = ansp = ansq = ansr = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
		p[i] = q[i] = r[i] = i;

		int tmp = max(max(a[i], b[i]), c[i]);
		if(a[i] == tmp)
			cntp++;
		else if(b[i] == tmp)
			cntq++;
		else if(c[i] == tmp)
			cntr++;
		ans += tmp;

		ansp += a[i];
		ansq += b[i];
		ansr += c[i];
		int A = a[i], B = b[i], C = c[i];
		a[i] = max(B, C) - A;
		b[i] = max(A, C) - B;
		c[i] = max(A, B) - C;
	}
	if(!(cntp <= n / 2 && cntq <= n / 2 && cntr <= n / 2))
		ans = 0;

	sort(p + 1, p + 1 + n, cmp1);
	sort(q + 1, q + 1 + n, cmp2);
	sort(r + 1, r + 1 + n, cmp3);

	for(int i = 1; i <= n / 2; i++){
		ansp += a[p[i]];
		ansq += b[q[i]];
		ansr += c[r[i]];
	}
	ans = max(ans, ansp);
	ans = max(ans, ansq);
	ans = max(ans, ansr);
	cout << ans << "\n";
	return ;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--) solve();
	return 0;
}