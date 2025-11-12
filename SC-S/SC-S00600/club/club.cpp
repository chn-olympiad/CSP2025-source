#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int maxn = 1e5+8;
int n, t;
struct clubs {
	int like, id;
} a[maxn], b[maxn], c[maxn], a1[maxn];
bool cmp(clubs x, clubs y) {
	return x.like > y.like;
}
bool flag[maxn];
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		int mxa = 0, mxb = 0, mxc = 0, flaga = 0, flagb = 0, flagc = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].like >> b[i].like >> c[i].like;
			a[i].id = b[i].id = c[i].id = i;
			if(a[i].like==0&&b[i].like==0&&c[i].like!=0){
				mxc += c[i].like;
				flag[c[i].id] = 1;
				flagc++;
			}else if(c[i].like==0&&b[i].like==0&&a[i].like!=0){
				mxa += a[i].like;
				flag[a[i].id] = 1;
				flaga++;
			}else if(a[i].like==0&&c[i].like==0&&b[i].like!=0){
				mxb += b[i].like;
				flag[b[i].id] = 1;
				flagb++;
			}
		}
		if(flaga>n/2||flagb>n/2||flagc>n/2){
			memset(flag, 0, sizeof(flag));
			mxa = 0, mxb = 0; mxc = 0; flaga = 0; flagb = 0; flagc = 0;
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);

		
		for (int i = 1; i <= n; i++) {
			if (flaga + flagb + flagc == n)break;
			if (flag[a[i].id] && flag[b[i].id] && flag[c[i].id])continue;
			if (flag[a[i].id] && flag[b[i].id] || (flagb == n / 2 && flaga == n / 2)) {
				mxc += c[i].like;
				flag[c[i].id] = 1;
				flagc++;
				continue;
			}
			if (flag[a[i].id] && flag[c[i].id] || (flagc == n / 2 && flagc == n / 2)) {
				mxb += b[i].like;
				flag[b[i].id] = 1;
				flagb++;
				continue;
			}
			if (flag[c[i].id] && flag[b[i].id] || (flagb == n / 2 && flagc == n / 2)) {
				mxa += a[i].like;
				flag[a[i].id] = 1;
				flaga++;
				continue;
			}
			if (flag[a[i].id] || flaga == n / 2 && (flagb < n / 2 && flagc < n / 2)) {
				if (c[i].id == b[i].id) {
					if (c[i].like > b[i].like) {
						mxc += c[i].like;
						flag[c[i].id] = 1;
						flagc++;
					} else {
						mxb += b[i].like;
						flag[b[i].id] = 1;
						flagb++;
					}
				} else {
					mxc += c[i].like;
					flag[c[i].id] = 1;
					mxb += b[i].like;
					flag[b[i].id] = 1;
					flagc++;
					flagb++;
				}
				continue;
			}//a
			if (flag[b[i].id] || flagb == n / 2 && (flaga < n / 2 && flagc < n / 2)) {
				if (c[i].id == a[i].id) {
					if (c[i].like > a[i].like) {
						mxc += c[i].like;
						flag[c[i].id] = 1;
						flagc++;
					} else {
						mxa += a[i].like;
						flag[a[i].id] = 1;
						flaga++;
					}
				} else {
					mxc += c[i].like;
					flag[c[i].id] = 1;
					mxa += a[i].like;
					flag[a[i].id] = 1;
					flagc++;
					flaga++;
				}
				continue;
			}//b
			if (flag[c[i].id] || flagc == n / 2 && (flagb < n / 2 && flaga < n / 2)) {
				if (a[i].id == b[i].id) {
					if (a[i].like > b[i].like) {
						mxa += a[i].like;
						flag[a[i].id] = 1;
						flaga++;
					} else {
						mxb += b[i].like;
						flag[b[i].id] = 1;
						flagb++;
					}
				} else {
					mxa += a[i].like;
					flag[a[i].id] = 1;
					mxb += b[i].like;
					flag[b[i].id] = 1;
					flaga++;
					flagb++;
				}
				continue;
			}//c

			if (a[i].id == b[i].id && b[i].id == c[i].id) {
				if (a[i].like > b[i].like && a[i].like > c[i].like) {
					mxa += a[i].like;
					flag[a[i].id] = 1;
					flaga++;
				}
				if (b[i].like > a[i].like && b[i].like > c[i].like) {
					mxb += b[i].like;
					flag[b[i].id] = 1;
					flagb++;
				}
				if (c[i].like > a[i].like && b[i].like < c[i].like) {
					mxc += c[i].like;
					flag[c[i].id] = 1;
					flagc++;
				}
			} else if (a[i].id == b[i].id) {
				if (a[i].like > b[i].like) {
					mxa += a[i].like;
					flag[a[i].id] = 1;
					flaga++;
				} else {
					mxb += b[i].like;
					flag[b[i].id] = 1;
					flagb++;
				}
				mxc += c[i].like;
				flag[c[i].id] = 1;
				flagc++;
			} //ab
			else if (c[i].id == b[i].id) {
				if (c[i].like > b[i].like) {
					mxc += c[i].like;
					flag[c[i].id] = 1;
					flagc++;
				} else {
					mxb += b[i].like;
					flag[b[i].id] = 1;
					flagb++;
				}
				mxa += a[i].like;
				flag[a[i].id] = 1;
				flaga++;
			} //bc
			else if (a[i].id == c[i].like) {
				if (a[i].like > c[i].like) {
					mxa += a[i].like;
					flag[a[i].id] = 1;
					flaga++;
				} else {
					mxc += c[i].like;
					flag[c[i].id] = 1;
					flagc++;
				}
				mxb += b[i].like;
				flag[b[i].id] = 1;
				flagb++;
			} //ac
			else {
				mxa += a[i].like;
				flag[a[i].id] = 1;
				mxb += b[i].like;
				flag[b[i].id] = 1;
				flaga++;
				flagb++;
				mxc += c[i].like;
				flag[c[i].id] = 1;
				flagc++;
			}
		}
		cout << mxa + mxb + mxc << endl;

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(a1, 0, sizeof(a1));
		memset(flag, 0, sizeof(flag));
	}

	return 0;
}
