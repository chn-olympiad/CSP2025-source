#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
#define int long long
int T,n,ans;
int a[MAXN],b[MAXN],c[MAXN];
int dp[2][205][205][205];
inline int maxx(int a,int b,int c,int d){
	return max(max(a,b),max(c,d));
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		bool flag=true;
		cin>>n;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0) flag=false;
			if(c[i]!=0) flag=false;
		}
		if(flag==true){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		dp[0][0][0][0]=0;
		for(int i=1;i<=n;++i){
			for(int cnta=0;cnta<=min(i,n/2);++cnta){
				for(int cntb=0;cntb<=min(i-cnta,n/2);++cntb){
					for(int cntc=0;cntc<=min(i-cnta-cntb,n/2);++cntc){
						if(cnta+cntb+cntc==n) break;
						if(cnta!=min(i,n/2)) dp[1][cnta+1][cntb][cntc]=max(dp[1][cnta+1][cntb][cntc],dp[0][cnta][cntb][cntc]+a[i]);
						if(cntb!=min(i-cnta,n/2)) dp[1][cnta][cntb+1][cntc]=max(dp[1][cnta][cntb+1][cntc],dp[0][cnta][cntb][cntc]+b[i]);
						if(cntc!=min(i-cnta-cntb,n/2)) dp[1][cnta][cntb][cntc+1]=max(dp[1][cnta][cntb][cntc+1],dp[0][cnta][cntb][cntc]+c[i]);
						ans=maxx(dp[1][cnta+1][cntb][cntc],dp[1][cnta][cntb+1][cntc],dp[1][cnta][cntb][cntc+1],ans);
					}
				}
			}
			for(int cnta=0;cnta<=min(i,n/2);++cnta){
				for(int cntb=0;cntb<=min(i-cnta,n/2);++cntb){
					for(int cntc=0;cntc<=min(i-cnta-cntb,n/2);++cntc){
						dp[0][cnta][cntb][cntc]=dp[1][cnta][cntb][cntc];
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}