#include <bits/stdc++.h>
using namespace std;

int t, n;
int f, s, th;
int first[200005] = {0}, second[200005] = {0}, third[200005] = {0};
int fv[200005] = {0}, sv[200005] = {0}, thv[200005] = {0};
int a, b, c;
int maxi, imax, xmember, maxn;
int m, o;
int ans = 0;

int main() {
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

	cin >> t;
	for(int tt = 1;tt <= t;tt++) {
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> a >> b >> c;
			maxi = max(max(a, b), c);
			if(maxi == a) {
				f++;
				first[i] = i;
				imax = a;
			}
			else if(maxi == b) {
				s++;
				second[i] = i;
				imax = b;
			}
			else if(maxi == c) {
				th++;
				third[i] = i;
				imax = c;
			}
			ans += maxi;
			if(imax == a) {
				m = a - b;
				o = a - c;
				m = min(m, o);
				fv[i] = m;
			}
			else if(imax == b) {
				m = b - a;
				o = b - c;
				m = min(m, o);
				sv[i] = m;
			}
			else if(imax == c) {
				m = c - a;
				o = c - b;
				m = min(m, o);
				thv[i] = m;
			}
		}
		maxn = max(max(f, s), th);
		n /= 2;
		if(maxn > n) {
			int p = maxn - n;
			if(maxn == f) {
				sort(fv + 1,fv + 1 + n);
				for(int i = 1;i <= p;i++) {
					ans -= fv[i];
				}
			}
			else if(maxn == s) {
				sort(sv + 1,sv + 1 + n);
				for(int i = 1;i <= p;i++) {
					ans -= sv[i];
				}
			}
			else if(maxn == th) {
				sort(thv + 1,thv + 1 + n);
				for(int i = 1;i <= p;i++) {
					ans -= thv[i];
				}
			}
			cout << ans << endl;
		}
		else cout << ans << endl;
		f = s = th = maxi = imax = xmember = m = n = ans = maxn = 0;
		for(int i = 1;i <= n;i++) {
			first[i] = second[i] = third[i] = 0;
			fv[i] = sv[i] = thv[i] = 0;
		}
	}
	return 0; 
}

