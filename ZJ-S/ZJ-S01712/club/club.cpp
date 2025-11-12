#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,t,ans;
const int maxn=1e5+5;
int a[maxn][4];
int sum[maxn];
int z[maxn];
int p[maxn];
signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf("%lld",&t);
	while(t--){
		z[1]=0;
		z[2]=0;
		z[3]=0;
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			p[i]=1e18;
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++){
			sum[i]=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==sum[i]) z[1]++;
			if(a[i][2]==sum[i]) z[2]++;
			if(a[i][3]==sum[i]) z[3]++;
			ans+=sum[i];
		}
		int u;
		int v=max(max(z[1],z[2]),z[3]);
		if(v==z[1]) u=1;
		if(v==z[2]) u=2;
		if(v==z[3]) u=3;
		if(v<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(sum[i]==a[i][u]){
				tot++;
				for(int j=1;j<=3;j++){
					if(j==u) continue;
					p[tot]=min(p[tot],a[i][u]-a[i][j]);
				}
			}
		}
		sort(p+1,p+tot+1);
		for(int i=1;i<=v-n/2;i++) ans-=p[i];
		printf("%lld\n",ans);
	}
	return 0;
}

