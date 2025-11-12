#include <bits/stdc++.h>
#define ED cerr<<'\n';
#define TS cerr<<"I AK IOI\n";
#define cr(x) cerr<<x<<'\n';
#define cr2(x,y) cerr<<x<<" "<<y<<'\n';
#define cr3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<'\n';
#define cr4(x,y,z,w) cerr<<x<<" "<<y<<" "<<z<<" "<<w<<'\n';
#define pr(a,l,r) for(int iii=l;iii<=r;++iii) cerr<<a[iii]<<" ";ED
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=505,M=(1<<18)+5,mod=1e9+7,INF=2e9;
int T,n,m,k;
int dp[M][20]; 
char str[N];int c[N];

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	for(int i=0;i<n;++i) {
		scanf("%d",&c[i]);
	}
	dp[0][0]=1;
	for(int s=0;s<(1<<n);++s) {
		int ct=__builtin_popcount(s);
		for(int i=0;i<n;++i) {
			for(int j=0;j<n;++j) {
				if(!((s>>j)&1)) {
					int x=s|(1<<j);
					int y=i+(c[j]<=i||str[ct]=='0');
					dp[x][y]+=dp[s][i];
				}
			}
		}
	}
	int all=(1<<n)-1,ans=0;
	for(int i=0;i<=n-m;++i) {
		ans+=dp[all][i];
	}
	printf("%d\n",ans);
	return 0;
}

