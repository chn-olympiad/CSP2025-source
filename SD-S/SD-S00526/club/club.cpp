#include<bits/stdc++.h>
#define int long long
const int N = 1e5+5;
using namespace std;
int n,t,ans;
int a[N][5],b[5][N],cnt[5],maxn[N],maxn2[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i<=n;i++){
			a[i][1] = a[i][2] = a[i][3] = 0;
			maxn[i] = maxn2[i] = 0;
			b[1][i] = b[2][i] = b[3][i] = 0;
		}
		cnt[1] = cnt[2] = cnt[3] = 0;
		ans = 0;
		for(int i = 1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				maxn[i] = 1;
				cnt[1]++;
				if(a[i][2]>=a[i][3])maxn2[i] = 2;
				else maxn2[i] = 3;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				maxn[i] = 2;
				cnt[2]++;
				if(a[i][1]>=a[i][3])maxn2[i] = 1;
				else maxn2[i] = 3;
			}else {
				maxn[i] = 3;
				cnt[3]++;
				if(a[i][1]>=a[i][2])maxn2[i] = 1;
				else maxn2[i] = 2;
			}
			ans += a[i][maxn[i]];
			b[maxn[i]][cnt[maxn[i]]] = a[i][maxn[i]] - a[i][maxn2[i]];
		}
		int bg = 0;
		for(int i = 1;i<=3;i++)
			if(cnt[i]>n/2)bg = i;
		if(bg==0)cout << ans << "\n";
		else{
			int duo = cnt[bg]-n/2;
			sort(b[bg]+1,b[bg]+cnt[bg]+1);
			for(int i = 1;i<=duo;i++)ans-=b[bg][i];
			cout << ans << "\n";
		}
	}
}
/*Ren5Jie4Di4Ling5%
14:53 done.
*/
