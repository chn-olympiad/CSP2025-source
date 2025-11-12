#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5,M = 2e2+5;
int t,n,n2,dp[M][M][M],ans;
struct A{
	int a,b,c;
}s[N];
bool cmp1(A i,A j){
	return i.a > j.a;
}
bool cmp2(A i,A j){
	return i.a - i.b > j.a - j.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t --){
		cin>>n;
		n2 = n >> 1;
		int mxb = 0,mxc = 0;
		ans = 0;
		for (int i = 1;i <= n;++ i){
			cin>>s[i].a>>s[i].b>>s[i].c;
			mxb = max(mxb,s[i].b);
			mxc = max(mxc,s[i].c);
		}
		if (!mxb && !mxc){
			sort(s+1,s+n+1,cmp1);
			for (int i = 1;i <= n2;++ i){
				ans += s[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		if (!mxc){
			sort(s+1,s+n+1,cmp2);
			for (int i = 1;i <= n2;++ i){
				ans += s[i].a;
			}
			for (int i = n2 + 1;i <= n;++ i){
				ans += s[i].b;
			}
			cout<<ans<<'\n';
			continue;
		}
		memset(dp,0,sizeof(dp));
		for (int i = 1;i <= n;++ i){
			dp[i][i][0] = dp[i - 1][i - 1][0] + s[i].a;
			dp[i][0][i] = dp[i - 1][0][i - 1] + s[i].b;
			dp[i][0][0] = dp[i - 1][0][0] + s[i].c;
		}
		for (int i = 2;i <= n;++ i){
			for (int j = 0;j <= n2;++ j){
				for (int k = 0;k <= n2;++ k){
					int k2 = i - j - k;
					if (k2 < 0){
						continue;
					}
					if (k2 > n2){
						continue;
					}
					if (j > 0){
						dp[i][j][k] = max(dp[i - 1][j - 1][k] + s[i].a,dp[i][j][k]);
					}
					if (k > 0){
						dp[i][j][k] = max(dp[i - 1][j][k - 1] + s[i].b,dp[i][j][k]);
					}
					if (k2 > 0){
						dp[i][j][k] = max(dp[i - 1][j][k] + s[i].c,dp[i][j][k]);
					}
					ans = max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}