#include<bits/stdc++.h>
//#define int long long
//RP++ RP++ RP++ RP++ RP++
using namespace std;
const int N=1e6+10;
struct rp{
	int ll,rr;
}x[N];
int n,k,a[N],c[N],t,minn,ans,dp[N][300];
bool cmp(rp xx,rp yy){
	return xx.rr <yy.rr ;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	if(n<=1000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			c[i]=c[i-1]^a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((c[j]^c[i-1])==k){
					x[++t].ll=i,x[t].rr=j;
				}
			}
		}
		sort(x+1,x+1+t,cmp);
		for(int i=1;i<=t;i++){
			if(x[i].ll >minn)minn=x[i].rr ,ans++;
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(dp,-1,sizeof(dp));
		dp[1][a[1]]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=255;j++){
				if(a[i]==j)dp[i][j]=i;
				else dp[i][j]=dp[i-1][j^a[i]];
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i][k]==-1)continue;
			else{
				if(dp[i][k]>minn)minn=i,ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
