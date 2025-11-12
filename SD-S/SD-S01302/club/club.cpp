#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int t,n;
struct node {
	int w;
	int i;
	int j;
};
node s[N*3];
int cnt,num[4],ans;
bool vis[N];
int dp[210][110][110];

bool cmp(node x,node y){
	return x.w>y.w;
}

int main () {

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin >> t;
	while(t--) {
		cin >> n;
		if(n<=200) {
			int x,y,z;
			for(int i=1; i<=n; i++) {
				cin >> x >> y >> z;
				for(int j=0; j<=min(n/2,i); j++) {
					for(int l=0; l<=min(i-j,n/2); l++) {
						int k=i-l-j;
						if(k>n/2) continue;
						if(j) dp[i][j][l]=dp[i-1][j-1][l]+x;
						if(l) dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l-1]+y);
						if(j+l<i) dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]+z);
						if(i==n) ans=max(ans,dp[i][j][l]);
					}
				}
			}
			cout << ans << '\n';
			memset(dp,0,sizeof(dp));
			ans=0;
		} else {
			int x,y,z;
			for(int i=1; i<=n; i++) {
				cin >> x >> y >> z;
				s[++cnt].w=x,s[cnt].i=i,s[cnt].j=1;
				s[++cnt].w=y,s[cnt].i=i,s[cnt].j=2;
				s[++cnt].w=z,s[cnt].i=i,s[cnt].j=3;
			}

			sort(s+1,s+cnt+1,cmp);

			long long ans=0;
			for(int i=1; i<=cnt; i++) {
				if(!vis[s[i].i]) {
					if(num[s[i].j]>=n/2) continue;
					num[s[i].j]++;
					vis[s[i].i]=true;
					ans+=s[i].w;
				}
			}
			cout << ans << '\n';

			memset(num,0,sizeof(num));
			memset(vis,0,sizeof(vis));
			for(int i=1; i<=cnt; i++) s[i].i=s[i].j=s[i].w=0;
			cnt=0;
		}

	}


	return 0;
}
