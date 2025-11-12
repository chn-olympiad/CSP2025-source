#include<bits/stdc++.h>
using namespace std;
#define MAX 0x3f3f3f3f3f3f3f
#define MIN -0x3f3f3f3f3f3f3f
const int N = 1e5 + 5;
int a[N],b[N],c[N];
int fa[N],fb[N],fc[N];
int at[N],bt[N],ct[N];
bool xa[N],xb[N],xc[N];
int t;
int dp1[N],dp[N];
bool cmp(int x,int y) {
	return x > y;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(dp,0,sizeof dp);
		memset(dp1,0,sizeof dp1);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(fa,0,sizeof fa);
		memset(fb,0,sizeof fb);
		memset(fc,0,sizeof fc);
		memset(at,0,sizeof at);
		memset(bt,0,sizeof bt);
		memset(ct,0,sizeof ct);
		memset(xa,0,sizeof xa);
		memset(xb,0,sizeof xb);
		memset(xc,0,sizeof xc);
		long long ans = 0;
		int cnt1 = 0,cnt2 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] == 0) {
				cnt1++;
			}
			if (c[i] == 0) {
				cnt2++;
			}
		}
		if (cnt1 == cnt2 && cnt1 + cnt2 == 2 * n) {
			sort(a + 1,a + n + 1);
			for (int i = n; i >= n / 2; i--) {
				ans += a[i];
			}
			cout << ans << '\n';
			continue;
		}
		else if (cnt2 == n && cnt1 != n) {
			long long mina = MAX,minb = MAX;
			long long maxa = MIN,maxb = MIN;
			int xia = 0,xib = 0;
			int na = 0,nb = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] > maxa) {
					maxa = a[i];
					xia = i;
				}
				else if (a[i] == maxa) {
					if (xia == xib) {
						xia = i;
						maxa = a[i];
					}
				}
				if (b[i] > maxb) {
					maxb = b[i];
					xib = i;
				}
				else if (b[i] == maxb) {
					if (xia == xib) {
						xib = i;
						maxb = b[i];
					}
				}
			}
		//	cout << maxa << ' ' << maxb << '\n';
		//	cout << xa << ' ' << xb << '\n';
			int ca = 0,cb = 0;
			bool f = 0;
			for (int i = 1; i <= n; i++) {
				if (ca >= n / 2 || cb >= n / 2) {
					f = 1;
					break;
				}
				if (a[i] == maxa) {
					ca++;
					ans += a[i];
					dp[i] = 1;
					//cout << a[i] << '\n';
				}
				if (b[i] == maxb) {
					cb++;
					ans += b[i];
					dp1[i] = 1;
					//cout << b[i] << '\n';
				}
				//以下代码均挪到下一行 
			/*	else {
					if (ca < n / 2 && cb < n / 2) {
						if (a[i] > b[i]) {
							ca++;
							ans += a[i];
						}
						else if (b[i] > a[i]) {
							cb++;
							ans += b[i];
						}
					}
				}
				*/
			}
			if (ca == n / 2) {
				for (int i = 1; i <= n; i++) {
					if (dp[i] == 0) {
						dp1[i] = 1;
						ans += b[i];
						//cout << b[i] << '\n';
					}
				}
			}
			else if (cb == n / 2){
				for (int i = 1; i <= n; i++) {
					if (dp1[i] == 0) {
						dp[i] = 1;
						ans += a[i];
						//cout << a[i] << '\n';
					}
				}
			}
			else {
				for (int i = 1; i <= n; i++) {
					if (dp[i] == 1 || dp1[i] == 1) {
						continue;
					}
					else {
						if (ca < n / 2 && cb < n / 2) {
							if (a[i] > b[i]) {
								ca++;
								ans += a[i];
								dp[i] = 1;
								//cout << a[i] << '\n';
							}
							else if (b[i] > a[i]) {
								cb++;
								ans += b[i];
								dp1[i] = 1;
								//cout << b[i] << '\n';
							}
							else if (a[i] == b[i]) {
								if (ca > cb) {
									cb++;
									ans += b[i];
									dp1[i] = 1;
									//cout << b[i] << '\n';
								}
								else {
									ca++;
									ans += a[i];
									dp[i] = 1;
									//cout << a[i] << '\n';
								}
							}
						}
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				if (dp[i] == 0 && dp1[i] == 0) {
					ans += max(a[i],b[i]);
				}
			}
			cout << ans << '\n';
		}
		else {
			
			//cout << 13 << '\n'; 
			int ca = 0,cb = 0,cc = 0;
			for (int i = 1; i <= n; i++) {
				at[i] = a[i];
				bt[i] = b[i];
				ct[i] = c[i];
			}
			int xiaa = 0,xiab = 0,xiac = 0;
			sort(at + 1,at + n + 1,cmp);
			sort(bt + 1,bt + n + 1,cmp);
			sort(ct + 1,ct + n + 1,cmp);
			if (n == 2) {
				/*int ga = a[1];
				int gb = b[1];
				int gc = c[1];
				int ea = a[2];
				int eb = b[2];
				int ec = c[2];
				*/
				int s1 = 0,s2 = 0,s3 = 0,s4 = 0;
			//s5 = 0,s6 = 0,s7 = 0,s8 = 0,s9 = 0;
				s1 = a[1] + b[2];
				s2 = a[1] + c[2];
				s3 = a[2] + b[1];
				s4 = a[2] + c[1];
				ans += max(max(s1,s2),max(s3,s4));
				cout << ans << '\n';
				continue;
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n / 2; j++) {
					if (a[i] == at[j]) {
						fa[++xiaa] = a[i];
						xa[i] = 1;
						break;
					}
				}
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n / 2; j++) {
					if (b[i] == bt[j]) {
						fb[++xiab] = b[i];
						xb[i] = 1;
						break;
					}
				}
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n / 2; j++) {
					if (c[i] == ct[j]) {
						fc[++xiaa] = c[i];
						xc[i] = 1;
						break;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				if (xa[i] == 1 && xb[i] == 0 && xc[i] == 0) {
					ca++;
					ans += a[i];
				}
				else if (xa[i] == 0 && xb[i] == 1 && xc[i] == 0) 
				{
					cb++;
					ans += b[i];
				}
				else if (xa[i] == 0 && xb[i] == 0 && xc[i] == 1) {
					cc++;
					ans += c[i];
				}
				else if (xa[i] == 0 && xb[i] == 0 && xc[i] == 0) 
				{
					continue;
				}
				else if (xa[i] == 1 && xb[i] == 1 && xc[i] == 1) {
					int cnt = ans;
					ans += max(a[i],max(b[i],c[i]));
					if (ans - a[i] == cnt) {
						ca++;
					}
					else if (ans - b[i] == cnt) {
						cb++;
					}
					else {
						cc++;
					}
				}
				else if (xa[i] == 1 && xb[i] == 1 && xc[i] == 0) {
					if (a[i] > b[i]) {
						ca++;
					}
					else {
						cb++;
					}
					ans += max(a[i],b[i]);
				}
				else if (xa[i] == 0 && xb[i] == 1 && xc[i] == 1) {
					if (b[i] > c[i]) {
						cb++;
					}
					else {
						cc++;
					}
					ans += max(b[i],c[i]);
				}
				else if (xa[i] == 1 && xb[i] == 0 && xc[i] == 1) {
					if (a[i] > c[i]) {
						ca++;
					}
					else {
						cc++;
					}
					ans += max(a[i],c[i]);
				}
			}
			if (ca + cb + cc < n) {
				for (int i = 1; i <= n; i++) {
					if (xa[i] == 0 && xb[i] == 0 && xc[i] == 0) {
						int cnt = ans;
						ans += max(a[i],max(b[i],c[i]));
						if (ans - a[i] == cnt && ca < n / 2) {
							ca++;
						}
						else if (ans - b[i] == cnt && cb < n / 2) {
							cb++;
						}
						else {
							cc++;
						}
					}
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
