#include<bits/stdc++.h>

using namespace std;

const int maxn=200+10;
const int maxm=1e5+5;

int read() {
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	} while(isdigit(c)) {
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	} return x*f;
}

int T,n,cnt[4],ans=0;
int dp[maxn][maxn][maxn];

struct node{
	int val[4],rk[4];
}a[maxm];

bool cmp(node n1,node n2) {
	return n1.val[1]>n2.val[1];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {
		bool flag=true;
		n=read(); memset(dp,0,sizeof dp); ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				a[i].val[j]=read();
				if(a[i].val[3]!=0 || a[i].val[2]!=0) flag=false;
			}
		}
		if(flag) {
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].val[1];
			cout<<ans<<"\n";
			continue;
		}
//		random_shuffle(a+1,a+1+n);
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=n/2;j++) {
				for(int k=0;k<=n/2;k++) {
					if(i-j-k<0 || i-j-k>n/2) continue;
					if(i-j-k>=1) dp[i][j][k]=dp[i-1][j][k]+a[i].val[3];
					if(j>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].val[1]);
					if(k>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].val[2]);
					ans=max(ans,dp[i][j][k]);
				}
			}
		} cout<<ans<<"\n";
	}
	return 0;
}