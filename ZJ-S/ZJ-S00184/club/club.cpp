#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, cnt[4];
struct yrd {
	ll val[4], mx1, mx2, cha, choice;
} a[N];
bool cmp(yrd x, yrd y) {
	return x.cha < y.cha;
}
ll ans = 0;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		for(int i = 1; i <= 3; i++) {
			cnt[i] = 0;
		}
		for(int i = 1; i <= n; i++) {
			cin >> a[i].val[1] >> a[i].val[2] >> a[i].val[3];
			a[i].mx1 = 0, a[i].mx2 = 0;
			for(int j = 1; j <= 3; j++) {
				if(a[i].val[j] >= a[i].val[a[i].mx1]) {
					a[i].mx2 = a[i].mx1;
					a[i].mx1 = j;
				}
				else if(a[i].val[j] >= a[i].val[a[i].mx2]) {
					a[i].mx2 = j;
				}
			}
			a[i].cha = a[i].val[a[i].mx1] - a[i].val[a[i].mx2];
			cnt[a[i].mx1]++;
			a[i].choice = a[i].mx1;
			ans += a[i].val[a[i].mx1];
		}
		sort(a + 1, a + n + 1, cmp);
		for(int j = 1; j <= 3; j++) {
			if(cnt[j] > n / 2) {
				for(int i = 1; i <= n; i++) {
					if(a[i].choice == j) {
						cnt[a[i].mx1]--;
						cnt[a[i].mx2]++;
						ans -= a[i].cha;
						a[i].choice = a[i].mx2;
					}
					if(cnt[j] <= n / 2) {
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
