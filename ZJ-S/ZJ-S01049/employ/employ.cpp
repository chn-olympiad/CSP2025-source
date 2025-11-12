#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=505;
const int M=(1<<18)+5;
const int inf=2e9+9999;
const int mod=998244353;
int n,m,a[N],b[N];
ll dp[M][25],ans;
char S[N];
void sol(){
	scanf("%d%d%s",&n,&m,S+1);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	dp[0][0]=1;
	int mx=(1<<n)-1;
	for(int s=0;s<mx;s++){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(s&(1<<i)) cnt++;
		}
		for(int i=0;i<n;i++){
			if(s&(1<<i)) continue;
			int v=(s|(1<<i));
			for(int j=0;j<=cnt;j++){
				int f=cnt-j,x=j;
				if(S[cnt+1]=='1') x+=(a[i]>f?1:0);
				dp[v][x]+=dp[s][j];
				(dp[v][x]>=mod)&&(dp[v][x]-=mod);
			}
		}
	}
	for(int i=m;i<=n;i++) ans+=dp[mx][i];
	ans%=mod;
	printf("%lld\n",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	//scanf("%d",&T);
	while(T--) sol();
	return 0;
} 