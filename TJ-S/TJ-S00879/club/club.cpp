#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100001][3],dp[201][201][201],b[100001];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for (int kk = 1;kk <= t;kk++){
		scanf("%lld",&n);
		for (int i = 1;i <= n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		}
		int cnt0 = 0,cnt1 = 0,cnt2 = 0,ans = 0;
		for (int i = 1;i <= n;i++){
			int cc = max(a[i][0],max(a[i][1],a[i][2]));
			ans += cc;
			if (cc == a[i][0]){
				cnt0++;
			}else if (cc == a[i][1]){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		int tot = 0;
		if (cnt0 > (n / 2)){
			for (int i = 1;i <= n;i++){
				if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
					b[++tot] = min(a[i][0] - a[i][1],a[i][0] - a[i][2]);
				}
			}
			sort(b + 1,b + tot + 1);
			for (int i = 1;cnt0 - i >= (n / 2);i++){
				ans -= b[i];
			}
		}else if (cnt1 > (n / 2)){
			for (int i = 1;i <= n;i++){
				if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
					b[++tot] = min(a[i][1] - a[i][0],a[i][1] - a[i][2]);
				}
			}
			sort(b + 1,b + tot + 1);
			for (int i = 1;cnt1 - i >= (n / 2);i++){
				ans -= b[i];
			}
		}else if (cnt2 > (n / 2)){
			for (int i = 1;i <= n;i++){
				if (a[i][2] >= a[i][1] && a[i][2] >= a[i][0]){
					b[++tot] = min(a[i][2] - a[i][1],a[i][2] - a[i][0]);
				}
			}
			sort(b + 1,b + tot + 1);
			for (int i = 1;cnt2 - i >= (n / 2);i++){
				ans -= b[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
