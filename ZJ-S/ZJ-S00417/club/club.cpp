#include <bits/stdc++.h>
using namespace std;
char *pa, *pb, buf[1000000];
#define int long long
#define db double
#define p_b push_back
#define nc() (pa==pb && (pb=(pa=buf)+fread(buf,1,1000000,stdin),pa==pb)?EOF:*pa++)
inline int in() { int x=0,f=1;char c=nc();while(!isdigit(c))f*=c==45?-1:1,c=nc();while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=nc();return x*f; }

const int N = 1e5+5;
int T, n, a[N][5], mx1[N], mx2[N], mx3[N], mxi[N], d[N], fl[5], ch[5], mxch = 0, mxchi = 0, cnt = 0, res = 0;

signed main() 
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = in(); while (T--) {
		n = in(), res = mxch = mxchi = 0; fill(d+1, d+5, 0); fill(ch+1, ch+5, 0); fill(fl+1, fl+5, 0);
		fill(mx1+1, mx1+n+1, 0); fill(mx2+1, mx2+n+1, 0); fill(mx3+1, mx3+n+1, 0); fill(mxi+1, mxi+n+1, 0);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) a[i][j] = in();
			mxi[i] = a[i][1] > a[i][2] && a[i][1] > a[i][3] ? 1 : (a[i][2] > a[i][3] ? 2 : 3);
			mx1[i] = max(a[i][1], max(a[i][2], a[i][3]));
			mx3[i] = min(a[i][1], min(a[i][2], a[i][3]));
			fl[1] = a[i][1] == mx1[i] || a[i][1] == mx3[i];
			fl[2] = a[i][2] == mx1[i] || a[i][2] == mx3[i];
			fl[3] = a[i][3] == mx1[i] || a[i][3] == mx3[i];
			mx2[i] = fl[1] ? (fl[2] ? a[i][3] : a[i][2]) : a[i][1];
			res += mx1[i], d[i] = mx1[i] - mx2[i], ++ch[mxi[i]];
		}
		mxchi = ch[1] >= ch[2] && ch[1] >= ch[3] ? 1 : (ch[2] >= ch[3] ? 2 : 3), mxch = ch[mxchi];
		if (mxch > n/2) {
			for (int i = 1; i <= n; ++i) if (mxi[i] != mxchi && d[i]) d[i] = 2e4+5;
			sort(d+1, d+n+1); cnt = 0;
			while (mxch > n/2) res -= d[++cnt], --mxch;
		} 
		printf("%lld\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}