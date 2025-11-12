#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,dp[N][10],p1[N],p2[N],dpp[N];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin >> t;
	while (t --) {
		cin >> n;
		int d = n/2;
		long long cnt=0,ans[N];
		int m1=0,m2=0,mx=-10005,mn=200005,min_=200005,o=200005;
		int a=0,b=0,c=0,x=-1,l=1;

		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) {
				cin >> dp[i][j];
				if (dp[i][j] > mx) {
					m1=j;
					mx = max(mx,dp[i][j]);
				}
				if (dp[i][j] < mx) {
					m2=j;
					mn = min(mx,dp[i][j]);
				}
			}
			cnt += mx;
			mx=0;
			if (m1 == 1) a ++;
			else if (m1 == 2) b ++;
			else if (m1 == 3) c ++;

		}

		if (a > d) x = 1;
		else if (b > d) x = 2;
		else if (c > d) x = 3;
		else x = 0;
		ans[0] = cnt;
		if (x > 0) {
			while (true) {
				if (a <= d && b <= d && c <= d) break;
				for (int i = 1; i <= n; i ++) {
					for (int j = 1; j <= 3; j ++) {
						dpp[j] = dp[i][j];
					}
					sort(dpp+1,dpp+1+n,greater<int>());
					ans[i] = ans[i-1] - dpp[1] + dpp[2];
					if (x == 1) a --;
					else if (x == 2) b --;
					else if (x == 3) c --;
					
					if (a > d || b > d ||c > d) {
						l ++ ;
					}
				}
			}
			sort(ans+1,ans+1+n,greater<int>());
			cnt = ans[l];
		}
		cout << cnt << "\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
